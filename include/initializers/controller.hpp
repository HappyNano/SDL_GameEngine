#ifndef SGE_INITIALIZERS_CONTROLLER_HPP
#define SGE_INITIALIZERS_CONTROLLER_HPP

#include <memory>
#include <stack>
#include <queue>

#include "initializers/initializer.hpp"

namespace SGE
{
  class InitializerController final
  {
   public:
    using initializer_shared_t = std::shared_ptr< Initializer >;

    InitializerController();
    ~InitializerController();

    void add(initializer_shared_t);
    /**
     * \brief Takes initializers from queue, and do initialise each one in right order
     */
    int init();
    void quit();

   private:
    std::stack< initializer_shared_t > _inits_stack;
    std::queue< initializer_shared_t > _inits_queue;
  };
}

#endif
