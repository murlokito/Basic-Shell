#A Simple Example Makefile for soshell
# 
# Alvo: Dependencias
# tab Action 1
# tab Action 2
#
#Variaveis: Compiler, compiler flags, libraries to link, name of of object files
#

CC=cc
FLAGS=-c -Wall
LIBS=-lm
OBS=main.o execute.o parse.o socp.o files.o help.o redirects.o tworand.o
 
#Alvo por defeito é o primeiro 
all :  soshell
 
main.o 		: shell.h main.c
	$(CC) $(FLAGS) main.c
	
execute.o   : shell.h execute.c
	$(CC) $(FLAGS) execute.c
	
parse.o     : shell.h parse.c
	$(CC) $(FLAGS) parse.c
	
socp.o      : shell.h socp.c
	$(CC) $(FLAGS) socp.c

files.o     : shell.h files.c
	$(CC) $(FLAGS) files.c

help.o    	: shell.h help.c
	$(CC) $(FLAGS) help.c
	
redirects.o : shell.h redirects.c
	$(CC) $(FLAGS) redirects.c

tworand.o : shell.h tworand.c
	$(CC) $(FLAGS) tworand.c
	
soshell     : $(OBS)
	$(CC)  -o soshell  $(OBS) $(LIBS)
	
clean limpar:
	rm -f soshell *.o
	rm *~
	echo "Limpeza dos ficheiros exectuaveis, objectos e gedit tralha"
