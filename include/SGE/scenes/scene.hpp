#ifndef SGE_SCENE_HPP
#define SGE_SCENE_HPP

#include "SGE/events/event_keeper.hpp"

namespace SGE
{
  /**
   * \brief Abstract class of Scene
   */
  class Scene
  {
   public:
    virtual ~Scene() = default;

    virtual void load() = 0;
    virtual void mloop() = 0;
    virtual void quit() = 0;

    virtual KeyboardEventKeeper::ConstShared getKeyboardEventKeeper() = 0;
    virtual MouseEventKeeper::ConstShared getMouseEventKeeper() = 0;
    // virtual void setKeyboardEventKeeper(KeyboardEventKeeper::ConstShared) = 0;
    // virtual void setMouseEventKeeper(MouseEventKeeper::ConstShared) = 0;

   protected:
    Scene() = default;
  };
}

#endif
