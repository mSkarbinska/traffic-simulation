#include "settingswidget.h"

SettingsWidget::SettingsWidget(QWidget *parent)
    : QWidget{parent}
{
    layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Settings"));

    QPushButton *button = new QPushButton("Button", this);
    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    layout->addWidget(button);

    layout->setAlignment(Qt::AlignLeft);
}
