#ifndef SGE_INITIALIZER_HPP
#define SGE_INITIALIZER_HPP

namespace SGE
{
  /**
   * \brief Abstart class of initializers
   */
  class Initializer
  {
   public:
    virtual ~Initializer();

    /**
     * \brief NON-ZERO returns = error
     * \return -1 = already initialized
     * 0 = good
     */
    int init();
    void quit();

   protected:
    Initializer();

    virtual int do_init() = 0;
    virtual void do_quit() = 0;

   private:
    bool is_initialized; ///< Used to avoid reinitialization
  };
}

#endif
