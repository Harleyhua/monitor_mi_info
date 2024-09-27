#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QtNetwork/QTcpSocket>
#include "up_load.h"
#include <QThread>


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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
