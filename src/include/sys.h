#ifndef __sys_h
#define __sys_h

/** 
 * Returns directory separator either for current OS familly.
 * @returns 0 - for Unix, 1 - for Windows
*/
unsigned DetectSys();

#endif