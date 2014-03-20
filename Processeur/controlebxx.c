
#include <stdlib.h>
#include <stdio.h>
#include "codewar.h"
void bcc(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->C == 0) {
	switch(typeSource) {
		case 0 : 
			/* BCC Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BCC -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* BCC (Rn) */
			c -> Registres[6] = c -> Registres[6] + c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* BCC (Rn)+ */
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BCC #x */
			c -> Registres[6] = c ->Registres[6] + valSource;			
	
		break;
		
		}
	}
}
void bcs(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->C == 1) {
	switch(typeSource) {
		case 0 : 
			/* BCS Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BCS -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* BCS (Rn) */
			c -> Registres[6] = c -> Registres[6] + c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* BCS (Rn)+ */
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BCS #x */
			c -> Registres[6] = c ->Registres[6] + valSource;			
	
		break;
		
		}
	}
}
void beq(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->Z == 1) {
	switch(typeSource) {
		case 0 : 
			/* BEQ Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BEQ -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* BEQ (Rn) */
			c -> Registres[6] = c -> Registres[6] + c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* BEQ (Rn)+ */
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BEQ #x */
			c -> Registres[6] = c ->Registres[6] + valSource;			
	
		break;
		
		}
	}
}
void bne(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->Z == 0) {
	switch(typeSource) {
		case 0 : 
			/* BNE Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BNE -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* BNE (Rn) */
			c -> Registres[6] = c -> Registres[6] + c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* BNE (Rn)+ */
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BNE #x */
			c -> Registres[6] = c ->Registres[6] + valSource;			
	
		break;
		
		}
	}
}
void blt(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->C == 1) {
	switch(typeSource) {
		case 0 : 
			/* BLT Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BLT -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* BLT (Rn) */
			c -> Registres[6] = c -> Registres[6] + c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* BLT (Rn)+ */
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BLT #x */
			c -> Registres[6] = c ->Registres[6] + valSource;			
	
		break;
		
		}
	}
}
void ble(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if((c->C == 1) | (c->Z == 1)) {
	switch(typeSource) {
		case 0 : 
			/* BLE Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BLE -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* BLE (Rn) */
			c -> Registres[6] = c -> Registres[6] + c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* BLE (Rn)+ */
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BLE #x */
			c -> Registres[6] = c ->Registres[6] + valSource;			
	
		break;
		
		}
	}
}
void bgt(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if(c->C == 0) {
	switch(typeSource) {
		case 0 : 
			/* BGT Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BGT -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* BGT (Rn) */
			c -> Registres[6] = c -> Registres[6] + c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* BGT (Rn)+ */
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BGT #x */
			c -> Registres[6] = c ->Registres[6] + valSource;			
	
		break;
		
		}
	}
}
void bge(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
if((c->C == 0) | (c->Z == 1)) {
	switch(typeSource) {
		case 0 : 
			/* BGE Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BGE -(Rn) */
			c -> Registres[valSource] -= 2; 
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
		break;

		case 2 : 
			/* BGE (Rn) */
			c -> Registres[6] = c -> Registres[6] + c->RAM[c->Registres[valSource]];
		break;
	
		case 3 : /* BGE (Rn)+ */
			c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BGE #x */
			c -> Registres[6] = c ->Registres[6] + valSource;			
	
		break;
		
		}
	}
}
void bra(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
switch(typeSource) {
	case 0 : 
		/* BRA Rn */
		c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
	break;
	
	case 1 : /* BRA -(Rn) */	
		c -> Registres[valSource] -= 2; 
		c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
	break;

	case 2 : 
		/* BRA (Rn) */
		c -> Registres[6] = c -> Registres[6] + c->RAM[c->Registres[valSource]];
	break;
	
	case 3 : /* BRA (Rn)+ */
		c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
		c -> Registres[valSource] += 2; 
	break;
		
	case 4 : /* BRA #x */
		c -> Registres[6] = c ->Registres[6] + valSource;			

	break;	
	}
}
void bsr(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
uint16_t PCpushed = 6;
push(c,&PCpushed);
switch(typeSource) {
	case 0 : 
		/* BSR Rn */
		c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
	break;
	
	case 1 : /* BSR -(Rn) */	
		c -> Registres[valSource] -= 2;
		c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
	break;

	case 2 : 
		/* BSR (Rn) */
		
		c -> Registres[6] = c -> Registres[6] + c->RAM[c->Registres[valSource]];
	break;
	
	case 3 : /* BSR (Rn)+ */
		c -> Registres[6] = c ->Registres[6] + c->RAM[c->Registres[valSource]];
		c -> Registres[valSource] += 2; 
	break;
		
	case 4 : /* BSR #x */
		c -> Registres[6] = c ->Registres[6] + valSource;			

	break;	
	}
}
