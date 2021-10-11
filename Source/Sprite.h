/****************************************************************************
 *  File name: Sprite.h
 *  Description:
 *      - Interface for the Sprite class that supports multiple file formats
  
*****************************************************************************/
#pragma once
#include "Component.h"
#include "Vector2D.h"

typedef struct SDL_Texture* TexturePtr;
typedef class Sprite* SpritePtr;


/* Constants                      */

/* Enums                          */

/* Public classes                 */

class Sprite : public Component
{
public:


  //The default constructor
  Sprite();
  
  //The non-default constructor for the sprite class.
  //Takes in the filepath to the texture
  Sprite(const char* filepath);

  //The non-default constructor for the sprite class.
  //Takes in the filepath to the texture,
  //The width and the height of the image
  Sprite(const char* filepath, float width, float height);

  //The destructor for sprite
  //Frees the texture pointer inside of it
  ~Sprite();

  //Loads the sprite's texture from a file
  void LoadFile(const char* filepath);
  
  //Sets the sprite's width to a given value
  void SetWidth(float width);

  //Sets the sprite's height to a given value
  void SetHeight(float height);

  //Frees the sprite's texture
  void FreeTexture();

  //Draws the sprite on the screen on the provided coordinates
  void Draw(float x, float y, bool centered = false);
  Vector2D GetSize();
  TexturePtr GetTexture();

private:
  
  
  

  //Sprite's texture
  TexturePtr texture_;

  Vector2D size_;

};

/* Public functions declarations  */

