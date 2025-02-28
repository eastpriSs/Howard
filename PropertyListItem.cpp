#include "PropertyListItem.h"

PropertyListItem::PropertyListItem(QLabel* name, QWidget* value)
    : nameL(name), valueWidget(value)
{
    addWidget(name);
    addWidget(value);
}

void PropertyListItem::hide(bool f)
{
    if (!f){
        nameL->hide();
        valueWidget->hide();
    } else {
        nameL->show();
        valueWidget->show();
    }
}
