#include <iostream>
#include <string>
#include "args.h"
#include "path.h"



int main(int argc, char const *argv[])
{
  
  parsed_args x = ParseArgs(argc, argv);
  std::string path = ParsePath(x);
  std::cout << path << std::endl;
  
}
