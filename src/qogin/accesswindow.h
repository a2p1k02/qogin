#ifndef ACCESSWINDOW_H
#define ACCESSWINDOW_H

#include <QWidget>

namespace Ui {
    class AccessWindow;
}

class AccessWindow : public QWidget {
    Q_OBJECT

public:
    explicit AccessWindow(QString message = "", QWidget *parent = nullptr);
    ~AccessWindow();

private slots:
    void on_okButton_clicked();

private:
    Ui::AccessWindow *ui;
};

#endif // ACCESSWINDOW_H
