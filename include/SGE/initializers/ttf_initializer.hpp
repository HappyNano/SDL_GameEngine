#ifndef SGE_TTF_INITIALIZER_HPP
#define SGE_TTF_INITIALIZER_HPP

#include <SDL3/SDL_ttf.h>

#include "SGE/initializers/initializer.hpp"

namespace SGE
{
  /**
   * \brief Initializer of SDL_ttf (fonts). Doing TTF_INIT
   */
  class TTF_Initializer final: public Initializer
  {
   public:
    TTF_Initializer() = default;
    ~TTF_Initializer() = default;

   private:
    int do_init() override;
    void do_quit() override;
  };
}

#endif
