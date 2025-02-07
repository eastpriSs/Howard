#ifndef TOOLLISTHANDLER_H
#define TOOLLISTHANDLER_H

#include <QString>
#include <QHash>
#include <QGraphicsScene>

class ToolHandler {
public:
    virtual void handle(QGraphicsScene&) = 0;
    virtual ~ToolHandler() = default;
};

class SpriteHandler : public ToolHandler {
public:
    void handle(QGraphicsScene&) override;
};

class TextHandler : public ToolHandler {
public:
   void handle(QGraphicsScene&) override;
};

class ToolListHandler
{
public:
    static const QHash<QString, std::function<ToolHandler*()>> handlers;
    static std::unique_ptr<ToolHandler> createHandler(const QString& toolName);
};

#endif // TOOLLISTHANDLER_H
