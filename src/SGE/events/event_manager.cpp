#include "SGE/events/event_manager.hpp"

typename SGE::KeyboardEventKeeper::ConstShared SGE::EventManager::get_keyboardKeycodes()
{
  return _keyboard_event_keeper;
}

void SGE::EventManager::set_keyboardKeycodes(KeyboardEventKeeper::ConstShared ekeeper)
{
  unset_keyboardKeycodes();
  _keyboard_event_keeper = ekeeper;
  for (auto && code: _keyboard_event_keeper->get_codes())
  {
    for (auto && value: code.second)
    {
      _keyboard_actions.insert({ value, false });
    }
  }
}

void SGE::EventManager::unset_keyboardKeycodes()
{
  _keyboard_event_keeper.reset();
}

typename SGE::MouseEventKeeper::ConstShared SGE::EventManager::get_mouseKeycodes()
{
  return _mouse_event_keeper;
}

void SGE::EventManager::set_mouseKeycodes(MouseEventKeeper::ConstShared ekeeper)
{
  unset_mouseKeycodes();
  _mouse_event_keeper = ekeeper;
  for (auto && code: _mouse_event_keeper->get_codes())
  {
    for (auto && value: code.second)
    {
      _mouse_actions.insert({ value, false });
    }
  }
}

void SGE::EventManager::unset_mouseKeycodes()
{
  _mouse_event_keeper.reset();
  _mouse_actions.clear();
}
