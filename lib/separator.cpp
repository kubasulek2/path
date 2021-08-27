#include <cctype>
#include "separator.h"


/* DEFINE */
#ifdef _WIN32
#define DEF_SEP '\\'
#else
#define DEF_SEP '/'
#endif


const char DetectSeparator(char sys)
{
  sys = tolower(sys);

  switch (sys)
  {
  case 0:
    return '/';
  case 1:
    return '\\';
  default:
    return DEF_SEP;
  }
}