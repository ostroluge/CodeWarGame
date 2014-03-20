
#include <stdlib.h>
#include <stdio.h>
#include "codewar.h"
void jcc(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->C == 0) {
	switch(typeSource) {
		case 0 : 
			/* JCC Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JCC -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* JCC (Rn) */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* JCC (Rn)+ */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JCC #x */
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}

void jcs(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->C == 1) {
	switch(typeSource) {
		case 0 : 
			/* JCS Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JCS -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* JCS (Rn) */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* JCS (Rn)+ */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JCS #x */
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jeq(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->Z == 1) {
	switch(typeSource) {
		case 0 : 
			/* JEQ Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JEQ -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* JEQ (Rn) */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* JEQ (Rn)+ */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JEQ #x */
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jne(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->Z == 0) {
	switch(typeSource) {
		case 0 : 
			/* JNE Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JNE -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* JNE (Rn) */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* JNE (Rn)+ */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JNE #x */
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jlt(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->C == 1) {
	switch(typeSource) {
		case 0 : 
			/* JLT Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JLT -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* JLT (Rn) */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* JLT (Rn)+ */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JLT #x */
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jle(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if((c->C == 1) | (c->Z=1)) {
	switch(typeSource) {
		case 0 : 
			/* JLE Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JLE -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* JLE (Rn) */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* JLE (Rn)+ */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JLE #x */
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jgt(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->C == 0) {
	switch(typeSource) {
		case 0 : 
			/* JGT Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JGT -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* JGT (Rn) */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* JGT (Rn)+ */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JGT #x */
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jge(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if((c->C == 0) | (c->Z == 1)) {
	switch(typeSource) {
		case 0 : 
			/* JGE Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JGE -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* JGE (Rn) */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* JGE (Rn)+ */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JGE #x */
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jmp(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	switch(typeSource) {
		case 0 : 
			/* JMP Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JMP -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* JMP (Rn) */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* JMP (Rn)+ */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JMP #x */
			c -> Registres[6] = valSource;			
	
		break;
		
	}
}

void jsr(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
uint16_t PCpushed = 6;
push(c,&PCpushed);
	switch(typeSource) {
		case 0 : 
			/* JSR Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JSR -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* JSR (Rn) */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* JSR (Rn)+ */
			c -> Registres[6] = c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JSR #x */
			c -> Registres[6] = valSource;			
	
		break;
		
	}
}
