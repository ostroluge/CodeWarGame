CFLAGS = -Wall -pedantic -Werror -I.
all:codewar
codewar:codewar.o controle.o controlejxx.o controlebxx.o main.o affichage.o
	gcc -o $@ $^	

%.o:%.c %.h
	gcc $(CFLAGS) -c $^

