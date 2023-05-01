/* --- Generated the 30/3/2023 at 20:45 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 6 13:40:44 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s valet_parking -hepts Logic.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logic_types.h"

Logic__st Logic__st_of_string(char* s) {
  if ((strcmp(s, "St_Stop")==0)) {
    return Logic__St_Stop;
  };
  if ((strcmp(s, "St_Line_follow")==0)) {
    return Logic__St_Line_follow;
  };
  if ((strcmp(s, "St_Back")==0)) {
    return Logic__St_Back;
  };
}

char* string_of_Logic__st(Logic__st x, char* buf) {
  switch (x) {
    case Logic__St_Stop:
      strcpy(buf, "St_Stop");
      break;
    case Logic__St_Line_follow:
      strcpy(buf, "St_Line_follow");
      break;
    case Logic__St_Back:
      strcpy(buf, "St_Back");
      break;
    default:
      break;
  };
  return buf;
}

