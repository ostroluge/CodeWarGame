#include <stdlib.h>
#include <stdio.h>
#include "codewar.h"
#include <time.h>
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
struct cpu *adresse_vers_cpu(struct cpu *c,uint16_t adresse) {
  uint16_t x,y,x_cpu,y_cpu,x_final,y_final;
  int i,j;
  x = adresse & 0xF000;
  y = adresse & 0x0F00;
  /* Comment trouver l'adresse du CPU courant */ 
  for(i = 0 ; i < 16 ; i ++) {
    for(j = 0 ; j < 16 ; j ++) {
      if(c == &(plateau[i][j])) {
	x_cpu = i;
	y_cpu = j;
      }
    }
  }
  x_final = x+x_cpu;
  y_final = y+y_cpu;
  if(x_final >= 16) {
    x_final = x_final - 16;
  } else if(x_final <= 0) {
    x_final = x_final + 16;
  }
  if(y_final >= 16) {
    y_final = y_final - 16;
      } else if(y_final <= 0) {
    y_final = y_final -16;
  }
 
  return &(plateau[x_final][y_final]);
}
uint16_t cpu_vers_adresse(struct cpu *c, uint16_t adresse) {
    return adresse & 0xFF;
}

void init_plateau(){
  int i,j;
  for(i = 0 ; i < 16 ; i ++) {
    for(j = 0 ; j < 16 ; j ++) {
      plateau[i][j].Registres[PC] = 0x10;
      plateau[i][j].RAM[0xD] = 0;
	plateau[i][j].RAM[0x10] = 0x10;
	plateau[i][j].RAM[0x11] = 0xD4;
    }
  }
}

struct cpu *selectionCPU(){
int color,x,y;
struct cpu *c;
printf("Entrez votre coordonnées X souhaitez (decimale : entre 0 et 15) : \n");
scanf("%d",&x);
printf("Entrez votre coordonnées Y souhaitez (decimale : entre 0 et 15) :\n");
scanf("%d",&y);
c =  &(plateau[x][y]);
printf("Entrez la valeur de votre couleur (décimale : entre 0 et 32767) :\n");
scanf("%d", &color);
c->RAM[1] = color;
return c;
}
void afficherCPUSelected(struct cpu *c){
  int i,j,x,y;
  for(i = 0 ; i < 16 ; i ++) {
    for(j = 0 ; j < 16 ; j ++) {
	if(c == &(plateau[i][j])) {
		x=i;
		y=j;
		}
	}
}
printf("Votre CPU est initilisé au coordonnées : (%d,%d)\n",x,y);
}
int getCouleur(struct cpu *c) {
return c->RAM[1];
}
