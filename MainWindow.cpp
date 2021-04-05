#include "MainWindow.h"
#include "ui_MainWindow.h"



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
static void fixupPopupDelegate(QComboBox* ComboBox, const QSize& IconSize = QSize())
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
static QString readStyleSheet(const QString& FileName)
{
    QString Result;
    QFile StyleSheetFile(FileName);
    StyleSheetFile.open(QIODevice::ReadOnly);
    QTextStream StyleSheetStream(&StyleSheetFile);
    Result = StyleSheetStream.readAll();
    StyleSheetFile.close();
    return Result;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    m_StyleSheetFile = defstring(CSS_FILE);
    ui->setupUi(this);
    QPalette Palette(QColor(230, 230, 230));
    Palette.setColor(QPalette::Active, QPalette::Button, QColor(0, 0, 0, 50));
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

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::reloadStyleSheet()
{
    auto StyleSheet = readStyleSheet(m_StyleSheetFile);
    setStyleSheet(StyleSheet);
}
