#include "PropertyList.h"
#include <QPushButton>
#include <QLineEdit>

PropertyList::PropertyList()
    : allProperties(3, true), textProperties(3, true), pixmapProperties(3, true)
{
    list = {
        new PropertyListItem(new QLabel("Текст:"),  new QLineEdit()),
        new PropertyListItem(new QLabel("Путь:"),   new QLineEdit()),
        new PropertyListItem(new QLabel("Скрыть:"), new QPushButton())
    };

    addLayout(list[0]);
    addLayout(list[1]);
    addLayout(list[2]);

    textProperties[1] = false;
    pixmapProperties[0] = false;
}



void PropertyList::update(const QList<QGraphicsItem*>& selectedItems)
{
    if (selectedItems.isEmpty())
        return;

    QBitArray generalProperties(allProperties);
    foreach (QGraphicsItem* item, selectedItems) {
        if (qgraphicsitem_cast<QGraphicsPixmapItem*>(item))
            generalProperties &= pixmapProperties;
        else if (qgraphicsitem_cast<QGraphicsTextItem*>(item))
            generalProperties &= textProperties;
    }

    for (int i = 0; i < generalProperties.size(); ++i) {
        list[i]->setChildrensEnabled(generalProperties.at(i));
    }

    selected = selectedItems;
}

void PropertyList::test()
{
    foreach (QGraphicsItem* item, selected) {
        item->setVisible(false);
    }
}
