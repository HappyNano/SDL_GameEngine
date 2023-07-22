#ifndef SGE_RENDERER_HPP
#define SGE_RENDERER_HPP

#include <SDL3/SDL.h>
#include <string>

namespace SGE
{
  /**
   * \brief This class does not own the SDL_Renderer, but only serves as a helper.
   */
  class Renderer final
  {
   public:
    Renderer();
    Renderer(SDL_Renderer * renderer);

    SDL_Renderer * get_renderer();
    void set_renderer(SDL_Renderer * renderer);

    void clear();
    void present();

    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void setDrawColor(const SDL_Color & clr);
    SDL_Color getDrawColor();

   private:
    SDL_Renderer * _renderer;
  };
}

#endif
