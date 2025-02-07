#ifndef SPRITE_H
#define SPRITE_H

#include <QGraphicsPixmapItem>

class Sprite : public QGraphicsPixmapItem
{
public:
    explicit Sprite(QString fileName);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};
#endif // SPRITE_H
