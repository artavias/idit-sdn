/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_ip;
    QRadioButton *radioButton_serial;
    QLineEdit *ipAddress;
    QLabel *label;
    QSpinBox *portNumber;
    QSpacerItem *horizontalSpacer;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clsButton;
    QTextBrowser *terminalTextBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *statusLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(687, 450);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_ip = new QRadioButton(centralWidget);
        radioButton_ip->setObjectName(QString::fromUtf8("radioButton_ip"));
        radioButton_ip->setChecked(true);

        horizontalLayout->addWidget(radioButton_ip);

        radioButton_serial = new QRadioButton(centralWidget);
        radioButton_serial->setObjectName(QString::fromUtf8("radioButton_serial"));

        horizontalLayout->addWidget(radioButton_serial);

        ipAddress = new QLineEdit(centralWidget);
        ipAddress->setObjectName(QString::fromUtf8("ipAddress"));

        horizontalLayout->addWidget(ipAddress);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        portNumber = new QSpinBox(centralWidget);
        portNumber->setObjectName(QString::fromUtf8("portNumber"));
        portNumber->setMaximum(65000);
        portNumber->setValue(60001);

        horizontalLayout->addWidget(portNumber);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        horizontalLayout->addWidget(connectButton);

        disconnectButton = new QPushButton(centralWidget);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));
        disconnectButton->setEnabled(false);

        horizontalLayout->addWidget(disconnectButton);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        clsButton = new QPushButton(groupBox);
        clsButton->setObjectName(QString::fromUtf8("clsButton"));

        horizontalLayout_2->addWidget(clsButton);


        verticalLayout->addWidget(groupBox);

        terminalTextBox = new QTextBrowser(centralWidget);
        terminalTextBox->setObjectName(QString::fromUtf8("terminalTextBox"));
        terminalTextBox->setReadOnly(true);

        verticalLayout->addWidget(terminalTextBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        horizontalLayout_3->addWidget(statusLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 687, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Controller", nullptr));
        radioButton_ip->setText(QApplication::translate("MainWindow", "IP", nullptr));
        radioButton_serial->setText(QApplication::translate("MainWindow", "Serial", nullptr));
        ipAddress->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        label->setText(QApplication::translate("MainWindow", "IP PORT", nullptr));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        disconnectButton->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Commands", nullptr));
        clsButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        statusLabel->setText(QApplication::translate("MainWindow", "Disconnected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
