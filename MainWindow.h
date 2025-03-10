#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QListWidgetItem>
#include <QHash>


#include "PropertyList.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void test();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolList_itemDoubleClicked(QListWidgetItem *item);

    void on_addSceneBtn_clicked();

    void on_sceneList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::MainWindow *ui;
    PropertyList propertyList;
    QHash<QString, QGraphicsScene*> sceneMap;
    QGraphicsScene* currentScene;
};
#endif // MAINWINDOW_H
