#ifndef PROPERTYLIST_H
#define PROPERTYLIST_H

#include <QVBoxLayout>
#include <QGraphicsItem>
#include <QLineEdit>
#include <QPushButton>
#include <QLineEdit>

#include "PropertyListItem.h"

class PropertyList : public QVBoxLayout
{
public:
    enum Property {
        text            = 1 << 0,
        rotation        = 1 << 1,
        allProps        = (1 << 3) - 1
    };
    Q_DECLARE_FLAGS(Properties, Property)
    Q_FLAG(Properties)

public:
    PropertyList();

public slots:
    void update(const QList<QGraphicsItem*>&);
    void setTextSelectedFromInputForm();
    void setRotationSelectedFromInputForm();

private:
    void initPropertiesInputForms();

private:
    QList<PropertyListItem*> list;
    QList<QGraphicsItem*> selected;

    const QVector<Property> propertyMapping;

    QLineEdit*      textInputForm;
    QLineEdit*      rotationInputForm;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(PropertyList::Properties)

#endif // PROPERTYLIST_H
