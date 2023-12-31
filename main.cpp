#include <iostream>
#include <SGE/SGE.hpp>

#include <cmath>

namespace
{
  class TestScene final: public SGE::Scene
  {
   public:
    TestScene(SGE::Engine & engine):
      _engine(engine),
      _backupClr{ 0, 0, 0, 0 },
      _keyboard_ekeeper{ std::make_shared< SGE::KeyboardEventKeeper >() },
      _mouse_ekeeper{ std::make_shared< SGE::MouseEventKeeper >() }
    {
      _keyboard_ekeeper->register_key("game_quit", SDL_SCANCODE_Q);
      _mouse_ekeeper->register_key("game_quit", { 400, 0, 100, 100 });
    }

    ~TestScene()
    {
      this->quit();
    }

    void load() override
    {
      _backupClr = _engine.renderer().getDrawColor();
    }

    void mloop() override
    {
      constexpr double freq = .0005f;
      static double i = 0;

      SDL_Color clr = { 0, 0, 0, SDL_ALPHA_OPAQUE };

      clr.r = std::sin(freq * i + 0) * 127 + 128;
      clr.g = std::sin(freq * i + 2) * 127 + 128;
      clr.b = std::sin(freq * i + 4) * 127 + 128;

      if (i++ >= -1U)
      {
        i = 0;
      }

      _engine.renderer().setDrawColor(clr);
    }

    void quit() override
    {
      _engine.renderer().setDrawColor(_backupClr);
    }

    SGE::KeyboardEventKeeper::ConstShared getKeyboardEventKeeper()
    {
      return _keyboard_ekeeper;
    }

    SGE::MouseEventKeeper::ConstShared getMouseEventKeeper()
    {
      return _mouse_ekeeper;
    }

   private:
    SGE::Engine & _engine;

    SDL_Color _backupClr;

    SGE::KeyboardEventKeeper::Shared _keyboard_ekeeper;
    SGE::MouseEventKeeper::Shared _mouse_ekeeper;
  };
}

int main(int argc, char * argv[])
{
  SGE::Config cfg("config.file");

  SGE::Engine engine(SGE::CfgScreen{ cfg });

  engine.init();

  engine.window().set_title("SDL_GameEngine");

  auto mainScene = std::make_shared< TestScene >(engine);
  engine.setScene(mainScene);

  engine.run();

  engine.quit();
}