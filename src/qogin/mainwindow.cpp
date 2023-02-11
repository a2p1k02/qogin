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
    std::string email = static_cast<std::string>(ui->emailEdit->text().toStdString());
    psql->create_user(user, password, email);
    window = new AccessWindow("Your login is correct");
    window->show();
}

void MainWindow::on_pushButton_clicked()
{
    loginCheck();
}

void MainWindow::on_passwordEdit_returnPressed()
{
    loginCheck();
}

void MainWindow::on_loginEdit_returnPressed()
{
    ui->emailEdit->selectedText();
}

void MainWindow::on_emailEdit_returnPressed()
{
    ui->passwordEdit->selectedText();
}
