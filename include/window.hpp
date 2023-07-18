#ifndef SGE_WINDOW_HPP
#define SGE_WINDOW_HPP

#include <SDL3/SDL.h>
#include <string>

namespace SGE
{
  /**
   * \brief This class does not own the SDL_Window, but only serves as a helper.
   */
  class Window final
  {
   public:
    Window();
    Window(SDL_Window * window);

    SDL_Window * get_window();
    void set_window(SDL_Window * window);

    void set_title(const std::string & title);

   private:
    SDL_Window * _window;
  };
}

#endif
