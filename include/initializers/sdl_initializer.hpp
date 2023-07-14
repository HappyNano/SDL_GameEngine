#ifndef SGE_SDL_INITIALIZER_HPP
#define SGE_SDL_INITIALIZER_HPP

#include <SDL3/SDL.h>

#include "initializers/initializer.hpp"

namespace SGE
{
  /**
   * \brief Initializer of SDL. Doing SDL_INIT
   */
  class SDL_Initializer final: public Initializer
  {
   public:
    static const auto sdl_init_param = SDL_INIT_EVERYTHING;

    SDL_Initializer() = default;
    ~SDL_Initializer() = default;

   private:
    int do_init() override;
    void do_quit() override;
  };
}

#endif
