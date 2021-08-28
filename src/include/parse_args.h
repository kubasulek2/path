#include <string>
struct parsed_args
{
  std::string path;
  std::string rel;
  /** 0 for Unix, 1 for Windows  */
  unsigned short sys;
};

/** 
 * Parses and format program arguments
 * @param argc program arguments length
 * @param argv program arguments
 * @returns parsed_args
*/
parsed_args ParseArgs(int argc, char const *argv[]);
