/**
 * shell.c
 * This file contains the main for the shell program
 *
 * @author Erik Corral
 * @version 1.0.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "mytoc.h"
#include <string.h>


	



int  main(int argc, char**argv, char**envp)
{
  int pid;
  int pathGiven;
  int status;
  char * command;
  char * fullPath;
  char ** tokenPath;
  char ** tokenVec;
  while(1){
     
    char buffer[128];
    printf ("$ ");
    fflush(stdout);
    fgets(buffer, 128, stdin);
	

    tokenVec = mytoc(buffer, ' ');

    /* If tokenVec[0] == "Exit" Terminate the shell.
     */
    
    if(checkExit(tokenVec))
      {
	break;
      }

    if(checkCd(tokenVec))
      {
	chDir(tokenVec[1]);
	pathGiven = 2;
	
      }
    /* If tokenVec[0][0] starts with a '/' a path is more than likely
     * being specified
     */

    if(tokenVec[0][0] == '/')
      {
	pathGiven = 1;
	command = tokenVec[0];
      }

    /* If tokenVec[0][0] == blank this means the user has not entered
     * any input
     */
    
    else if (tokenVec[0][0] == '\0')
      {
	
	pathGiven = 2;
      }

    /* pathGiven = 0 if there is not a path specified
     */
    
    else
      {
	pathGiven = 0;
      }



    if(pathGiven == 0)
      {
	
	char * path = getenv("PATH");
	tokenPath = mytoc(path, ':');
	char * cmd = tokenVec[0];

	 
	 
	for(int i = 0; tokenPath[i] != '\0'    ; i++)
	  {
	   
	    fullPath = merge(tokenPath[i], cmd);
	    if(checkCommand(fullPath) == 1)
	      {
		command = cmd;
		status = 1;
		break;
	      }
	    else
	      {
		status = 0;
	      }
	  }
      }


    else if (pathGiven == 1){
    if(checkCommand(command) == 1)
      {
	
	status = 1;
      }
    else
      {
	status = 0;
      }
    }

    else
      {
	status = 2;
      }
    	 

    if (status == 1)
      {
	pid = saferFork();
	
	if(pid == 0)
	  {
	    execve(fullPath, &command, envp);
	  }
	else if (pid == -1)
	  {
	    printf("Failed to fork");
	    exit(1);
	  }
	else
	  {
	    int waitStatus;
	    waitpid(pid, &waitStatus, 0);
	  }
		 
		
	     
      }

    else if (status == 0)
      {
	printf("Command not found!\n");
      }


    /*
    
    for(int i = 0 ; tokenVec[i] != '\0' ; i++)
      {

	printf("%d: %s\n", i, tokenVec[i]);
      }

    */
       
  }


  
  freeMem(tokenPath);
  freeMem(tokenVec);


}



 



       



