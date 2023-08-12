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
    using this_t = Renderer;

    Renderer();
    Renderer(SDL_Renderer * renderer);

    SDL_Renderer * get_renderer();
    void set_renderer(SDL_Renderer * renderer);

    void clear();
    void present();

    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void setDrawColor(const SDL_Color & clr);
    SDL_Color getDrawColor();

    this_t & drawPoint(float x, float y);
    this_t & drawLine(float x1, float y1, float x2, float y2);
    this_t & drawRect(float x, float y, float w, float h);
    this_t & drawRect(const SDL_FRect & rect);

   private:
    SDL_Renderer * _renderer;
  };
}

#endif
