#include "ToggleSwitch.h"

#include <QDebug>
#include <QStyleOption>
#include <QApplication>

CToggleSwitch::CToggleSwitch(QWidget* parent)
    : Super(parent)
{
    qDebug() << "CToggleSwitch()";
    connect(this, &CToggleSwitch::toggled, [this](bool Checked){
        Q_UNUSED(Checked);
        updateText();
    });

    updateText();
    setText("Uwe");
}

void CToggleSwitch::setOnText(const QString& OnText)
{
    m_OnText = OnText;
    updateText();
}


void CToggleSwitch::setOffText(const QString& OffText)
{
    m_OffText = OffText;
    updateText();
}

void CToggleSwitch::updateText()
{
    qDebug() << "updateText";
    setText(isChecked() ? m_OnText : m_OffText);
    m_SizeHint = QSize();
    updateGeometry();
}

QSize CToggleSwitch::sizeHint() const
{
    if (m_SizeHint.isValid())
        return m_SizeHint;
    ensurePolished();
    QFontMetrics fm = fontMetrics();
    QStyleOptionButton opt;
    initStyleOption(&opt);
    const auto& Text = (m_OnText.size() > m_OffText.size()) ? m_OnText : m_OffText;
    QSize sz = style()->itemTextRect(fm, QRect(), Qt::TextShowMnemonic, false,
                                     Text).size();
    if (!opt.icon.isNull())
        sz = QSize(sz.width() + opt.iconSize.width() + 4, qMax(sz.height(), opt.iconSize.height()));
    m_SizeHint = (style()->sizeFromContents(QStyle::CT_CheckBox, &opt, sz, this)
                     .expandedTo(QApplication::globalStrut()));
    return m_SizeHint;
}

