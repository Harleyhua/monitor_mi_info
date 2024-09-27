/********************************************************************************
** Form generated from reading UI file 'up_load.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UP_LOAD_H
#define UI_UP_LOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Up_load
{
public:
    QLineEdit *IP_Edit;
    QLineEdit *Port_Edit;
    QPushButton *Connect_btn;
    QLabel *label_24;
    QPushButton *Start_btn;
    QLabel *label_20;
    QPushButton *Load_btn;
    QTextEdit *Show_Edit;
    QLabel *label_25;
    QLineEdit *reply_Edit_2;
    QLabel *label_26;
    QTextEdit *reply_Edit;

    void setupUi(QWidget *Up_load)
    {
        if (Up_load->objectName().isEmpty())
            Up_load->setObjectName(QString::fromUtf8("Up_load"));
        Up_load->resize(1119, 677);
        IP_Edit = new QLineEdit(Up_load);
        IP_Edit->setObjectName(QString::fromUtf8("IP_Edit"));
        IP_Edit->setGeometry(QRect(20, 45, 150, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font.setPointSize(12);
        font.setBold(false);
        IP_Edit->setFont(font);
        Port_Edit = new QLineEdit(Up_load);
        Port_Edit->setObjectName(QString::fromUtf8("Port_Edit"));
        Port_Edit->setGeometry(QRect(20, 150, 150, 31));
        Port_Edit->setFont(font);
        Connect_btn = new QPushButton(Up_load);
        Connect_btn->setObjectName(QString::fromUtf8("Connect_btn"));
        Connect_btn->setGeometry(QRect(30, 250, 131, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft Tai Le"));
        font1.setPointSize(12);
        font1.setBold(true);
        Connect_btn->setFont(font1);
        label_24 = new QLabel(Up_load);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 125, 62, 19));
        label_24->setFont(font1);
        Start_btn = new QPushButton(Up_load);
        Start_btn->setObjectName(QString::fromUtf8("Start_btn"));
        Start_btn->setGeometry(QRect(30, 450, 131, 41));
        Start_btn->setFont(font1);
        label_20 = new QLabel(Up_load);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 20, 61, 19));
        label_20->setFont(font1);
        Load_btn = new QPushButton(Up_load);
        Load_btn->setObjectName(QString::fromUtf8("Load_btn"));
        Load_btn->setGeometry(QRect(30, 350, 131, 41));
        Load_btn->setFont(font1);
        Show_Edit = new QTextEdit(Up_load);
        Show_Edit->setObjectName(QString::fromUtf8("Show_Edit"));
        Show_Edit->setGeometry(QRect(250, 20, 451, 621));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        Show_Edit->setFont(font2);
        label_25 = new QLabel(Up_load);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(770, 30, 121, 19));
        label_25->setFont(font1);
        reply_Edit_2 = new QLineEdit(Up_load);
        reply_Edit_2->setObjectName(QString::fromUtf8("reply_Edit_2"));
        reply_Edit_2->setGeometry(QRect(770, 165, 171, 61));
        reply_Edit_2->setFont(font);
        label_26 = new QLabel(Up_load);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(770, 140, 121, 19));
        label_26->setFont(font1);
        reply_Edit = new QTextEdit(Up_load);
        reply_Edit->setObjectName(QString::fromUtf8("reply_Edit"));
        reply_Edit->setGeometry(QRect(770, 60, 171, 71));

        retranslateUi(Up_load);

        QMetaObject::connectSlotsByName(Up_load);
    } // setupUi

    void retranslateUi(QWidget *Up_load)
    {
        Up_load->setWindowTitle(QCoreApplication::translate("Up_load", "Form", nullptr));
        Connect_btn->setText(QCoreApplication::translate("Up_load", "\350\277\236\346\216\245", nullptr));
        label_24->setText(QCoreApplication::translate("Up_load", "\347\253\257\345\217\243\357\274\232", nullptr));
        Start_btn->setText(QCoreApplication::translate("Up_load", "\345\220\257\345\212\250", nullptr));
        label_20->setText(QCoreApplication::translate("Up_load", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        Load_btn->setText(QCoreApplication::translate("Up_load", "\345\212\240\350\275\275", nullptr));
        label_25->setText(QCoreApplication::translate("Up_load", "MES\345\233\236\344\274\240\344\277\241\346\201\257\357\274\232", nullptr));
        label_26->setText(QCoreApplication::translate("Up_load", "MES\345\233\236\344\274\240\350\256\241\346\227\266\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Up_load: public Ui_Up_load {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UP_LOAD_H
