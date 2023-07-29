#ifndef SGE_EVENT_KEEPER_HPP
#define SGE_EVENT_KEEPER_HPP

#include <SDL3/SDL.h>

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>

namespace SGE
{
  /**
   * \brief The EventKeeper class is used to store keycode names.
   * Used to easily switch between scenes.
   */
  // TODO: docs
  template < typename KeyCode_t >
  class EventKeeper final
  {
   public:
    using Shared = std::shared_ptr< EventKeeper< KeyCode_t > >;
    using ConstShared = std::shared_ptr< const EventKeeper< KeyCode_t > >;

    EventKeeper() = default;
    ~EventKeeper() = default;

    void register_key(const std::string & key, const KeyCode_t & code);
    void unregister_key(const std::string & key, const KeyCode_t & code);
    void unregister_key(const std::string & key);

   private:
    using key_code_set_t = std::unordered_set< KeyCode_t >;

    std::unordered_map< std::string, key_code_set_t > _codes;
  };

  using KeyboardEventKeeper = EventKeeper< SDL_KeyCode >;
  using MouseEventKeeper = EventKeeper< SDL_Rect >;
  // TODO: For Joystick
}

template < typename KeyCode_t >
void SGE::EventKeeper< KeyCode_t >::register_key(const std::string & key, const KeyCode_t & code)
{
  _codes[key].insert(code);
}

template < typename KeyCode_t >
void SGE::EventKeeper< KeyCode_t >::unregister_key(const std::string & key, const KeyCode_t & code)
{
  _codes[key].erase(code);
}

template < typename KeyCode_t >
void SGE::EventKeeper< KeyCode_t >::unregister_key(const std::string & key)
{
  _codes[key].clear();
}

#endif
