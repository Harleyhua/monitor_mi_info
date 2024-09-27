#include "tcp_socket.h"
#include <QThread>
#include <QTimer>


tcp_socket::tcp_socket(QObject *parent)
{
    connect(this,&tcp_socket::readyRead,this,&tcp_socket::onm_new_msg);
    //connect(this, &tcp_socket::disconnected, this, &tcp_socket::onDisconnected);

    connect(this, &QTcpSocket::disconnected, this, &tcp_socket::onDisconnected);
    connect(this, &QTcpSocket::connected, this, &tcp_socket::onConnected);
    connectionChecker.setInterval(reconnectInterval);
    connectionChecker.setSingleShot(false);
    connect(&connectionChecker, &QTimer::timeout, this, &tcp_socket::checkConnection);
}

tcp_socket::~tcp_socket()
{
    this->disconnectFromHost();
    this->waitForDisconnected();
    delete socket;
}

void tcp_socket::connectToServer(const QString &host, quint16 port)
{
    this->connectToHost(host, port);
}

void tcp_socket::checkConnection()
{
    if (this->state() != QAbstractSocket::ConnectedState)
    {
        const QString host = "47.97.180.36";
        const quint16 port = 40032;
        connectToServer(host, port);
    }
}

void tcp_socket::disconnectFromServer()
{
    this->disconnectFromHost();
}

void tcp_socket::onm_new_msg()
{
    QByteArray data = readAll();
    //QLOG_DEBUG() << QStringLiteral("socket接收 当前线程id : %1").arg(quintptr(QThread::currentThreadId()));
    emit s_new_msg(data);
}

void tcp_socket::onm_send_msg(QByteArray send_msg)
{
    //QLOG_DEBUG() << QStringLiteral("socket发送 当前线程id : %1").arg(quintptr(QThread::currentThreadId()));
    this->write(send_msg);
}

void tcp_socket::onm_close()
{
    this->abort();
    this->disconnect();
}

void tcp_socket::onConnected()
{
    connectionChecker.stop();
}

void tcp_socket::onDisconnected()
{
    connectionChecker.start();
}

void tcp_socket::tryConnect()
{
    const QString host = "47.97.180.36";
    const quint16 port = 40032;
    this->connectToHost(host, port);

    //QLOG_INFO() << "尝试重新连接到：" << host;
}


