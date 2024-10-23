#include "scan_code.h"
#include "ui_scan_code.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QRegularExpression>
#include <QMessageBox>
#include <QMenu>
#include <QAction>

QString globaldata;

scan_code::scan_code(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::scan_code)
{
    ui->setupUi(this);

    ui->Room_Box->addItem("room-1");
    ui->Room_Box->addItem("room-2");

    ui->tableWidget1->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget2->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget3->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget4->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget5->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget6->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->tableWidget1, &QTableWidget::customContextMenuRequested, this, &scan_code::showContextMenu);
    connect(ui->tableWidget2, &QTableWidget::customContextMenuRequested, this, &scan_code::showContextMenu);
    connect(ui->tableWidget3, &QTableWidget::customContextMenuRequested, this, &scan_code::showContextMenu);
    connect(ui->tableWidget4, &QTableWidget::customContextMenuRequested, this, &scan_code::showContextMenu);
    connect(ui->tableWidget5, &QTableWidget::customContextMenuRequested, this, &scan_code::showContextMenu);
    connect(ui->tableWidget6, &QTableWidget::customContextMenuRequested, this, &scan_code::showContextMenu);

    connect(ui->Start_Scan_btn, &QPushButton::clicked, this, &scan_code::onStartScanClicked);
    connect(ui->ScanIDEdit, &QLineEdit::returnPressed, this, &scan_code::onScanFinished);
}

scan_code::~scan_code()
{
    delete ui;
}

//开始扫码
void scan_code::onStartScanClicked()
{
    ui->Start_Scan_btn->setEnabled(false);
    ui->Stop_Scan->setEnabled(true);
    ui->ScanIDEdit->setFocus();
}

//每一次扫码结束
void scan_code::onScanFinished()
{
    QString scannedID = ui->ScanIDEdit->text();
    onScanIDTextEdited();
}

//判断是位置还是编号,并按位置分配编号
void scan_code::onScanIDTextEdited()
{
    QString text = ui->ScanIDEdit->text();

    QList<QTableWidget*> tableWidgets;
    tableWidgets.append(ui->tableWidget1);
    tableWidgets.append(ui->tableWidget2);
    tableWidgets.append(ui->tableWidget3);
    tableWidgets.append(ui->tableWidget4);
    tableWidgets.append(ui->tableWidget5);
    tableWidgets.append(ui->tableWidget6);

    if (text.startsWith("BTSC"))
    {
        ui->PosEdit->setText(text);
        Position = text;
    }
    else if (text.startsWith("A") || text.startsWith("B") || text.startsWith("C")
            || text.startsWith("1") || text.startsWith("2") || text.startsWith("4"))
    {
        QRegularExpression regex("^[ABC124][0-9]+$");
        QRegularExpressionMatch match = regex.match(text);
        if (match.hasMatch())
        {
            ui->ProductEdit->setText(text);
            MiCid = text;


            for (QTableWidget *tableWidget : tableWidgets)
            {
                if (!Position.isEmpty())
                {
                    QStringList positionParts = Position.split("-");
                    if (positionParts.length() >= 4)
                    {
                        int rackIndex = positionParts[1].toInt();
                        int rowIndex = positionParts[2].toInt();
                        int columnIndex = positionParts[3].toInt();

                        QString objectName = tableWidget->objectName();
                        QString lastPart = objectName.mid(10);
                        QString singleChar = objectName.right(1);
                        int index = singleChar.toInt();

                        if(index == rackIndex)
                        {
                            Position.clear();

                            QTableWidgetItem *newItem = new QTableWidgetItem(MiCid);
                            if (rowIndex >= 0 && rowIndex <= tableWidget->rowCount() &&
                                columnIndex >= 0 && columnIndex <= tableWidget->columnCount())
                            {
                                tableWidget->setItem(rowIndex -1, columnIndex -1, newItem);
                            }
                        }
                    }
                }
            }
        }
    }

    ui->ScanIDEdit->clear();
}

//停止扫码
void scan_code::on_Stop_Scan_clicked()
{
    ui->Stop_Scan->setEnabled(false);
    ui->Start_Scan_btn->setEnabled(true);
}

void scan_code::create_room_temp_js(room_strc status)
{
    QJsonObject root_js;
    QJsonObject racksArrayJson;
    QJsonArray racksArray;
    QList<QTableWidget*> tableWidgets;
    tableWidgets.append(ui->tableWidget1);
    tableWidgets.append(ui->tableWidget2);
    tableWidgets.append(ui->tableWidget3);
    tableWidgets.append(ui->tableWidget4);
    tableWidgets.append(ui->tableWidget5);
    tableWidgets.append(ui->tableWidget6);

    QString room_id = ui->Room_Box->currentText();
    QString age_time = ui->agetime_Edit->text();
    int age = age_time.toInt();

    root_js["room_id"] = room_id;
    //root_js["current_time"] = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    for (QTableWidget *tableWidget : tableWidgets)
    {
        if (tableWidget->rowCount() > 0)
        {
            QJsonObject rackObj;
            rackObj["rack_id"] = QString("rack-%1").arg(tableWidgets.indexOf(tableWidget) + 1);

            // 创建leakage数组
            QJsonArray leakageArray;
            for (int floor = 1; floor <= 8; floor++)
            {
                QJsonObject leakageObj;
                leakageObj["floor"] = floor;

                QTableWidgetItem *item = tableWidget->item(floor - 1, 0);
                if (item && !item->text().isEmpty())
                {
                    leakageObj["status"] = "ON";
                    QJsonArray nodesArray;
                    for (int row = 0; row <= tableWidget->rowCount(); ++row)
                    {
                        for (int column = 0; column <= tableWidget->columnCount(); ++column)
                        {
                            QTableWidgetItem *nodeItem = tableWidget->item(row, column);

                            if (nodeItem && !nodeItem->text().isEmpty())
                            {
                                QJsonObject nodeJson;
                                nodeJson["pos"] = QString("%1-%2").arg(row + 1).arg(column + 1);
                                nodeJson["aging_start_time"] = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                                nodeJson["mi_cid"] = nodeItem->text();
                                nodeJson["dc_V"] = 0.000;
                                nodeJson["dc_A"] = 0.000;
                                nodeJson["dc_W"] = 0.000;
                                nodeJson["ac_V"] = 0.000;
                                nodeJson["ac_A"] = 0.000;
                                nodeJson["ac_W"] = 0.000;
                                nodeJson["age_time"] = age;
                                nodesArray.append(nodeJson);
                            }
                        }
                    }
                    if (!nodesArray.isEmpty())
                    {
                        rackObj["nodes"] = nodesArray;
                    }
                }
                else
                {
                    leakageObj["status"] = "OFF";
                }
                leakageArray.append(leakageObj);
            }
            rackObj["leakage"] = leakageArray;

            if (leakageArray.size() > 0)
            {
                racksArray.append(rackObj);
            }
        }
    }

    root_js["racks"] = racksArray;

    send_cs_msg(root_js,CS_ROOM_RACK_REQUEST);
}

void scan_code::showContextMenu(const QPoint &pos)
{
    QTableWidget *tableWidget = qobject_cast<QTableWidget *>(sender());
    if (tableWidget)
    {
        QMenu menu(tableWidget);
        QAction *deleteAction = menu.addAction(tr("删除"));
        connect(deleteAction, &QAction::triggered, this, [this, tableWidget]() {
            deleteSelectedRows(tableWidget);
        });
        menu.exec(tableWidget->mapToGlobal(pos));
    }
}

void scan_code::deleteSelectedRows(QTableWidget *tableWidget)
{
    QList<QTableWidgetItem*> items = tableWidget->selectedItems();

    foreach(QTableWidgetItem *item, items)
    {
        tableWidget->takeItem(item->row(), item->column());
    }
}


bool scan_code::saveJSONToFile(const QByteArray &jsonData, const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "保存失败", "无法打开文件");
        return false;
    }
    QTextStream textStream(&file);
    textStream << jsonData;
    return true;
}

void scan_code::send_cs_msg(QJsonObject &root_js, QString cmd)
{
    QByteArray msg;
    QJsonDocument root_doc;
    QJsonDocument jsonDoc(root_js);

    QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Indented);
    msg.append(jsonData);

    cs_communicate_encode(msg,cmd,"XXXX");

    QString fileName = "data.json";
    if (saveJSONToFile(msg, fileName))
    {
        QMessageBox::information(this, "保存成功", "JSON 数据保存至data.json");
    }
    else
    {
        QMessageBox::critical(this, "保存失败", "JSON 数据保存失败！");
    }
}

void scan_code::cs_communicate_encode(QByteArray &buffer, QString cmd, QString status)
{
    int length = buffer.size();
    buffer.insert(0,CS_DEFAULT_HEARD);
    buffer.insert(8,cmd.toUtf8());
    buffer.insert(12,status.toUtf8());
    buffer.insert(16,QString("%1").arg(length,11,10,QLatin1Char('0')).toUtf8());
}

//保存按钮
void scan_code::on_Savebtn_clicked()
{
    room_strc status;
    create_room_temp_js(status);
    globaldata = ui->agetime_Edit->text();
}


