#include <QFileDialog>
#include <QDebug>
#include <QTextEdit>

#include "TextEnterDialog.h"
#include "ToolListHandler.h"
#include "Sprite.h"


// Handlers
// --------
void SpriteHandler::handle(QGraphicsScene& scene)
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Image", "C:/", "Image Files (*.png *.jpg *.bmp)");
    scene.addItem(new Sprite(fileName));
}

void TextHandler::handle(QGraphicsScene& scene)
{
    TextEnterDialog dialog;
    if (dialog.exec() == QDialog::DialogCode::Accepted) {
        QGraphicsTextItem* text = scene.addText(dialog.getText());
        text->setFlag(QGraphicsItem::ItemIsMovable, true);
        text->setFlag(QGraphicsItem::ItemIsSelectable, true);
    }
}

void BackGroundHandler::handle(QGraphicsScene& scene)
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Image", "C:/", "Image Files (*.png *.jpg *.bmp)");
    scene.addItem(new QGraphicsPixmapItem(fileName));
}


// Tool List Handler
// ------------------
const QHash<QString, std::function<ToolHandler*()>> ToolListHandler::handlers {
    {"Спрайт", [](){ return new SpriteHandler; }},
    {"Текст",  [](){ return new TextHandler; }},
    {"Фон",    [](){ return new BackGroundHandler; }}
};

std::unique_ptr<ToolHandler> ToolListHandler::createHandler(const QString& toolName)
{
    assert(handlers.contains(toolName));

    if (handlers.contains(toolName)) {
        return std::unique_ptr<ToolHandler>(handlers[toolName]());
    }
    return nullptr;
}
