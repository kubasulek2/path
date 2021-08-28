#include <iostream>
#include <filesystem>
#include <string>
#include "parse_args.h"
#include "parse_path.h"



int main(int argc, char const *argv[])
{
  
  parsed_args x = ParseArgs(argc, argv);
  std::string path = std::filesystem::current_path();
  path = ReplaceSeperator(path, x.sys);
  std::cout << path << std::endl;
  return 0;
}
