#include <string>
#include <iostream>
#include <regex>

std::string ReplaceSeperator(std::string path, unsigned short sys)
{
  std::regex sep_re("\\\\|/");
  return std::regex_replace(path, sep_re, (sys ? "\\" : "/"));
}
