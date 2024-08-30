#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QRegularExpression>
#include "scan_code.h"
#include "up_load.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tabWidget->addTab(new scan_code,"扫码录入");
    ui->tabWidget->addTab(new Up_load,"上传服务器");

}

MainWindow::~MainWindow()
{
    delete ui;
}

