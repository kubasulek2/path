#include <iostream>
#include <string>
#include <cstring>
#include "parse_args.h"

void ErrMsgAndExit()
{
  std::cout << "Incorrect format. Use: path [-s (u|w)] path/to/translate" << std::endl;
  exit(1);
}

args ParseArgs(int argc, char const *argv[])
{
  args a;

  // Valid args number is 1 or 3.
  if (argc != 4 && argc != 2)
  {
    std::cout << argc << std::endl;
    ErrMsgAndExit();
  }

  // One arg only no flag specified, set sys to default.
  if (argc == 2)
  {
    std::cout << "2 args" << std::endl;
    a.path = argv[1];
    a.sys = 2;
    return a;
  }

  // Find flag
  int flag_pos = 0;
  for (size_t i = 1; i < argc - 1; i++)
  {
    // std::cout << argv[i] << std::endl;
    // std::cout << i << std::endl;
    if (std::string(argv[i]) == "-s")
      flag_pos = i;
  }

  // Flag not found
  if (!flag_pos)
  {
    std::cout << "No flag pos" << std::endl;
    ErrMsgAndExit();
  }

  // This is not a flag value
  if (strlen(argv[flag_pos + 1]) != 1)
  {
    std::cout << "Wrong flag value length" << std::endl;
    ErrMsgAndExit();
  }

  // Find the path arg. Can be either first or thrird
  a.path = std::string(argv[flag_pos == 1 ? 3 : 1]);

  // normalize the flag value
  char flag_val = tolower(argv[flag_pos + 1][0]);

  // find out requested OS
  switch (flag_val)
  {
  case 'u':
    a.sys = 0;
    break;
  case 'w':
    a.sys = 1;
    break;
  default:
    std::cout << "default" << std::endl;
    ErrMsgAndExit();
  }

  return a;
};