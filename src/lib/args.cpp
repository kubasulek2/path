#include <iostream>
#include <string>
#include <cstring>
#include "args.h"
#include "sys.h"

#define FLAGS_LEN 2

struct flag
{
  char const *name;
  bool has_val;
  unsigned short id;
};

void ErrMsgAndExit()
{
  std::cout << "Incorrect format. Use: path [-s <u|w> [-r <relative/to>]] <path/to/translate>" << std::endl;
  exit(1);
}

void InitFlags(flag (&f)[FLAGS_LEN])
{
  f[0].has_val = true;
  f[0].name = "-s";
  f[0].id = 1;

  f[1].name = "-r";
  f[1].has_val = true;
  f[1].id = 2;
}

flag *FindFlag(const char *arg, flag *f)
{
  for (size_t i = 0; i < FLAGS_LEN; i++)
    if (strcmp(f[i].name, arg) == 0)
      return &f[i];
  return NULL;
}

parsed_args ParseArgs(int argc, char const *argv[])
{
  parsed_args a;
  flag flags[FLAGS_LEN];

  /* Initialization */
  InitFlags(flags);
  
  a.rel = "";
  // Path must be last argument
  a.path = argv[argc - 1];
  // Default system, may be overritten later
  a.sys = DetectSys();

  // Valid args number from 2 to 6.
  if (argc < 2 || argc > 6)
    ErrMsgAndExit();


  // Find flags
  for (size_t i = 1; i < argc - 1; i++)
  {
    flag *r = FindFlag(argv[i], flags);

    if (r == NULL)
      ErrMsgAndExit();

    // Dereference pointer, for easier operations
    flag f = *r;

    // flag has_val: next arg is the value
    if (f.has_val && ++i >= argc)
      ErrMsgAndExit();

    // val is either a flag or next arg
    // copy argv[i] to val
    char val[strlen(argv[i])];
    strcpy(val, argv[i]);

    switch (f.id)
    {
      /* sys flag */
    case 1:
      if (strcmp(val, "u") == 0)
        a.sys = 0;
      else if (strcmp(val, "w") == 0)
        a.sys = 1;
      else
        ErrMsgAndExit();
      break;

    /* rel flag */
    case 2:
      a.rel = val;
      break;
    }
  }
  return a;
};
