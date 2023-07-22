#include <iostream>
#include <SDL3/SDL.h>
#include "SGE/engine.hpp"

namespace
{
  class TestScene final: public SGE::Scene
  {
   public:
    TestScene(SGE::Engine & engine):
      _engine(engine),
      _backupClr{ 0, 0, 0, 0 }
    {}
    ~TestScene()
    {
      this->quit();
    }

    void load() override
    {
      _backupClr = _engine.renderer().getDrawColor();
      _engine.renderer().setDrawColor(255, 220, 80, SDL_ALPHA_OPAQUE);
    }

    void mloop() override
    {}

    void quit() override
    {
      _engine.renderer().setDrawColor(_backupClr);
    }

   private:
    SGE::Engine & _engine;

    SDL_Color _backupClr;
  };
}

int main(int argc, char * argv[])
{
  SGE::Config cfg("config.file");
  auto cfgScreen = std::make_shared< SGE::CfgScreen >(cfg);

  SGE::Engine engine(cfgScreen);

  engine.init();

  engine.window().set_title("SDL_GameEngine");

  auto mainScene = std::make_shared< TestScene >(engine);
  engine.setScene(mainScene);

  engine.run();

  engine.quit();
}