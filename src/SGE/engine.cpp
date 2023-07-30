#include "SGE/engine.hpp"
#include <iostream>

SGE::Engine::Engine(const SGE::CfgScreen & cfgScreen):
  _init_controller{},
  _sdl_initializer{ std::make_shared< SDL_Initializer >() },
  _window_initializer{ std::make_shared< Window_Initializer >(cfgScreen.width, cfgScreen.height) },
  _ttf_initializer{ std::make_shared< TTF_Initializer >() },
  _img_initializer{ std::make_shared< IMG_Initializer >() },
  _window{},
  _renderer{},
  _event_manager{ std::make_shared< EventManager >() }
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

void SGE::Engine::setScene(std::shared_ptr< SGE::Scene > scene)
{
  _main_scene = scene;
  _main_scene->load();
  _event_manager->set_keyboardKeycodes(_main_scene->getKeyboardEventKeeper());
  _event_manager->set_mouseKeycodes(_main_scene->getMouseEventKeeper());
}

void SGE::Engine::run()
{
  running = true;
  while (running)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_QUIT)
      {
        this->stop();
        break;
      }
      _event_manager->event_handle(&event);
    }
    if (!running)
    {
      break;
    }

    if (_event_manager->is_keyboardEventPressed("game_quit"))
    {
      std::cout << "Goodbye Keyboard!\n";
      this->stop();
    }

    if (_event_manager->is_mouseEventPressed("game_quit"))
    {
      std::cout << "Goodbye Mouse!\n";
      this->stop();
    }

    renderer().clear();
    _main_scene->mloop();
    renderer().present();
  }
}

void SGE::Engine::stop()
{
  running = false;
}

SGE::Window & SGE::Engine::window()
{
  return _window;
}

SGE::Renderer & SGE::Engine::renderer()
{
  return _renderer;
}
