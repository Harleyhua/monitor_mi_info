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



Up_load::Up_load(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Up_load)
{
    ui->setupUi(this);
    client = new QTcpSocket(this);

    ui->IP_Edit->setText("192.168.7.237");
    ui->Port_Edit->setText("40032");

    ui->Show_Edit->resize(451, 800);

    //按键打开文件
    connect(ui->Load_btn, &QPushButton::clicked, this, &Up_load::openFile);
    connect(client, &QTcpSocket::readyRead, this, &Up_load::onDataReceived);

    connectionChecker.setInterval(reconnectInterval);
    connectionChecker.setSingleShot(false);
    connect(&connectionChecker, &QTimer::timeout, this, &Up_load::checkConnection);

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
        ui->IP_Edit->setEnabled(false);
        ui->Port_Edit->setEnabled(false);
        QMessageBox::information(this,"提示","连接服务器成功！");
    }
    else
    {
        ui->Start_btn->setEnabled(true);
        QMessageBox::information(this,"提示","连接失败，请检查IP地址和端口！");
    }
}


void Up_load::on_Load_btn_clicked()
{

}


void Up_load::openFile()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "",
                                                    "Text Files (*.txt);;All Files (*.*)");
    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly))
        {
            QString fileContent = file.readAll();
            file.close();
            ui->Show_Edit->setText(fileContent);
        }
    }
}

void Up_load::on_Start_btn_clicked()
{
    QString msg = ui->Show_Edit->toPlainText();
    QByteArray msg_2 = msg.toUtf8();
    client->write(msg_2);
}

void Up_load::onm_timer_callback()
{
    static uint32_t t1 = 0;
    t1 ++;
    if(t1 >= 4)
    {
        //两间房
        //col_room_temp();
        t1 = 0;
    }
}

void Up_load::onm_new_timer()
{
    m_timer = new QTimer();
    connect(m_timer,&QTimer::timeout,this,&Up_load::onm_timer_callback);
    m_timer->start(15000);
}

void Up_load::onDataReceived()
{
    QByteArray data = client->readAll();
    ui->reply_Edit->setText(data);

}

void Up_load::checkConnection()
{
    if (client->state() != QAbstractSocket::ConnectedState)
    {
        ui->IP_Edit->setEnabled(true);
        ui->Port_Edit->setEnabled(true);
        ui->Start_btn->setEnabled(true);
        QMessageBox::information(this,"提示","未连接，尝试重新连接!");
        client->connectToHost(ui->IP_Edit->text(),ui->Port_Edit->text().toInt());
    }
}
