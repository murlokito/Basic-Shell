#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <errno.h>
#include <dirent.h>
#include <math.h>

typedef struct LL{
	char *string;	
	struct LL *next;
}LinkedList;

/* HISTORY LIST OPERATION */
LinkedList *insertFirst(LinkedList *head, char *string);
void printhistory(LinkedList *head);

/* SHELL OPERATION */
void printhelp();
int parse (char *buf, char **args);
void redirects(int numargs, char *args[]);
void execute (char **args, int numargs);
int builtin (char **args, int numargs, LinkedList *head);
int ultimo (int numargs, char **args);

/* TEXT COPY */
void socp (char *src, char *dest);
int socpaux (int src, int dest);
void soread (int n, int fdin, int fdout);

/* FILE DESCRIPTORS */
int validfd (int fd);
void openfile (char *filename, int mode);
void closefd (int fd);
void fileinfo ();
int isjpeg( int fd );
int get_num_fds();

/* MATHEMATICAL OPERATIONS */
void tworand ();
void calc(char *value1, char *op, char *value2);
void bits(char *value1, char *op, char *value2);

/* STOCK MARKETS (ETC) TECHNICAL INDICATORS */
void rsi(char *filename, int periods, double top, double bottom );



					/*CONSTANTS THAT MAY BE USEFUL*/

#define BG 0		  				/* used for background process*/
#define FG 1		  				/* used for foreground process*/
#define LLFIOBUFF 256 				/* low level file input/output buffer size */
