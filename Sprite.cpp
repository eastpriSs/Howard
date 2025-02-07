#include <QLabel>
#include <QGraphicsSceneMouseEvent>

#include "Sprite.h"

Sprite::Sprite(QString fileName)
    : QGraphicsPixmapItem(QPixmap(fileName))
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Sprite::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mousePressEvent(event);
}
