/* --- Generated the 11/4/2023 at 22:16 --- */
/* --- heptagon compiler, version 1.05.00 (compiled sat. jan. 7 11:25:6 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c Logic.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "logic.h"

void Logic__pid_reset(Logic__pid_mem* self) {
  self->kd_2 = 1;
  self->ki_2 = 1;
  self->kp_2 = 10;
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
  v_1 = (v-d);
  error = (v_1-e);
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
  self->kd_2 = kd;
  self->ki_2 = ki;
  self->kp_2 = kp;
  self->v_6 = error;
  self->v_5 = false;
  self->v_3 = integral;
  self->v_2 = false;;
}

void Logic__valet_parking_reset(Logic__valet_parking_mem* self) {
  Logic__pid_reset(&self->pid_1);
  Logic__pid_reset(&self->pid);
  self->v_71 = false;
  self->v_70 = Logic__St_Left_turn;
  self->back_1 = 0;
  self->initialize_1 = false;
  self->count_1 = 0;
  self->pnr_1 = false;
  self->ck = Logic__St_1_Stop;
}

void Logic__valet_parking_step(int ll, int lc, int cc, int rc, int rr,
                               int proxr, int proxc, int irbr, int irbl,
                               Logic__valet_parking_out* _out,
                               Logic__valet_parking_mem* self) {
  Logic__pid_out Logic__pid_out_st;
  
  int v_27;
  Logic__st_1 v_26;
  int v_25;
  int v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_20;
  int v_19;
  int v_18;
  int v_17;
  int v_16;
  int v_15;
  int v;
  int v_43;
  Logic__st_1 v_42;
  int v_41;
  int v_40;
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  int v_35;
  int v_34;
  int v_33;
  int v_32;
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int r_1_St_1_Stop_final;
  Logic__st_1 s_1_St_1_Stop_final;
  int r_1_St_1_Reverse;
  Logic__st_1 s_1_St_1_Reverse;
  int r_1_St_1_Parking;
  Logic__st_1 s_1_St_1_Parking;
  int r_1_St_1_Line_follow_b;
  Logic__st_1 s_1_St_1_Line_follow_b;
  int r_1_St_1_Back_b;
  Logic__st_1 s_1_St_1_Back_b;
  int r_1_St_1_Back;
  Logic__st_1 s_1_St_1_Back;
  int r_1_St_1_Obstacle_follow;
  Logic__st_1 s_1_St_1_Obstacle_follow;
  int r_1_St_1_Line_follow;
  Logic__st_1 s_1_St_1_Line_follow;
  int r_1_St_1_Stop;
  Logic__st_1 s_1_St_1_Stop;
  int v_44;
  int v_64;
  int v_63;
  int v_62;
  int v_61;
  int v_60;
  int v_59;
  int v_58;
  int v_57;
  int v_56;
  int v_55;
  int v_54;
  int v_53;
  int v_52;
  int v_51;
  int v_50;
  int v_49;
  int v_48;
  int v_47;
  int v_46;
  int v_45;
  int r_2;
  int v_65;
  int v_66;
  int v_69;
  int v_68;
  int nr_St_Right_turn;
  Logic__st ns_St_Right_turn;
  int right_speed_St_1_Obstacle_follow_St_Right_turn;
  int left_speed_St_1_Obstacle_follow_St_Right_turn;
  int nr_St_Forward;
  Logic__st ns_St_Forward;
  int right_speed_St_1_Obstacle_follow_St_Forward;
  int left_speed_St_1_Obstacle_follow_St_Forward;
  int nr_St_Left_turn;
  Logic__st ns_St_Left_turn;
  int right_speed_St_1_Obstacle_follow_St_Left_turn;
  int left_speed_St_1_Obstacle_follow_St_Left_turn;
  Logic__st ck_2;
  int v_67;
  Logic__st ns;
  int r;
  int nr;
  int pnr;
  int v_83;
  int v_82;
  int v_81;
  int v_80;
  int v_79;
  int v_78;
  int v_77;
  int v_76;
  int v_75;
  int v_74;
  int v_73;
  int v_72;
  int r_3;
  int v_86;
  Logic__st_1 v_85;
  int v_84;
  int nr_1_St_1_Stop_final;
  Logic__st_1 ns_1_St_1_Stop_final;
  int pid_out_St_1_Stop_final;
  int back_St_1_Stop_final;
  int initialize_St_1_Stop_final;
  int count_St_1_Stop_final;
  int right_speed_St_1_Stop_final;
  int left_speed_St_1_Stop_final;
  int nr_1_St_1_Reverse;
  Logic__st_1 ns_1_St_1_Reverse;
  int pid_out_St_1_Reverse;
  int back_St_1_Reverse;
  int initialize_St_1_Reverse;
  int count_St_1_Reverse;
  int right_speed_St_1_Reverse;
  int left_speed_St_1_Reverse;
  int nr_1_St_1_Parking;
  Logic__st_1 ns_1_St_1_Parking;
  int pid_out_St_1_Parking;
  int back_St_1_Parking;
  int initialize_St_1_Parking;
  int count_St_1_Parking;
  int right_speed_St_1_Parking;
  int left_speed_St_1_Parking;
  int nr_1_St_1_Line_follow_b;
  Logic__st_1 ns_1_St_1_Line_follow_b;
  int pid_out_St_1_Line_follow_b;
  int back_St_1_Line_follow_b;
  int initialize_St_1_Line_follow_b;
  int count_St_1_Line_follow_b;
  int right_speed_St_1_Line_follow_b;
  int left_speed_St_1_Line_follow_b;
  int nr_1_St_1_Back_b;
  Logic__st_1 ns_1_St_1_Back_b;
  int pid_out_St_1_Back_b;
  int back_St_1_Back_b;
  int initialize_St_1_Back_b;
  int count_St_1_Back_b;
  int right_speed_St_1_Back_b;
  int left_speed_St_1_Back_b;
  int nr_1_St_1_Back;
  Logic__st_1 ns_1_St_1_Back;
  int pid_out_St_1_Back;
  int back_St_1_Back;
  int initialize_St_1_Back;
  int count_St_1_Back;
  int right_speed_St_1_Back;
  int left_speed_St_1_Back;
  int nr_1_St_1_Obstacle_follow;
  Logic__st_1 ns_1_St_1_Obstacle_follow;
  int pid_out_St_1_Obstacle_follow;
  int back_St_1_Obstacle_follow;
  int initialize_St_1_Obstacle_follow;
  int count_St_1_Obstacle_follow;
  int right_speed_St_1_Obstacle_follow;
  int left_speed_St_1_Obstacle_follow;
  int nr_1_St_1_Line_follow;
  Logic__st_1 ns_1_St_1_Line_follow;
  int pid_out_St_1_Line_follow;
  int back_St_1_Line_follow;
  int initialize_St_1_Line_follow;
  int count_St_1_Line_follow;
  int right_speed_St_1_Line_follow;
  int left_speed_St_1_Line_follow;
  int nr_1_St_1_Stop;
  Logic__st_1 ns_1_St_1_Stop;
  int pid_out_St_1_Stop;
  int back_St_1_Stop;
  int initialize_St_1_Stop;
  int count_St_1_Stop;
  int right_speed_St_1_Stop;
  int left_speed_St_1_Stop;
  Logic__st_1 ck_1;
  Logic__st_1 s_1;
  Logic__st_1 ns_1;
  int r_1;
  int nr_1;
  int count;
  int initialize;
  int back;
  int pid_out;
  switch (self->ck) {
    case Logic__St_1_Stop:
      r_1_St_1_Stop = self->pnr_1;
      s_1_St_1_Stop = Logic__St_1_Stop;
      s_1 = s_1_St_1_Stop;
      r_1 = r_1_St_1_Stop;
      break;
    case Logic__St_1_Line_follow:
      v_40 = (cc<500);
      v_38 = (rr>900);
      v_37 = (ll>900);
      v_39 = (v_37&&v_38);
      v_41 = (v_39&&v_40);
      if (v_41) {
        v_43 = true;
        v_42 = Logic__St_1_Line_follow_b;
      } else {
        v_43 = self->pnr_1;
        v_42 = Logic__St_1_Line_follow;
      };
      v_35 = (rr<500);
      v_33 = (rc<500);
      v_31 = (cc<500);
      v_29 = (lc<500);
      v_28 = (ll<500);
      v_30 = (v_28&&v_29);
      v_32 = (v_30&&v_31);
      v_34 = (v_32&&v_33);
      v_36 = (v_34&&v_35);
      if (v_36) {
        r_1_St_1_Line_follow = true;
        s_1_St_1_Line_follow = Logic__St_1_Back;
      } else {
        r_1_St_1_Line_follow = v_43;
        s_1_St_1_Line_follow = v_42;
      };
      s_1 = s_1_St_1_Line_follow;
      r_1 = r_1_St_1_Line_follow;
      break;
    case Logic__St_1_Obstacle_follow:
      r_1_St_1_Obstacle_follow = self->pnr_1;
      s_1_St_1_Obstacle_follow = Logic__St_1_Obstacle_follow;
      s_1 = s_1_St_1_Obstacle_follow;
      r_1 = r_1_St_1_Obstacle_follow;
      break;
    case Logic__St_1_Back:
      r_1_St_1_Back = self->pnr_1;
      s_1_St_1_Back = Logic__St_1_Back;
      s_1 = s_1_St_1_Back;
      r_1 = r_1_St_1_Back;
      break;
    case Logic__St_1_Back_b:
      r_1_St_1_Back_b = self->pnr_1;
      s_1_St_1_Back_b = Logic__St_1_Back_b;
      s_1 = s_1_St_1_Back_b;
      r_1 = r_1_St_1_Back_b;
      break;
    case Logic__St_1_Line_follow_b:
      v_24 = (rr>900);
      v_22 = (rc>900);
      v_20 = (cc>900);
      v_18 = (lc>900);
      v_17 = (ll>900);
      v_19 = (v_17&&v_18);
      v_21 = (v_19&&v_20);
      v_23 = (v_21&&v_22);
      v_25 = (v_23&&v_24);
      if (v_25) {
        v_27 = true;
        v_26 = Logic__St_1_Back_b;
      } else {
        v_27 = self->pnr_1;
        v_26 = Logic__St_1_Line_follow_b;
      };
      v_15 = (self->count_1>100);
      v = !(irbr);
      v_16 = (v&&v_15);
      if (v_16) {
        r_1_St_1_Line_follow_b = true;
        s_1_St_1_Line_follow_b = Logic__St_1_Parking;
      } else {
        r_1_St_1_Line_follow_b = v_27;
        s_1_St_1_Line_follow_b = v_26;
      };
      s_1 = s_1_St_1_Line_follow_b;
      r_1 = r_1_St_1_Line_follow_b;
      break;
    case Logic__St_1_Parking:
      r_1_St_1_Parking = self->pnr_1;
      s_1_St_1_Parking = Logic__St_1_Parking;
      s_1 = s_1_St_1_Parking;
      r_1 = r_1_St_1_Parking;
      break;
    case Logic__St_1_Reverse:
      r_1_St_1_Reverse = self->pnr_1;
      s_1_St_1_Reverse = Logic__St_1_Reverse;
      s_1 = s_1_St_1_Reverse;
      r_1 = r_1_St_1_Reverse;
      break;
    case Logic__St_1_Stop_final:
      r_1_St_1_Stop_final = self->pnr_1;
      s_1_St_1_Stop_final = Logic__St_1_Stop_final;
      s_1 = s_1_St_1_Stop_final;
      r_1 = r_1_St_1_Stop_final;
      break;
    default:
      break;
  };
  ck_1 = s_1;
  switch (ck_1) {
    case Logic__St_1_Stop:
      pid_out_St_1_Stop = self->pid_out_1;
      back_St_1_Stop = self->back_1;
      initialize_St_1_Stop = self->initialize_1;
      count_St_1_Stop = self->count_1;
      right_speed_St_1_Stop = 0;
      left_speed_St_1_Stop = 0;
      if (proxc) {
        v_86 = true;
        v_85 = Logic__St_1_Obstacle_follow;
      } else {
        v_86 = false;
        v_85 = Logic__St_1_Stop;
      };
      v_84 = (cc>900);
      if (v_84) {
        nr_1_St_1_Stop = true;
        ns_1_St_1_Stop = Logic__St_1_Line_follow;
      } else {
        nr_1_St_1_Stop = v_86;
        ns_1_St_1_Stop = v_85;
      };
      initialize = initialize_St_1_Stop;
      count = count_St_1_Stop;
      back = back_St_1_Stop;
      pid_out = pid_out_St_1_Stop;
      ns_1 = ns_1_St_1_Stop;
      nr_1 = nr_1_St_1_Stop;
      _out->left_speed = left_speed_St_1_Stop;
      _out->right_speed = right_speed_St_1_Stop;
      break;
    case Logic__St_1_Line_follow:
      back_St_1_Line_follow = self->back_1;
      initialize_St_1_Line_follow = self->initialize_1;
      count_St_1_Line_follow = self->count_1;
      if (proxc) {
        nr_1_St_1_Line_follow = true;
        ns_1_St_1_Line_follow = Logic__St_1_Obstacle_follow;
      } else {
        nr_1_St_1_Line_follow = false;
        ns_1_St_1_Line_follow = Logic__St_1_Line_follow;
      };
      r_3 = r_1;
      if (r_3) {
        Logic__pid_reset(&self->pid_1);
      };
      Logic__pid_step(ll, lc, cc, rc, rr, &Logic__pid_out_st, &self->pid_1);
      pid_out_St_1_Line_follow = Logic__pid_out_st.out;
      initialize = initialize_St_1_Line_follow;
      count = count_St_1_Line_follow;
      back = back_St_1_Line_follow;
      pid_out = pid_out_St_1_Line_follow;
      v_82 = (pid_out>50);
      if (v_82) {
        v_83 = 100;
      } else {
        v_83 = 0;
      };
      v_81 = (50+pid_out);
      v_79 = (pid_out>-50);
      v_78 = (pid_out<50);
      v_80 = (v_78&&v_79);
      if (v_80) {
        right_speed_St_1_Line_follow = v_81;
      } else {
        right_speed_St_1_Line_follow = v_83;
      };
      v_76 = (pid_out>50);
      if (v_76) {
        v_77 = 0;
      } else {
        v_77 = 100;
      };
      v_75 = (50-pid_out);
      v_73 = (pid_out>-50);
      v_72 = (pid_out<50);
      v_74 = (v_72&&v_73);
      if (v_74) {
        left_speed_St_1_Line_follow = v_75;
      } else {
        left_speed_St_1_Line_follow = v_77;
      };
      ns_1 = ns_1_St_1_Line_follow;
      nr_1 = nr_1_St_1_Line_follow;
      _out->left_speed = left_speed_St_1_Line_follow;
      _out->right_speed = right_speed_St_1_Line_follow;
      break;
    case Logic__St_1_Obstacle_follow:
      pid_out_St_1_Obstacle_follow = self->pid_out_1;
      back_St_1_Obstacle_follow = self->back_1;
      initialize_St_1_Obstacle_follow = self->initialize_1;
      count_St_1_Obstacle_follow = self->count_1;
      if (r_1) {
        pnr = false;
      } else {
        pnr = self->v_71;
      };
      r = pnr;
      if (r_1) {
        ck_2 = Logic__St_Left_turn;
      } else {
        ck_2 = self->v_70;
      };
      v_67 = (cc>900);
      if (v_67) {
        nr_1_St_1_Obstacle_follow = true;
        ns_1_St_1_Obstacle_follow = Logic__St_1_Line_follow;
      } else {
        nr_1_St_1_Obstacle_follow = false;
        ns_1_St_1_Obstacle_follow = Logic__St_1_Obstacle_follow;
      };
      initialize = initialize_St_1_Obstacle_follow;
      count = count_St_1_Obstacle_follow;
      back = back_St_1_Obstacle_follow;
      pid_out = pid_out_St_1_Obstacle_follow;
      ns_1 = ns_1_St_1_Obstacle_follow;
      nr_1 = nr_1_St_1_Obstacle_follow;
      switch (ck_2) {
        case Logic__St_Left_turn:
          right_speed_St_1_Obstacle_follow_St_Left_turn = 83;
          left_speed_St_1_Obstacle_follow_St_Left_turn = -83;
          if (proxr) {
            nr_St_Left_turn = true;
            ns_St_Left_turn = Logic__St_Forward;
          } else {
            nr_St_Left_turn = false;
            ns_St_Left_turn = Logic__St_Left_turn;
          };
          left_speed_St_1_Obstacle_follow = left_speed_St_1_Obstacle_follow_St_Left_turn;
          right_speed_St_1_Obstacle_follow = right_speed_St_1_Obstacle_follow_St_Left_turn;
          ns = ns_St_Left_turn;
          nr = nr_St_Left_turn;
          break;
        case Logic__St_Forward:
          right_speed_St_1_Obstacle_follow_St_Forward = 80;
          left_speed_St_1_Obstacle_follow_St_Forward = 80;
          v_68 = (proxc||proxr);
          v_69 = !(v_68);
          if (v_69) {
            nr_St_Forward = true;
            ns_St_Forward = Logic__St_Left_turn;
          } else {
            nr_St_Forward = false;
            ns_St_Forward = Logic__St_Forward;
          };
          left_speed_St_1_Obstacle_follow = left_speed_St_1_Obstacle_follow_St_Forward;
          right_speed_St_1_Obstacle_follow = right_speed_St_1_Obstacle_follow_St_Forward;
          ns = ns_St_Forward;
          nr = nr_St_Forward;
          break;
        case Logic__St_Right_turn:
          right_speed_St_1_Obstacle_follow_St_Right_turn = -83;
          left_speed_St_1_Obstacle_follow_St_Right_turn = 83;
          if (proxr) {
            nr_St_Right_turn = true;
            ns_St_Right_turn = Logic__St_Forward;
          } else {
            nr_St_Right_turn = false;
            ns_St_Right_turn = Logic__St_Right_turn;
          };
          left_speed_St_1_Obstacle_follow = left_speed_St_1_Obstacle_follow_St_Right_turn;
          right_speed_St_1_Obstacle_follow = right_speed_St_1_Obstacle_follow_St_Right_turn;
          ns = ns_St_Right_turn;
          nr = nr_St_Right_turn;
          break;
        default:
          break;
      };
      _out->left_speed = left_speed_St_1_Obstacle_follow;
      _out->right_speed = right_speed_St_1_Obstacle_follow;
      self->v_71 = nr;
      self->v_70 = ns;
      break;
    case Logic__St_1_Back:
      pid_out_St_1_Back = self->pid_out_1;
      back_St_1_Back = self->back_1;
      initialize_St_1_Back = self->initialize_1;
      count_St_1_Back = self->count_1;
      right_speed_St_1_Back = -98;
      left_speed_St_1_Back = -98;
      v_66 = (cc>900);
      if (v_66) {
        nr_1_St_1_Back = true;
        ns_1_St_1_Back = Logic__St_1_Line_follow;
      } else {
        nr_1_St_1_Back = false;
        ns_1_St_1_Back = Logic__St_1_Back;
      };
      initialize = initialize_St_1_Back;
      count = count_St_1_Back;
      back = back_St_1_Back;
      pid_out = pid_out_St_1_Back;
      ns_1 = ns_1_St_1_Back;
      nr_1 = nr_1_St_1_Back;
      _out->left_speed = left_speed_St_1_Back;
      _out->right_speed = right_speed_St_1_Back;
      break;
    case Logic__St_1_Back_b:
      pid_out_St_1_Back_b = self->pid_out_1;
      back_St_1_Back_b = self->back_1;
      initialize_St_1_Back_b = self->initialize_1;
      count_St_1_Back_b = self->count_1;
      right_speed_St_1_Back_b = -98;
      left_speed_St_1_Back_b = -98;
      v_65 = (cc<500);
      if (v_65) {
        nr_1_St_1_Back_b = true;
        ns_1_St_1_Back_b = Logic__St_1_Line_follow_b;
      } else {
        nr_1_St_1_Back_b = false;
        ns_1_St_1_Back_b = Logic__St_1_Back_b;
      };
      initialize = initialize_St_1_Back_b;
      count = count_St_1_Back_b;
      back = back_St_1_Back_b;
      pid_out = pid_out_St_1_Back_b;
      ns_1 = ns_1_St_1_Back_b;
      nr_1 = nr_1_St_1_Back_b;
      _out->left_speed = left_speed_St_1_Back_b;
      _out->right_speed = right_speed_St_1_Back_b;
      break;
    case Logic__St_1_Line_follow_b:
      back_St_1_Line_follow_b = self->back_1;
      v_64 = (self->count_1+1);
      v_62 = (self->initialize_1||irbr);
      if (v_62) {
        initialize_St_1_Line_follow_b = true;
      } else {
        initialize_St_1_Line_follow_b = false;
      };
      v_49 = (1000-rr);
      v_48 = (1000-rc);
      v_47 = (1000-cc);
      v_46 = (1000-lc);
      v_45 = (1000-ll);
      nr_1_St_1_Line_follow_b = false;
      ns_1_St_1_Line_follow_b = Logic__St_1_Line_follow_b;
      r_2 = r_1;
      if (r_2) {
        Logic__pid_reset(&self->pid);
      };
      Logic__pid_step(v_45, v_46, v_47, v_48, v_49, &Logic__pid_out_st,
                      &self->pid);
      pid_out_St_1_Line_follow_b = Logic__pid_out_st.out;
      initialize = initialize_St_1_Line_follow_b;
      v_63 = (initialize&&irbr);
      if (v_63) {
        count_St_1_Line_follow_b = v_64;
      } else {
        count_St_1_Line_follow_b = 0;
      };
      count = count_St_1_Line_follow_b;
      back = back_St_1_Line_follow_b;
      pid_out = pid_out_St_1_Line_follow_b;
      v_60 = (pid_out>50);
      if (v_60) {
        v_61 = 100;
      } else {
        v_61 = 0;
      };
      v_59 = (50+pid_out);
      v_57 = (pid_out>-50);
      v_56 = (pid_out<50);
      v_58 = (v_56&&v_57);
      if (v_58) {
        right_speed_St_1_Line_follow_b = v_59;
      } else {
        right_speed_St_1_Line_follow_b = v_61;
      };
      v_54 = (pid_out>50);
      if (v_54) {
        v_55 = 0;
      } else {
        v_55 = 100;
      };
      v_53 = (50-pid_out);
      v_51 = (pid_out>-50);
      v_50 = (pid_out<50);
      v_52 = (v_50&&v_51);
      if (v_52) {
        left_speed_St_1_Line_follow_b = v_53;
      } else {
        left_speed_St_1_Line_follow_b = v_55;
      };
      ns_1 = ns_1_St_1_Line_follow_b;
      nr_1 = nr_1_St_1_Line_follow_b;
      _out->left_speed = left_speed_St_1_Line_follow_b;
      _out->right_speed = right_speed_St_1_Line_follow_b;
      break;
    case Logic__St_1_Parking:
      pid_out_St_1_Parking = self->pid_out_1;
      back_St_1_Parking = self->back_1;
      initialize_St_1_Parking = self->initialize_1;
      count_St_1_Parking = self->count_1;
      right_speed_St_1_Parking = -45;
      left_speed_St_1_Parking = -99;
      if (irbl) {
        nr_1_St_1_Parking = true;
        ns_1_St_1_Parking = Logic__St_1_Reverse;
      } else {
        nr_1_St_1_Parking = false;
        ns_1_St_1_Parking = Logic__St_1_Parking;
      };
      initialize = initialize_St_1_Parking;
      count = count_St_1_Parking;
      back = back_St_1_Parking;
      pid_out = pid_out_St_1_Parking;
      ns_1 = ns_1_St_1_Parking;
      nr_1 = nr_1_St_1_Parking;
      _out->left_speed = left_speed_St_1_Parking;
      _out->right_speed = right_speed_St_1_Parking;
      break;
    case Logic__St_1_Reverse:
      pid_out_St_1_Reverse = self->pid_out_1;
      initialize_St_1_Reverse = self->initialize_1;
      count_St_1_Reverse = self->count_1;
      back_St_1_Reverse = (self->back_1+1);
      right_speed_St_1_Reverse = -50;
      left_speed_St_1_Reverse = -50;
      initialize = initialize_St_1_Reverse;
      count = count_St_1_Reverse;
      back = back_St_1_Reverse;
      v_44 = (back>10);
      if (v_44) {
        nr_1_St_1_Reverse = true;
        ns_1_St_1_Reverse = Logic__St_1_Stop_final;
      } else {
        nr_1_St_1_Reverse = false;
        ns_1_St_1_Reverse = Logic__St_1_Reverse;
      };
      pid_out = pid_out_St_1_Reverse;
      ns_1 = ns_1_St_1_Reverse;
      nr_1 = nr_1_St_1_Reverse;
      _out->left_speed = left_speed_St_1_Reverse;
      _out->right_speed = right_speed_St_1_Reverse;
      break;
    case Logic__St_1_Stop_final:
      pid_out_St_1_Stop_final = self->pid_out_1;
      back_St_1_Stop_final = self->back_1;
      initialize_St_1_Stop_final = self->initialize_1;
      count_St_1_Stop_final = self->count_1;
      right_speed_St_1_Stop_final = 0;
      left_speed_St_1_Stop_final = 0;
      nr_1_St_1_Stop_final = false;
      ns_1_St_1_Stop_final = Logic__St_1_Stop_final;
      initialize = initialize_St_1_Stop_final;
      count = count_St_1_Stop_final;
      back = back_St_1_Stop_final;
      pid_out = pid_out_St_1_Stop_final;
      ns_1 = ns_1_St_1_Stop_final;
      nr_1 = nr_1_St_1_Stop_final;
      _out->left_speed = left_speed_St_1_Stop_final;
      _out->right_speed = right_speed_St_1_Stop_final;
      break;
    default:
      break;
  };
  self->pid_out_1 = pid_out;
  self->back_1 = back;
  self->initialize_1 = initialize;
  self->count_1 = count;
  self->pnr_1 = nr_1;
  self->ck = ns_1;;
}

