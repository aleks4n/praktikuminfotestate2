#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
class City;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    City* addCity();
    ~Dialog();

private:
    Ui::Dialog *ui;
    QString nameofCity;
    int x;
    int y;
};

#endif // DIALOG_H
