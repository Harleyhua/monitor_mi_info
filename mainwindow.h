#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QtNetwork/QTcpSocket>


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
    //cm_mg *m_cm_mg;

signals:
    void s_cm_start();
    void s_send_cs_msg(QByteArray msg);

private slots:

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
