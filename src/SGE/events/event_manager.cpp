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
      _keyboard_active.insert({ value, false });
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
      _mouse_active.insert({ value, false });
    }
  }
}

void SGE::EventManager::unset_mouseKeycodes()
{
  _mouse_event_keeper.reset();
  _mouse_active.clear();
}

void SGE::EventManager::event_handle(SDL_Event * event)
{
  switch (event->type)
  {
  case SDL_EVENT_MOUSE_BUTTON_DOWN:
    mouseEventHandle(event, true);
    break;

  case SDL_EVENT_MOUSE_BUTTON_UP:
    mouseEventHandle(event, false);
    break;

  case SDL_EVENT_KEY_DOWN:
    keyboardEventHandle(event, true);
    break;

  case SDL_EVENT_KEY_UP:
    keyboardEventHandle(event, false);
    break;

  default:
    break;
  }
}

bool SGE::EventManager::is_keyboardEventPressed(const std::string & name)
{
  auto && keyCodes = _keyboard_event_keeper->get_codes().at(name);

  for (auto && code: keyCodes)
  {
    if (_keyboard_active.at(code))
    {
      return true;
    }
  }

  return false;
}

bool SGE::EventManager::is_keyboardEventReleased(const std::string & name)
{
  return !is_keyboardEventPressed(name);
}

bool SGE::EventManager::is_mouseEventPressed(const std::string & name)
{
  auto && keyCodes = _mouse_event_keeper->get_codes().at(name);

  for (auto && code: keyCodes)
  {
    if (_mouse_active.at(code))
    {
      return true;
    }
  }

  return false;
}

bool SGE::EventManager::is_mouseEventReleased(const std::string & name)
{
  return !is_mouseEventPressed(name);
}

void SGE::EventManager::keyboardEventHandle(SDL_Event * event, bool isPressed)
{
  auto keyCode = event->key.keysym.scancode;
  auto iter = _keyboard_active.find(keyCode);

  if (iter != _keyboard_active.end())
  {
    iter->second = isPressed;
  }
}

void SGE::EventManager::mouseEventHandle(SDL_Event * event, bool isPressed)
{
  int x = event->button.x;
  int y = event->button.y;

  for (auto & val: _mouse_active)
  {
    SDL_Rect tmp{ x, y, 1, 1 };
    if (SDL_HasRectIntersection(&val.first, &tmp))
    {
      val.second = true;
    }
  }
}
