#include "SGE/initializers/img_initializer.hpp"

int SGE::IMG_Initializer::do_init()
{
  int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_AVIF | IMG_INIT_JXL | IMG_INIT_TIF | IMG_INIT_WEBP;
  return IMG_Init(imgFlags) & imgFlags;
}

void SGE::IMG_Initializer::do_quit()
{
  IMG_Quit();
}
