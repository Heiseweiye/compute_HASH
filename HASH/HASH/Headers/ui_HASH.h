/********************************************************************************
** Form generated from reading UI file 'HASH.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HASH_H
#define UI_HASH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HASHClass
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPlainTextEdit *input_plaintext;
    QPushButton *Butn_compute;
    QPlainTextEdit *input_plaintext_2;
    QPushButton *btn_computeSHA1;
    QPlainTextEdit *plainTextEdit_MD5;
    QPlainTextEdit *plainTextEdit_SHA1;
    QWidget *page_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Select_Button_plain;
    QPushButton *Select_Button_file;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HASHClass)
    {
        if (HASHClass->objectName().isEmpty())
            HASHClass->setObjectName(QStringLiteral("HASHClass"));
        HASHClass->resize(859, 558);
        HASHClass->setStyleSheet(QStringLiteral("border-top-color: rgb(170, 255, 255);"));
        centralWidget = new QWidget(HASHClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("\n"
"        #centralWidget{border-image: url(:/HASH/Resources/images/nanyou.jpg);}\n"
""));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(150, 0, 711, 501));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        input_plaintext = new QPlainTextEdit(page);
        input_plaintext->setObjectName(QStringLiteral("input_plaintext"));
        input_plaintext->setGeometry(QRect(20, 10, 551, 141));
        input_plaintext->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 200);\n"
"font: 9pt \"Consolas\";"));
        Butn_compute = new QPushButton(page);
        Butn_compute->setObjectName(QStringLiteral("Butn_compute"));
        Butn_compute->setGeometry(QRect(580, 10, 101, 211));
        Butn_compute->setStyleSheet(QLatin1String("font: 75 14pt \"Consolas\";\n"
"background-color: rgba(255, 255, 255, 200);"));
        input_plaintext_2 = new QPlainTextEdit(page);
        input_plaintext_2->setObjectName(QStringLiteral("input_plaintext_2"));
        input_plaintext_2->setGeometry(QRect(20, 260, 551, 141));
        input_plaintext_2->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 200);\n"
"font: 9pt \"Consolas\";"));
        btn_computeSHA1 = new QPushButton(page);
        btn_computeSHA1->setObjectName(QStringLiteral("btn_computeSHA1"));
        btn_computeSHA1->setGeometry(QRect(580, 260, 101, 211));
        btn_computeSHA1->setStyleSheet(QLatin1String("font: 75 14pt \"Consolas\";\n"
"background-color: rgba(255, 255, 255, 200);"));
        plainTextEdit_MD5 = new QPlainTextEdit(page);
        plainTextEdit_MD5->setObjectName(QStringLiteral("plainTextEdit_MD5"));
        plainTextEdit_MD5->setGeometry(QRect(20, 160, 551, 61));
        plainTextEdit_MD5->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 200);\n"
"font: 9pt \"Consolas\";"));
        plainTextEdit_SHA1 = new QPlainTextEdit(page);
        plainTextEdit_SHA1->setObjectName(QStringLiteral("plainTextEdit_SHA1"));
        plainTextEdit_SHA1->setGeometry(QRect(20, 410, 551, 61));
        plainTextEdit_SHA1->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 200);\n"
"font: 9pt \"Consolas\";"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 114, 478));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Select_Button_plain = new QPushButton(layoutWidget);
        Select_Button_plain->setObjectName(QStringLiteral("Select_Button_plain"));
        Select_Button_plain->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\346\245\267\344\275\223\";\n"
"background-color: rgba(255, 255, 255, 200);\n"
"font: 10pt \"Agency FB\";"));

        verticalLayout->addWidget(Select_Button_plain);

        Select_Button_file = new QPushButton(layoutWidget);
        Select_Button_file->setObjectName(QStringLiteral("Select_Button_file"));
        Select_Button_file->setStyleSheet(QString::fromUtf8("font: 75 9pt \"\346\245\267\344\275\223\";\n"
"background-color: rgba(255, 255, 255, 200);\n"
"font: 10pt \"Agency FB\";"));

        verticalLayout->addWidget(Select_Button_file);

        verticalSpacer = new QSpacerItem(109, 388, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        HASHClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HASHClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 859, 30));
        HASHClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HASHClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HASHClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HASHClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HASHClass->setStatusBar(statusBar);

        retranslateUi(HASHClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HASHClass);
    } // setupUi

    void retranslateUi(QMainWindow *HASHClass)
    {
        HASHClass->setWindowTitle(QApplication::translate("HASHClass", "HASH", 0));
        input_plaintext->setPlainText(QApplication::translate("HASHClass", "\350\257\267\350\276\223\345\205\245\346\230\216\346\226\207...", 0));
        Butn_compute->setText(QApplication::translate("HASHClass", "MD5", 0));
        input_plaintext_2->setPlainText(QApplication::translate("HASHClass", "\350\257\267\350\276\223\345\205\245\346\230\216\346\226\207...", 0));
        btn_computeSHA1->setText(QApplication::translate("HASHClass", "SHA1", 0));
        Select_Button_plain->setText(QApplication::translate("HASHClass", "\346\230\216\346\226\207\346\225\243\345\210\227", 0));
        Select_Button_file->setText(QApplication::translate("HASHClass", "\346\226\207\344\273\266\347\255\276\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class HASHClass: public Ui_HASHClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HASH_H
