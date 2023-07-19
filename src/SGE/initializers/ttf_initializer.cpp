#include "SGE/initializers/ttf_initializer.hpp"

int SGE::TTF_Initializer::do_init()
{
  return TTF_Init() == -1;
}

void SGE::TTF_Initializer::do_quit()
{
  TTF_Quit();
}
