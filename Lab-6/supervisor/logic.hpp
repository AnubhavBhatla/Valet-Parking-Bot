extern "C" {
/* --- Generated the 11/4/2023 at 22:16 --- */
/* --- heptagon compiler, version 1.05.00 (compiled sat. jan. 7 11:25:6 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c Logic.ept --- */

#ifndef LOGIC_H
#define LOGIC_H

#include "logic_types.h"
typedef struct Logic__pid_mem {
  int v_6;
  int v_5;
  int v_3;
  int v_2;
  int kd_2;
  int ki_2;
  int kp_2;
} Logic__pid_mem;

typedef struct Logic__pid_out {
  int out;
} Logic__pid_out;

void Logic__pid_reset(Logic__pid_mem* self);

void Logic__pid_step(int a, int b, int c, int d, int e, Logic__pid_out* _out,
                     Logic__pid_mem* self);

typedef struct Logic__valet_parking_mem {
  Logic__st_1 ck;
  Logic__st v_70;
  int v_71;
  int pnr_1;
  int pid_out_1;
  int back_1;
  int initialize_1;
  int count_1;
  Logic__pid_mem pid;
  Logic__pid_mem pid_1;
} Logic__valet_parking_mem;

typedef struct Logic__valet_parking_out {
  int left_speed;
  int right_speed;
} Logic__valet_parking_out;

void Logic__valet_parking_reset(Logic__valet_parking_mem* self);

void Logic__valet_parking_step(int ll, int lc, int cc, int rc, int rr,
                               int proxr, int proxc, int irbr, int irbl,
                               Logic__valet_parking_out* _out,
                               Logic__valet_parking_mem* self);

#endif // LOGIC_H
}
