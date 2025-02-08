#ifndef TEXTENTERDIALOG_H
#define TEXTENTERDIALOG_H

#include <QDialog>

namespace Ui {
class TextEnterDialog;
}

class TextEnterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TextEnterDialog(QWidget *parent = nullptr);
    ~TextEnterDialog();
    QString getText() const;

private:
    Ui::TextEnterDialog *ui;
};

#endif // TEXTENTERDIALOG_H
