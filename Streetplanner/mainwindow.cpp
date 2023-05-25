#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsTextitem>

#include "city.h"
#include "map.h"
#include "street.h"
#include "dialog.h"
#include "mapionrw.h"
#include "dialogAddStreet.h"







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    mapio = new MapIoNrw;

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 *  @brief Map Tester Function
 *
 */

void MainWindow::testAbstractMap()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}

/*!
 *  @brief Tests the first button of the list
 */

void MainWindow::on_pushButton_teste_was_clicked()
{
    QString str;
    str = ui->lineEdit_teste_was->text();
    QMessageBox msgBox;
    msgBox.setText(str);
    msgBox.exec();

    scene.addEllipse(rand()*90/RAND_MAX, rand()*90/RAND_MAX, 4, 4, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));

}
/*!
 *  @brief Exit closes the program
 */

void MainWindow::on_actionExid_triggered()
{
    close();
}


void MainWindow::on_actionExit_triggered()
{
    close();
}

/*!
 *  @brief Clears the scene
 */
void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}

/*!
 *  @brief Shows the about info
 */

void MainWindow::on_actionAbout_triggered()
{


        QMessageBox::about(this,"About","Streetplanner SS2023 Aliihsan");

}


/*!
 *  @brief Draws two cities to test the function
 */


void MainWindow::on_drawcitytest_clicked()
{
        City city1("Istanbul",0,200);
        City city2("Aachen",100,50);

        city1.draw(scene);
        city2.draw(scene);
}
/*!
 *  @brief Tests the map class
 */

void MainWindow::on_mapTest_clicked()
{
        City c1("city c1", 20,50);
        map.addCity(&c1);
        map.draw(scene);
}
/*!
 *  @brief Draws a new street and its cities
 */

void MainWindow::on_testDrawStreets_clicked()
{
        City newCityy1("noobCity1", 0, 20);
        City newCityy2("noobCity2", 100, 200);

        Street newStreet(&newCityy1, &newCityy2);
        map.addCity(&newCityy1);
        map.addCity(&newCityy2);
        newCityy1.draw(scene);
        newCityy2.draw(scene);
        newStreet.draw(scene);


}

/*!
 *  @brief Hides/Shows the test buttons
 */

void MainWindow::on_checkBox_clicked()
{
        if (ui->checkBox->isChecked()==true)
        {
            ui->drawcitytest->hide();
            ui->pushButton_teste_was->hide();
            ui->testDrawStreets->hide();
            ui->mapTest->hide();
        }

        else if(ui->checkBox->isChecked()==false)
        {
            ui->drawcitytest->show();
            ui->pushButton_teste_was->show();
            ui->testDrawStreets->show();
            ui->mapTest->show();
        }
}


/*!
 *  @brief Adds a new city
 */

void MainWindow::on_addCity_clicked()
{
        Dialog dialog;
a:
        int i = dialog.exec();
        qDebug() << "Der Rückgabewert: " << i;

            if (i == 1)
        {
            City* city = dialog.addCity();
            if(dialog.result()==2){

                QMessageBox::warning(this,"Fehler!","Bitte geben Sie nur ganze Zahlen ein! ");

                goto a;

            }
            else{
                map.addCity(city);
                city->draw(scene);
            }
        }

        else
        {
            qDebug() << "Keine neue Stadt wurde hinzugefuegt.";
        }

}

/*!
 *  @brief Fills the map with the cities
 */
void MainWindow::on_fillMap_clicked()
{
        mapio->fillMap(map);
        map.draw(scene);
}

/*!
 *  @brief Runs test abstract map
 */

void MainWindow::on_testAbstractMap_clicked()
{
        testAbstractMap();
}


void MainWindow::on_dijkstraevaluation_clicked()
{
        Map testMap;
        City a("a", 0, 0);
        City b("b", 100, 0);
        City c("c", 0, 100);
        City d("d", 100, 200);

        testMap.addCity(&a);
        testMap.addCity(&b);
        testMap.addCity(&c);
        testMap.addCity(&d);

        Street s1(&a, &b);
        Street s2(&b, &c);
        Street s3(&a, &c);
        Street s4(&c, &d);
        testMap.addStreet(&s1);
        testMap.addStreet(&s2);
        testMap.addStreet(&s3);
        testMap.addStreet(&s4);
        s1.draw(scene);
        s2.draw(scene);
        s3.draw(scene);
        s4.draw(scene);

        testMap.draw(scene);

        QVector<Street*> kuerzesterWeg = Dijkstra::search(testMap, a.getName(), d.getName());

        for(auto it = kuerzesterWeg.begin(); it != kuerzesterWeg.end(); it++)
        {
            (*it)->drawRed(scene);
        }
}

/*!
 *  @brief Finds the shortest between two given cities
 */
void MainWindow::on_submit_clicked()
{
     QString namestart;
     QString nameend;
        namestart = ui->startcity->text();
        nameend = ui->endcity->text();

        City* city1 = map.findCity(namestart);
        City* city2 = map.findCity(nameend);




        QVector<Street*> kuerzesterWeg = Dijkstra::search(map, city1->getName(), city2->getName());

        for(auto it = kuerzesterWeg.begin(); it != kuerzesterWeg.end(); it++)
        {
            (*it)->drawRed(scene);
        }

}

/*!
 *  @brief Adds a street to the map and draws it
 */
void MainWindow::on_addStreet_clicked()
{
        dialogAddStreet dialog;
        int i = dialog.exec();
        qDebug() << "Der Rückgabewert: " << i;


        if (i == 1)
        {
            QString Name1 = dialog.getname1();
            QString Name2 = dialog.getname2();

            if(map.findCity(Name1) == nullptr || map.findCity(Name2) == nullptr)
            {
                qDebug() << "Geben Sie richtige Stadt ein!";
                return;
            }

            City* city1 = map.findCity(Name1);
            City* city2 = map.findCity(Name2);

            Street* strasse = new Street(city1, city2);
            if(map.addStreet(strasse))
            {
                strasse->draw(scene);
            }
        }

        else
        {
            qDebug() << "Keine neue Strasse war hinzugefuegt!";
        }


        if (i == 1)
        {
            QString Name1 = dialog.getname1();
            QString Name2 = dialog.getname2();

            if(map.findCity(Name1) == nullptr || map.findCity(Name2) == nullptr)
            {
                qDebug() << "Geben Sie richtige Stadt ein!";
                return;
            }

            City* city1 = map.findCity(Name1);
            City* city2 = map.findCity(Name2);

            Street* strasse = new Street(city1, city2);
            if(map.addStreet(strasse))
            {
                strasse->draw(scene);
            }
        }

        else
        {
            qDebug() << "Keine neue Strasse war hinzugefuegt!";
        }
}
/*!
 *  @brief Controls the combobox
 */

void MainWindow::on_stadtList_currentIndexChanged(int index)
{
        switch(index)
        {
        case 1:
        {City* koeln = new City("Köln", 0,0);
             map.addCity(koeln);
            map.draw(scene);}break;

        case 2:{
             City* bonn = new City("Bonn", 0,200);
             map.addCity(bonn);
             map.draw(scene);}break;

        case 3:{
                City* ddorf = new City("Düsseldorf", 50,-100);
                map.addCity(ddorf);
                map.draw(scene);}break;
        case 4:{
                City* aachen = new City("Aachen", -100,100);
                map.addCity(aachen);
                map.draw(scene);}break;

        case 5:{
            map.deletecities();
            scene.clear();

                }break;
        }
}



