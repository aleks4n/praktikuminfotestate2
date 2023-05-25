#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "mapio.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();



    void on_drawcitytest_clicked();

    void on_mapTest_clicked();

    void on_testDrawStreets_clicked();

    void on_checkBox_clicked();

    void on_addCity_clicked();

    void on_fillMap_clicked();

    void on_testAbstractMap_clicked();
    void testAbstractMap();

    void on_dijkstraevaluation_clicked();

    void on_submit_clicked();

    void on_addStreet_clicked();

    void on_stadtList_currentIndexChanged(int index);

    void on_actionExid_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapio;

};
#endif // MAINWINDOW_H
