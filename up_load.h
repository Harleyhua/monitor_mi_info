#ifndef UP_LOAD_H
#define UP_LOAD_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include <QTextEdit>

namespace Ui {
class Up_load;
}

class Up_load : public QWidget
{
    Q_OBJECT

public:
    explicit Up_load(QWidget *parent = nullptr);
    ~Up_load();

private slots:
    void on_Connect_btn_clicked();

    void on_Load_btn_clicked();

    void openFile();

    void on_Start_btn_clicked();


private:
    Ui::Up_load *ui;

    QTcpSocket *client;
    QTextEdit *textEdit;
};

#endif // UP_LOAD_H
