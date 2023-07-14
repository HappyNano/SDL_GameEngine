#include <iostream>
#include <SDL3/SDL.h>
#include "engine.hpp"

int main(int argc, char * argv[])
{
  SGE::Engine engine;

  engine.init();

  SDL_Window * window = engine.get_window();
  SDL_Renderer * renderer = engine.get_renderer();

  SDL_SetWindowTitle(window, "SDL issue");

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

    SDL_SetRenderDrawColor(renderer, 255, 80, 80, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  engine.quit();
}