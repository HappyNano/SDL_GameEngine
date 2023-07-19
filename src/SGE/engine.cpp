#include "SGE/engine.hpp"

SGE::Engine::Engine():
  _init_controller{},
  _sdl_initializer{ std::make_shared< SDL_Initializer >() },
  _window_initializer{ std::make_shared< Window_Initializer >(500, 500) },
  _ttf_initializer{ std::make_shared< TTF_Initializer >() },
  _window{},
  _renderer{}
{
  _init_controller.add(_sdl_initializer);
  _init_controller.add(_window_initializer);
  _init_controller.add(_ttf_initializer);
}

int SGE::Engine::init()
{
  auto return_value = _init_controller.init();
  _window.set_window(_window_initializer->get_window());
  _renderer.set_renderer(_window_initializer->get_renderer());
  return return_value;
}

void SGE::Engine::quit()
{
  _window.set_window(nullptr);
  _renderer.set_renderer(nullptr);
  _init_controller.quit();
}

SGE::Window & SGE::Engine::window()
{
  return _window;
}

SGE::Renderer & SGE::Engine::renderer()
{
  return _renderer;
}
