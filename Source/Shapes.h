/****************************************************************************
 *  File name: Shapes.h
 *  Description:
 *      - Interface for the drawing of the basic shapes
  
*****************************************************************************/
#pragma once
typedef int Colour;
typedef class Vector2D Vector2D;

/* Constants                      */

/* Enums                          */

/* Public classes                 */


/* Public functions declarations  */

namespace Draw
{
  namespace Shape
  {
    void Rectangle(float x, float y, float width, float height, Colour rgb, int alpha, bool centered = 0, bool filled = 0);

    void Line(float x1, float y1, float x2, float y2, Colour rgb, int alpha);

    void Polygon(float x1, float y1, float x2, float y2, float x3, float y3, Colour rgb, int alpha, bool filled = 0);

    void Polygon(Vector2D p1, Vector2D p2, Vector2D p3, Colour rgb, int alpha, bool filled = 0);

    void Line(Vector2D point1, Vector2D point2, Colour rgb, int alpha);

    void Circle(float centreX, float centreY, float radius, Colour rgb, int alpha, bool filled = 0);

    void Circle(Vector2D centre, float radius, Colour rgb, int alpha, bool filled = 0);

    void Point(float x, float y, Colour rgb, int alpha);

    void Point(Vector2D&, Colour rgb, int alpha);
  }
 
}


