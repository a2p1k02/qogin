#include "accesswindow.h"
#include "ui_accesswindow.h"

AccessWindow::AccessWindow(QString message, QWidget *parent) : QWidget(parent), ui(new Ui::AccessWindow)
{
    ui->setupUi(this);
    ui->label->setText(message);
}

AccessWindow::~AccessWindow()
{
    delete ui;
}

void AccessWindow::on_okButton_clicked()
{
    delete this;
}

