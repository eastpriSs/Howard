#include "TextEnterDialog.h"
#include "ui_TextEnterDialog.h"

TextEnterDialog::TextEnterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TextEnterDialog)
{
    ui->setupUi(this);
}

TextEnterDialog::~TextEnterDialog()
{
    delete ui;
}

QString TextEnterDialog::getText() const
{
    return ui->textEdit->toPlainText();
}
