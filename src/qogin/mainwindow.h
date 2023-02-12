#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "accesswindow.h"
#include "controlform.h"
#include "postgresql.h"

QT_BEGIN_NAMESPACE
    namespace Ui {
        class MainWindow;
    }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_passwordEdit_returnPressed();

    void on_loginButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::MainWindow* ui;
    AccessWindow* window;
    ControlForm* control;
    PostgreSQL* psql;

    void loginCheck();
    void registration();
};
#endif // MAINWINDOW_H
