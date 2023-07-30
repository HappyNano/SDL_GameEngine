#ifndef SGE_EVENT_KEEPER_HPP
#define SGE_EVENT_KEEPER_HPP

#include <SDL3/SDL.h>

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>

#include "SGE/sdl_utilities.hpp"

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
    using type = KeyCode_t;
    using this_t = EventKeeper< KeyCode_t >;
    using Shared = std::shared_ptr< this_t >;
    using ConstShared = std::shared_ptr< const this_t >;

    using key_code_set_t = std::unordered_set< KeyCode_t >;
    using codes_type = std::unordered_map< std::string, key_code_set_t >;

    EventKeeper() = default;
    ~EventKeeper() = default;

    const codes_type & get_codes() const;

    void register_key(const std::string & key, const KeyCode_t & code);
    void unregister_key(const std::string & key, const KeyCode_t & code);
    void unregister_key(const std::string & key);

    /**
     * \brief Function to merge codes from different EventKeeper
     *
     * \param obj Object of EventKeeper
     * \return const this_t& for simple using
     */
    this_t & merge(const this_t & obj);

   private:
    codes_type _codes;
  };

  using KeyboardEventKeeper = EventKeeper< SDL_Keycode >;
  using MouseEventKeeper = EventKeeper< SDL_Rect >;
  // TODO: For Joystick
}

template < typename KeyCode_t >
const typename SGE::EventKeeper< KeyCode_t >::codes_type & SGE::EventKeeper< KeyCode_t >::get_codes() const
{
  return _codes;
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

template < typename KeyCode_t >
typename SGE::EventKeeper< KeyCode_t >::this_t & SGE::EventKeeper< KeyCode_t >::merge(const this_t & obj)
{
  for (auto && code: obj._codes)
  {
    _codes[code.first].merge(code.second);
  }

  return *this;
}

#endif
