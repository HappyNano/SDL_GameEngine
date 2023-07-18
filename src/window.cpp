#include "window.hpp"

SGE::Window::Window():
  _window{ nullptr }
{}

SGE::Window::Window(SDL_Window * window):
  _window{ window }
{}

SDL_Window * SGE::Window::get_window()
{
  return _window;
}

void SGE::Window::set_window(SDL_Window * window)
{
  _window = window;
}

void SGE::Window::set_title(const std::string & title)
{
  SDL_SetWindowTitle(_window, title.c_str());
}
