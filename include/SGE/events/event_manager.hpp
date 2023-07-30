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
    typename KeyboardEventKeeper::ConstShared get_keyboardKeycodes();

    /**
     * \brief Set the keyboard keycodes object.
     *
     * \param ekeeper - EventKeeper::ConstShared object
     */
    void set_keyboardKeycodes(KeyboardEventKeeper::ConstShared ekeeper);
    void unset_keyboardKeycodes();

    /**
     * \brief Get the mouse keycodes object.
     * \return _event_keeper for mouse
     */
    typename MouseEventKeeper::ConstShared get_mouseKeycodes();

    /**
     * \brief Set the mouse keycodes object.
     *
     * \param ekeeper - EventKeeper::ConstShared object
     */
    void set_mouseKeycodes(MouseEventKeeper::ConstShared ekeeper);
    void unset_mouseKeycodes();

    void handle(SDL_Event * event);

    bool is_keyboardEventPressed(const std::string & name);
    bool is_keyboardEventReleased(const std::string & name);
    bool is_mouseEventPressed(const std::string & name);
    bool is_mouseEventReleased(const std::string & name);

   private:
    KeyboardEventKeeper::ConstShared _keyboard_event_keeper;
    MouseEventKeeper::ConstShared _mouse_event_keeper;

    std::unordered_map< KeyboardEventKeeper::type, bool > _keyboard_active;
    std::unordered_map< MouseEventKeeper::type, bool > _mouse_active;

    // TODO: Refactor in future

    void keyboardEventHandle(SDL_Event * event, bool isPressed);
    void mouseEventHandle(SDL_Event * event, bool isPressed);

    // TODO: In future do keep mouse events with rects and R-Tree
  };
}

#endif
