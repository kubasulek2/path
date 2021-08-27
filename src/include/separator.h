#pragma once

/** 
 * Returns directory separator either for requested OS familly, or currently installed OS
 * @param sys either 0 for "Unix" or 1 for "Windows", can be ommited for OS default value
 * @returns separator character
*/
const char DetectSeparator(char sys = (char)2);