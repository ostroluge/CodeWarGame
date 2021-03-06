
#include <stdlib.h>
#include <stdio.h>
#include "codewar.h"
void jcc(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->C == 0) {
	switch(typeSource) {
		case 0 : 
			/* JCC Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JCC -(Rn) */
			c -> Registres[valSource] -= 2; 
		c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
		addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* JCC (Rn) */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* JCC (Rn)+ */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JCC #x */
		c_infected = adresse_vers_cpu(c,valSource);
		addr_infected = cpu_vers_adresse(c,valSource);
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}

void jcs(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->C == 1) {
	switch(typeSource) {
		case 0 : 
			/* JCS Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JCS -(Rn) */
			c -> Registres[valSource] -= 2; 
		c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
		addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* JCS (Rn) */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* JCS (Rn)+ */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JCS #x */
		c_infected = adresse_vers_cpu(c,valSource);
		addr_infected = cpu_vers_adresse(c,valSource);
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jeq(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->Z == 1) {
	switch(typeSource) {
		case 0 : 
			/* JCS Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JCS -(Rn) */
			c -> Registres[valSource] -= 2; 
		c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
		addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* JCS (Rn) */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* JCS (Rn)+ */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JCS #x */
		c_infected = adresse_vers_cpu(c,valSource);
		addr_infected = cpu_vers_adresse(c,valSource);
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jne(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->Z == 0) {
		switch(typeSource) {
		case 0 : 
			/* JCS Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* JCS -(Rn) */
			c -> Registres[valSource] -= 2; 
		c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
		addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* JCS (Rn) */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* JCS (Rn)+ */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* JCS #x */
		c_infected = adresse_vers_cpu(c,valSource);
		addr_infected = cpu_vers_adresse(c,valSource);
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jlt(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->C == 1) {
		switch(typeSource) {
		case 0 : 
			/* Jxx Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* Jxx -(Rn) */
			c -> Registres[valSource] -= 2; 
		c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
		addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* Jxx (Rn) */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* Jxx (Rn)+ */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* Jxx #x */
		c_infected = adresse_vers_cpu(c,valSource);
		addr_infected = cpu_vers_adresse(c,valSource);
			c -> Registres[6] = valSource;			
	
		break;
		
		}
}
}
void jle(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if((c->C == 1) | (c->Z=1)) {
		switch(typeSource) {
		case 0 : 
			/* Jxx Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* Jxx -(Rn) */
			c -> Registres[valSource] -= 2; 
		c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
		addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* Jxx (Rn) */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* Jxx (Rn)+ */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* Jxx #x */
		c_infected = adresse_vers_cpu(c,valSource);
		addr_infected = cpu_vers_adresse(c,valSource);
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jgt(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if(c->C == 0) {
		switch(typeSource) {
		case 0 : 
			/* Jxx Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* Jxx -(Rn) */
			c -> Registres[valSource] -= 2; 
		c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
		addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* Jxx (Rn) */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* Jxx (Rn)+ */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* Jxx #x */
		c_infected = adresse_vers_cpu(c,valSource);
		addr_infected = cpu_vers_adresse(c,valSource);
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jge(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
if((c->C == 0) | (c->Z == 1)) {
		switch(typeSource) {
		case 0 : 
			/* Jxx Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* Jxx -(Rn) */
			c -> Registres[valSource] -= 2; 
		c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
		addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* Jxx (Rn) */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* Jxx (Rn)+ */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* Jxx #x */
		c_infected = adresse_vers_cpu(c,valSource);
		addr_infected = cpu_vers_adresse(c,valSource);
			c -> Registres[6] = valSource;			
	
		break;
		
		}
	}
}
void jmp(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]); 
		switch(typeSource) {
		case 0 : 
			/* Jxx Rn */
			printf("JMP %d",c->Registres[valSource]);
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* Jxx -(Rn) */
			c -> Registres[valSource] -= 2; 
		c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
		addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			afficherCPUSelected(c_infected);
			printf("JMP %d",c_infected->RAM[addr_infected]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* Jxx (Rn) */
			afficherCPUSelected(c_infected);
			printf("JMP %d",c_infected->RAM[addr_infected]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* Jxx (Rn)+ */
			afficherCPUSelected(c_infected);
			printf("JMP %d",c_infected->RAM[addr_infected]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* Jxx #x */
			c -> Registres[6] = valSource;			
	
		break;
		
		}
}

void jsr(struct cpu *c, uint16_t *inst) {
uint16_t typeSource = (*inst >> 8) & 0x07;
uint16_t valSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
uint16_t PCpushed = 6;
if((typeSource == 1) | (typeSource == 2) | (typeSource == 3) | (typeSource == 4)) {
push(c_infected,&PCpushed);
} else {
push(c,&PCpushed);
}
	switch(typeSource) {
		case 0 : 
			/* Jxx Rn */
			c -> Registres[6] = c->Registres[valSource];
		break;
	
		case 1 : /* Jxx -(Rn) */
			c -> Registres[valSource] -= 2; 
		c_infected = adresse_vers_cpu(c,c->RAM[valSource]);
		addr_infected = cpu_vers_adresse(c,c->RAM[valSource]);
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;

		case 2 : 
			/* Jxx (Rn) */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
		break;
	
		case 3 : /* Jxx (Rn)+ */
			c_infected -> Registres[6] = c_infected->RAM[addr_infected];
			c -> Registres[valSource] += 2; 
		break;
		
		case 4 : /* Jxx #x */
		c_infected = adresse_vers_cpu(c,valSource);
		addr_infected = cpu_vers_adresse(c,valSource);
		c -> Registres[6] = valSource;			
	
		break;
		
		}
}
