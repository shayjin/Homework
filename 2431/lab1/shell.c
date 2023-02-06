/*
 CSE 2431 - Jay Shin
 
 Instruction:
 Compile the code by simply entering 'make' in the directory.
 Execute the code by entering './mysh'.
 Enter commands as it is to run as foreground processes. ex) ls
 Enter commands with a & at the end to run as backround processes. ex) ls &
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAXLINE 80 /* 80 chars per line, per command, should be enough. */

/** The setup() routine reads in the next command line string storing it in the input buffer.
 * The line is separated into distinct tokens using whitespace as delimiters.  Setup also
 * modifies the args parameter so that it holds points to the null-terminated strings which
 * are the tokens in the most recent user command line as well as a NULL pointer, indicating the
 * end of the argument list, which comes after the string pointers that have been assigned to
 * args. ***/

void setup(char inBuffer[], char *args[],int *bkgd)
{
    int length,  /* #  characters in the command line */
        start,   /* Beginning of next command parameter           */
        i,       /* Index for inBuffer arrray          */
        j;       /* Where to place the next parameter into args[] */

    /* Read what the user enters */
    length = read(STDIN_FILENO, inBuffer, MAXLINE);

    start = -1;
    j = 0;

    if (length == 0)
        exit(0);            /* Cntrl-d was entered, end of user command stream */

    if (length < 0){
        perror("error reading command");
	exit(-1);           /* Terminate with error code of -1 */
    }

    /* Examine every character in the input buffer */
    for (i = 0; i < length; i++) {

        switch (inBuffer[i]){
        case ' ':
        case '\t' :          /* Argument separators */

            if(start != -1){
                args[j] = &inBuffer[start];    /* Set up pointer */
                j++;
            }

            inBuffer[i] = '\0'; /* Add a null char; make a C string */
            start = -1;
            break;

        case '\n':             /* Final char examined */
            if (start != -1){
                args[j] = &inBuffer[start];
                j++;
            }

            inBuffer[i] = '\0';
            args[j] = NULL; /* No more arguments to this command */
            break;

        case '&':
            *bkgd = 1;
            inBuffer[i] = '\0';
            break;

        default :             /* Some other character */
            if (start == -1)
                start = i;
	}

    }
    args[j] = NULL; /* Just in case the input line was > 80 */
}

int main(void)
{
    char inBuffer[MAXLINE]; /* Input buffer  to hold the command entered */
    char *args[MAXLINE/2+1];/* Command line arguments */
    int bkgd;             /* Equals 1 if a command is followed by '&', else 0 */	
    pid_t pid;

    while (1) {            /* Program terminates normally inside setup */
	
	bkgd = 0;

	printf("COMMAND-> ");  /* Shell prompt */
        fflush(0);
	
	setup(inBuffer, args, &bkgd); /* Get next command */

	pid = fork();	/* Forks a child process */
	
	if (pid == 0) {	/* Child Process */
		execvp(args[0], args); /* Child process will invoke execvp() */ 
		exit(1);
	} else {
		if (bkgd == 0) { /* If background is 0, the parent will wait */
			wait(NULL); 	
		}
		  
		/* The parent will not wait if background is 1, or when the user input had & at the end */
	} 	
    }

    return 0;
}


