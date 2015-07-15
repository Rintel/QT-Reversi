/********************************************************************************
** Form generated from reading UI file 'hauptmenue.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAUPTMENUE_H
#define UI_HAUPTMENUE_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QFormLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QSpacerItem>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_Hauptmenue
{
public:
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *newGameButton;
    QPushButton *loadButton;
    QPushButton *creditsButton;
    QPushButton *endButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *Hauptmenue)
    {
        if (Hauptmenue->objectName().isEmpty())
            Hauptmenue->setObjectName(QString::fromUtf8("Hauptmenue"));
        Hauptmenue->resize(521, 380);
        formLayout = new QFormLayout(Hauptmenue);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        verticalSpacer_4 = new QSpacerItem(494, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer_4);

        horizontalSpacer_14 = new QSpacerItem(494, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(1, QFormLayout::FieldRole, horizontalSpacer_14);

        newGameButton = new QPushButton(Hauptmenue);
        newGameButton->setObjectName(QString::fromUtf8("newGameButton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, newGameButton);

        loadButton = new QPushButton(Hauptmenue);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));

        formLayout->setWidget(4, QFormLayout::FieldRole, loadButton);

        creditsButton = new QPushButton(Hauptmenue);
        creditsButton->setObjectName(QString::fromUtf8("creditsButton"));

        formLayout->setWidget(6, QFormLayout::FieldRole, creditsButton);

        endButton = new QPushButton(Hauptmenue);
        endButton->setObjectName(QString::fromUtf8("endButton"));

        formLayout->setWidget(8, QFormLayout::FieldRole, endButton);

        horizontalSpacer_8 = new QSpacerItem(494, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(9, QFormLayout::FieldRole, horizontalSpacer_8);

        verticalSpacer_5 = new QSpacerItem(494, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(10, QFormLayout::FieldRole, verticalSpacer_5);


        retranslateUi(Hauptmenue);

        QMetaObject::connectSlotsByName(Hauptmenue);
    } // setupUi

    void retranslateUi(QWidget *Hauptmenue)
    {
        Hauptmenue->setWindowTitle(QApplication::translate("Hauptmenue", "Form", 0));
        newGameButton->setText(QApplication::translate("Hauptmenue", "Neues Spiel", 0));
        loadButton->setText(QApplication::translate("Hauptmenue", "Spiel Laden", 0));
        creditsButton->setText(QApplication::translate("Hauptmenue", "Credits", 0));
        endButton->setText(QApplication::translate("Hauptmenue", "Beenden", 0));
    } // retranslateUi

};

namespace Ui {
    class Hauptmenue: public Ui_Hauptmenue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAUPTMENUE_H
