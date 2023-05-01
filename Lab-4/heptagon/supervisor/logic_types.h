/* --- Generated the 14/3/2023 at 0:56 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 6 13:40:44 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s logic -hepts Logic.ept --- */

#ifndef LOGIC_TYPES_H
#define LOGIC_TYPES_H

#include "stdbool.h"
#include "assert.h"
//#include "pervasives.h"
typedef enum {
  Logic__St_Start,
  Logic__St_Right_turn,
  Logic__St_Left_turn,
  Logic__St_Forward
} Logic__st;

Logic__st Logic__st_of_string(char* s);

char* string_of_Logic__st(Logic__st x, char* buf);

#endif // LOGIC_TYPES_H
