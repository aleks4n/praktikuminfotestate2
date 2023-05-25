#ifndef STREET_H
#define STREET_H

#include "city.h"
class Street
{
public:
    Street( City* a, City* b);
    void draw(QGraphicsScene &scene);
    City* getcity1() const;
    City* getcity2() const;
    void drawRed(QGraphicsScene &scene);
    void drawBlue(QGraphicsScene &scene);
private:
    City* city1;
    City* city2;
};



#endif // STREET_H
