#include "initializers/window_initializer.hpp"

SGE::Window_Initializer::Window_Initializer(int width, int height):
  _width{ width },
  _height{ height },
  _window_ptr{ nullptr },
  _renderer_ptr{ nullptr }
{}

SDL_Window * SGE::Window_Initializer::get_window()
{
  return _window_ptr;
}

SDL_Renderer * SGE::Window_Initializer::get_renderer()
{
  return _renderer_ptr;
}

int SGE::Window_Initializer::do_init()
{
  return SDL_CreateWindowAndRenderer(640, 480, 0, &_window_ptr, &_renderer_ptr) < 0;
}

void SGE::Window_Initializer::do_quit()
{
  SDL_DestroyRenderer(_renderer_ptr);
  SDL_DestroyWindow(_window_ptr);
}
