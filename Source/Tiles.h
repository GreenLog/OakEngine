/****************************************************************************
 *  File name: Tiles.h
 *  Description:
 *      - The interface for a system that can parse .map files
 *        into a tiled map
  
*****************************************************************************/
#pragma once
#include "Vector2D.h"
#include "SpriteSheet.h"
/* Constants                      */

/* Enums                          */

enum class MapLayer
{
  Invalid = -1,
  Water,
  Background1,
  Background2,
  Background3,
  Decor,
  Items,
  Misc,
  Hiding,
  Special
};

/* Public classes                 */

class Tile
{
public:
  Tile(int id = -1);
  void SetId(int id);
  int GetId() const;
  int& GetId();
private:
  int id_;
};
typedef class Tile* TilePtr;

class TiledMap 
{
public:
  TiledMap(const char* path, int sizeX, int sizeY, SpriteSheet* spriteSheet, MapLayer layer);
  int operator()(int column, int row) const;
  int& operator()(int column, int row);
  void Draw(float size);
private:
  MapLayer layer_;
  Tile** map_;
  Vector2D size_;
  SpriteSheet* spriteSheet_;
};
typedef class TiledMap * TiledMapPtr;



/* Public functions declarations  */

