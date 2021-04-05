#ifndef TOGGLESWITCH_H
#define TOGGLESWITCH_H

#include <QCheckBox>

class CToggleSwitch : public QCheckBox
{
    Q_OBJECT
public:
    using Super = QCheckBox;
    CToggleSwitch(QWidget* parent = nullptr);

    void setOnText(const QString& OnText);
    void setOffText(const QString& OffText);
    QSize sizeHint() const override;

private:
    QString m_OnText = "On";
    QString m_OffText = "Off";
    mutable QSize m_SizeHint;
    void updateText();
};

#endif // TOGGLESWITCH_H
