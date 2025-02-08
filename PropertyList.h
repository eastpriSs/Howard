#ifndef PROPERTYLIST_H
#define PROPERTYLIST_H

#include <QVBoxLayout>
#include <QGraphicsItem>
#include <QBitArray>

#include "PropertyListItem.h"

class PropertyList : public QVBoxLayout
{
public:
    PropertyList();
public slots:
    void update(const QList<QGraphicsItem*>&);
    void test();
private:
    QList<PropertyListItem*> list;
    QList<QGraphicsItem*> selected;

    QBitArray allProperties;
    QBitArray textProperties;
    QBitArray pixmapProperties;
};

#endif // PROPERTYLIST_H
