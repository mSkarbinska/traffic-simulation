#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

class SettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWidget(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;

signals:
};

#endif // SETTINGSWIDGET_H
