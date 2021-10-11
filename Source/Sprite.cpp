/****************************************************************************
 *  File name: Sprite.h
 *  Description:
 *      - Implementation for the Sprite class that supports multiple file formats

*****************************************************************************/
#include "OEngine.h"
#include "Sprite.h"
#include "SDL.h"
#include "SDL_image.h"

#include <string>

/* Constants                      */

/* Enums                          */

enum class ImageType
{
  Invalid = -1,
  BMP,
  PNG = IMG_INIT_PNG,
  TIF = IMG_INIT_TIF,
  WEBP = IMG_INIT_WEBP,
  JPG = IMG_INIT_JPG,
};

/* Private classes                */

/* Public variables               */

/* Private variables              */

static Rect quad = { 0,0,0,0 };

/* Private functions declarations */

static ImageType DetectImageType(const char* filepath);

/* Public functions definitions   */

//The default constructor
Sprite::Sprite()
  : Component(ComponentType::Sprite)
  , texture_(nullptr)
  , size_(Vector2D(0, 0))
{

}

//The non-default constructor for the sprite class.
//Takes in the filepath to the texture
Sprite::Sprite(const char* filepath)
  : Component(ComponentType::Sprite)
  , texture_(nullptr)
{
  LoadFile(filepath);
  int h;
  int w;
  SDL_QueryTexture(this->texture_, nullptr, nullptr, &w, &h);
  size_.x = w;
  size_.y = h;
}

//The non-default constructor for the sprite class.
//Takes in the filepath to the texture,
//The width and the height of the image
Sprite::Sprite(const char* filepath, float width, float height)
  : Component(ComponentType::Sprite)
  , texture_(nullptr)
  , size_(Vector2D(width, height))
{
  LoadFile(filepath);
}

//The destructor for sprite
//Frees the texture pointer inside of it
Sprite::~Sprite()
{
  FreeTexture();
}

//Loads the sprite's texture from a file
void Sprite::LoadFile(const char* filepath)
{
  FreeTexture();
  ImageType type = DetectImageType(filepath);

  if (!(int)type)
  {
    SDL_Surface* image = SDL_LoadBMP(filepath);
    texture_ = SDL_CreateTextureFromSurface(renderer, image);
  }

  else
  {
    IMG_Init((IMG_InitFlags)type);
    SDL_Surface* image = IMG_Load(filepath);
    texture_ = SDL_CreateTextureFromSurface(renderer, image);
  }
}

//Sets the sprite's width to a given value
void Sprite::SetWidth(float width)
{
 size_.x = width;
}

//Sets the sprite's height to a given value
void Sprite::SetHeight(float height)
{
  size_.y = height;
}

//Draws the sprite on the screen on the provided coordinates
void Sprite::Draw(float xCoor, float yCoor, bool centered)
{
  if (centered)
  {
    xCoor -= size_.x / 2;
    yCoor -= size_.y / 2;
  }
  quad.x = xCoor;
  quad.y = yCoor;
  quad.w =size_.x;
  quad.h = size_.y;
  
  SDL_RenderCopyF(renderer, texture_, nullptr, &quad);
}

TexturePtr Sprite::GetTexture()
{
  return texture_;
}

Vector2D Sprite::GetSize()
{
  return size_;
}



//Frees the sprite's texture
void Sprite::FreeTexture()
{
  SDL_DestroyTexture(texture_);
  texture_ = nullptr;
}

/* Private functions definition */

static ImageType DetectImageType(const char* filepath)
{
  std::string path = filepath;

  if (path.find(".png"))
  {
    return ImageType::PNG;
  }

  if (path.find(".bmp"))
  {
    return ImageType::BMP;
  }

  if (path.find(".jpg"))
  {
    return ImageType::JPG;
  }

  if (path.find(".tif"))
  {
    return ImageType::TIF;
  }

  if (path.find(".webp"))
  {
    return ImageType::WEBP;
  }
  return ImageType::Invalid;

}
