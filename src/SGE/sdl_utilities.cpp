#include "SGE/sdl_utilities.hpp"

bool operator==(const SDL_Rect & a, const SDL_Rect & b)
{
  return a.x == b.x && a.y == b.y && a.w == b.w && a.h == b.h;
}
