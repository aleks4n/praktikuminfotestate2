#include "map.h"
#include "city.h"
Map::Map()
{

}
/*!
 *  @brief Adds a City to the Map
 */

void Map::addCity(City* stadt)
{
    cities.append(stadt);
    qDebug() << stadt->getName()<< "is added to the map"<<"\n";
}
/*!
 *  @brief Draws the cities in a Map
 */

void Map::draw(QGraphicsScene& scene)
{
    for(auto city : cities)
    {
        city->draw(scene);
    }
}
/*!
 *  @brief Adds a ctreet to the map
 */

bool Map::addStreet(Street* street)
{

    City* city1  = street->getcity1();
    City* city2 = street->getcity2();


    if (findCity(city1->getName()) != nullptr && findCity(city2->getName()) != nullptr)
    {
        streets.append(street);
        return true;
    }
    else
    {
        qDebug()<<"Error Exists in your Parameters";
        return false;
    }
}
/*!
 *  @brief Finds a city in map given its name
 *  @param Name of the city
 */

City* Map::findCity(const QString cityName) const
{
    for(QVector<City*>::const_iterator it = cities.begin(); it != cities.end(); it++)
    {
        if ((*it)->getName() == cityName)
        {
            return *it;
        }
    }
    return nullptr;
}

/*!
 *  @brief Gets the list of the streets
 *  @param The City
 */

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector <Street*> cityStreetList;
    for(QVector<Street*>::const_iterator it = streets.begin();
         it != streets.end();
         it++)
    {
        if(city == (*it)->getcity1() || city == (*it)->getcity2())
        {
            cityStreetList.append(*it);
        }
    }
    return cityStreetList;
}

/*!
 *  @brief Gets the oppsite city
 *  @param The street
 *  @param Chosen City
 */

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if(street->getcity1() == city){return street->getcity2();}
    if(street->getcity2() == city){return street->getcity1();}
    else{return nullptr;}

}
/*!
 *  @brief Gets the length of a Street
 *  @param Street
 */


double Map::getLength(const Street* street) const
{
    double x1 = street->getcity1()->getX();
    double y1 = street->getcity1()->getY();
    double x2 = street->getcity2()->getX();
    double y2 = street->getcity2()->getY();
    double abs = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    double laenge = sqrt(abs);
    return laenge;
}

void Map::deletecities()
{
    cities.clear();
}

