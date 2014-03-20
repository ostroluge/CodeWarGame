#include <stdint.h>
#include <stdio.h>
#include "codewar.h"
struct cpu init() {
    struct cpu c;
    c.Registres[PC] = 0x10;
    return c;
}

void move(struct cpu *c, uint16_t *op1, uint16_t *op2) {
    uint16_t typeMove = (*op1 >> 9) & 0x03; /*  On veut les bits 5,6 */
    uint16_t dest = (*op1 >> 3) & 0x07 ;
    uint16_t source = (*op1 >> 6) & 0x07; /* On prend les bits 7,8,9 */
    uint16_t num_reg = *op1 & 0x07;
    uint8_t ram_val = c->RAM[*op2];
    int h,l,normal;
    /* On prend la valeur de la RAM[Registres] */
    struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[c->Registres[*op2]]);
    uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[c->Registres[*op2]]);
    h = 0;l = 0; normal = 0;
    printf("%d",c_infected->RAM[0]);
    if(source == 0) {
	/* Registre Rn */
	switch(dest) {
		
	case 0 :
	    /* Move R0 R1 */
	    printf("Instruction : MOVE R[%d] R[%d] \n",num_reg,*op2);  
	    if(typeMove == 2) { /* .h 8 bits de poids fort */
		c -> Registres[*op2] = (c->Registres[num_reg] & 0xFF00) | (c->Registres[*op2] & 0x00FF);
		h = 1;
	    } else if(typeMove == 1) { /* .l  8 bits de poids faible */
		c -> Registres[*op2] = (c->Registres[num_reg] & 0x00FF) | (c->Registres[*op2] & 0xFF00);
		l = 1;
	    } else {
		c -> Registres[*op2] = c->Registres[num_reg];
		normal = 1; 
	    }
	    break;
		
	case 1 :
	    /* Move R0 -(R1) */
	    printf("Instruction : MOVE R[%d] -(R%d) \n",num_reg,*op2); 
	    c -> Registres[*op2] -= 2;
	    c_infected = adresse_vers_cpu(c,c->RAM[c->Registres[*op2]]);
	    addr_infected = cpu_vers_adresse(c,c->RAM[c->Registres[*op2]]);
	    if(typeMove == 2) { /* .h 8 bits de poids fort */
		c_infected->RAM[addr_infected] = c->Registres[num_reg] >> 8; 
		h = 1;
	    } else if(typeMove == 1) { /* .l  8 bits de poids faible */
		c_infected->RAM[addr_infected] = c->Registres[num_reg] << 8; 
		l = 1;
	    } else {
		c_infected->RAM[addr_infected] = c->Registres[num_reg];
				
		normal = 1; 
	    }
	    break; 
		
	case 2 : 		
	    /* Move R0 (R1) */ 
	    printf("Instruction : MOVE R[%d] (R%d) \n",num_reg,*op2);  
	    if(typeMove == 2) { /* .h 8 bits de poids fort */
		c_infected->RAM[addr_infected] = c->Registres[num_reg] >> 8; 
		h = 1;
	    } else if(typeMove == 1) { /* .l  8 bits de poids faible */
		c_infected->RAM[addr_infected] = c->Registres[num_reg] << 8;
		l = 1;
	    } else {
		c_infected->RAM[addr_infected] = c->Registres[num_reg];
		normal = 1; 
					
	    }
	    break;
			
	case 3 :
	    /* Move R0 (R1)+ */
	    printf("Instruction : MOVE R[%d] (R%d)+ \n",num_reg,*op2);  
	    if(typeMove == 2) { /* .h 8 bits de poids fort */
		c_infected -> RAM[addr_infected] = c->Registres[num_reg] >> 8; 
		h = 1;
	    } else if(typeMove == 1) { /* .l  8 bits de poids faible */
		c_infected -> RAM[addr_infected] = c->Registres[num_reg] << 8; 
		l = 1;
	    } else {
			
		c_infected->RAM[addr_infected]  = c->Registres[num_reg];
		normal = 1; 
	    }
	    c->Registres[*op2] += 2;
	    break;
		
	case 5 : 
	    /* Move R0 @1 */
	    c_infected = adresse_vers_cpu(c,c->RAM[*op2]);
	    addr_infected = cpu_vers_adresse(c,c->RAM[*op2]);
	    printf("Instruction : MOVE R[%d] RAM[%d] \n",num_reg,*op2);  
	    if(typeMove == 2) { /* .h 8 bits de poids fort */
		c_infected -> RAM[addr_infected] = c->Registres[num_reg] >> 8; 
		h = 1;
	    } else if(typeMove == 1) { /* .l  8 bits de poids faible */
		c_infected -> RAM[addr_infected] = c->Registres[num_reg] << 8; 
		l = 1;
	    } else {
		c_infected -> RAM[addr_infected] = c->Registres[num_reg];
		normal = 1; 
	    }
	    break;
	default :
	    printf("Erreur destination");
	    /* Instruction illégale détecté */
	    illegalInst(c);
	    break;
	}
    } else if(source == 1) {
	/* Registre -(Rn) */
	switch(dest) {
		
	case 0 :
	    printf("Instruction : MOVE -R(%d) R[%d] \n",num_reg,*op2);
	    /* Move -(R0) R1 */
	    c->Registres[num_reg] -= 2; 
	    if(typeMove == 2) { /* .h 8 bits de poids fort */
		c->Registres[*op2] = (c->Registres[*op2] & 0xFF) | ((uint16_t)(c -> RAM[c->Registres[num_reg]] << 8));
		h = 1;
	    } else if(typeMove == 1) { /* .l  8 bits de poids faible */
		c->Registres[*op2] = (c -> RAM[c->Registres[num_reg]+1] & 0xFF00) | (c -> RAM[c->Registres[num_reg]+1]);	 			
		l = 1;
	    } else {
		c->Registres[*op2] = (uint16_t)(c -> RAM[c->Registres[num_reg]]);
		normal = 1;
	    }
	    break;
			
	case 1 :
	    printf("Instruction : MOVE -(R%d) -(R%d) \n",num_reg,*op2);
	    /* Move -(R0) -(R1) */
	    c->Registres[num_reg] -= 2;
	    c->Registres[*op2] -= 2;
	    c_infected = adresse_vers_cpu(c,c->RAM[c->Registres[*op2]]);
	    addr_infected = cpu_vers_adresse(c,c->RAM[c->Registres[*op2]]);
	    if(typeMove == 2) { /* .h 8 bits de poids fort */
		c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
		h = 1;
	    } else if(typeMove == 1) { /* .l  8 bits de poids faible */
		c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];	 			
		l = 1;
	    } else {
		c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
		c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]+1];
		normal = 1;
	    }
	    break;
		
	case 2 : 		
	    printf("Instruction : MOVE -(R%d) (R%d) \n",num_reg,*op2);
	    /* Move -(R0) (R1) */
	    c->Registres[num_reg] -= 2;
	    if(typeMove == 2) { /* .h 8 bits de poids fort */
		c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
		h = 1;
	    } else if(typeMove == 1) { /* .l  8 bits de poids faible */
		c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];	 			
		l = 1;
	    } else {
		c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
		c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]+1];
		normal = 1;
	    }
	    break;	
    case 3 :
	printf("Instruction : MOVE -(R%d) (R%d)+ \n",num_reg,*op2);
	/* Move -(R0) (R1)+ */
	c->Registres[num_reg] -= 2;
	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    h = 1;
	} else if(typeMove == 1) { /* .l  8 bits de poids faible */
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];	 			
	    l = 1;
	} else {
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];
	    normal = 1;
	}
	c->Registres[*op2] += 2;
	break;
		
    case 5 : 
	printf("Instruction : MOVE -(R%d) @%d \n",num_reg,*op2);
	/* Move -(R0) @1 */
	c->Registres[num_reg] -= 2;
	c_infected = adresse_vers_cpu(c,c->RAM[*op2]);
	addr_infected = cpu_vers_adresse(c,c->RAM[*op2]);
	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    h = 1;
	} else if(typeMove == 1) { /* .l  8 bits de poids faible */
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];	 			
	    l = 1;
	} else {
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    c_infected->RAM[addr_infected + 1] = c->RAM[c->Registres[num_reg]+1];
	    normal = 1;
	}
	break;
    default :
	printf("Erreur destination");
	/* Instruction illégale détecté */
	illegalInst(c);
	break;
    }
} else if(source == 2) {
    /* Registre (Rn) */
    switch(dest) {
			
    case 0 :
	printf("Instruction : MOVE (R%d) R%d \n",num_reg,*op2);
	/* Move (R0) R1 */ 
	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c->Registres[*op2] = (c->Registres[*op2] & 0xFF) | ((uint16_t)(c -> RAM[c->Registres[num_reg]] << 8));
	    h = 1;
	} else if(typeMove == 1) { /* .l  8 bits de poids faible */
	    c->Registres[*op2] = (c -> RAM[c->Registres[num_reg]+1] & 0xFF00) | (c -> RAM[c->Registres[num_reg]+1]);	 			
	    l = 1;
	} else {
	    c->Registres[*op2] = (uint16_t)(c -> RAM[c->Registres[num_reg]]);
	    normal = 1;
	}
	break;
			
    case 1 :
	printf("Instruction : MOVE (R%d) -(R%d) \n",num_reg,*op2);
	/* Move (R0) -(R1) */
	c->Registres[*op2] -= 2;
	c_infected = adresse_vers_cpu(c,c->RAM[*op2]);
	addr_infected = cpu_vers_adresse(c,c->RAM[*op2]);
	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    h = 1;
	} else if(typeMove == 1) { /* .l  8 bits de poids faible */
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];	 			
	    l = 1;
	} else {
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];
	    normal = 1;
	}
	break;
			
    case 2 : 		
	printf("Instruction : MOVE (R%d) (R%d) \n",num_reg,*op2);
	/* Move (R0) (R1) */
	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    h = 1;
	} else if(typeMove == 1) { /* .l  8 bits de poids faible */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]+1];	 			
	    l = 1;
	} else {
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];
	    normal = 1;
	}
	break;
			
    case 3 :
	printf("Instruction : MOVE (R%d) (R%d)+ \n",num_reg,*op2);
	/* Move (R0) (R1)+ */
	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    h = 1;
	} else if(typeMove == 1) { /* .l  8 bits de poids faible */
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];	 			
	    l = 1;
	} else {
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];
	    normal = 1;
	}
	c->Registres[*op2] += 2;
	break;
			
    case 5 : 
	printf("Instruction : MOVE (R%d) @%d \n",num_reg,*op2);
	/* Move (R0) @1 */
	c_infected = adresse_vers_cpu(c,c->RAM[*op2]);
	addr_infected = cpu_vers_adresse(c,c->RAM[*op2]);
	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    h = 1;
	} else if(typeMove == 1) { /* .l  8 bits de poids faible */
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];	 			
	    l = 1;
	} else {
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]+1];
	    normal = 1;
	}
	break;
    default :
	printf("Erreur destination");
	/* Instruction illégale détecté */
	illegalInst(c);
	break;
    }
 } else if(source == 3) {
    switch(dest) {
    case 0 :
	/* Move (R0)+ R1 */
	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c->Registres[*op2] = (c->Registres[*op2] & 0xFF) | ((uint16_t)(c -> RAM[c->Registres[num_reg]] << 8));
	    h = 1;
	} else if(typeMove == 1) { /* .l 8 bits de poids faible */
	    c->Registres[*op2] = (c -> RAM[c->Registres[num_reg]+1] & 0xFF00) | (c -> RAM[c->Registres[num_reg]+1]);	
	    l = 1;
	} else {
	    c->Registres[*op2] = (c->Registres[*op2] & 0xFF) | ((uint16_t)(c -> RAM[c->Registres[num_reg]] << 8));
	    c->Registres[*op2] = (c -> RAM[c->Registres[num_reg]+1] & 0xFF00) | (c -> RAM[c->Registres[num_reg+1]]);
	    normal = 1;
	}
	c->Registres[num_reg] += 2;
	break;
    case 1 :
	/* Move (R0)+ -(R1) */

	c->Registres[*op2] -= 2;
	c_infected = adresse_vers_cpu(c,c->RAM[c->Registres[*op2]]);
	addr_infected = cpu_vers_adresse(c,c->RAM[c->Registres[*op2]]);
	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    h = 1;
	} else if(typeMove == 1) { /* .l 8 bits de poids faible */
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];	
	    l = 1;
	} else {
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];
	    normal = 1;
	}
	c->Registres[num_reg] += 2;
	break;
    case 2 :
	/* Move (R0)+ (R1) */

	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    h = 1;
	} else if(typeMove == 1) { /* .l 8 bits de poids faible */
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];	
	    l = 1;
	} else {
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];
	    normal = 1;
	}
	c->Registres[num_reg] += 2;
	break;

    case 3 :
	/* Move (R0)+ (R1)+ */

	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    h = 1;
	} else if(typeMove == 1) { /* .l 8 bits de poids faible */
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];	
	    l = 1;
	} else {
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];
	    normal = 1;
	}
	c->Registres[*op2] += 2;
	c->Registres[num_reg] += 2;
	break;
    case 5 :
	/* Move (R0)+ @1 */
	c_infected = adresse_vers_cpu(c,c->RAM[*op2]);
	addr_infected = cpu_vers_adresse(c,c->RAM[*op2]);
	if(typeMove == 2) { /* .h 8 bits de poids fort */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    h = 1;
	} else if(typeMove == 1) { /* .l 8 bits de poids faible */
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]+1];	
	    l = 1;
	} else {
	    c_infected->RAM[addr_infected] = c->RAM[c->Registres[num_reg]];
	    c_infected->RAM[addr_infected+1] = c->RAM[c->Registres[num_reg]+1];
	    normal = 1;
	}
	c->Registres[num_reg] += 2;
	break;
    default :
	printf("Erreur destination");
	/* Instruction illégale détecté */
	illegalInst(c);
	break;
    }

} else if(source == 4) {
      /* Valeur immediate */
      switch(dest) {
			
      case 0 :
	  printf("Instruction : MOVE #%d R%d \n",*op2,num_reg);
	  /* Move #1 R0 */ 
	  if(typeMove == 2) { /* .h 8 bits de poids fort */
	      c -> Registres[num_reg] = *op2;
	      h = 1;
	  } else if(typeMove == 1) { /* .l  8 bits de poids faible */
	      c -> Registres[num_reg] = *op2;
	      l = 1;
	  } else {
	      c -> Registres[num_reg] = *op2;
	      normal = 1; 
	  }
	  break;
			
      case 1 :
	  printf("Instruction : MOVE #%d -(R%d) \n",*op2,num_reg);
	  /* Move #1 -(R0) */
	  c -> Registres[num_reg] -= 2;
		c_infected = adresse_vers_cpu(c,*op2);
	addr_infected = cpu_vers_adresse(c,*op2);
	  if(typeMove == 2) { /* .h 8 bits de poids fort */
	      c_infected -> RAM[addr_infected] = *op2 >>8;
	      h = 1;
	  } else if(typeMove == 1) { /* .l  8 bits de poids faible */
	      c_infected -> RAM[addr_infected+1] = *op2 & 0xFF;
	      l = 1;
	  } else {
	      c_infected -> RAM[addr_infected] = *op2;
	      normal = 1; 
	  }
	  break; 
			
      case 2 : 		
	  printf("Instruction : MOVE #%d (R%d) \n",*op2,num_reg);
	  /* Move #1 (R0) */ 
		c_infected = adresse_vers_cpu(c,*op2);
	addr_infected = cpu_vers_adresse(c,*op2);
	  if(typeMove == 2) { /* .h 8 bits de poids fort */
	      c_infected -> RAM[addr_infected] = *op2 >>8;
	      h = 1;
	  } else if(typeMove == 1) { /* .l  8 bits de poids faible */
	      c_infected -> RAM[addr_infected+1] = *op2 & 0xFF;
	      l = 1;
	  } else {
	      c_infected -> RAM[addr_infected] = *op2;
	      normal = 1; 
	  }
	  break; 
			
      case 3 :
	  printf("Instruction : MOVE #%d+ (R%d) \n",*op2,num_reg);
	  /* Move #1 (R0)+ */
		c_infected = adresse_vers_cpu(c,*op2);
	addr_infected = cpu_vers_adresse(c,*op2);
	  if(typeMove == 2) { /* .h 8 bits de poids fort */
	      c_infected -> RAM[addr_infected] = *op2 >>8;
	      h = 1;
	  } else if(typeMove == 1) { /* .l  8 bits de poids faible */
	      c_infected -> RAM[addr_infected+1] = *op2 & 0xFF;
	      l = 1;
	  } else {
	      c_infected -> RAM[addr_infected] = *op2;
	      normal = 1; 
	  }
	c->Registres[num_reg] += 2;
	  break; 
      default :
	  printf("Erreur destination");
	  /* Instruction illégale détecté */
	  illegalInst(c);
	  break;
      }
  } else if(source == 5) {
      /* adresse */
      switch(dest) {
			
      case 0 :
	  printf("Instruction : MOVE @%d R%d \n",*op2,num_reg);
	  /* Move @1 R0 */ 
	  if(typeMove == 2) { /* .h 8 bits de poids fort */
	      c -> Registres[num_reg] = ram_val | (c->Registres[num_reg] & 0xFF00);
	      h = 1;
	  } else if(typeMove == 1) { /* .l  8 bits de poids faible */
	      c -> Registres[num_reg] = ram_val | (c->Registres[num_reg+1] & 0xFF00);
	      l = 1;
	  } else {
	      /*c -> Registres[num_reg] = *((uint16_t*)&(c->RAM[*op2]));*/
	      c -> Registres[num_reg] = (uint16_t)(c->RAM[*op2]);
	      normal = 1; 
	  }
	  break;
		
      case 1 :
	  printf("Instruction : MOVE @%d -(R%d) \n",*op2,num_reg);
	  /* Move @1 -(R0) */
	  c -> Registres[num_reg] -= 2;
		c_infected = adresse_vers_cpu(c,c->RAM[c->Registres[*op2]]);
	addr_infected = cpu_vers_adresse(c,c->RAM[c->Registres[*op2]]);
	  if(typeMove == 2) { /* .h 8 bits de poids fort */
	      c_infected -> RAM[addr_infected] = c->RAM[*op2];
	      h = 1;
	  } else if(typeMove == 1) { /* .l  8 bits de poids faible */
	      c_infected -> RAM[addr_infected+1] = c->RAM[*op2+1];
	      l = 1;
	  } else {
	      c_infected -> RAM[addr_infected] = c->RAM[*op2];
	      c_infected -> RAM[addr_infected + 1] = c->RAM[*op2+1];
	      normal = 1; 
	  }
	  break; 
			
      case 2 : 		
	  printf("Instruction : MOVE @%d (R%d) \n",*op2,num_reg);
	  /* Move @1 (R0) */ 
	  if(typeMove == 2) { /* .h 8 bits de poids fort */
	      c_infected -> RAM[addr_infected] = c->RAM[*op2];
	      h = 1;
	  } else if(typeMove == 1) { /* .l  8 bits de poids faible */
	      c_infected -> RAM[addr_infected+1] = c->RAM[*op2+1];
	      l = 1;
	  } else {
	      c_infected -> RAM[addr_infected] = c->RAM[*op2];
	      c_infected -> RAM[addr_infected + 1] = c->RAM[*op2+1];
	      normal = 1; 
	  }
	  break; 
			
      case 3 :
	  printf("Instruction : MOVE @%d (R%d)+ \n",*op2,num_reg);
	  /* Move @1 (R0)+ */
	  if(typeMove == 2) { /* .h 8 bits de poids fort */
	      c_infected -> RAM[addr_infected] = c->RAM[*op2];
	      h = 1;
	  } else if(typeMove == 1) { /* .l  8 bits de poids faible */
	      c_infected -> RAM[addr_infected+1] = c->RAM[*op2+1];
	      l = 1;
	  } else {
	      c_infected -> RAM[addr_infected] = c->RAM[*op2];
	      c_infected -> RAM[addr_infected + 1] = c->RAM[*op2+1];
	      normal = 1; 
	  }
		c->Registres[num_reg] += 2;
	  break;
      default :
	  printf("Erreur destination");
	  /* Instruction illégale détecté */
	  illegalInst(c);
	  break;
      }
  }
/* Mise à jour des FLAGS */
c -> C = 0;
if(l == 1) {
    c -> N = (*op1  & 0x80) >> 7; /* Valeur du bit 7 S7 */
 }
if(normal == 1 || h == 1) {
    c -> N = (*op1 >> 15) & 0x01; /* Valeur du bit 15 S15 */
 }
if(op1 == 0) {
    c -> Z = 1;
 } else {
    c -> Z = 0;
 }
			
}
void push(struct cpu *c, uint16_t *inst) {
    /* dans inst :: iiiii/ttt/vvvvvvvv/ .. type source > ttt et valeur > vvvvvvvv ;; source possible -> Only registre*/
    uint16_t typeSource = (*inst >> 8) & 0x07;
    uint16_t valeur = *inst & 0xFF;
    /* structure d'un move : iiiii/hl/t1,t1,t1/t2,t2,t2/rrr/ et 16 bits de v */
    uint16_t op1 = 1544;
    /* pour move(S,-(R7)) > 00000/11/000/001/000 et v = 7 > 111 */
    uint16_t op2 = 7;
	/* Replacement de la source pour l'inclure au move */
    typeSource = typeSource << 6;
    op1 = ((op1) | (typeSource)) | ((op1) | (valeur));
    move(c, &op1, &op2);
}
void pop(struct cpu *c, uint16_t *inst) {
    /* dans inst :: iiiii/ttt/vvvvvvvv/ .. type source > ttt et valeur > vvvvvvvv ;; source possible -> Only registre*/
    uint16_t typeSource = (*inst >> 8) & 0x07;
    uint16_t valeur = *inst & 0xFF;
    /* structure d'un move : iiiii/hl/t1,t1,t1/t2,t2,t2/rrr/ et 16 bits de v */
    uint16_t op1 = 1735;

    typeSource = typeSource << 3;
    op1 = (op1) | (typeSource);
    move(c, &op1, &valeur);
}
void add(struct cpu *c, uint16_t *inst) {
    uint16_t num_dest = (*inst >> 8) & 0x07;   
    uint16_t typeSource = (*inst >> 5) & 0x07;
    uint16_t valSource = *inst & 0x1F;
    /* Test du type d'operande de la source */
    switch (typeSource) {
    case 0 : /* ADD Rn Rn */
	printf("Instruction : ADD R[%d] R[%d] \n",valSource,num_dest);  
	c -> Registres[num_dest] = c -> Registres[num_dest] + c -> Registres[valSource];
	break;
    case 1 : /* ADD -(Rn) Rn */
	printf("Instruction : ADD -(R%d) R[%d] \n",valSource,num_dest);  
	c->Registres[valSource] -= 2;
	c -> Registres[num_dest] += c->RAM[c->Registres[valSource]];
	break;
    case 2 : /* ADD (Rn) Rn */
	printf("Instruction : ADD (R%d) R[%d] \n",valSource,num_dest);  
	c -> Registres[num_dest] += c -> RAM[c->Registres[valSource]];
	break;
    case 3 : /* ADD (Rn)+ Rn */
	printf("Instruction : ADD (R%d)+ R[%d] \n",valSource,num_dest);  
	c -> Registres[num_dest] += c -> RAM[c->Registres[valSource]];
	c -> Registres[valSource] +=2;
	break;
    case 4 : /* ADD #x Rn */
	printf("Instruction : ADD #%d R[%d] \n",valSource,num_dest);  
	c -> Registres[num_dest] += valSource;
	break;
    default:
	illegalInst(c);
	break;
    }
    /* Mise a jour des flags */ 
    c -> N = c->Registres[num_dest] & 0x8000;
    if(c->Registres[num_dest] == 0) {
	c -> Z = 0;
    } else {
	c -> Z = 1;
    }
    if(c->Registres[num_dest] > 0xFFFF) {
	c -> C = 1; 
    } else {
	c -> C = 0;
    }
}

void lsl(struct cpu *c, uint16_t *inst) {
    uint16_t num_dest = (*inst >> 8) & 0x07;   
    uint16_t typeSource = (*inst >> 5) & 0x07;
    uint16_t valSource = *inst & 0x1F;
    uint32_t tmp = c->Registres[num_dest];
    switch (typeSource) {
	  	
    case 0 : /* LSL Rn Rn */
	printf("Instruction : LSL R%d R%d \n",valSource,num_dest);
	tmp = (c -> Registres[num_dest]) << (c -> Registres[valSource]);
	c -> Registres[num_dest] = (c -> Registres[num_dest]) << (c -> Registres[valSource]);
	break;
    case 1 : /* LSL -(Rn) Rn */
	printf("Instruction : LSL -(R%d) R%d \n",valSource,num_dest);
	c->Registres[valSource] -=2;
	tmp = c -> Registres[num_dest] << (c->RAM[c->Registres[valSource]]);
	c -> Registres[num_dest] = c -> Registres[num_dest] << (c->RAM[c->Registres[valSource]]);
	break;
    case 2 : /* LSL (Rn) Rn */
	printf("Instruction : LSL (R%d) R%d \n",valSource,num_dest);
	tmp = c -> Registres[num_dest] << (c->RAM[c->Registres[valSource]]);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] << (c -> RAM[c->Registres[valSource]]);
	break;
    case 3 : /* LSL (Rn)+ Rn */
	printf("Instruction : LSL (R%d)+ R%d \n",valSource,num_dest);
	tmp = c -> Registres[num_dest] << (c->RAM[c->Registres[valSource]]);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] << (c -> RAM[c->Registres[valSource]]);
	c -> Registres[valSource] +=2;
	break;
    case 4 : /* LSL #x Rn */
	printf("Instruction : LSL #%d R%d \n",valSource,num_dest);
	tmp = c -> Registres[num_dest] << valSource;
	c -> Registres[num_dest] +=  c -> Registres[num_dest] << valSource;
	break;
    default: 
	illegalInst(c);
	break;
    }
    /* Mise a jour des FLAGS */
    c -> N = c->Registres[num_dest] & 0x8000;
    if(c->Registres[num_dest] == 0) {
	c -> Z = 0;
    } else {
	c -> Z = 1;
    }
    /* Hypothese ! */
    /* --------------------------------------------- */
    c -> C = tmp & 0x10000;
    /* --------------------------------------------- */
}

void lsr(struct cpu *c, uint16_t *inst) {
    uint16_t num_dest = (*inst >> 8) & 0x07;   
    uint16_t typeSource = (*inst >> 5) & 0x07;
    uint16_t valSource = *inst & 0x1F;
    uint32_t tmp;
    switch (typeSource) {

    case 0 : /* LSR Rn Rn */
	printf("Instruction : LSR R%d R%d \n",valSource,num_dest);
   
	c -> Registres[num_dest] = (c -> Registres[num_dest]) >> (c -> Registres[valSource]);
	break;
    case 1 : /* LSR -(Rn) Rn */
	printf("Instruction : LSR -(R%d) R%d \n",valSource,num_dest);
	c->Registres[valSource] -=2;
	tmp = (c -> Registres[num_dest] << 1) >> (c ->RAM[c->Registres[valSource]]);
	c -> Registres[num_dest] = c -> Registres[num_dest] >> (c->RAM[c->Registres[valSource]]);
	break;	  
    case 2 : /* LSR (Rn) Rn */
	printf("Instruction : LSR (R%d) R%d \n",valSource,num_dest);
	tmp = (c -> Registres[num_dest] << 1 ) >> (c ->RAM[c->Registres[valSource]]);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] >> (c -> RAM[c->Registres[valSource]]);
	break;
    case 3 : /* LSR (Rn)+ Rn */
	printf("Instruction : LSR (R%d)+ R%d \n",valSource,num_dest);
	tmp = (c -> Registres[num_dest] << 1) >> (c ->RAM[c->Registres[valSource]]);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] >> (c -> RAM[c->Registres[valSource]]);
	c -> Registres[valSource] +=2;
	break;
    case 4 : /* LSR #x Rn */
	printf("Instruction : LSR #%d R%d \n",valSource,num_dest);
	tmp = (c -> Registres[num_dest]<< 1) >> (c ->RAM[c->Registres[valSource]]);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] >> valSource;
	break;
    default:
	illegalInst(c);
	break;
    }

    /* Mise a jour des FLAGS */
    c -> N = c->Registres[num_dest] & 0x8000;
    if(c->Registres[num_dest] == 0) {
	c -> Z = 0;
    } else {
	c -> Z = 1;
    }
    /* Hypothese ! */
    /* --------------------------------------------- */
    c -> C = tmp & 0x01;
    /* --------------------------------------------- */
}

void sub(struct cpu *c, uint16_t *inst) {
    uint16_t num_dest = (*inst >> 8) & 0x07;   
    uint16_t typeSource = (*inst >> 5) & 0x07;
    uint16_t valSource = *inst & 0x1F;
    /* Test du type d'operande de la source */
    switch (typeSource) {
    case 0 : /* SUB Rn Rn */
	printf("Instruction : SUB R[%d] R[%d] \n",valSource,num_dest);  
	c -> Registres[num_dest] -= c -> Registres[valSource];
	break;
    case 1 : /* SUB -(Rn) Rn */
	printf("Instruction : SUB -(R%d) R[%d] \n",valSource,num_dest);  
	c->Registres[valSource] -=2;
	c -> Registres[num_dest] -= c->RAM[c->Registres[valSource]];
	break;
    case 2 : /* SUB (Rn) Rn */
	printf("Instruction : SUB (R%d) R[%d] \n",valSource,num_dest); 
	c -> Registres[num_dest] -= c -> RAM[c->Registres[valSource]];
	break;
    case 3 : /* SUB (Rn)+ Rn */
	printf("Instruction : SUB (R%d)+ R[%d] \n",valSource,num_dest); 
	c -> Registres[num_dest] -= c ->RAM[c->Registres[valSource]];
	c -> Registres[valSource] +=2;
	break;
    case 4 : /* SUB #x Rn */
	printf("Instruction : SUB #%d R[%d] \n",valSource,num_dest); 
	c -> Registres[num_dest] -= valSource;
	break;
    default:
	illegalInst(c);
	break;
    }
    /* Mise a jour des flags */
    c -> N = (c->Registres[num_dest] & 0x8000) << 15;
    if(c->Registres[num_dest] == 0) {
	c -> Z = 0;
    } else {
	c -> Z = 1;
    }
    if(c->Registres[num_dest] < 0) { /* Si D < S, celà signifie que D=D-S < 0 */
	c -> C = 1; 
    } else {
	c -> C = 0;
    }
}

void cmp(struct cpu *c, uint16_t *inst) {
    uint16_t num_dest = (*inst >> 8) & 0x07;   
    uint16_t typeSource = (*inst >> 5) & 0x07;
    uint16_t valSource = *inst & 0x1F;
    uint16_t res;
    /* Test du type d'operande de la source */
    switch (typeSource) {
	
    case 0 : /* CMP Rn Rn */
	printf("Instruction : CMP R%d R%d \n",valSource,num_dest);
	res = c->Registres[num_dest] - c->Registres[valSource];
	break;
    case 1 : /* CMP -(Rn) Rn */
	printf("Instruction : CMP -(R%d) R%d \n",valSource,num_dest);
	c->Registres[valSource] -=2;
	res = c->Registres[num_dest] - c->RAM[c->Registres[valSource]];
	break;
    case 2 : /* CMP (Rn) Rn */
	printf("Instruction : CMP (R%d) R%d \n",valSource,num_dest);
	res = c->Registres[num_dest] - c ->RAM[c->Registres[valSource]];
	break;
    case 3 : /* CMP (Rn)+ Rn */
	printf("Instruction : CMP (R%d)+ R%d \n",valSource,num_dest);
	res = c -> Registres[num_dest] - c -> RAM[c->Registres[valSource]]	;
	c -> Registres[valSource] +=2;
	break;
    case 4 : /* CMP #x Rn */
	printf("Instruction : CMP #%d R%d \n",valSource,num_dest);
	res = c -> Registres[num_dest] - valSource;
	break;
    default: 
	illegalInst(c);
	break;
    }
    /* Mise à jour des flags */
    c -> N = (res & 0x8000 << 15);
    if(res == 0) {
	c -> Z = 1;
    } else {
	c -> Z = 0;
    }
    if( c-> Registres[num_dest] - c->Registres[valSource] < 0) {
	c -> C = 1;
    } else {
	c -> C = 0;
    }
}

void and(struct cpu *c, uint16_t *inst) {
    uint16_t num_dest = (*inst >> 8) & 0x07;   
    uint16_t typeSource = (*inst >> 5) & 0x07;
    uint16_t valSource = *inst & 0x1F;
	
    switch (typeSource) {
		
    case 0 : /* AND Rn Rn */
	printf("Instruction : AND R%d R%d \n",valSource,num_dest);
	c -> Registres[num_dest] = (c -> Registres[num_dest]) & (c -> Registres[valSource]);
	break;
    case 1 : /* AND -(Rn) Rn */
	printf("Instruction : AND -(R%d) R%d \n",valSource,num_dest);
	c->Registres[valSource] -=2;
	c -> Registres[num_dest] = c -> Registres[num_dest] & (c->RAM[c->Registres[valSource]]);
	break;
    case 2 : /* AND (Rn) Rn */
	printf("Instruction : AND (R%d) R%d \n",valSource,num_dest);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] & (c -> RAM[c->Registres[valSource]]);
	break;
    case 3 : /* AND (Rn)+ Rn */
	printf("Instruction : AND (R%d)+ R%d \n",valSource,num_dest);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] & (c -> RAM[c->Registres[valSource]]);
	c -> Registres[valSource] +=2;
	break;
    case 4 : /* AND #x Rn */
	printf("Instruction : AND #%d R%d \n",valSource,num_dest);
 	c -> Registres[num_dest] +=  c -> Registres[num_dest] & valSource;
	break;
    default:
	illegalInst(c);
	break;
    }
    /* Mise a jour des FLAGS */
    c -> N = (c->Registres[num_dest] & 0x8000) << 15;
    if(c->Registres[num_dest] == 0) {
	c -> Z = 0;
    } else {
	c -> Z = 1;
    }
    c -> C = 0;
}

void or(struct cpu *c, uint16_t *inst) {
    uint16_t num_dest = (*inst >> 8) & 0x07;   
    uint16_t typeSource = (*inst >> 5) & 0x07;
    uint16_t valSource = *inst & 0x1F;
  	
    switch (typeSource) {
		
    case 0 : /* OR Rn Rn */
	printf("Instruction : OR R%d R%d \n",valSource,num_dest);
	c -> Registres[num_dest] = (c -> Registres[num_dest]) | (c -> Registres[valSource]);
	break;
    case 1 : /* OR -(Rn) Rn */
	printf("Instruction : OR -(R%d) R%d \n",valSource,num_dest);
	c->Registres[valSource] -=2;
	c -> Registres[num_dest] = c -> Registres[num_dest] | (c->RAM[c->Registres[valSource]]);
	break;
    case 2 : /* OR (Rn) Rn */
	printf("Instruction : OR (R%d) R%d \n",valSource,num_dest);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] | (c -> RAM[c->Registres[valSource]]);
	break;
    case 3 : /* OR (Rn)+ Rn */
	printf("Instruction : OR (R%d)+ R%d \n",valSource,num_dest);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] | (c -> RAM[c->Registres[valSource]]);
	c -> Registres[valSource] +=2;
	break;
    case 4 : /* OR #x Rn */
	printf("Instruction : OR #%d R%d \n",valSource,num_dest);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] | valSource;
	break;
    default:
	illegalInst(c);
	break;
    }

    /* Mise a jour des FLAGS */
    c -> N =(c->Registres[num_dest] & 0x8000) << 15;
    if(c->Registres[num_dest] == 0) {
	c -> Z = 0;
    } else {
	c -> Z = 1;
    }
    c -> C = 0;
}

void xor(struct cpu *c, uint16_t *inst) {
    uint16_t num_dest = (*inst >> 8) & 0x07;   
    uint16_t typeSource = (*inst >> 5) & 0x07;
    uint16_t valSource = *inst & 0x1F;
	
    switch (typeSource) {
	
    case 0 : /* XOR Rn Rn */
	printf("Instruction : XOR R%d R%d \n",valSource,num_dest);
	c -> Registres[num_dest] = (c -> Registres[num_dest]) ^ (c -> Registres[valSource]);
	break;
    case 1 : /* XOR -(Rn) Rn */
	printf("Instruction : XOR -(R%d) R%d \n",valSource,num_dest);
	c->Registres[valSource] -=2;
	c -> Registres[num_dest] = c -> Registres[num_dest] ^ (c->RAM[c->Registres[valSource]]);
	break;
    case 2 : /* XOR (Rn) Rn */
	printf("Instruction : XOR (R%d) R%d \n",valSource,num_dest);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] ^ (c -> RAM[c->Registres[valSource]]);
	break;
    case 3 : /* XOR (Rn)+ Rn */
	printf("Instruction : XOR (R%d)+ R%d \n",valSource,num_dest);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] ^ (c -> RAM[c->Registres[valSource]]);
	c -> Registres[valSource] +=2;
	break;
    case 4 : /* XOR #x Rn */
	printf("Instruction : XOR #%d R%d \n",valSource,num_dest);
	c -> Registres[num_dest] +=  c -> Registres[num_dest] ^ valSource;
	break;
    default:
	illegalInst(c);
	break;
    }
	
    /* Mise a jour des FLAGS */
    c -> N = (c->Registres[num_dest] & 0x8000) << 15;
    if(c->Registres[num_dest] == 0) {
	c -> Z = 0;
    } else {
	c -> Z = 1;
    }
    c -> C = 0;
}

void not(struct cpu  *c, uint16_t *inst) {
    uint16_t typeSource = (*inst >> 8) & 0x07;
    uint16_t valeurSource = *inst & 0xFF;
	struct cpu *c_infected = adresse_vers_cpu(c,c->RAM[c->Registres[valeurSource]]);
	uint16_t addr_infected = cpu_vers_adresse(c,c->RAM[c->Registres[valeurSource]]);
    switch (typeSource) {

    case 0 : /* NOT Rn */
	printf("Instruction : NOT R%d \n",valeurSource);
	c->Registres[valeurSource]  = ~(c->Registres[valeurSource]);
	break;
    case 1 : /* NOT -(Rn) */
	printf("Instruction : NOT -(R%d) \n",valeurSource);
	
	c->Registres[valeurSource] -=2;
	c_infected = adresse_vers_cpu(c,c->RAM[c->Registres[valeurSource]]);
	addr_infected = cpu_vers_adresse(c,c->RAM[c->Registres[valeurSource]]);
	
	c_infected->RAM[addr_infected]  = ~(c_infected->RAM[addr_infected]);
	break;
    case 2 : /* NOT (Rn) */
	printf("Instruction : NOT (R%d) \n",valeurSource);
	c_infected->RAM[addr_infected]  = ~(c_infected->RAM[addr_infected]);
	break;
    case 3 : /* NOT (Rn)+ */
	printf("Instruction : NOT (R%d)+ \n",valeurSource);
	c_infected->RAM[addr_infected]  = ~(c_infected->RAM[addr_infected]);
	c -> Registres[valeurSource] +=2;
	break;
    default :
	illegalInst(c);
	break;
    }
    /* Mise a jour des FLAGS */	
    c -> N = (c->Registres[valeurSource] & 0x8000) << 15;
    if(c->Registres[valeurSource] == 0) {
	c -> Z = 0;
    } else {
	c -> Z = 1;
    }
    c -> C = 0;
}

void execute(struct cpu *c){
    int pc = c -> Registres[6]; /* pc = program counter */
    uint16_t inst=0;
    uint16_t instNext=0;
	inst = c -> RAM[pc] | (c -> RAM[pc+1] << 8);
	instNext = c -> RAM[pc+2] | (c -> RAM[pc+3] << 8);	
	switch (inst >> 11){
	case MOVE:
	    move(c, &inst, &instNext);
	    c->Registres[6] += 4;				
	    break;
	case ADD:
	    add(c, &inst);
	    c->Registres[6] += 2;
	    break;
	case PUSH:
	    push(c,&inst);
	    c->Registres[6] += 2;		 
	    break;
	case POP:
	    pop(c, &inst);
	    c->Registres[6] += 2;
	    break;
	case CMP:
	    cmp(c, &inst);
	    c->Registres[6] += 2;
	    break;
	case SUB:
	    sub(c, &inst);
	    c->Registres[6] += 2;
	    break;
	case LSL:
	    lsl(c, &inst);
	    c->Registres[6] += 2;
	    break;
	case LSR:
	    lsr(c, &inst);
	    c->Registres[6] += 2;
	    break;
	case AND:
	    and(c,&inst);
	    c->Registres[6] += 2;
	    break;
	case OR:
	    or(c,&inst);
	    c->Registres[6] += 2;
	    break;
	case XOR:
	    xor(c,&inst);
	    c->Registres[6] += 2;
	    break;
	case NOT:
	    not(c,&inst);
	    c->Registres[6] += 2;
	    break;
	case BCCBGT:
	    bcc(c,&inst);
	    break;
	case BCSBLT:
	    bcs(c,&inst);

	    break;
	case BEQ:
	    beq(c,&inst);

	    break;
	case BNE:
	    bne(c,&inst);

	    break;
	case BLE:
	    ble(c,&inst);

	    break;
	case BGE:
	    bge(c,&inst);

	    break;
	case BRA:
	    bra(c,&inst);

	    break;
	case BSR:
	    bsr(c,&inst);

	    break;
	case JCCJGT:
	    jcc(c,&inst);
	    break;
	case JCSJLT:
	    jcs(c,&inst);
	    break;
	case JEQ:
	    jeq(c,&inst);
	    break;
	case JNE:
	    jne(c,&inst);
	    break;
	case JLE:
	    jle(c,&inst);
	    break;
	case JGE:
	    jge(c,&inst);
	    break;
	case JMP:
	    jmp(c,&inst);
	    break;
	case JSR:
	    jsr(c,&inst);
	    break;
	}
    }

