/********************************************************************************
** Form generated from reading UI file 'gewinner.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEWINNER_H
#define UI_GEWINNER_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_gewinner
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_2;
    QLabel *siegerName;
    QLabel *label;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *gewinner)
    {
        if (gewinner->objectName().isEmpty())
            gewinner->setObjectName(QString::fromUtf8("gewinner"));
        gewinner->resize(565, 401);
        gridLayout = new QGridLayout(gewinner);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_2 = new QLabel(gewinner);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        siegerName = new QLabel(gewinner);
        siegerName->setObjectName(QString::fromUtf8("siegerName"));

        verticalLayout->addWidget(siegerName);


        verticalLayout_2->addLayout(verticalLayout);

        label = new QLabel(gewinner);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(gewinner);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(gewinner);

        QMetaObject::connectSlotsByName(gewinner);
    } // setupUi

    void retranslateUi(QWidget *gewinner)
    {
        gewinner->setWindowTitle(QApplication::translate("gewinner", "Form", 0));
        label_2->setText(QApplication::translate("gewinner", "Spieler:", 0));
        siegerName->setText(QString());
        label->setText(QApplication::translate("gewinner", "hat das Spiel gewonnen!", 0));
        pushButton_2->setText(QApplication::translate("gewinner", "Spiel beenden", 0));
    } // retranslateUi

};

namespace Ui {
    class gewinner: public Ui_gewinner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEWINNER_H
