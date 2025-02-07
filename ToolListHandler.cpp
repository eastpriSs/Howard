#include <QFileDialog>
#include <QDebug>

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
    qDebug() << "text";
}



// Tool List Handler
// ------------------
const QHash<QString, std::function<ToolHandler*()>> ToolListHandler::handlers {
    {"Спрайт", [](){ return new SpriteHandler; }},
    {"Текст",  [](){ return new TextHandler; }}
};

std::unique_ptr<ToolHandler> ToolListHandler::createHandler(const QString& toolName)
{
    assert(handlers.contains(toolName));

    if (handlers.contains(toolName)) {
        return std::unique_ptr<ToolHandler>(handlers[toolName]());
    }
    return nullptr;
}
