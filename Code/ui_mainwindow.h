/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_map;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QPushButton *pushButton_A;
    QPushButton *pushButton;
    QPushButton *pushButton_mc;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(925, 626);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(660, 140, 211, 321));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        comboBox_2 = new QComboBox(horizontalLayoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout_3->addWidget(comboBox_2);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_3->addWidget(comboBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox_2 = new QCheckBox(horizontalLayoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setTristate(false);

        horizontalLayout_2->addWidget(checkBox_2);

        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setStyleSheet(QStringLiteral("border: blue"));

        horizontalLayout_2->addWidget(checkBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        pushButton_map = new QPushButton(horizontalLayoutWidget);
        pushButton_map->setObjectName(QStringLiteral("pushButton_map"));

        verticalLayout_3->addWidget(pushButton_map);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout->addLayout(verticalLayout_3);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        pushButton_A = new QPushButton(horizontalLayoutWidget);
        pushButton_A->setObjectName(QStringLiteral("pushButton_A"));

        verticalLayout->addWidget(pushButton_A);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_mc = new QPushButton(horizontalLayoutWidget);
        pushButton_mc->setObjectName(QStringLiteral("pushButton_mc"));

        verticalLayout->addWidget(pushButton_mc);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 0, 591, 521));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\351\232\234\347\242\215\347\211\251\345\257\206\345\272\246", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "10%", Q_NULLPTR)
         << QApplication::translate("MainWindow", "20%", Q_NULLPTR)
         << QApplication::translate("MainWindow", "30%", Q_NULLPTR)
         << QApplication::translate("MainWindow", "40%", Q_NULLPTR)
         << QApplication::translate("MainWindow", "50%", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("MainWindow", "\345\234\260\345\233\276\345\244\247\345\260\217", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "4*4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8*8", Q_NULLPTR)
         << QApplication::translate("MainWindow", "16*16", Q_NULLPTR)
         << QApplication::translate("MainWindow", "32*32", Q_NULLPTR)
        );
        checkBox_2->setText(QApplication::translate("MainWindow", "\344\270\215\346\230\276\347\244\272\346\255\245\346\225\260", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MainWindow", "\345\217\252\346\230\276\347\244\272\350\267\257\345\276\204", Q_NULLPTR));
        pushButton_map->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\346\226\260\345\234\260\345\233\276", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242\347\256\227\346\263\225", Q_NULLPTR));
        pushButton_A->setText(QApplication::translate("MainWindow", "\344\270\200\350\207\264\344\273\243\344\273\267", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\350\264\252\345\251\252", Q_NULLPTR));
        pushButton_mc->setText(QApplication::translate("MainWindow", "A*", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\212\250\347\224\273\346\274\224\347\244\272", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
