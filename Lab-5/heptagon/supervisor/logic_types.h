/* --- Generated the 30/3/2023 at 20:45 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 6 13:40:44 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s valet_parking -hepts Logic.ept --- */

#ifndef LOGIC_TYPES_H
#define LOGIC_TYPES_H

#include "stdbool.h"
#include "assert.h"
//#include "pervasives.h"
typedef enum {
  Logic__St_Stop,
  Logic__St_Line_follow,
  Logic__St_Back
} Logic__st;

Logic__st Logic__st_of_string(char* s);

char* string_of_Logic__st(Logic__st x, char* buf);

#endif // LOGIC_TYPES_H
