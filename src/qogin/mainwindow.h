#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "accesswindow.h"
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
    void on_pushButton_clicked();

    void on_passwordEdit_returnPressed();

    void on_loginEdit_returnPressed();

    void on_emailEdit_returnPressed();

private:
    Ui::MainWindow* ui;
    AccessWindow* window;
    PostgreSQL* psql;

    void loginCheck();
};
#endif // MAINWINDOW_H
