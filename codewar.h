
#include <stdint.h>
#define MOVE 0
#define PUSH 1
#define POP 2
#define ADD 3
#define CMP 4
#define SUB 5
#define LSL 6
#define LSR 7
#define AND 8
#define OR 9
#define XOR 10
#define NOT 11
#define BCCBGT 12
#define BCSBLT 13
#define BEQ 14
#define BNE 15
#define BLE 16
#define BGE 17
#define BRA 18
#define BSR 19
#define JCCJGT 20
#define JCSJLT 21
#define JEQ 22
#define JNE 23
#define JLE 24
#define JGE 25
#define JMP 26
#define JSR 27
#define RTS 28
#define TRAP 29
#define RTE 30
#define PC 6
#define SP 7

/* structure de données du microprocesseur */

struct cpu{
    uint16_t Registres[8];
    uint8_t RAM[256];
    int Z, N, C; /* boolean a 0 ou 1 */
};


/* structure qui definie le plateau de jeu */
 struct cpu plateau[16][16];


void move(struct cpu *c, uint16_t *op1, uint16_t *op2);

void add(struct cpu *c, uint16_t *inst);

void cmp(struct cpu *c, uint16_t *inst);

void sub(struct cpu *c, uint16_t *inst);

void push(struct cpu *c, uint16_t *inst);

void pop(struct cpu *c, uint16_t *inst);

void lsl(struct cpu *c, uint16_t *inst);

void lsr(struct cpu *c, uint16_t *inst);

void and(struct cpu *c, uint16_t *inst);

void or(struct cpu *c, uint16_t *inst);

void xor(struct cpu *c, uint16_t *inst);

void not(struct cpu *c, uint16_t *inst);

void bcc(struct cpu *c, uint16_t *inst);

void bcs(struct cpu *c, uint16_t *inst);

void beq(struct cpu *c, uint16_t *inst);

void bne(struct cpu *c, uint16_t *inst);

void blt(struct cpu *c, uint16_t *inst);

void ble(struct cpu *c, uint16_t *inst);

void bgt(struct cpu *c, uint16_t *inst);

void bge(struct cpu *c, uint16_t *inst);

void bra(struct cpu *c, uint16_t *inst);

void bsr(struct cpu *c, uint16_t *inst);

void jcc(struct cpu *c, uint16_t *inst);

void jcs(struct cpu *c, uint16_t *inst);

void jeq(struct cpu *c, uint16_t *inst);

void jne(struct cpu *c, uint16_t *inst);

void jlt(struct cpu *c, uint16_t *inst);

void jle(struct cpu *c, uint16_t *inst);

void jgt(struct cpu *c, uint16_t *inst);

void jge(struct cpu *c, uint16_t *inst);

void jmp(struct cpu *c, uint16_t *inst);

void jsr(struct cpu *c, uint16_t *inst);

void execute(struct cpu *c);
struct cpu *selectionCPU();
void illegalInst(struct cpu *c);
struct cpu init();
void init_plateau();
int getCouleur(struct cpu *c);
void afficherCPUSelected(struct cpu *c);
struct cpu *adresse_vers_cpu(struct cpu *c,uint16_t adresse);
uint16_t cpu_vers_adresse(struct cpu *c,uint16_t adresse);
void affichage_grille();
