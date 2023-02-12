#include "controlform.h"
#include "ui_controlform.h"

ControlForm::ControlForm(QWidget *parent) : QWidget(parent), ui(new Ui::ControlForm)
{
    ui->setupUi(this);
}

ControlForm::~ControlForm()
{
    delete ui;
}

void ControlForm::on_logoutButton_clicked()
{
    this->close();
}

void ControlForm::setUsername(QString name)
{
    ui->usernameLabel->setText(name);
}
