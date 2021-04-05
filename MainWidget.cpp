#include "MainWidget.h"
#include "ui_MainWidget.h"

#include <iostream>

#include <QApplication>
#include <QPalette>
#include <QComboBox>
#include <QStyledItemDelegate>
#include <QAbstractItemView>
#include <QFile>
#include <QTextStream>

#define defstring(s) _defstring(s)
    #define _defstring(s) #s


//============================================================================
void fixupPopupDelegate(QComboBox* ComboBox, const QSize& IconSize = QSize())
{
    ComboBox->view()->setItemDelegate(new QStyledItemDelegate(ComboBox->view()));
    if (IconSize.isValid())
    {
        ComboBox->setIconSize(IconSize);
    }
}


/**
 * Reads the content of the given style sheet file
 */
QString readStyleSheet(const QString& FileName)
{
    QString Result;
    QFile StyleSheetFile(FileName);
    StyleSheetFile.open(QIODevice::ReadOnly);
    QTextStream StyleSheetStream(&StyleSheetFile);
    Result = StyleSheetStream.readAll();
    StyleSheetFile.close();
    return Result;
}

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    m_StyleSheetFile = defstring(CSS_FILE);
    ui->setupUi(this);
    QPalette Palette(QColor(255, 255, 255));
    Palette.setColor(QPalette::Active, QPalette::Button, QColor(204, 204, 204));
    Palette.setColor(QPalette::Active, QPalette::Shadow, QColor(Qt::black));
    /*Palette.setColor(QPalette::Active, QPalette::Highlight, QColor(247, 138, 9));
    Palette.setColor(QPalette::Inactive, QPalette::Highlight, Palette.color(QPalette::Active, QPalette::Highlight));
    Palette.setColor(QPalette::Normal, QPalette::Highlight, Palette.color(QPalette::Active, QPalette::Highlight));
    Palette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(81, 81, 81));
    Palette.setColor(QPalette::Disabled, QPalette::Background, QColor(51, 51, 51));// for coloring disabled icons
    Palette.setColor(QPalette::Active, QPalette::Mid, QColor(81, 81, 81));
    Palette.setColor(QPalette::Active, QPalette::Window, QColor(51, 51, 51));
    Palette.setColor(QPalette::Active, QPalette::Base, QColor(51, 51, 51));
    Palette.setColor(QPalette::Inactive, QPalette::Base, QColor(51, 51, 51));*/
    qApp->setPalette(Palette);
    fixupPopupDelegate(ui->comboBox);
    reloadStyleSheet();
}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::reloadStyleSheet()
{
    auto StyleSheet = readStyleSheet(m_StyleSheetFile);
    setStyleSheet(StyleSheet);
}

