#ifndef SGE_ENGINE_HPP
#define SGE_ENGINE_HPP

#include <memory>

#include "SGE/initializers/controller.hpp"
#include "SGE/initializers/sdl_initializer.hpp"
#include "SGE/initializers/window_initializer.hpp"
#include "SGE/initializers/ttf_initializer.hpp"

#include "SGE/window.hpp"
#include "SGE/renderer.hpp"

#include "SGE/scenes/scene.hpp"

namespace SGE
{
  class Engine final
  {
   public:
    Engine();
    ~Engine() = default;

    int init();
    void quit();

    void setScene(std::shared_ptr< SGE::Scene > scene);

    void run();
    void stop();

    Window & window();
    Renderer & renderer();

   private:
    SGE::InitializerController _init_controller;

    std::shared_ptr< SGE::SDL_Initializer > _sdl_initializer;
    std::shared_ptr< SGE::Window_Initializer > _window_initializer;
    std::shared_ptr< SGE::TTF_Initializer > _ttf_initializer;

    Window _window;
    Renderer _renderer;

    std::shared_ptr< SGE::Scene > _main_scene;
    bool running;
  };
}

#endif
