#include "SGE/config/config.hpp"

#include <fstream>

namespace
{
  std::string trim(const std::string & str)
  {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos)
    {
      return "";
    }
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(start, end - start + 1);
  }
}

SGE::Config::Config(const std::string & cf_pwd):
  data_(Config::loadFile(cf_pwd))
{}

const SGE::Config::cfg_t & SGE::Config::getConfig() const
{
  return this->data_;
}

// Static function
SGE::Config::cfg_t SGE::Config::loadFile(const std::string & cf_pwd)
{
  auto file = std::ifstream(cf_pwd);

  if (!file.is_open())
  {
    throw std::logic_error("[Config] Bad file");
  }

  cfg_t data{};

  while (file && !file.eof())
  {
    char letter = 0;
    std::string key{}, value{};
    while (file && !file.eof() && (letter = file.get()) != '=')
    {
      key += letter;
    }
    while (file && !file.eof() && (letter = file.get()) != '\n')
    {
      value += letter;
    }

    if (!key.empty() && !value.empty())
    {
      data.insert({ trim(key), trim(value) });
    }
  }

  file.close();

  return data;
}
