/********************************************************************************
** Form generated from reading UI file 'openglgame.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLGAME_H
#define UI_OPENGLGAME_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_OpenGLGame
{
public:
    QHBoxLayout *horizontalLayout;
    GLWidget *widget;

    void setupUi(QWidget *OpenGLGame)
    {
        if (OpenGLGame->objectName().isEmpty())
            OpenGLGame->setObjectName(QString::fromUtf8("OpenGLGame"));
        OpenGLGame->resize(790, 533);
        horizontalLayout = new QHBoxLayout(OpenGLGame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget = new GLWidget(OpenGLGame);
        widget->setObjectName(QString::fromUtf8("widget"));

        horizontalLayout->addWidget(widget);


        retranslateUi(OpenGLGame);

        QMetaObject::connectSlotsByName(OpenGLGame);
    } // setupUi

    void retranslateUi(QWidget *OpenGLGame)
    {
        OpenGLGame->setWindowTitle(QApplication::translate("OpenGLGame", "Reversi(OpenGL)", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenGLGame: public Ui_OpenGLGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLGAME_H
