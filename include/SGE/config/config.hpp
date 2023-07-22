#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iosfwd>
#include <string>
#include <map>

namespace SGE
{
  /**
   * \brief This config class
   * It parses file with cf_pwd path
   * \example Example of file:
   * HEIGHT=30
   * WIDTH = 30
   */
  class Config final
  {
   public:
    using cfg_t = std::map< std::string, std::string >;

    Config(const std::string & cf_pwd);
    ~Config() = default;

    const cfg_t & getConfig() const;

    /**
     * \brief Parse config from cf_pwd file
     * \param cf_pwd is path to config file
     */
    static cfg_t loadFile(const std::string & cf_pwd);

   private:
    cfg_t data_;
  };
}

#endif
