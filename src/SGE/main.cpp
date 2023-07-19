#include <iostream>
#include <SDL3/SDL.h>
#include "SGE/engine.hpp"

int main(int argc, char * argv[])
{
  SGE::Engine engine;

  engine.init();

  engine.window().set_title("SDL_GameEngine");

  while (1)
  {
    int finished = 0;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_EVENT_QUIT)
      {
        finished = 1;
        break;
      }
    }
    if (finished)
    {
      break;
    }

    engine.renderer().setDrawColor(255, 80, 80, SDL_ALPHA_OPAQUE);
    engine.renderer().clear();
    engine.renderer().present();
  }

  engine.quit();
}