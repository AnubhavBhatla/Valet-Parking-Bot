/* --- Generated the 11/4/2023 at 22:16 --- */
/* --- heptagon compiler, version 1.05.00 (compiled sat. jan. 7 11:25:6 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c Logic.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logic_types.h"

Logic__st_1 Logic__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_Stop_final")==0)) {
    return Logic__St_1_Stop_final;
  };
  if ((strcmp(s, "St_1_Stop")==0)) {
    return Logic__St_1_Stop;
  };
  if ((strcmp(s, "St_1_Reverse")==0)) {
    return Logic__St_1_Reverse;
  };
  if ((strcmp(s, "St_1_Parking")==0)) {
    return Logic__St_1_Parking;
  };
  if ((strcmp(s, "St_1_Obstacle_follow")==0)) {
    return Logic__St_1_Obstacle_follow;
  };
  if ((strcmp(s, "St_1_Line_follow_b")==0)) {
    return Logic__St_1_Line_follow_b;
  };
  if ((strcmp(s, "St_1_Line_follow")==0)) {
    return Logic__St_1_Line_follow;
  };
  if ((strcmp(s, "St_1_Back_b")==0)) {
    return Logic__St_1_Back_b;
  };
  if ((strcmp(s, "St_1_Back")==0)) {
    return Logic__St_1_Back;
  };
}

char* string_of_Logic__st_1(Logic__st_1 x, char* buf) {
  switch (x) {
    case Logic__St_1_Stop_final:
      strcpy(buf, "St_1_Stop_final");
      break;
    case Logic__St_1_Stop:
      strcpy(buf, "St_1_Stop");
      break;
    case Logic__St_1_Reverse:
      strcpy(buf, "St_1_Reverse");
      break;
    case Logic__St_1_Parking:
      strcpy(buf, "St_1_Parking");
      break;
    case Logic__St_1_Obstacle_follow:
      strcpy(buf, "St_1_Obstacle_follow");
      break;
    case Logic__St_1_Line_follow_b:
      strcpy(buf, "St_1_Line_follow_b");
      break;
    case Logic__St_1_Line_follow:
      strcpy(buf, "St_1_Line_follow");
      break;
    case Logic__St_1_Back_b:
      strcpy(buf, "St_1_Back_b");
      break;
    case Logic__St_1_Back:
      strcpy(buf, "St_1_Back");
      break;
    default:
      break;
  };
  return buf;
}

Logic__st Logic__st_of_string(char* s) {
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

