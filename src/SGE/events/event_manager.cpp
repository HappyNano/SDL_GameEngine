#include "SGE/events/event_manager.hpp"

typename SGE::KeyboardEventKeeper::Shared SGE::EventManager::get_keyboardKeycodes()
{
  return _keyboard_event_keeper;
}

void SGE::EventManager::set_keyboardKeycodes(KeyboardEventKeeper::Shared ekeeper)
{
  _keyboard_event_keeper = ekeeper;
}

void SGE::EventManager::unset_keyboardKeycodes()
{
  _keyboard_event_keeper.reset();
}

typename SGE::MouseEventKeeper::Shared SGE::EventManager::get_mouseKeycodes()
{
  return _mouse_event_keeper;
}

void SGE::EventManager::set_mouseKeycodes(MouseEventKeeper::Shared ekeeper)
{
  _mouse_event_keeper = ekeeper;
}

void SGE::EventManager::unset_mouseKeycodes()
{
  _mouse_event_keeper.reset();
}
