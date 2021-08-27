#include <string>
struct parsed_args
{
  std::string path;
  std::string rel;
  /** 0 for Unix, 1 for Windows, 2 for default (current OS)  */
  unsigned short sys;
};

parsed_args ParseArgs(int argc, char const *argv[]);
