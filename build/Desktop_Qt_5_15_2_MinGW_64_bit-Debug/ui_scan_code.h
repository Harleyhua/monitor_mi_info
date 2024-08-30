/********************************************************************************
** Form generated from reading UI file 'scan_code.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCAN_CODE_H
#define UI_SCAN_CODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scan_code
{
public:
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QTableWidget *tableWidget4;
    QLineEdit *agetime_Edit;
    QWidget *layoutWidget_8;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_15;
    QTableWidget *tableWidget3;
    QLineEdit *ProductEdit;
    QLineEdit *Temp_Edit;
    QLineEdit *PosEdit;
    QPushButton *Start_Scan_btn;
    QWidget *layoutWidget_9;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_16;
    QTableWidget *tableWidget2;
    QWidget *layoutWidget_10;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_17;
    QTableWidget *tableWidget1;
    QLabel *label_18;
    QWidget *layoutWidget_11;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_19;
    QTableWidget *tableWidget6;
    QLabel *label_20;
    QPushButton *Savebtn;
    QLabel *label_21;
    QLineEdit *ScanIDEdit;
    QPushButton *Stop_Scan;
    QLabel *label_22;
    QWidget *layoutWidget_12;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_23;
    QTableWidget *tableWidget5;
    QLabel *label_24;
    QComboBox *Room_Box;

    void setupUi(QWidget *scan_code)
    {
        if (scan_code->objectName().isEmpty())
            scan_code->setObjectName(QString::fromUtf8("scan_code"));
        scan_code->resize(1670, 957);
        layoutWidget_7 = new QWidget(scan_code);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(650, 320, 611, 281));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(11);
        font.setBold(true);
        label_7->setFont(font);

        verticalLayout_7->addWidget(label_7);

        tableWidget4 = new QTableWidget(layoutWidget_7);
        if (tableWidget4->columnCount() < 6)
            tableWidget4->setColumnCount(6);
        if (tableWidget4->rowCount() < 8)
            tableWidget4->setRowCount(8);
        tableWidget4->setObjectName(QString::fromUtf8("tableWidget4"));
        tableWidget4->setRowCount(8);
        tableWidget4->setColumnCount(6);
        tableWidget4->horizontalHeader()->setVisible(false);
        tableWidget4->verticalHeader()->setVisible(false);

        verticalLayout_7->addWidget(tableWidget4);

        agetime_Edit = new QLineEdit(scan_code);
        agetime_Edit->setObjectName(QString::fromUtf8("agetime_Edit"));
        agetime_Edit->setGeometry(QRect(1470, 625, 150, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(12);
        font1.setBold(false);
        agetime_Edit->setFont(font1);
        layoutWidget_8 = new QWidget(scan_code);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 320, 611, 281));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_8);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget_8);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        verticalLayout_8->addWidget(label_15);

        tableWidget3 = new QTableWidget(layoutWidget_8);
        if (tableWidget3->columnCount() < 6)
            tableWidget3->setColumnCount(6);
        if (tableWidget3->rowCount() < 8)
            tableWidget3->setRowCount(8);
        tableWidget3->setObjectName(QString::fromUtf8("tableWidget3"));
        tableWidget3->setRowCount(8);
        tableWidget3->setColumnCount(6);
        tableWidget3->horizontalHeader()->setVisible(false);
        tableWidget3->verticalHeader()->setVisible(false);

        verticalLayout_8->addWidget(tableWidget3);

        ProductEdit = new QLineEdit(scan_code);
        ProductEdit->setObjectName(QString::fromUtf8("ProductEdit"));
        ProductEdit->setGeometry(QRect(1470, 405, 150, 31));
        ProductEdit->setFont(font1);
        Temp_Edit = new QLineEdit(scan_code);
        Temp_Edit->setObjectName(QString::fromUtf8("Temp_Edit"));
        Temp_Edit->setGeometry(QRect(1470, 740, 150, 31));
        Temp_Edit->setFont(font1);
        PosEdit = new QLineEdit(scan_code);
        PosEdit->setObjectName(QString::fromUtf8("PosEdit"));
        PosEdit->setGeometry(QRect(1470, 300, 150, 31));
        PosEdit->setFont(font1);
        Start_Scan_btn = new QPushButton(scan_code);
        Start_Scan_btn->setObjectName(QString::fromUtf8("Start_Scan_btn"));
        Start_Scan_btn->setGeometry(QRect(1480, 90, 131, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font2.setPointSize(12);
        font2.setBold(true);
        Start_Scan_btn->setFont(font2);
        layoutWidget_9 = new QWidget(scan_code);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(650, 10, 611, 281));
        verticalLayout_9 = new QVBoxLayout(layoutWidget_9);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_9);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        verticalLayout_9->addWidget(label_16);

        tableWidget2 = new QTableWidget(layoutWidget_9);
        if (tableWidget2->columnCount() < 6)
            tableWidget2->setColumnCount(6);
        if (tableWidget2->rowCount() < 8)
            tableWidget2->setRowCount(8);
        tableWidget2->setObjectName(QString::fromUtf8("tableWidget2"));
        tableWidget2->setRowCount(8);
        tableWidget2->setColumnCount(6);
        tableWidget2->horizontalHeader()->setVisible(false);
        tableWidget2->verticalHeader()->setVisible(false);

        verticalLayout_9->addWidget(tableWidget2);

        layoutWidget_10 = new QWidget(scan_code);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(9, 9, 611, 281));
        verticalLayout_10 = new QVBoxLayout(layoutWidget_10);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget_10);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);

        verticalLayout_10->addWidget(label_17);

        tableWidget1 = new QTableWidget(layoutWidget_10);
        if (tableWidget1->columnCount() < 6)
            tableWidget1->setColumnCount(6);
        if (tableWidget1->rowCount() < 8)
            tableWidget1->setRowCount(8);
        tableWidget1->setObjectName(QString::fromUtf8("tableWidget1"));
        tableWidget1->setRowCount(8);
        tableWidget1->setColumnCount(6);
        tableWidget1->horizontalHeader()->setVisible(false);
        tableWidget1->verticalHeader()->setVisible(false);

        verticalLayout_10->addWidget(tableWidget1);

        label_18 = new QLabel(scan_code);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(1470, 715, 105, 19));
        label_18->setFont(font2);
        layoutWidget_11 = new QWidget(scan_code);
        layoutWidget_11->setObjectName(QString::fromUtf8("layoutWidget_11"));
        layoutWidget_11->setGeometry(QRect(650, 630, 611, 281));
        verticalLayout_11 = new QVBoxLayout(layoutWidget_11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget_11);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);

        verticalLayout_11->addWidget(label_19);

        tableWidget6 = new QTableWidget(layoutWidget_11);
        if (tableWidget6->columnCount() < 6)
            tableWidget6->setColumnCount(6);
        if (tableWidget6->rowCount() < 8)
            tableWidget6->setRowCount(8);
        tableWidget6->setObjectName(QString::fromUtf8("tableWidget6"));
        tableWidget6->setRowCount(8);
        tableWidget6->setColumnCount(6);
        tableWidget6->horizontalHeader()->setVisible(false);
        tableWidget6->verticalHeader()->setVisible(false);

        verticalLayout_11->addWidget(tableWidget6);

        label_20 = new QLabel(scan_code);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(1470, 275, 45, 19));
        label_20->setFont(font2);
        Savebtn = new QPushButton(scan_code);
        Savebtn->setObjectName(QString::fromUtf8("Savebtn"));
        Savebtn->setGeometry(QRect(1480, 840, 131, 41));
        Savebtn->setFont(font2);
        label_21 = new QLabel(scan_code);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(1470, 490, 62, 19));
        label_21->setFont(font2);
        ScanIDEdit = new QLineEdit(scan_code);
        ScanIDEdit->setObjectName(QString::fromUtf8("ScanIDEdit"));
        ScanIDEdit->setGeometry(QRect(1470, 515, 150, 31));
        ScanIDEdit->setFont(font1);
        ScanIDEdit->setMaxLength(10);
        Stop_Scan = new QPushButton(scan_code);
        Stop_Scan->setObjectName(QString::fromUtf8("Stop_Scan"));
        Stop_Scan->setGeometry(QRect(1480, 190, 131, 41));
        Stop_Scan->setFont(font2);
        label_22 = new QLabel(scan_code);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(1470, 600, 75, 19));
        label_22->setFont(font2);
        layoutWidget_12 = new QWidget(scan_code);
        layoutWidget_12->setObjectName(QString::fromUtf8("layoutWidget_12"));
        layoutWidget_12->setGeometry(QRect(10, 630, 611, 281));
        verticalLayout_12 = new QVBoxLayout(layoutWidget_12);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(layoutWidget_12);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font);

        verticalLayout_12->addWidget(label_23);

        tableWidget5 = new QTableWidget(layoutWidget_12);
        if (tableWidget5->columnCount() < 6)
            tableWidget5->setColumnCount(6);
        if (tableWidget5->rowCount() < 8)
            tableWidget5->setRowCount(8);
        tableWidget5->setObjectName(QString::fromUtf8("tableWidget5"));
        tableWidget5->setRowCount(8);
        tableWidget5->setColumnCount(6);
        tableWidget5->horizontalHeader()->setVisible(false);
        tableWidget5->verticalHeader()->setVisible(false);

        verticalLayout_12->addWidget(tableWidget5);

        label_24 = new QLabel(scan_code);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(1470, 380, 62, 19));
        label_24->setFont(font2);
        Room_Box = new QComboBox(scan_code);
        Room_Box->setObjectName(QString::fromUtf8("Room_Box"));
        Room_Box->setGeometry(QRect(1480, 30, 131, 21));
        Room_Box->setDuplicatesEnabled(false);

        retranslateUi(scan_code);

        QMetaObject::connectSlotsByName(scan_code);
    } // setupUi

    void retranslateUi(QWidget *scan_code)
    {
        scan_code->setWindowTitle(QCoreApplication::translate("scan_code", "Form", nullptr));
        label_7->setText(QCoreApplication::translate("scan_code", "\350\200\201\345\214\226\350\275\2464", nullptr));
        label_15->setText(QCoreApplication::translate("scan_code", "\350\200\201\345\214\226\350\275\2463", nullptr));
        Start_Scan_btn->setText(QCoreApplication::translate("scan_code", "\345\274\200\345\247\213\346\211\253\347\240\201", nullptr));
        label_16->setText(QCoreApplication::translate("scan_code", "\350\200\201\345\214\226\350\275\2462", nullptr));
        label_17->setText(QCoreApplication::translate("scan_code", "\350\200\201\345\214\226\350\275\2461", nullptr));
        label_18->setText(QCoreApplication::translate("scan_code", "\350\200\201\345\214\226\351\242\204\347\203\255\346\227\266\351\225\277\357\274\232", nullptr));
        label_19->setText(QCoreApplication::translate("scan_code", "\350\200\201\345\214\226\350\275\2466", nullptr));
        label_20->setText(QCoreApplication::translate("scan_code", "\344\275\215\347\275\256\357\274\232", nullptr));
        Savebtn->setText(QCoreApplication::translate("scan_code", "\344\277\235\345\255\230", nullptr));
        label_21->setText(QCoreApplication::translate("scan_code", "\346\211\253\347\240\201ID\357\274\232", nullptr));
        Stop_Scan->setText(QCoreApplication::translate("scan_code", "\345\201\234\346\255\242", nullptr));
        label_22->setText(QCoreApplication::translate("scan_code", "\350\200\201\345\214\226\346\227\266\351\225\277\357\274\232", nullptr));
        label_23->setText(QCoreApplication::translate("scan_code", "\350\200\201\345\214\226\350\275\2465", nullptr));
        label_24->setText(QCoreApplication::translate("scan_code", "\344\272\247\345\223\201ID\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scan_code: public Ui_scan_code {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCAN_CODE_H
