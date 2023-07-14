#include "initializers/initializer.hpp"

SGE::Initializer::Initializer():
  is_initialized{ false }
{}

SGE::Initializer::~Initializer()
{
  this->quit();
}

int SGE::Initializer::init()
{
  if (is_initialized)
  {
    return -1;
  }
  auto return_value = do_init();
  if (return_value)
  {
    is_initialized = true;
  }
  return return_value;
}

void SGE::Initializer::quit()
{
  if (!is_initialized)
  {
    return;
  }
  do_quit();
  is_initialized = false;
}