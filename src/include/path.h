#include <string>
#include "args.h"

#ifndef __path_h
#define __path_h

/** 
 * Takes path string, and replace directory separators specific to desired OS
 * @param path path string
 * @param sys desired OS, 0 for Unix, 1 for Windows
*/
std::string ReplaceSeperator(std::string path, unsigned short sys);

/** 
 * Takes arguments of the program and returns absolute path
 * @param arg parsed program args
 * @return absolute path
*/
std::string ParsePath(parsed_args arg);

#endif