#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QtNetwork/QTcpSocket>
#include <QThread>
#include <QMessageBox>
#include <QCloseEvent>
#include "up_load.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Up_load *up_load;
    QThread m_thread;

signals:
    void s_cm_start();
    void s_send_cs_msg(QByteArray msg);

private slots:


protected:
    void closeEvent(QCloseEvent *event) override
    {
        QMessageBox::StandardButton res = QMessageBox::question(this, "退出系统","是否要退出本系统?",
                                                                QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
        if (res == QMessageBox::Yes)
        {
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
