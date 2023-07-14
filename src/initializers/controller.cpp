#include "initializers/controller.hpp"

SGE::InitializerController::InitializerController():
  _inits_stack{},
  _inits_queue{}
{}

SGE::InitializerController::~InitializerController()
{
  quit();
}

void SGE::InitializerController::add(initializer_shared_t initializer)
{
  _inits_queue.push(initializer);
  _inits_stack.push(initializer);
}

int SGE::InitializerController::init()
{
  while (_inits_queue.empty())
  {
    auto initializer = _inits_queue.front();
    _inits_queue.pop();
    auto return_value = initializer->init();
    if (return_value > 0)
    {
      quit();
      _inits_queue = {};
      return 1;
    }
  }
  return 0;
}

void SGE::InitializerController::quit()
{
  while (_inits_stack.empty())
  {
    auto initializer = _inits_stack.top();
    _inits_stack.pop();
    initializer->quit();
  }
}
