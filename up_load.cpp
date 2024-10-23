#include "up_load.h"
#include "ui_up_load.h"
#include <QMessageBox>
#include <QTextEdit>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonArray>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QMessageBox>
#include <QTimer>

extern QString globaldata;

Up_load::Up_load(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Up_load)
{

    ui->setupUi(this);
    client = new QTcpSocket(this);
    sent_timer = new QTimer(this);
    Hit_timer = new QTimer(this);

    ui->IP_Edit->setText("47.97.180.36");
    ui->Port_Edit->setText("40032");

    ui->Show_Edit->resize(451, 800);

    //按键打开文件
    connect(ui->Load_btn, &QPushButton::clicked, this, &Up_load::openFile);
    connect(client, &QTcpSocket::readyRead, this, &Up_load::onDataReceived);
    connect(sent_timer,&QTimer::timeout,this,&Up_load::sent_msg);
    connect(&connectionChecker, &QTimer::timeout, this, &Up_load::checkConnection);
    connect(Hit_timer,&QTimer::timeout,this,&Up_load::updateCountdown);

    connectionChecker.start(5000);
}

Up_load::~Up_load()
{
    delete ui;
}

void Up_load::on_Connect_btn_clicked()
{
    client->connectToHost(ui->IP_Edit->text(),ui->Port_Edit->text().toInt());
    if(client->waitForConnected(10000))
    {
        ui->Connect_btn->setEnabled(false);
        setLED(ui->LED_label,2,16);
        ui->IP_Edit->setEnabled(false);
        ui->Port_Edit->setEnabled(false);
        //QMessageBox::information(this,"提示","连接服务器成功！");
    }
    else
    {
        ui->Start_btn->setEnabled(true);
        setLED(ui->LED_label,0,16);
        QMessageBox::information(this,"提示","连接失败，请检查IP地址和端口！");
    }
}

// void Up_load::openFile()
// {
//     QString filePath = QFileDialog::getOpenFileName(this, "Open File", "",
//                                                     "Text Files (*.txt);;All Files (*.*)");
//     if (!filePath.isEmpty())
//     {
//         QFile file(filePath);
//         if (file.open(QIODevice::ReadOnly))
//         {
//             ui->Show_Edit->setText(file.readAll());
//             file.close();
//         }
//     }
// }

void Up_load::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "",
                                                    "Text Files (*.json);;All Files (*.*)");
    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly))
        {
            QString fileContent = file.readAll();
            file.close();

            QStringList parts = fileContent.split('{');
            QString head = parts.at(0);

            fileContent.remove(0, head.length());

            //读取json文件
            QJsonDocument doc = QJsonDocument::fromJson(fileContent.toUtf8());
            if (doc.isNull())
            {
                qDebug() << "Failed to parse JSON";
                return;
            }

            QJsonObject jsonObject = doc.object();
            QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            jsonObject.insert("current_time", currentTime);

            QJsonDocument doc_data = QJsonDocument(jsonObject);
            QByteArray buffer = doc_data.toJson();
            int length = buffer.size();
            QString status = "XXXX";
            QString cmd = CS_ROOM_RACK_REQUEST;
            buffer.insert(0,CS_DEFAULT_HEARD);
            buffer.insert(8,cmd.toUtf8());
            buffer.insert(12,status.toUtf8());
            buffer.insert(16,QString("%1").arg(length,11,10,QLatin1Char('0')).toUtf8());

            QJsonDocument data = QJsonDocument::fromJson(buffer);
            QString updated = QString(buffer);

            ui->Show_Edit->setText(updated);
        }
    }
}

void Up_load::sent_msg()
{
    QString msg = ui->Show_Edit->toPlainText();
    QByteArray msg_2 = msg.toUtf8();
    client->write(msg_2);
}

void Up_load::onDataReceived()
{
    QByteArray data = client->readAll();

    QString statusCode = data.mid(12,4);
    // 检查状态码
    if (statusCode == "2100")
    {
        ui->reply_Edit->setText(data);
    }
    else
    {
        ui->reply_Edit->setText("服务器返回异常");
    }
}

void Up_load::checkConnection()
{
    if (client->state() != QAbstractSocket::ConnectedState)
    {
        ui->IP_Edit->setEnabled(true);
        ui->Port_Edit->setEnabled(true);
        ui->Connect_btn->setEnabled(true);
        setLED(ui->LED_label,0,16);
        QMessageBox::information(this,"提示","未连接，尝试重新连接!");
        client->connectToHost(ui->IP_Edit->text(),ui->Port_Edit->text().toInt());
    }
    else
    {
        ui->IP_Edit->setEnabled(false);
        ui->Port_Edit->setEnabled(false);
        ui->Connect_btn->setEnabled(false);
        setLED(ui->LED_label,2,16);
    }
}

void Up_load::on_Start_btn_clicked()
{
    sent_timer->start(120000);
    ui->Start_btn->setEnabled(false);
    Hit_timer->start(1000);
}

void Up_load::updateCountdown()
{
    int countdownValue = globaldata.toInt() * 60;

    if (elapsedTime < countdownValue)
    {
        elapsedTime ++;
        int hours = elapsedTime / 3600; // 计算小时
        int minutes = (elapsedTime % 3600) / 60; // 计算分钟
        int seconds = elapsedTime % 60; // 计算秒
        ui->Reply_Edit->setText(QString("%1:%2:%3")
                                .arg(hours, 2, 10, QLatin1Char('0'))
                                .arg(minutes, 2, 10, QLatin1Char('0'))
                                .arg(seconds, 2, 10, QLatin1Char('0')));
    }
    else
    {
        sent_timer->stop();
        Hit_timer->stop();
    }
}


void Up_load::setLED(QLabel* label, int color, int size)
{
    label->setText("");

    QString min_width = QString("min-width: %1px;").arg(size);              // 最小宽度：size
    QString min_height = QString("min-height: %1px;").arg(size);            // 最小高度：size
    QString max_width = QString("max-width: %1px;").arg(size);              // 最小宽度：size
    QString max_height = QString("max-height: %1px;").arg(size);            // 最小高度：size
    // 再设置边界形状及边框
    QString border_radius = QString("border-radius: %1px;").arg(size/2);    // 边框是圆角，半径为size/2
    QString border = QString("border:1px solid black;");                    // 边框为1px黑色
    // 最后设置背景颜色
    QString background = "background-color:";
    switch (color)
    {
    case 0:
        // 灰色
        background += "rgb(190,190,190)";
        break;
    case 1:
        // 红色
        background += "rgb(255,48,48)";
        break;
    case 2:
        // 绿色
        //background += "rgb(0,255,0)";
        background += "rgb(124,252,0)";
        break;
    case 3:
        // 黄色
        background += "rgb(255,255,0)";
        break;
    default:
        break;
    }

    const QString SheetStyle = min_width + min_height + max_width + max_height + border_radius + border + background;
    label->setStyleSheet(SheetStyle);
}
