#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <regex>

std::string ReplaceSeperator(std::string path, unsigned short sys)
{
  std::regex sep_re("\\\\|/");
  return std::regex_replace(path, sep_re, (sys ? "\\" : "/"));
}

std::vector<std::string> TokenizePath(std::string path)
{
  // matches both separators
  std::regex sep_re("\\\\|/");
  // finds paths that are relative but starts without "./"
  std::regex hidden_rel_re("^([^\\\\/\\.])");
  std::smatch m;
  std::vector<std::string> res;

  // appends "./" when path is implicitly relative
  path = std::regex_replace(path, hidden_rel_re, "./$1");

  // split path string into vector of tokens
  while (std::regex_search(path, m, sep_re))
  {
    int pos = m.position();
    res.push_back(path.substr(0, pos));
    path = path.substr(pos + 1);
  }

  // when first token points to current dir, prepend path to current
  if (res[0] == (std::string) ".")
  {
    std::vector<std::string> base = TokenizePath((std::string)std::filesystem::current_path());
    res.insert((res.begin() + 1), base.begin(), base.end());
    res.erase(res.begin());
  }

  return res;
}

std::vector<std::string> ParseTokens(std::vector<std::string> tokens)
{
  // std::vector<std::string> res;
  // std::string token;
  // std::regex sep_re("\\\\|/");
  // std::smatch m;

  // while (std::regex_search(path, m, sep_re))
  // {
  //   int pos = m.position();
  //   token = path.substr(0, pos);
  //   res.push_back(token);
  // }
  // return res;
}

/* 
  you are: /projekty/system-programing/path
  rel: ../projekt2/../
  path ../system-programing
 */
