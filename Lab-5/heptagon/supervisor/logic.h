/* --- Generated the 30/3/2023 at 20:45 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 6 13:40:44 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s valet_parking -hepts Logic.ept --- */

#ifndef LOGIC_H
#define LOGIC_H

#include "logic_types.h"
typedef struct Logic__pid_mem {
  int v_6;
  int v_5;
  int v_3;
  int v_2;
  int kd_1;
  int ki_1;
  int kp_1;
} Logic__pid_mem;

typedef struct Logic__pid_out {
  int out;
} Logic__pid_out;

void Logic__pid_reset(Logic__pid_mem* self);

void Logic__pid_step(int a, int b, int c, int d, int e, Logic__pid_out* _out,
                     Logic__pid_mem* self);

typedef struct Logic__valet_parking_mem {
  Logic__st ck;
  int pnr;
  int pid_out_1;
  Logic__pid_mem pid;
} Logic__valet_parking_mem;

typedef struct Logic__valet_parking_out {
  int left_speed;
  int right_speed;
  int dir;
} Logic__valet_parking_out;

void Logic__valet_parking_reset(Logic__valet_parking_mem* self);

void Logic__valet_parking_step(int ll, int lc, int cc, int rc, int rr,
                               int irl, int irc, int irr,
                               Logic__valet_parking_out* _out,
                               Logic__valet_parking_mem* self);

#endif // LOGIC_H
