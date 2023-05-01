/* --- Generated the 30/3/2023 at 20:45 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 6 13:40:44 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s valet_parking -hepts Logic.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logic.h"

void Logic__pid_reset(Logic__pid_mem* self) {
  self->kd_1 = 1;
  self->ki_1 = 1;
  self->kp_1 = 10;
  self->v_5 = true;
  self->v_2 = true;
}

void Logic__pid_step(int a, int b, int c, int d, int e, Logic__pid_out* _out,
                     Logic__pid_mem* self) {
  
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  int v_9;
  int v_8;
  int v_7;
  int v_4;
  int v_1;
  int v;
  int kp;
  int ki;
  int kd;
  int derivative;
  int integral;
  int error;
  kd = 1;
  ki = 1;
  kp = 10;
  v = (a+b);
  v_1 = (v-d*1.2);
  error = (v_1-e*1.2);
  v_8 = (kp*error);
  v_9 = (v_8/400);
  v_7 = (error-self->v_6);
  if (self->v_5) {
    derivative = error;
  } else {
    derivative = v_7;
  };
  v_13 = (kd*derivative);
  v_14 = (v_13/100);
  v_4 = (self->v_3+error);
  if (self->v_2) {
    integral = error;
  } else {
    integral = v_4;
  };
  v_10 = (ki*integral);
  v_11 = (v_10/100000);
  v_12 = (v_9+v_11);
  _out->out = (v_12+v_14);
  self->kd_1 = kd;
  self->ki_1 = ki;
  self->kp_1 = kp;
  self->v_6 = error;
  self->v_5 = false;
  self->v_3 = integral;
  self->v_2 = false;;
}

void Logic__valet_parking_reset(Logic__valet_parking_mem* self) {
  Logic__pid_reset(&self->pid);
  self->pnr = false;
  self->ck = Logic__St_Stop;
}

void Logic__valet_parking_step(int ll, int lc, int cc, int rc, int rr,
                               int irl, int irc, int irr,
                               Logic__valet_parking_out* _out,
                               Logic__valet_parking_mem* self) {
  Logic__pid_out Logic__pid_out_st;
  
  int v_22;
  int v_21;
  int v_20;
  int v_19;
  int v_18;
  int v_17;
  int v_16;
  int v_15;
  int v;
  int r_St_Back;
  Logic__st s_St_Back;
  int r_St_Line_follow;
  Logic__st s_St_Line_follow;
  int r_St_Stop;
  Logic__st s_St_Stop;
  int v_23;
  int v_35;
  int v_34;
  int v_33;
  int v_32;
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int v_27;
  int v_26;
  int v_25;
  int v_24;
  int r_1;
  int v_36;
  int nr_St_Back;
  Logic__st ns_St_Back;
  int pid_out_St_Back;
  int dir_St_Back;
  int right_speed_St_Back;
  int left_speed_St_Back;
  int nr_St_Line_follow;
  Logic__st ns_St_Line_follow;
  int pid_out_St_Line_follow;
  int dir_St_Line_follow;
  int right_speed_St_Line_follow;
  int left_speed_St_Line_follow;
  int nr_St_Stop;
  Logic__st ns_St_Stop;
  int pid_out_St_Stop;
  int dir_St_Stop;
  int right_speed_St_Stop;
  int left_speed_St_Stop;
  Logic__st ck_1;
  Logic__st s;
  Logic__st ns;
  int r;
  int nr;
  int pid_out;
  switch (self->ck) {
    case Logic__St_Stop:
      r_St_Stop = self->pnr;
      s_St_Stop = Logic__St_Stop;
      s = s_St_Stop;
      r = r_St_Stop;
      break;
    case Logic__St_Line_follow:
      v_21 = (rr<350);
      v_19 = (rc<350);
      v_17 = (cc<350);
      v_15 = (lc<350);
      v = (ll<500);
      v_16 = (v&&v_15);
      v_18 = (v_16&&v_17);
      v_20 = (v_18&&v_19);
      v_22 = (v_20&&v_21);
      if (v_22) {
        r_St_Line_follow = true;
        s_St_Line_follow = Logic__St_Back;
      } else {
        r_St_Line_follow = self->pnr;
        s_St_Line_follow = Logic__St_Line_follow;
      };
      s = s_St_Line_follow;
      r = r_St_Line_follow;
      break;
    case Logic__St_Back:
      r_St_Back = self->pnr;
      s_St_Back = Logic__St_Back;
      s = s_St_Back;
      r = r_St_Back;
      break;
    default:
      break;
  };
  ck_1 = s;
  switch (ck_1) {
    case Logic__St_Stop:
      pid_out_St_Stop = self->pid_out_1;
      right_speed_St_Stop = 0;
      left_speed_St_Stop = 0;
      dir_St_Stop = 0;
      v_36 = (cc>900);
      if (v_36) {
        nr_St_Stop = true;
        ns_St_Stop = Logic__St_Line_follow;
      } else {
        nr_St_Stop = false;
        ns_St_Stop = Logic__St_Stop;
      };
      _out->dir = dir_St_Stop;
      pid_out = pid_out_St_Stop;
      _out->left_speed = left_speed_St_Stop;
      _out->right_speed = right_speed_St_Stop;
      ns = ns_St_Stop;
      nr = nr_St_Stop;
      break;
    case Logic__St_Line_follow:
      dir_St_Line_follow = 1;
      nr_St_Line_follow = false;
      ns_St_Line_follow = Logic__St_Line_follow;
      r_1 = r;
      if (r_1) {
        Logic__pid_reset(&self->pid);
      };
      Logic__pid_step(ll, lc, cc, rc, rr, &Logic__pid_out_st, &self->pid);
      pid_out_St_Line_follow = Logic__pid_out_st.out;
      _out->dir = dir_St_Line_follow;
      pid_out = pid_out_St_Line_follow;
      v_34 = (pid_out>50);
      if (v_34) {
        v_35 = 100;
      } else {
        v_35 = 0;
      };
      v_33 = (50+pid_out);
      v_31 = (pid_out>-50);
      v_30 = (pid_out<50);
      v_32 = (v_30&&v_31);
      if (v_32) {
        right_speed_St_Line_follow = v_33;
      } else {
        right_speed_St_Line_follow = v_35;
      };
      v_28 = (pid_out>50);
      if (v_28) {
        v_29 = 0;
      } else {
        v_29 = 100;
      };
      v_27 = (50-pid_out);
      v_25 = (pid_out>-50);
      v_24 = (pid_out<50);
      v_26 = (v_24&&v_25);
      if (v_26) {
        left_speed_St_Line_follow = v_27;
      } else {
        left_speed_St_Line_follow = v_29;
      };
      _out->left_speed = left_speed_St_Line_follow;
      _out->right_speed = right_speed_St_Line_follow;
      ns = ns_St_Line_follow;
      nr = nr_St_Line_follow;
      break;
    case Logic__St_Back:
      pid_out_St_Back = self->pid_out_1;
      right_speed_St_Back = -98;
      left_speed_St_Back = -98;
      dir_St_Back = 5;
      v_23 = (cc>900);
      if (v_23) {
        nr_St_Back = true;
        ns_St_Back = Logic__St_Line_follow;
      } else {
        nr_St_Back = false;
        ns_St_Back = Logic__St_Back;
      };
      _out->dir = dir_St_Back;
      pid_out = pid_out_St_Back;
      _out->left_speed = left_speed_St_Back;
      _out->right_speed = right_speed_St_Back;
      ns = ns_St_Back;
      nr = nr_St_Back;
      break;
    default:
      break;
  };
  self->pid_out_1 = pid_out;
  self->pnr = nr;
  self->ck = ns;;
}
