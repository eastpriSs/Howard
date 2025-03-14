#ifndef PROPERTYLISTITEM_H
#define PROPERTYLISTITEM_H

#include <QHBoxLayout>
#include <QLabel>

class PropertyListItem : public QHBoxLayout
{
public:
    PropertyListItem(QLabel*, QWidget*);
    void hide(bool);
private:
    QLabel* nameL;
    QWidget* valueWidget;
};

#endif // PROPERTYLISTITEM_H
