#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    psql = new PostgreSQL("hospital");
//    psql->create_db();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginCheck()
{
    std::string user = static_cast<std::string>(ui->loginEdit->text().toStdString());
    std::string password = static_cast<std::string>(ui->passwordEdit->text().toStdString());
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
    std::string user = static_cast<std::string>(ui->loginEdit->text().toStdString());
    std::string password = static_cast<std::string>(ui->passwordEdit->text().toStdString());
    std::string email = static_cast<std::string>(ui->emailEdit->text().toStdString());
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

void MainWindow::on_loginEdit_returnPressed()
{
    ui->emailEdit->selectedText();
}

void MainWindow::on_emailEdit_returnPressed()
{
    ui->passwordEdit->selectedText();
}

void MainWindow::on_loginButton_clicked()
{
    loginCheck();
}

void MainWindow::on_registerButton_clicked()
{
    registration();
}
