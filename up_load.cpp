#include "up_load.h"
#include "ui_up_load.h"
#include <QMessageBox>
#include <QTextEdit>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonArray>

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
    QByteArray msg;
    //emit s_send_cs_msg(msg);
}

