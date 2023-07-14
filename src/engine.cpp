#include "engine.hpp"

SGE::Engine::Engine():
  _init_controller{},
  _sdl_initializer{ std::make_shared< SDL_Initializer >() },
  _window_initializer{ std::make_shared< Window_Initializer >(500, 500) }
{
  _init_controller.add(_sdl_initializer);
  _init_controller.add(_window_initializer);
}

int SGE::Engine::init()
{
  return _init_controller.init();
}

void SGE::Engine::quit()
{
  _init_controller.quit();
}

SDL_Window * SGE::Engine::get_window()
{
  return _window_initializer->get_window();
}

SDL_Renderer * SGE::Engine::get_renderer()
{
  return _window_initializer->get_renderer();
}
