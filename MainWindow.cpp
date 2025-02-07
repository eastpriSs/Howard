#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ToolListHandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(QRect(0,0,800,600), this)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setSceneRect(QRect(0,0,300,600));

    ui->toolList->addItems({"Спрайт",
                            "Текст"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolList_itemDoubleClicked(QListWidgetItem *item)
{
    ToolListHandler::createHandler(item->text())->handle(scene);
}

