#ifndef SCAN_CODE_H
#define SCAN_CODE_H

#include <QWidget>

typedef struct
{
    QString room_name;
    bool run_status;//运行情况
    uint16_t cur_temp;  //实时温度
    uint16_t set_temp;  //当前温度
}room_strc;


namespace Ui {
class scan_code;
}


class scan_code : public QWidget
{
    Q_OBJECT

public:
    explicit scan_code(QWidget *parent = nullptr);
    ~scan_code();

private slots:
    void onStartScanClicked();

    void onScanFinished();

    void onScanIDTextEdited();

    void addScanResultToTable(const QString &result);

    bool saveJSONToFile(const QByteArray &jsonData, const QString &fileName);

    void create_room_temp_js(room_strc status);

    void send_cs_msg(QJsonObject &root_js, QString cmd);

    void cs_communicate_encode(QByteArray &buffer, QString cmd, QString status);

    void on_Savebtn_clicked();

    void on_Stop_Scan_clicked();

private:
    Ui::scan_code *ui;
};

#endif // SCAN_CODE_H
