/* --- Generated the 14/3/2023 at 0:56 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 6 13:40:44 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s logic -hepts Logic.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logic_types.h"

Logic__st Logic__st_of_string(char* s) {
  if ((strcmp(s, "St_Start")==0)) {
    return Logic__St_Start;
  };
  if ((strcmp(s, "St_Right_turn")==0)) {
    return Logic__St_Right_turn;
  };
  if ((strcmp(s, "St_Left_turn")==0)) {
    return Logic__St_Left_turn;
  };
  if ((strcmp(s, "St_Forward")==0)) {
    return Logic__St_Forward;
  };
}

char* string_of_Logic__st(Logic__st x, char* buf) {
  switch (x) {
    case Logic__St_Start:
      strcpy(buf, "St_Start");
      break;
    case Logic__St_Right_turn:
      strcpy(buf, "St_Right_turn");
      break;
    case Logic__St_Left_turn:
      strcpy(buf, "St_Left_turn");
      break;
    case Logic__St_Forward:
      strcpy(buf, "St_Forward");
      break;
    default:
      break;
  };
  return buf;
}

