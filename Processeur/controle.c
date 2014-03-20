#include <stdlib.h>
#include <stdio.h>
#include "codewar.h"
void rts(struct cpu *c) {
  uint16_t instPop = 7;
  pop(c,&instPop);
}
void rte(struct cpu *c) {
  uint16_t instPop = 7;
  pop(c,&instPop);
  c->Z = c->RAM[c->Registres[7]];
  c->Registres[7] += 2;
  c->N = c->RAM[c->Registres[7]];
  c->Registres[7] += 2;
  c->C = c->RAM[c->Registres[7]];
}
void trap(struct cpu *c, uint16_t *inst) {

}
void illegalInst(struct cpu *c) {
  /* Branchement de PC à @3 */
  c->Registres[PC] = c->RAM[3];  
}

