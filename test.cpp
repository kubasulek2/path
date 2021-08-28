#include <vector>
#include <iostream>
#include <filesystem>
#include <string>
#include <regex>

std::vector<std::string> TokenizePath(std::string path)
{
  std::regex sep_re("\\\\|/");
  std::regex hidden_rel_re("^([^\\\\/\\.])");
  std::smatch m;
  std::vector<std::string> res;

  path = std::regex_replace(path, hidden_rel_re, "./$1");

  while (std::regex_search(path, m, sep_re))
  {
    int pos = m.position();
    res.push_back(path.substr(0, pos));
    path = path.substr(pos + 1);
  }



  if (res[0] == (std::string) ".")
  {
    std::vector<std::string> base = TokenizePath((std::string)std::filesystem::current_path());
    base.insert(base.end(), (res.begin() + 1), res.end());
    return base;
  }

  return res;
}

int main()
{
  std::string path = "home/kuba/projekty/system-programing/path/test.cpp";
  std::vector<std::string> res = TokenizePath(path);
  for (std::vector<std::string>::iterator i = res.begin(); i != res.end(); ++i)
    std::cout << *i << ' ';
  std::cout << std::endl;
  return 0;
}
