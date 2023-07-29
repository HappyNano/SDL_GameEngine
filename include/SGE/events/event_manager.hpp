#ifndef SGE_EVENT_MANAGER_HPP
#define SGE_EVENT_MANAGER_HPP

#include <SDL3/SDL.h>

#include <functional>

#include "SGE/events/event_keeper.hpp"

namespace SGE
{
  /**
   * \brief EventManager class
   */
  // TODO: docs
  class EventManager final
  {
   public:
    EventManager() = default;
    ~EventManager() = default;

    /**
     * \brief Get the keyboard keycodes object.
     * \return _event_keeper for keyboard
     */
    typename KeyboardEventKeeper::Shared get_keyboardKeycodes();

    /**
     * \brief Set the keyboard keycodes object.
     *
     * \param ekeeper - EventKeeper::Shared object
     */
    void set_keyboardKeycodes(KeyboardEventKeeper::Shared ekeeper);
    void unset_keyboardKeycodes();

    /**
     * \brief Get the mouse keycodes object.
     * \return _event_keeper for mouse
     */
    typename MouseEventKeeper::Shared get_mouseKeycodes();

    /**
     * \brief Set the mouse keycodes object.
     *
     * \param ekeeper - EventKeeper::Shared object
     */
    void set_mouseKeycodes(MouseEventKeeper::Shared ekeeper);
    void unset_mouseKeycodes();

   private:
    KeyboardEventKeeper::Shared _keyboard_event_keeper;
    MouseEventKeeper::Shared _mouse_event_keeper;

    // TODO: In future do keep mouse events with rects and R-Tree 
  };
}

#endif
