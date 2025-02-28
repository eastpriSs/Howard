#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ToolListHandler.h"

void MainWindow::test(){ qDebug() << 1; }

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
                            "Текст",
                            "Фон"});

    ui->propertyLayout->addLayout(&propertyList);

    QObject::connect(&scene, &QGraphicsScene::selectionChanged,
                     &propertyList, [&](){ propertyList.update(scene.selectedItems()); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolList_itemDoubleClicked(QListWidgetItem *item)
{
    ToolListHandler::createHandler(item->text())->handle(scene);
}

