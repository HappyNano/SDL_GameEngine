#ifndef SGE_UTILITIES_HPP
#define SGE_UTILITIES_HPP

#include <SDL3/SDL.h>

/**
 * \brief For SDL Utilities
 *
 */

namespace SGE
{
  bool operator==(const SDL_Rect& a, const SDL_Rect& b);
}

#endif
