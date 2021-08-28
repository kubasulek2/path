#include <string>

/** 
 * Takes path string, and replace directory separators specific to desired OS
 * @param path path string
 * @param sys desired OS, 0 for Unix, 1 for Windows
*/
std::string ReplaceSeperator(std::string path, unsigned short sys);