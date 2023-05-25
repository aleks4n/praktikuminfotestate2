#ifndef DIALOGADDSTREET_H
#define DIALOGADDSTREET_H

#include <QDialog>

namespace Ui {
class dialogAddStreet;
}

class dialogAddStreet : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAddStreet(QWidget *parent = nullptr);
    ~dialogAddStreet();
    QString getname1();
    QString getname2();

private:
    Ui::dialogAddStreet *ui;
    QString name1;
    QString name2;
};

#endif // DIALOGADDSTREET_H
