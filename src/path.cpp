#include <iostream>
#include <string>
#include "separator.h"
#include "parse_args.h"



int main(int argc, char const *argv[])
{
  
  parsed_args x = ParseArgs(argc, argv);
  char sep = DetectSeparator(x.sys);
  std::cout << x.path << std::endl;
  std::cout << x.sys << std::endl;
  std::cout << x.rel << std::endl;
  std::cout << sep << std::endl;

  return 0;
}
