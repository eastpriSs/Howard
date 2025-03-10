#include "PropertyList.h"
#include <QDoubleValidator>

PropertyList::PropertyList()
    : propertyMapping({
       text,
       rotation,
    })
{
    initPropertiesInputForms();

    list = {
        new PropertyListItem(new QLabel("Текст:"),  textInputForm),
        new PropertyListItem(new QLabel("Угол поворота:"), rotationInputForm)
    };

    foreach (PropertyListItem* i, list)
        addLayout(i);
}

PropertyList::Properties getProperties(QGraphicsItem* item)
{
    PropertyList::Properties res;

    if (qgraphicsitem_cast<QGraphicsPixmapItem*>(item)) {
        res |= PropertyList::Property::rotation;
    } else if (qgraphicsitem_cast<QGraphicsTextItem*>(item)) {
        res |= PropertyList::Property::text
            | PropertyList::Property::rotation;
    }

    return res;
}

void PropertyList::update(const QList<QGraphicsItem*>& selectedItems)
{
    selected = selectedItems;

    if (selectedItems.isEmpty())
        return;

    Properties generalProp = allProps;
    foreach (QGraphicsItem* item, selectedItems) {
        generalProp &= getProperties(item);
        if (generalProp == 0) break;
    }
    for (int i = 0; i < propertyMapping.size(); ++i)
        list[i]->hide(generalProp & propertyMapping[i]);
}

void PropertyList::setTextSelectedFromInputForm()
{
    foreach (QGraphicsItem* item, selected)
        qgraphicsitem_cast<QGraphicsTextItem*>(item)->setPlainText(textInputForm->text());
}

void PropertyList::setRotationSelectedFromInputForm()
{
    foreach (QGraphicsItem* item, selected)
        item->setRotation(rotationInputForm->text().toDouble());
}


void PropertyList::initPropertiesInputForms()
{
    textInputForm = new QLineEdit();

    rotationInputForm = new QLineEdit();
    rotationInputForm->setValidator(new QDoubleValidator(0.0, 5.0, 2));

    QObject::connect(textInputForm, &QLineEdit::textChanged, this, &PropertyList::setTextSelectedFromInputForm);
    QObject::connect(rotationInputForm, &QLineEdit::textChanged, this, &PropertyList::setRotationSelectedFromInputForm);
}
