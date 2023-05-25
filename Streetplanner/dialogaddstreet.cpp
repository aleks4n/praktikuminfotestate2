#include "dialogaddstreet.h"
#include "ui_dialogaddstreet.h"

dialogAddStreet::dialogAddStreet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogAddStreet)
{
    ui->setupUi(this);
}

dialogAddStreet::~dialogAddStreet()
{
    delete ui;
}

/*!
 *  name returner
 *  @returns Qstring name 1
 */

QString dialogAddStreet::getname1()
{
    name1 = ui->city1->text();

    return name1;
}
/*!
 *  name returner
 *  @returns Qstring name 1
 */
QString dialogAddStreet::getname2()
{
    name2 = ui->city2->text();

    return name2;
}
