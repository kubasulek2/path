#include <cctype>
#include "detect_sys.h"

/* DEFINE */
#ifdef _WIN32
#define SYS 1
#else
#define SYS 0
#endif

unsigned DetectSys()
{
  return SYS;
}