#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ToolListHandler.h"

void MainWindow::test(){ qDebug() << 1; }

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentScene(new QGraphicsScene(QRect(0,0,800,600), this))
{
    QString sname = "Scene # 0";
    sceneMap.insert(sname, currentScene);

    ui->setupUi(this);
    ui->sceneList->addItem(sname);
    ui->graphicsView->setScene(currentScene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setSceneRect(QRect(0,0,300,600));

    ui->toolList->addItems({"Спрайт",
                            "Текст",
                            "Фон"});

    ui->propertyLayout->addLayout(&propertyList);

    QObject::connect(currentScene, &QGraphicsScene::selectionChanged,
                     &propertyList, [&](){ propertyList.update(currentScene->selectedItems()); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolList_itemDoubleClicked(QListWidgetItem *item)
{
    ToolListHandler::createHandler(item->text())->handle(*ui->graphicsView->scene());
}


void MainWindow::on_addSceneBtn_clicked()
{
    static int sceneCount = 1;
    QString sname =  QString("Scene # %1").arg(sceneCount++);
    ui->sceneList->addItem(sname);
    sceneMap.insert(sname, new QGraphicsScene(this));
}


void MainWindow::on_sceneList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    currentScene = sceneMap[current->text()];
    ui->graphicsView->setScene(currentScene);
}

