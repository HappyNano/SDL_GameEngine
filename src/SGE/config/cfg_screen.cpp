#include "SGE/config/cfg_screen.hpp"
#include <iostream>

SGE::CfgScreen::CfgScreen(const Config & cfg):
  width{ 0 },
  height{ 0 }
{
  try
  {
    std::string str_width = cfg.getConfig().at("WIDTH");
    std::string str_height = cfg.getConfig().at("HEIGHT");

    width = std::stol(str_width);
    height = std::stol(str_height);
  }
  catch (const std::out_of_range & e)
  {
    std::cerr << "Bad config!\n";
    throw e;
  }
}
