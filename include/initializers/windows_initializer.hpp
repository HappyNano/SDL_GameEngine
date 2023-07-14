#ifndef SGE_WINDOWS_INITIALIZER_HPP
#define SGE_WINDOWS_INITIALIZER_HPP

#include <SDL3/SDL.h>

#include "initializers/initializer.hpp"

namespace SGE
{
  /**
   * \brief Initializer of Window and Renderer of SDL
   */
  class Window_Initializer final: public Initializer
  {
   public:
    Window_Initializer(int width, int height);
    ~Window_Initializer() = default;

    SDL_Window * get_window();
    SDL_Renderer * get_renderer();

   private:
    int _width, _height; ///< Width and height of SDL Window

    SDL_Window * _window_ptr;
    SDL_Renderer * _renderer_ptr;

    int do_init() override;
    void do_quit() override;
  };
}

#endif
