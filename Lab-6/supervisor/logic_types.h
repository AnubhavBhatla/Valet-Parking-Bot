/* --- Generated the 11/4/2023 at 22:16 --- */
/* --- heptagon compiler, version 1.05.00 (compiled sat. jan. 7 11:25:6 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c Logic.ept --- */

#ifndef LOGIC_TYPES_H
#define LOGIC_TYPES_H

#include "stdbool.h"
#include "assert.h"
typedef enum {
  Logic__St_1_Stop_final,
  Logic__St_1_Stop,
  Logic__St_1_Reverse,
  Logic__St_1_Parking,
  Logic__St_1_Obstacle_follow,
  Logic__St_1_Line_follow_b,
  Logic__St_1_Line_follow,
  Logic__St_1_Back_b,
  Logic__St_1_Back
} Logic__st_1;

Logic__st_1 Logic__st_1_of_string(char* s);

char* string_of_Logic__st_1(Logic__st_1 x, char* buf);

typedef enum {
  Logic__St_Right_turn,
  Logic__St_Left_turn,
  Logic__St_Forward
} Logic__st;

Logic__st Logic__st_of_string(char* s);

char* string_of_Logic__st(Logic__st x, char* buf);

#endif // LOGIC_TYPES_H
