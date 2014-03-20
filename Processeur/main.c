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
struct cpu myC = init();
int resultat=-1;
int fd;
struct stat buf;
int fs;
/* Affichage du CPU initial : 
printf(" Affichage de CPU initial \n");
for(i = 0 ; i < 8 ; i ++) {
printf("Valeur du registre R[%d] = %d\n",i,myC.Registres[i]);
	}
printf(" ----------------------------\n");
for(j = 0 ; j < 256 ; j ++) {
printf("Valeur de la RAM[%d] = %d \n",j,myC.RAM[j]);
	}

printf(" ----------------------------\n");
*/
fd = open(argv[1], O_RDONLY);

if(fd == -1) {
perror(argv[1]);
}
/* Taille du fichier BIN */
 
fs=stat(argv[1], &buf);
if(fs == -1) {
perror("stat");
exit(1);
}
resultat = read(fd,&(myC.RAM[myC.Registres[6]]),(int)buf.st_size);
if(resultat == -1) {
printf("Erreur read\n");
exit(1);
}

execute(&myC,(int)buf.st_size);

	close(fd);
/* Affichage du CPU changement ! : */
	return 0;
}
