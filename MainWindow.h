#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QListWidgetItem>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    PropertyList propertyList;
};
#endif // MAINWINDOW_H
