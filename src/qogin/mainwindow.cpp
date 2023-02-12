#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    psql = new PostgreSQL("hospital");
    control = new ControlForm();
    connect(control, &ControlForm::destroyed, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginCheck()
{
    std::string user = ui->loginEdit->text().toStdString();
    std::string password = ui->passwordEdit->text().toStdString();
    QString message = "Your login is not correct";
    if (psql->check_user(user, password)) {
        ui->label_2->setText("Hello, " + ui->loginEdit->text());
        message = "Your login is correct";
    }
    window = new AccessWindow(message);
    window->show();
}

void MainWindow::registration()
{
    std::string user = ui->loginEdit->text().toStdString();
    std::string password = ui->passwordEdit->text().toStdString();
    std::string email = ui->emailEdit->text().toStdString();
    psql->create_user(user, password, email);
    window = new AccessWindow("Your account was created");
    window->show();
}

void MainWindow::on_passwordEdit_returnPressed()
{
    if (ui->emailEdit->text() == "")
        loginCheck();
    else
        registration();
}

void MainWindow::on_loginButton_clicked()
{
    loginCheck();
    control->setUsername(ui->loginEdit->text());
    control->show();
}

void MainWindow::on_registerButton_clicked()
{
    registration();
}
