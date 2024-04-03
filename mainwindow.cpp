#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qroadsmap.h"

#include <QLabel>
#include <QPushButton>
#include <QSplitter>
#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(Simulation* sim, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setSimulation(sim);
    RoadsMap& map = simulation->getMap();
    QRoadsMap *mapView = new QRoadsMap(map, this);

    // move to settingswidget
    QWidget *settingsWidget = new QWidget(this);
    settingsWidget->setFixedWidth(250);
    QVBoxLayout *settingsLayout = new QVBoxLayout(settingsWidget);
    settingsLayout->addWidget(new QLabel("Settings"));

    QPushButton *button = new QPushButton("Button", settingsWidget);
    button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    settingsLayout->addWidget(button);

    settingsLayout->setAlignment(Qt::AlignLeft);

    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(mapView);
    splitter->addWidget(settingsWidget);
    // end

    mapView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    settingsWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    setCentralWidget(splitter);
}

MainWindow::~MainWindow()
{
    delete ui;
}
