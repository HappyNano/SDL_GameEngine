#ifndef CONFIG_SCREEN_HPP
#define CONFIG_SCREEN_HPP

#include "SGE/config/config.hpp"

namespace SGE
{
  struct CfgScreen
  {
    int32_t width;
    int32_t height;

    CfgScreen(const Config & cfg);
  };
}

#endif
