/* --- Generated the 14/3/2023 at 0:56 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 6 13:40:44 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s logic -hepts Logic.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logic.h"

void Logic__logic_reset(Logic__logic_mem* self) {
  self->v_22 = true;
  self->v_1 = true;
  self->left_1 = false;
  self->start_1 = false;
  self->forwardrl2_1 = false;
  self->forwardrl1_1 = false;
  self->dist_1 = 1;
  self->pnr = false;
  self->ck = Logic__St_Start;
}

void Logic__logic_step(int proxc, int proxl, Logic__logic_out* _out,
                       Logic__logic_mem* self) {
  
  int v_4;
  int v_2;
  int v;
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  Logic__st v_9;
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v_25;
  int v_23;
  int v_21;
  int v_20;
  Logic__st v_19;
  int v_18;
  int v_17;
  int v_16;
  int v_15;
  int nr_St_Left_turn;
  Logic__st ns_St_Left_turn;
  int left_St_Left_turn;
  int start_St_Left_turn;
  int forwardrl2_St_Left_turn;
  int forwardrl1_St_Left_turn;
  int dist_St_Left_turn;
  int time_step_St_Left_turn;
  int right_speed_St_Left_turn;
  int left_speed_St_Left_turn;
  int nr_St_Forward;
  Logic__st ns_St_Forward;
  int left_St_Forward;
  int start_St_Forward;
  int forwardrl2_St_Forward;
  int forwardrl1_St_Forward;
  int dist_St_Forward;
  int time_step_St_Forward;
  int right_speed_St_Forward;
  int left_speed_St_Forward;
  int nr_St_Right_turn;
  Logic__st ns_St_Right_turn;
  int left_St_Right_turn;
  int start_St_Right_turn;
  int forwardrl2_St_Right_turn;
  int forwardrl1_St_Right_turn;
  int dist_St_Right_turn;
  int time_step_St_Right_turn;
  int right_speed_St_Right_turn;
  int left_speed_St_Right_turn;
  int nr_St_Start;
  Logic__st ns_St_Start;
  int left_St_Start;
  int start_St_Start;
  int forwardrl2_St_Start;
  int forwardrl1_St_Start;
  int dist_St_Start;
  int time_step_St_Start;
  int right_speed_St_Start;
  int left_speed_St_Start;
  Logic__st ns;
  int r;
  int nr;
  int time_step;
  int dist;
  int forwardrl1;
  int forwardrl2;
  int start;
  int left;
  r = self->pnr;
  switch (self->ck) {
    case Logic__St_Start:
      left_St_Start = self->left_1;
      forwardrl2_St_Start = self->forwardrl2_1;
      forwardrl1_St_Start = self->forwardrl1_1;
      dist_St_Start = self->dist_1;
      start_St_Start = true;
      right_speed_St_Start = 40;
      left_speed_St_Start = 40;
      time_step_St_Start = 0;
      if (proxc) {
        nr_St_Start = true;
        ns_St_Start = Logic__St_Right_turn;
      } else {
        nr_St_Start = false;
        ns_St_Start = Logic__St_Start;
      };
      _out->left_speed = left_speed_St_Start;
      _out->right_speed = right_speed_St_Start;
      time_step = time_step_St_Start;
      forwardrl1 = forwardrl1_St_Start;
      forwardrl2 = forwardrl2_St_Start;
      dist = dist_St_Start;
      start = start_St_Start;
      left = left_St_Start;
      ns = ns_St_Start;
      nr = nr_St_Start;
      break;
    case Logic__St_Right_turn:
      left_St_Right_turn = self->left_1;
      start_St_Right_turn = self->start_1;
      forwardrl2_St_Right_turn = self->forwardrl2_1;
      dist_St_Right_turn = self->dist_1;
      v_25 = (self->v_24+1);
      if (self->v_22) {
        v_23 = true;
      } else {
        v_23 = r;
      };
      if (v_23) {
        time_step_St_Right_turn = 0;
      } else {
        time_step_St_Right_turn = v_25;
      };
      right_speed_St_Right_turn = -43;
      left_speed_St_Right_turn = 43;
      v_21 = (self->start_1&&self->left_1);
      forwardrl1_St_Right_turn = !(v_21);
      _out->left_speed = left_speed_St_Right_turn;
      _out->right_speed = right_speed_St_Right_turn;
      time_step = time_step_St_Right_turn;
      v_17 = (time_step>=13);
      v_18 = (v_17&&self->forwardrl2_1);
      if (v_18) {
        v_20 = true;
        v_19 = Logic__St_Start;
      } else {
        v_20 = false;
        v_19 = Logic__St_Right_turn;
      };
      v_15 = (time_step>=13);
      forwardrl1 = forwardrl1_St_Right_turn;
      v_16 = (v_15&&forwardrl1);
      if (v_16) {
        nr_St_Right_turn = true;
        ns_St_Right_turn = Logic__St_Forward;
      } else {
        nr_St_Right_turn = v_20;
        ns_St_Right_turn = v_19;
      };
      forwardrl2 = forwardrl2_St_Right_turn;
      dist = dist_St_Right_turn;
      start = start_St_Right_turn;
      left = left_St_Right_turn;
      ns = ns_St_Right_turn;
      nr = nr_St_Right_turn;
      self->v_24 = time_step;
      self->v_22 = false;
      break;
    case Logic__St_Forward:
      left_St_Forward = self->left_1;
      start_St_Forward = self->start_1;
      forwardrl2_St_Forward = self->forwardrl2_1;
      v_13 = (self->dist_1-1);
      v_12 = (self->dist_1+3);
      right_speed_St_Forward = 40;
      left_speed_St_Forward = 40;
      v_11 = (self->start_1&&self->left_1);
      forwardrl1_St_Forward = !(v_11);
      time_step_St_Forward = 0;
      v_5 = (proxc||proxl);
      v_6 = !(v_5);
      _out->left_speed = left_speed_St_Forward;
      _out->right_speed = right_speed_St_Forward;
      time_step = time_step_St_Forward;
      forwardrl1 = forwardrl1_St_Forward;
      forwardrl2 = forwardrl2_St_Forward;
      if (forwardrl2) {
        v_14 = v_13;
      } else {
        v_14 = self->dist_1;
      };
      if (forwardrl1) {
        dist_St_Forward = v_12;
      } else {
        dist_St_Forward = v_14;
      };
      dist = dist_St_Forward;
      v_7 = (dist<=1);
      v_8 = (v_7&&self->forwardrl2_1);
      if (v_8) {
        v_10 = true;
      } else {
        v_10 = false;
      };
      if (v_6) {
        nr_St_Forward = true;
      } else {
        nr_St_Forward = v_10;
      };
      if (v_8) {
        v_9 = Logic__St_Right_turn;
      } else {
        v_9 = Logic__St_Forward;
      };
      if (v_6) {
        ns_St_Forward = Logic__St_Left_turn;
      } else {
        ns_St_Forward = v_9;
      };
      start = start_St_Forward;
      left = left_St_Forward;
      ns = ns_St_Forward;
      nr = nr_St_Forward;
      break;
    case Logic__St_Left_turn:
      start_St_Left_turn = self->start_1;
      forwardrl1_St_Left_turn = self->forwardrl1_1;
      dist_St_Left_turn = self->dist_1;
      v_4 = (self->v_3+1);
      if (self->v_1) {
        v_2 = true;
      } else {
        v_2 = r;
      };
      if (v_2) {
        time_step_St_Left_turn = 0;
      } else {
        time_step_St_Left_turn = v_4;
      };
      right_speed_St_Left_turn = 36;
      left_speed_St_Left_turn = -38;
      forwardrl2_St_Left_turn = !(self->forwardrl1_1);
      left_St_Left_turn = true;
      _out->left_speed = left_speed_St_Left_turn;
      _out->right_speed = right_speed_St_Left_turn;
      time_step = time_step_St_Left_turn;
      v = (time_step>=4);
      if (v) {
        nr_St_Left_turn = true;
        ns_St_Left_turn = Logic__St_Forward;
      } else {
        nr_St_Left_turn = false;
        ns_St_Left_turn = Logic__St_Left_turn;
      };
      forwardrl1 = forwardrl1_St_Left_turn;
      forwardrl2 = forwardrl2_St_Left_turn;
      dist = dist_St_Left_turn;
      start = start_St_Left_turn;
      left = left_St_Left_turn;
      ns = ns_St_Left_turn;
      nr = nr_St_Left_turn;
      self->v_3 = time_step;
      self->v_1 = false;
      break;
    default:
      break;
  };
  self->left_1 = left;
  self->start_1 = start;
  self->forwardrl2_1 = forwardrl2;
  self->forwardrl1_1 = forwardrl1;
  self->dist_1 = dist;
  self->pnr = nr;
  self->ck = ns;;
}
