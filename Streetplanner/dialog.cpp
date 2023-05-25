#include "dialog.h"
#include "ui_dialog.h"
#include "City.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


/*!
 *  City returner from the dialog
 *  @returns a pointer to the city
 */

City* Dialog::addCity()
{
    nameofCity = ui->namecity->text();
    qDebug() << nameofCity;
    bool ok;


    x = ui->xcordinate->text().toInt(&ok);

    if (ok == false)
    {

        qDebug() << "Bitte geben Sie eine ganze Zahl ein!";
        setResult(2);


    }
    else
    {
        qDebug() << y;
    }

    y = ui->ycordinate->text().toInt(&ok);

    if (ok == false)
    {
        qDebug() << "Bitte geben Sie eine ganze Zahl ein!";
        setResult(2);

        // QMessageBox::about(this,"Fehler!","Bitte geben Sie nur ganze Zahlen ein! ");

    }
    else
    {
        qDebug() << y;
    }

    return  new City(nameofCity, x, y);
}

