#include "MainWidget.h"
#include "ui_MainWidget.h"

#include <QApplication>
#include <QPalette>
#include <QComboBox>
#include <QStyledItemDelegate>
#include <QAbstractItemView>


//============================================================================
void fixupPopupDelegate(QComboBox* ComboBox, const QSize& IconSize = QSize())
{
    ComboBox->view()->setItemDelegate(new QStyledItemDelegate(ComboBox->view()));
    if (IconSize.isValid())
    {
        ComboBox->setIconSize(IconSize);
    }
}

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
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
}

MainWidget::~MainWidget()
{
    delete ui;
}

