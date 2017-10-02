/**
 * shell.c
 * This file contains the main for the shell program
 *
 * @author Erik Corral
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "mytoc.h"
#include <string.h>


	



int  main()
{
  int pid;
  int pathGiven;
  int status;
  char * command;
 
  char ** tokenVec;
  do{
     
    char buffer[128];
    printf ("$ ");
    fflush(stdout);
    fgets(buffer, 128, stdin);
	

    tokenVec = mytoc(buffer, ' ');
	

    if(tokenVec[0][0] == '/')
      {
	pathGiven = 1;
	command = tokenVec[0];
      }
    else
      {
	pathGiven = 0;
      }

    if(pathGiven == 0)
      {
	char * path = getenv("PATH");
	char ** tokenPath = mytoc(path, ':');
	char * cmd = tokenVec[0];

	 
	 
	for(int i = 0; i  < 9  ; i++)
	  {

	    char * fullPath = merge(tokenPath[i], cmd);
	    if(checkCommand(fullPath) == 1)
	      {
		command = cmd;
		status = 1;
	      }
	    else
	      {
		status = 0;
	      }
	  }
      }

    if(checkCommand(command) == 1)
      {
	
	status = 1;
      }
    else
      {
	status = 0;
      }

    	 

    if (status == 1)
      {
	pid = saferFork();
	if(pid == 0)
	  {
        
	  }
	     
      }

    else
      {
	printf("Command not found!\n");
      }
	 
	 
	 
	  
	
    for(int i = 0 ; tokenVec[i] != '\0' ; i++)
      {
	printf("%d: %s\n", i, tokenVec[i]);
      }
       
  }


  
  while(checkExit(tokenVec) != 1);
  freeMem(tokenVec);


}



 



       



