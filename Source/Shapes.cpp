/****************************************************************************
 *  File name: Shapes.cpp
 *  Description:
 *      - Implementation for the drawing of the basic shapes
  
*****************************************************************************/
#include "OEngine.h"
#include "SDL.h"
#include "Shapes.h"
#include "Vector2D.h"

#define SPLIT_COLOUR(rgb) rgb / 0x10000, (rgb / 0x100) % 0x100, rgb % 0x100

/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

Rect rect = { -1, -1, -1, -1 };

/* Private functions declarations */


/* Public functions definitions   */

namespace Draw
{
  namespace Shape
  {
    void Rectangle(float x, float y, float width, float height, Colour rgb, int alpha, bool centered, bool filled)
    {

      rect.x = x;
      rect.y = y;
      rect.w = width;
      rect.h = height;

      if (centered)
      {
        rect.x -= width / 2;
        rect.y -= height / 2;
      }

      SDL_SetRenderDrawColor(renderer, SPLIT_COLOUR(rgb), alpha);
      if (filled)
      {
        SDL_RenderFillRectF(renderer, &rect);
      }
      SDL_RenderDrawRectF(renderer, &rect);
    }

    void Line(float x1, float y1, float x2, float y2, Colour rgb, int alpha)
    {
      SDL_SetRenderDrawColor(renderer, SPLIT_COLOUR(rgb), alpha);
      SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
    }

    void Polygon(float x1, float y1, float x2, float y2, float x3, float y3, Colour rgb, int alpha, bool filled)
    {
      Line(x1, y1, x2, y2, rgb, alpha);
      Line(x1, y1, x3, y3, rgb, alpha);
      Line(x2, y2, x3, y3, rgb, alpha);
      if (filled)
      {
        Vector2D temp = (Vector2D(x2, y2) - Vector2D(x1, y1)).GetNormal();
        float ytemp = y1;
        if (x1 < x2)
        {

          for (float xtemp = x1; xtemp <= x2; xtemp += temp.x)
          {
            Line(Vector2D(xtemp, ytemp), Vector2D(x3, y3), rgb, 255);
            ytemp += temp.y;
          }

        }
        else if (x1 != x2)
        {
          for (float xtemp = x1; xtemp >= x2; xtemp += temp.x)
          {
            Line(Vector2D(xtemp, ytemp), Vector2D(x3, y3), rgb, 255);
            ytemp += temp.y;
          }
        }
      }
    }

    void Polygon(Vector2D p1, Vector2D p2, Vector2D p3, Colour rgb, int alpha, bool filled)
    {
      Polygon(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, rgb, alpha, filled);
    }


    void Line(Vector2D point1, Vector2D point2, Colour rgb, int alpha)
    {
      Line(point1.x, point1.y, point2.x, point2.y, rgb, alpha);
    }

    void Circle(float centreX, float centreY, float radius, Colour rgb, int alpha, bool filled)
    {
      SDL_SetRenderDrawColor(renderer, SPLIT_COLOUR(rgb), alpha);

      float diameter = (radius * 2);

      float x = (radius - 1);
      float y = 0;
      float tx = 1;
      float ty = 1;
      float error = (tx - diameter);

      while (x >= y)
      {
        SDL_RenderDrawPointF(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPointF(renderer, centreX + x, centreY + y);

        SDL_RenderDrawPointF(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPointF(renderer, centreX - x, centreY + y);

        SDL_RenderDrawPointF(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPointF(renderer, centreX + y, centreY + x);

        SDL_RenderDrawPointF(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPointF(renderer, centreX - y, centreY + x);
        if (filled)
        {
          Line(centreX + x, centreY - y, centreX + x, centreY + y, rgb, alpha);
          Line(centreX - x, centreY - y, centreX - x, centreY + y, rgb, alpha);
          Line(centreX + y, centreY - x, centreX + y, centreY + x, rgb, alpha);
          Line(centreX - y, centreY - x, centreX - y, centreY + x, rgb, alpha);
        }

        if (error <= 0)
        {
          ++y;
          error += ty;
          ty += 2;
        }

        if (error > 0)
        {
          --x;
          tx += 2;
          error += (tx - diameter);
        }
      }

    }

    void Circle(Vector2D centre, float radius, Colour rgb, int alpha, bool filled)
    {
      Circle(centre.x, centre.y, radius, rgb, alpha, filled);
    }

    void Point(float x, float y, Colour rgb, int alpha)
    {
      SDL_SetRenderDrawColor(renderer, SPLIT_COLOUR(rgb), alpha);
      SDL_RenderDrawPointF(renderer, x, y);
    }

    void Point(Vector2D& point, Colour rgb, int alpha)
    {
      Point(point.x, point.y, rgb, alpha);
    }
  }
  
}





