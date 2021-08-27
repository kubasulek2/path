#include <string>
struct args
{
  std::string path;
  /** 0 for Unix, 1 for Windows, 2 for default (current OS)  */
  unsigned short sys;
};

args ParseArgs(int argc, char const *argv[]);
