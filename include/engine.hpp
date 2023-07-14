#ifndef SGE_ENGINE_HPP
#define SGE_ENGINE_HPP

#include <memory>

#include "initializers/controller.hpp"
#include "initializers/sdl_initializer.hpp"
#include "initializers/window_initializer.hpp"

namespace SGE
{
  class Engine final
  {
   public:
    Engine();
    ~Engine() = default;

    int init();
    void quit();

    SDL_Window * get_window();
    SDL_Renderer * get_renderer();

   private:
    SGE::InitializerController _init_controller;

    std::shared_ptr< SGE::SDL_Initializer > _sdl_initializer;
    std::shared_ptr< SGE::Window_Initializer > _window_initializer;
  };
}

#endif
