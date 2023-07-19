#include "SGE/initializers/sdl_initializer.hpp"

int SGE::SDL_Initializer::do_init()
{
  return SDL_Init(SDL_Initializer::sdl_init_param) < 0;
}

void SGE::SDL_Initializer::do_quit()
{
  SDL_Quit();
}
