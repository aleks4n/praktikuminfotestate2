#ifndef MAP_H
#define MAP_H


#include <QVector>
#include <QGraphicsScene>
#include "abstractmap.h"
#include "dijkstra.h"

class City;
class Street;
class Map: public AbstractMap
{
public:
    Map();
    QVector<City*> cities;
    QVector<Street*> streets;
    bool addStreet(Street* Street);
    void addCity(City* stadt);
    void draw(QGraphicsScene& scene);
    City* findCity(const QString cityName) const;
    QVector<Street*> getStreetList(const City* city) const;
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;
    void deletecities();

};

#endif // MAP_H
