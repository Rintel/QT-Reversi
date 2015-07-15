/********************************************************************************
** Form generated from reading UI file 'spielladen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPIELLADEN_H
#define UI_SPIELLADEN_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QSpacerItem>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpielLaden
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *loadButton;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *SpielLaden)
    {
        if (SpielLaden->objectName().isEmpty())
            SpielLaden->setObjectName(QString::fromUtf8("SpielLaden"));
        SpielLaden->resize(586, 435);
        gridLayout = new QGridLayout(SpielLaden);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(SpielLaden);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 2, 1, 1);

        listWidget = new QListWidget(SpielLaden);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 2, 1, 1, 3);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 2);

        backButton = new QPushButton(SpielLaden);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(220, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 1, 1, 2);

        loadButton = new QPushButton(SpielLaden);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));

        gridLayout->addWidget(loadButton, 4, 4, 2, 1);

        verticalSpacer_4 = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 5, 0, 2, 1);

        verticalSpacer_5 = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 5, 1, 2, 2);

        verticalSpacer_6 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 6, 4, 1, 1);


        retranslateUi(SpielLaden);

        QMetaObject::connectSlotsByName(SpielLaden);
    } // setupUi

    void retranslateUi(QWidget *SpielLaden)
    {
        SpielLaden->setWindowTitle(QApplication::translate("SpielLaden", "Form", 0));
        label->setText(QApplication::translate("SpielLaden", "Spiel Laden:", 0));
        backButton->setText(QApplication::translate("SpielLaden", "Zur\303\274ck", 0));
        loadButton->setText(QApplication::translate("SpielLaden", "Laden", 0));
    } // retranslateUi

};

namespace Ui {
    class SpielLaden: public Ui_SpielLaden {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPIELLADEN_H
