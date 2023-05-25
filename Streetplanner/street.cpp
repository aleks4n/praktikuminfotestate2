#include "street.h"

Street::Street(City* city1,City* city2):city1(city1),city2(city2)
{

}


/*!
 *  @brief Draws a street with its cities
 */

void Street::draw(QGraphicsScene &scene)
{
    city1->draw(scene);
    city2->draw(scene);
    drawBlue(scene);
}

/*!
 *  @brief Returns the name of city one
 */
City* Street::getcity1() const
{
    return city1;
}

/*!
 *   @brief Returns the name of city two
 */

City* Street::getcity2() const
{
    return city2;
}
/*!
 *   @brief Draws a line in REd
 */

void Street::drawRed(QGraphicsScene &scene)
{
    int x1 = (city1)->getX();
    int y1 = (city1)->getY();
    int x2 = (city2)->getX();
    int y2 = (city2)->getY();

    QPen Pen;
    Pen.setColor(Qt::red);
    Pen.setWidth(3);
    scene.addLine(x1, y1, x2, y2, Pen);
}

/*!
 *  @brief Draws a line in Blue
 */


void Street::drawBlue(QGraphicsScene &scene)
{
    int x1 = (city1)->getX();
    int y1 = (city1)->getY();
    int x2 = (city2)->getX();
    int y2 = (city2)->getY();

    QPen Pen;
    Pen.setColor(Qt::blue);
    Pen.setWidth(3);
    scene.addLine(x1, y1, x2, y2, Pen);
}
