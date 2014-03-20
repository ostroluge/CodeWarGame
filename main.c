/* Ca c'est du main d'HOMME ! */
#include <stdio.h>
#include "codewar.h"
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char **argv){
struct stat buf;
int fs,i,j;
int resultat;
struct cpu *cpu1;
struct cpu *cpu2;
int nb_cycle,fd,fd2;
int cpt = 0;
if(argc != 3) {
printf("%d",argc);
printf("Error : <player 1 file> <player 2 file>\n");
exit(1);
}
	printf("Welcome to CodeWar :\n");
	init_plateau();
	printf("Joueur 1 : \n");
	cpu1 = selectionCPU();
	afficherCPUSelected(cpu1);
	fd = open(argv[1], O_RDONLY);

if(fd == -1) {
perror("open");
}
	printf("Joueur 2 : \n");
	cpu2 = selectionCPU();
	afficherCPUSelected(cpu2);
fd2 = open(argv[2], O_RDONLY);

if(fd2 == -1) {
perror("open");
}
	printf("Combien de cycle voulez vous jouer ?\n");
	scanf("%d",&nb_cycle);
	affichage_grille();
/*Chargement code joueur 1*/
	fs=stat(argv[1], &buf);
	if(fs == -1) {
	perror("stat");
	exit(1);
}
	resultat = read(fd,&(cpu1->RAM[cpu1->Registres[6]]),(int)buf.st_size);
	if(resultat == -1) {
	printf("Erreur read\n");	
	exit(1);
}
/*Chargement code joueur 2 */
	fs=stat(argv[2], &buf);
	if(fs == -1) {
	perror("stat");
	exit(1);
}
	resultat = read(fd2,&(cpu2->RAM[cpu2->Registres[6]]),(int)buf.st_size);
	if(resultat == -1) {
	printf("Erreur read\n");	
	exit(1);
}
	while( cpt != nb_cycle) {
	for(i = 0; i <15 ; i ++) {
		for(j = 0 ; j < 15 ; j++) {
		execute(&(plateau[i][j]));
	}
	}
	affichage_grille();
	cpt ++;
	}
	return 0;
}
