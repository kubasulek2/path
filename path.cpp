#include <iostream>
#include <string>
#include "separator.h"
#include "parse_args.h"



int main(int argc, char const *argv[])
{
  args x = ParseArgs(argc, argv);
  std::cout << x.path << std::endl;
  std::cout << x.sys << std::endl;

  return 0;
}
