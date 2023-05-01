extern "C" {
/* --- Generated the 13/3/2023 at 18:40 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. jan. 6 13:40:44 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s logic -hepts Logic.ept --- */

#ifndef LOGIC_H
#define LOGIC_H

#include "logic_types.h"
typedef struct Logic__logic_mem {
  Logic__st ck;
  int v_3;
  int v_1;
  int v_24;
  int v_22;
  int pnr;
  int left_1;
  int start_1;
  int forwardrl2_1;
  int forwardrl1_1;
  int dist_1;
} Logic__logic_mem;

typedef struct Logic__logic_out {
  int left_speed;
  int right_speed;
} Logic__logic_out;

void Logic__logic_reset(Logic__logic_mem* self);

void Logic__logic_step(int proxc, int proxl, Logic__logic_out* _out,
                       Logic__logic_mem* self);

#endif // LOGIC_H
}
