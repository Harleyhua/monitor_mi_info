#ifndef UP_LOAD_H
#define UP_LOAD_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include <QTextEdit>
#include <QTimer>
#include <QNetworkReply>
#include <QJsonObject>


#define LOCAL_TEST  1  // 0为正式服务器  1为本地服务器

namespace Ui {
class Up_load;
}

class Up_load : public QWidget
{
    Q_OBJECT

public:
    explicit Up_load(QWidget *parent = nullptr);
    ~Up_load();

    QJsonObject param;
    bool m_busy_status = false;
    QTimer *m_timer = nullptr;
    QTimer *m_http_timer =nullptr;
    QNetworkReply * m_reply = nullptr;
    QNetworkAccessManager *m_network_mg = nullptr;

    //QNetworkAccessManager *m_network_mg = nullptr;
#if LOCAL_TEST
    QString m_url_head = "http://localhost:38700";
#else
    QString m_url_head = "http://47.97.180.36:38700";
#endif

    quint32 m_max_timeout = 15000;
    QString m_account = "aging_room1";
    QString m_password = "123456";

    void onm_http_timer_callback();

    void openFile();

    void http_send(quint32 timeout, QString url, QByteArray msg);

    void http_recv(QNetworkReply *reply);

    void onDataReceived();

    void checkConnection();


private slots:
    void on_Connect_btn_clicked();

    void on_Load_btn_clicked();

    void on_Start_btn_clicked();

    void onm_timer_callback();

public slots:
    void onm_new_timer();

signals:
    void s_send_cs_msg(quint32 timeout, QString path, QByteArray msg);

private:
    Ui::Up_load *ui;

    QTcpSocket *client;
    QTextEdit *textEdit;

    QTimer connectionChecker;
    const int reconnectInterval = 5000; // 5 seconds
};

#endif // UP_LOAD_H
