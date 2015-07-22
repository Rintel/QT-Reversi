/********************************************************************************
** Form generated from reading UI file 'newgame.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAME_H
#define UI_NEWGAME_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGridLayout>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QSpacerItem>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_newGame
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *backButton;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *KIBtn;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *gelb;
    QRadioButton *blau;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_4;
    QTextEdit *nameSp1;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QTextEdit *nameSp2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_6;
    QPushButton *startButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_15;
    QGroupBox *groupBox_2;
    QRadioButton *blackButton;
    QRadioButton *whiteButton;

    void setupUi(QWidget *newGame)
    {
        if (newGame->objectName().isEmpty())
            newGame->setObjectName(QString::fromUtf8("newGame"));
        newGame->resize(710, 470);
        gridLayout = new QGridLayout(newGame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(104, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 13, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(43, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 11, 8, 1, 1);

        backButton = new QPushButton(newGame);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 11, 1, 1, 1);

        label_4 = new QLabel(newGame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 7, 1, 1, 2);

        label = new QLabel(newGame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        label_2 = new QLabel(newGame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 5, 1, 1, 1);

        label_3 = new QLabel(newGame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        KIBtn = new QRadioButton(newGame);
        KIBtn->setObjectName(QString::fromUtf8("KIBtn"));

        gridLayout->addWidget(KIBtn, 3, 3, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_17, 10, 6, 1, 1);

        verticalSpacer_5 = new QSpacerItem(221, 25, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 4, 6, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(164, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(24, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 5, 0, 1, 1);

        groupBox = new QGroupBox(newGame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gelb = new QRadioButton(groupBox);
        gelb->setObjectName(QString::fromUtf8("gelb"));
        gelb->setChecked(true);

        verticalLayout->addWidget(gelb);

        blau = new QRadioButton(groupBox);
        blau->setObjectName(QString::fromUtf8("blau"));

        verticalLayout->addWidget(blau);


        gridLayout->addWidget(groupBox, 8, 6, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_18, 10, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(43, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 5, 8, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(164, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 11, 3, 1, 1);

        nameSp1 = new QTextEdit(newGame);
        nameSp1->setObjectName(QString::fromUtf8("nameSp1"));
        nameSp1->setMaximumSize(QSize(100000, 50));

        gridLayout->addWidget(nameSp1, 1, 4, 1, 4);

        horizontalSpacer_14 = new QSpacerItem(221, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 7, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(243, 47, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(24, 47, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        nameSp2 = new QTextEdit(newGame);
        nameSp2->setObjectName(QString::fromUtf8("nameSp2"));
        nameSp2->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(nameSp2, 3, 4, 1, 4);

        verticalSpacer = new QSpacerItem(104, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(164, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 7, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(24, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 7, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(43, 47, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 1, 8, 1, 1);

        verticalSpacer_6 = new QSpacerItem(221, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 2, 6, 1, 1);

        startButton = new QPushButton(newGame);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        gridLayout->addWidget(startButton, 11, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(24, 47, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 3, 0, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(43, 47, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_16, 3, 8, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(24, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 11, 0, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(43, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 7, 8, 1, 1);

        groupBox_2 = new QGroupBox(newGame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 100));
        blackButton = new QRadioButton(groupBox_2);
        blackButton->setObjectName(QString::fromUtf8("blackButton"));
        blackButton->setGeometry(QRect(0, 30, 117, 22));
        blackButton->setChecked(true);
        whiteButton = new QRadioButton(groupBox_2);
        whiteButton->setObjectName(QString::fromUtf8("whiteButton"));
        whiteButton->setGeometry(QRect(0, 70, 221, 22));

        gridLayout->addWidget(groupBox_2, 5, 6, 1, 1);


        retranslateUi(newGame);

        QMetaObject::connectSlotsByName(newGame);
    } // setupUi

    void retranslateUi(QWidget *newGame)
    {
        newGame->setWindowTitle(QApplication::translate("newGame", "Form", 0));
        backButton->setText(QApplication::translate("newGame", "Zur\303\274ck", 0));
        label_4->setText(QApplication::translate("newGame", "(schwarzer Spieler beginnt)", 0));
        label->setText(QApplication::translate("newGame", "Name Spieler 1:", 0));
        label_2->setText(QApplication::translate("newGame", "Farbe Spieler 1:", 0));
        label_3->setText(QApplication::translate("newGame", "Name Spieler 2:", 0));
        KIBtn->setText(QApplication::translate("newGame", "Computer", 0));
        groupBox->setTitle(QApplication::translate("newGame", "Farbe des Spielfeldes", 0));
        gelb->setText(QApplication::translate("newGame", "Gelb", 0));
        blau->setText(QApplication::translate("newGame", "Blau", 0));
        nameSp1->setHtml(QApplication::translate("newGame", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Spieler 1</p></body></html>", 0));
        nameSp2->setHtml(QApplication::translate("newGame", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Spieler 2</p></body></html>", 0));
        startButton->setText(QApplication::translate("newGame", "Starten", 0));
        groupBox_2->setTitle(QApplication::translate("newGame", "GroupBox", 0));
        blackButton->setText(QApplication::translate("newGame", "Schwarz", 0));
        whiteButton->setText(QApplication::translate("newGame", "Wei\303\237", 0));
    } // retranslateUi

};

namespace Ui {
    class newGame: public Ui_newGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAME_H
