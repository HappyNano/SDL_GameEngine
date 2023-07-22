#ifndef SGE_SCENE_HPP
#define SGE_SCENE_HPP

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

    protected:
      Scene() = default;
  };
}

#endif
