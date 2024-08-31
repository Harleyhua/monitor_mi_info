#include "scan_code.h"
#include "ui_scan_code.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QRegularExpression>
#include <QMessageBox>


#define CS_ROOM_RACK_REQUEST    "40032"
#define CS_DEFAULT_HEARD        "HEAD55AA"


scan_code::scan_code(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::scan_code)
{
    ui->setupUi(this);

    ui->Room_Box->addItem("room-1");
    ui->Room_Box->addItem("room-2");

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
    //鼠标聚焦到输入框并等待用户输入
    ui->ScanIDEdit->setFocus();
}


//每一次扫码结束
void scan_code::onScanFinished()
{
    QString scannedID = ui->ScanIDEdit->text();
    onScanIDTextEdited();

    // QString Mi_id = ui->ProductEdit->text();
    // addScanResultToTable(Mi_id);
}

//判断是位置还是编号,并按位置分配编号
void scan_code::onScanIDTextEdited()
{
    QString text = ui->ScanIDEdit->text();
    // QString position;
    // QString mi_cid;
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
    else if (text.startsWith("A") || text.startsWith("B") || text.startsWith("C"))
    {
        QRegularExpression regex("^[ABC][0-9]+$");
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
                        int rackIndex = positionParts[1].toInt(); // 架位索引
                        int rowIndex = positionParts[2].toInt(); // 行索引
                        int columnIndex = positionParts[3].toInt(); // 列索引

                        QString objectName = tableWidget->objectName(); // 获取对象名称
                        QString lastPart = objectName.mid(10);
                        QString singleChar = objectName.right(1);
                        int index = singleChar.toInt();

                        if(index == rackIndex)
                        {
                            Position.clear();

                            QTableWidgetItem *newItem = new QTableWidgetItem(MiCid);
                            if (rowIndex >= 0 && rowIndex < tableWidget->rowCount() &&
                                columnIndex >= 0 && columnIndex < tableWidget->columnCount())
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

//添加到表格中
// void scan_code::addScanResultToTable(const QString &result)
// {
//     static int currentRow = 0;
//     if (currentRow >= ui->tableWidget1->rowCount())
//     {
//         currentRow = 0;
//     }

//     // 确保currentRow不会超过表格的行数
//     int currentColumn = ui->tableWidget1->columnCount() - 1;
//     for (int i = 0; i < currentColumn; ++i)
//     {
//         if (ui->tableWidget1->item(currentRow, i) == nullptr ||
//             ui->tableWidget1->item(currentRow, i)->text().isEmpty())
//         {
//             currentColumn = i;
//             break;
//         }
//     }

//     //找到当前行的第一个空单元格
//     QTableWidgetItem *newItem = new QTableWidgetItem(result);
//     ui->tableWidget1->setItem(currentRow, currentColumn, newItem);
//     ++currentColumn;
//     if (currentColumn >= ui->tableWidget1->columnCount())
//     {
//         ++currentRow;
//     }
// }

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
    root_js["current_time"] = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    for (QTableWidget *tableWidget : tableWidgets)
    {
        if (tableWidget->rowCount() > 0)
        {
            QJsonObject rackObj;
            rackObj["rack_id"] = QString("rack-%1").arg(tableWidgets.indexOf(tableWidget) + 1);

        // QTableWidgetItem *item_2 = tableWidget->item(0, 0);
        // if (item_2 && !item_2->text().isEmpty())
        // {
            // 第一个rack
            // for (int rackIndex = 0; rackIndex < 6; ++rackIndex)
            // {
                //QJsonObject rackObj;
                //rackObj["rack_id"] = QString("rack-%1").arg(rackIndex + 1);

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
                                nodeJson["aging_start_time"] = "2024-06-19 20:58:52";
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

    QString fileName = "output.txt";
    if (saveJSONToFile(msg, fileName))
    {
        QMessageBox::information(this, "保存成功", "JSON 数据保存成功！");
    }
    else
    {
        QMessageBox::critical(this, "保存失败", "JSON 数据保存失败！");
    }

    //QLOG_INFO() << "发送--->" + QString(msg);
    //emit s_send_cs_msg(msg);
    // 将 QJsonObject 转换为 QJsonDocument
}

void scan_code::cs_communicate_encode(QByteArray &buffer, QString cmd, QString status)
{
    int length = buffer.size();
    buffer.insert(0,CS_DEFAULT_HEARD);
    buffer.insert(8,cmd.toUtf8());
    buffer.insert(13,status.toUtf8());
    buffer.insert(17,QString("%1").arg(length,11,10,QLatin1Char('0')).toUtf8());
}


//保存按钮
void scan_code::on_Savebtn_clicked()
{
    room_strc status;
    create_room_temp_js(status);
}


