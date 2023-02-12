#ifndef CONTROLFORM_H
#define CONTROLFORM_H

#include <QWidget>

namespace Ui {
    class ControlForm;
}

class ControlForm : public QWidget {
    Q_OBJECT

public:
    explicit ControlForm(QWidget *parent = nullptr);
    ~ControlForm();

    void setUsername(QString name);

private slots:
    void on_logoutButton_clicked();

private:
    Ui::ControlForm *ui;
};

#endif // CONTROLFORM_H
