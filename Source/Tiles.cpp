/****************************************************************************
 *  File name: Tiles.cpp
 *  Description:
 *      - An implemenation for a system that can parse .map files 
 *        into a tiled map
  
*****************************************************************************/
#include "OEngine.h"
#include "Tiles.h"
#include <iostream>
#include <sstream>
#include <fstream>
/* Constants                      */

/* Enums                          */

/* Private classes                */

/* Public variables               */

/* Private variables              */

/* Private functions declarations */

/* Public functions definitions   */

/* Private functions definitions  */

TiledMap::TiledMap(const char* path, int sizeX, int sizeY, SpriteSheet* spriteSheet, MapLayer layer)
  :size_(Vector2D((float)sizeX, (float)sizeY))
  ,layer_(layer)
  ,spriteSheet_(spriteSheet)
{
  map_ = new Tile * [sizeY];
  for (int i = 0; i < sizeY; i++)
  {
    map_[i] = new Tile[sizeX];
  }

  std::ifstream file(path);

  for (int row = 0; row < sizeY; row++)
  {
    std::string line;
    std::getline(file, line);
    if (!file.good())
      break;

    std::stringstream iss(line);

    for (int col = 0; col < sizeX; col++)
    {
      std::string val;
      std::getline(iss, val, ',');
      if (!iss.good())
        break;

      std::stringstream convertor(val);
      int temp;
      convertor >> temp;
      map_[row][col].SetId(temp);
    }
  }
  file.close();
}

int TiledMap::operator()(int column, int row) const
{
  return map_[row][column].GetId();
}

int& TiledMap::operator()(int column, int row)
{
  return map_[row][column].GetId();
}

void TiledMap::Draw(float size)
{
  for (int i = 0; i < size_.x; i++)
  {
    for (int j = 0; j < size_.y; j++)
    {
      if (this->operator()(i,j) != -1)
      {
        spriteSheet_->SetFrame(this->operator()(i, j));
        spriteSheet_->Draw(i * size, j * size, true);
      }
    }
  }
}

Tile::Tile(int id)
  :id_(id)
{

}

void Tile::SetId(int id)
{
  id_ = id;
}

int Tile::GetId() const
{
  return id_;
}

int& Tile::GetId()
{
  return id_;
}
