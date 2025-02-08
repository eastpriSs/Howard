#include "PropertyListItem.h"

PropertyListItem::PropertyListItem(QLabel* name, QWidget* value)
    : nameL(name), valueWidget(value)
{
    addWidget(name);
    addWidget(value);
}

void PropertyListItem::setChildrensEnabled(bool f)
{
    nameL->setEnabled(f);
    valueWidget->setEnabled(f);
}
