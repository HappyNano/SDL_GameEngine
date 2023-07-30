#ifndef SGE_UTILITIES_HPP
#define SGE_UTILITIES_HPP

#include <SDL3/SDL.h>

#include <functional>

/**
 * \brief For SDL Utilities
 *
 */

bool operator==(const SDL_Rect & a, const SDL_Rect & b);

template <>
struct std::hash< SDL_Rect >
{
  std::size_t operator()(const SDL_Rect & rect) const noexcept
  {
    std::size_t x = std::hash< int >{}(rect.x);
    std::size_t y = std::hash< int >{}(rect.y);
    std::size_t w = std::hash< int >{}(rect.w);
    std::size_t h = std::hash< int >{}(rect.h);

    return x ^ (y << 1) ^ (w << 2) ^ (h << 3);
  }
};

#endif
