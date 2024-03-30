/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnUpdate;
    QPushButton *btnClear;
    QPushButton *btnDelete;
    QLabel *txtID;
    QListWidget *listNames;
    QLabel *txtTitle;
    QLabel *txtText;
    QLabel *label;
    QPlainTextEdit *planText;
    QLineEdit *lineID;
    QLabel *txtNames;
    QPushButton *btnSave;
    QPushButton *btnInsert;
    QLineEdit *lineSearch;
    QLineEdit *lineTitle;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(707, 559);
        QFont font;
        font.setFamilies({QString::fromUtf8("Goudy Stout")});
        font.setBold(false);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color:#363535;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 22, 3, 1, 1);

        btnCancel = new QPushButton(centralwidget);
        btnCancel->setObjectName("btnCancel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Swiss921 BT")});
        font1.setBold(false);
        btnCancel->setFont(font1);
        btnCancel->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color:#fff;\n"
"	background-color: #d32f2f ;	\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color: #c62828 ;\n"
"}\n"
""));

        gridLayout->addWidget(btnCancel, 24, 3, 1, 1);

        btnUpdate = new QPushButton(centralwidget);
        btnUpdate->setObjectName("btnUpdate");
        btnUpdate->setFont(font1);
        btnUpdate->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color:#fff;\n"
"	background-color: #2196f3 ;	\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color: #1e88e5 ;\n"
"}"));

        gridLayout->addWidget(btnUpdate, 11, 3, 1, 1);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName("btnClear");
        btnClear->setFont(font1);
        btnClear->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color:#fff;\n"
"	background-color: #ffc107;	\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color: #ffca28;\n"
"}"));

        gridLayout->addWidget(btnClear, 12, 3, 1, 1);

        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setFont(font1);
        btnDelete->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color:#fff;\n"
"	background-color: #d32f2f ;	\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color: #c62828 ;\n"
"}"));

        gridLayout->addWidget(btnDelete, 13, 3, 1, 1);

        txtID = new QLabel(centralwidget);
        txtID->setObjectName("txtID");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setBold(false);
        txtID->setFont(font2);
        txtID->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color:#fff;\n"
"}"));

        gridLayout->addWidget(txtID, 3, 2, 1, 1);

        listNames = new QListWidget(centralwidget);
        listNames->setObjectName("listNames");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Source Code Pro")});
        font3.setBold(true);
        listNames->setFont(font3);
        listNames->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	border-radius:10px;\n"
"	background-color:#2e2d2d;	\n"
"	color:#fff;\n"
"	padding-left:10px;\n"
"	padding-right:10px;\n"
"	padding-top:10px;\n"
"	padding-bottom:10px;\n"
"}\n"
"\n"
"QListWidget::item:hover \n"
"{\n"
"	background-color: #403f3f;\n"
"}\n"
"\n"
"QListWidget::item:selected\n"
" {\n"
"	border:0px;\n"
"	background-color: #5c5c5c;\n"
"}\n"
""));

        gridLayout->addWidget(listNames, 4, 0, 21, 2);

        txtTitle = new QLabel(centralwidget);
        txtTitle->setObjectName("txtTitle");
        txtTitle->setFont(font2);
        txtTitle->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color:#fff;\n"
"}"));

        gridLayout->addWidget(txtTitle, 5, 2, 1, 1);

        txtText = new QLabel(centralwidget);
        txtText->setObjectName("txtText");
        txtText->setFont(font2);
        txtText->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color:#fff;\n"
"}"));

        gridLayout->addWidget(txtText, 9, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font4;
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color:#fff;\n"
"}"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        planText = new QPlainTextEdit(centralwidget);
        planText->setObjectName("planText");
        planText->setEnabled(true);
        planText->setFont(font2);
        planText->setStyleSheet(QString::fromUtf8("QPlainTextEdit\n"
"{\n"
"	padding-top:10px;\n"
"	padding-left:10px;\n"
"	padding-right:10px;\n"
"	border-radius:10px;\n"
"	background-color:#2e2d2d;	\n"
"	color:#fff;\n"
"}"));

        gridLayout->addWidget(planText, 10, 2, 15, 1);

        lineID = new QLineEdit(centralwidget);
        lineID->setObjectName("lineID");
        lineID->setEnabled(false);
        lineID->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	border-radius:10px;\n"
"	background-color:#2e2d2d;	\n"
"	color:#fff;\n"
"	padding-left:10px;\n"
"	padding-right:10px;\n"
"}"));

        gridLayout->addWidget(lineID, 4, 2, 1, 1);

        txtNames = new QLabel(centralwidget);
        txtNames->setObjectName("txtNames");
        txtNames->setFont(font2);
        txtNames->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color:#fff;\n"
"}"));

        gridLayout->addWidget(txtNames, 3, 0, 1, 1);

        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");
        btnSave->setFont(font1);
        btnSave->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color:#fff;\n"
"	background-color: #4caf50;	\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color: #66bb6a ;\n"
"}"));

        gridLayout->addWidget(btnSave, 23, 3, 1, 1);

        btnInsert = new QPushButton(centralwidget);
        btnInsert->setObjectName("btnInsert");
        btnInsert->setEnabled(true);
        btnInsert->setFont(font1);
        btnInsert->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color:#fff;\n"
"	background-color: #4caf50;	\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton:hover \n"
"{\n"
"	background-color: #66bb6a ;\n"
"}"));

        gridLayout->addWidget(btnInsert, 10, 3, 1, 1);

        lineSearch = new QLineEdit(centralwidget);
        lineSearch->setObjectName("lineSearch");
        lineSearch->setEnabled(true);
        lineSearch->setStyleSheet(QString::fromUtf8("QLineEdit \n"
"{\n"
"    border-radius: 10px;\n"
"    background-color: #2e2d2d;\n"
"    color: #fff;\n"
"    background-repeat: no-repeat;\n"
"    background-position: 10px center;\n"
"	padding-left: 10px;\n"
"}"));
        lineSearch->setFrame(true);

        gridLayout->addWidget(lineSearch, 2, 0, 1, 1);

        lineTitle = new QLineEdit(centralwidget);
        lineTitle->setObjectName("lineTitle");
        lineTitle->setEnabled(true);
        lineTitle->setAcceptDrops(true);
        lineTitle->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	border-radius:10px;\n"
"	background-color:#2e2d2d;	\n"
"	color:#fff;\n"
"	padding-left:10px;\n"
"	padding-right:10px;\n"
"}"));

        gridLayout->addWidget(lineTitle, 6, 2, 3, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 707, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setStyleSheet(QString::fromUtf8("QStatusBar\n"
"{\n"
"	color:#fff;\n"
"}"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnCancel->setText(QCoreApplication::translate("MainWindow", "CANCEL", nullptr));
        btnUpdate->setText(QCoreApplication::translate("MainWindow", "UPDATE", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "CLEAR", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "DELETE", nullptr));
        txtID->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        txtTitle->setText(QCoreApplication::translate("MainWindow", "TITLE:", nullptr));
        txtText->setText(QCoreApplication::translate("MainWindow", "CONTENTS:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "SEARCH:", nullptr));
        txtNames->setText(QCoreApplication::translate("MainWindow", "NAMES:", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "SAVE", nullptr));
        btnInsert->setText(QCoreApplication::translate("MainWindow", "INSERT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
