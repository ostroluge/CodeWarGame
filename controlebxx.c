
#include <stdlib.h>
#include <stdio.h>
#include "codewar.h"
void bcc(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->C == 0) {
	switch(typeSource) {
		case 0 : 
			/* BCC Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BCC -(Rn) */
			c -> Registres[valSource] -= 2; 
			c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
			addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* BCC (Rn) */
			c_infected -> Registres[6] = c_infected -> Registres[6] + c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* BCC (Rn)+ */
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BCC #x */
			c_infected = adresse_vers_cpu(c,valSource);
			addr_infected = cpu_vers_adresse(c,valSource);
			c_infected -> Registres[6] = c_infected ->Registres[6] + addr_infected;			
	
		break;
		
		}
	}
}
void bcs(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->C == 1) {
	switch(typeSource) {
		case 0 : 
			/* BCS Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BCS -(Rn) */
			c -> Registres[valSource] -= 2; 
			c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
			addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* BCS (Rn) */
			c_infected -> Registres[6] = c_infected -> Registres[6] + c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* BCS (Rn)+ */
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BCS #x */
			c_infected = adresse_vers_cpu(c,valSource);
			addr_infected = cpu_vers_adresse(c,valSource);
			c_infected -> Registres[6] = c_infected ->Registres[6] + addr_infected;			
	
		break;
		
		}
	}
}
void beq(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->Z == 1) {
	switch(typeSource) {
		case 0 : 
			/* BEQ Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BEQ -(Rn) */
			c -> Registres[valSource] -= 2; 
			c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
			addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* BEQ (Rn) */
			c_infected -> Registres[6] = c_infected -> Registres[6] + c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* BEQ (Rn)+ */
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BEQ #x */
			c_infected = adresse_vers_cpu(c,valSource);
			addr_infected = cpu_vers_adresse(c,valSource);
			c_infected -> Registres[6] = c_infected ->Registres[6] + addr_infected;			
	
		break;
		
		}
	}
}
void bne(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->Z == 0) {
	switch(typeSource) {
		case 0 : 
			/* BNE Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BNE -(Rn) */
			c -> Registres[valSource] -= 2; 
			c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
			addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* BNE (Rn) */
			c_infected -> Registres[6] = c_infected -> Registres[6] + c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* BNE (Rn)+ */
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BNE #x */
			c_infected = adresse_vers_cpu(c,valSource);
			addr_infected = cpu_vers_adresse(c,valSource);
			c_infected -> Registres[6] = c_infected ->Registres[6] + addr_infected;			
	
		break;
		
		}
	}
}
void blt(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->C == 1) {
	switch(typeSource) {
		case 0 : 
			/* BLT Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BLT -(Rn) */
			c -> Registres[valSource] -= 2; 
			c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
			addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* BLT (Rn) */
			c_infected -> Registres[6] = c_infected -> Registres[6] + c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* BLT (Rn)+ */
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BLT #x */
			c_infected = adresse_vers_cpu(c,valSource);
			addr_infected = cpu_vers_adresse(c,valSource);
			c_infected -> Registres[6] = c_infected ->Registres[6] + addr_infected;			
	
		break;
		
		}
	}
}
void ble(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if((c->C == 1) | (c->Z == 1)) {
		switch(typeSource) {
		case 0 : 
			/* BLE Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BLE -(Rn) */
			c -> Registres[valSource] -= 2; 
			c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
			addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* BLE (Rn) */
			c_infected -> Registres[6] = c_infected -> Registres[6] + c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* BLE (Rn)+ */
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BLE #x */
			c_infected = adresse_vers_cpu(c,valSource);
			addr_infected = cpu_vers_adresse(c,valSource);
			c_infected -> Registres[6] = c_infected ->Registres[6] + addr_infected;			
	
		break;
		
		}
	}
}
void bgt(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->C == 0) {
	switch(typeSource) {
		case 0 : 
			/* BGT Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BGT -(Rn) */
			c -> Registres[valSource] -= 2; 
			c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
			addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* BGT (Rn) */
			c_infected -> Registres[6] = c_infected -> Registres[6] + c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* BGT (Rn)+ */
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BGT #x */
			c_infected = adresse_vers_cpu(c,valSource);
			addr_infected = cpu_vers_adresse(c,valSource);
			c_infected -> Registres[6] = c_infected ->Registres[6] + addr_infected;			
	
		break;
	}
}
}
void bge(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if((c->C == 0) | (c->Z == 1)) {
	switch(typeSource) {
		case 0 : 
			/* BGE Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BGE -(Rn) */
			c -> Registres[valSource] -= 2; 
			c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
			addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* BGE (Rn) */
			c_infected -> Registres[6] = c_infected -> Registres[6] + c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* BGE (Rn)+ */
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BGE #x */
			c_infected = adresse_vers_cpu(c,valSource);
			addr_infected = cpu_vers_adresse(c,valSource);
			c_infected -> Registres[6] = c_infected ->Registres[6] + addr_infected;			
	
		break;
	}
}
}
void bra(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
	switch(typeSource) {
		case 0 : 
			/* BRA Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BRA -(Rn) */
			c -> Registres[valSource] -= 2; 
			c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
			addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* BRA (Rn) */
			c_infected -> Registres[6] = c_infected -> Registres[6] + c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* BRA (Rn)+ */
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BRA #x */
			c_infected = adresse_vers_cpu(c,valSource);
			addr_infected = cpu_vers_adresse(c,valSource);
			c_infected -> Registres[6] = c_infected ->Registres[6] + addr_infected;			
	
		break;
}
}
void bsr(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
uint16_t PCpushed = 6;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if((typeSource == 1) | (typeSource == 2) | (typeSource == 3) | (typeSource == 4)) {
push(c_infected,&PCpushed);
} else {
push(c,&PCpushed);
}
	switch(typeSource) {
		case 0 : 
			/* BSR Rn */
			c -> Registres[6] = c -> Registres[6] + c->Registres[valSource];
		break;
	
		case 1 : /* BSR -(Rn) */
			c -> Registres[valSource] -= 2; 
			c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
			addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* BSR (Rn) */
			c_infected -> Registres[6] = c_infected -> Registres[6] + c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* BSR (Rn)+ */
			c_infected -> Registres[6] = c_infected ->Registres[6] + c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* BSR #x */
			c_infected = adresse_vers_cpu(c,valSource);
			addr_infected = cpu_vers_adresse(c,valSource);
			c_infected -> Registres[6] = c_infected ->Registres[6] + addr_infected;			
	
		break;
}
}
