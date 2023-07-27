#ifndef SGE_IMG_INITIALIZER_HPP
#define SGE_IMG_INITIALIZER_HPP

#include <SDL3/SDL_image.h>

#include "SGE/initializers/initializer.hpp"

namespace SGE
{
  /**
   * \brief Initializer of SDL_image. Doing IMG_Init
   */
  class IMG_Initializer final: public Initializer
  {
   public:
    IMG_Initializer() = default;
    ~IMG_Initializer() = default;

   private:
    int do_init() override;
    void do_quit() override;
  };
}

#endif
