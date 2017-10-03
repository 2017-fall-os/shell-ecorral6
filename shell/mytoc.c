/**
 * mytoc.c
 *
 * This file contains the necessary functions for tokenizing strings
 * and other string manipulation functions needed for the shell
 *
 * @author Erik Corral
 * @version 1.0
 */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Summary of countTokens
 * counts the number of tokens given a string pointer
 * @param char * str 
 * @param char delim 
 * @return int 
 * */


int countTokens(char *str, char delim)
{
  
  
  int numTokens = 0, i;
  for( i = 0; str[i] != '\0' ; i++)
    {
      if(str[i] == delim)
	{
	  numTokens++;
	}
    }


  return numTokens+1;
}

/**
 * Summary of getTokenLength
 * counts the length of a token
 * @param char * str
 * @param char delim
 * @param int numTokens
 * @return int 
 * */


void getTokenLength(int * tokenLengths, char * str, char delim, int numTokens)
{
  int i, j = 0, k = 0;

  
    for (i = 0; i < numTokens; i++)
    {
      
      while(str[j] != delim && str[j] != '\0')
	{
	 
	  tokenLengths[i] = k;  
	  k++;
	  j++;
	 
	}
     
      j++;
      
      k = 0;

    }

    tokenLengths[numTokens] = 0;
   

}

/**
 * Summary of setTokens
 * sets the tokens in a vector
 * @param char ** tokenVec
 * @param char * str
 * @param char delim
 * @param int numTokens
 * @param tokenLength
 * */

void setTokens(char ** tokenVec, char * str, char delim, int numTokens, int * tokenLength)
{
  int i, j= 0, k = 0;
  
  for (i = 0 ; i <= numTokens ; i++)
    {
      
      tokenVec[i] = (char *)malloc(tokenLength[i] + 1);
      
       while(str[j] != delim &&  str[j] != '\0' && i < numTokens)
      	{

	  if(str[j] != '\n'){
	  tokenVec[i][k] = str[j];
	  }
	          k++;
	  	  j++;
	  	 
	}
       if(i < numTokens)
	 {
       tokenVec[i][j] = '\0';
       j++;
       k = 0;
	 }
       
    }
  tokenVec[numTokens] = (char*)0;
  
}

/**
 * Summary of mytoc
 * Returns a vector of tokens
 * @param char * str
 * @param char * delim
 * @return char **
 * */

char ** mytoc(char *str, char delim)
{
  int numTokens = countTokens(str, delim);
  int tokenLengths[numTokens];
  getTokenLength(tokenLengths,str, delim, numTokens);
 char **tokenVec = (char **)calloc(numTokens+1, sizeof(char *));
 setTokens(tokenVec, str, delim, numTokens, tokenLengths);

  return tokenVec;
}

/**
 * Summary of checkExit
 * Checks to see if the first token in the vector equasl to exit
 * @param char ** tokenVec
 * @return int
 * */

  int checkExit(char ** tokenVec)
    {
      char * exit = "exit";
      int counter = 0;
      int i;
      for(i = 0; i < 4 ; i++)
	{
	
	  if(tokenVec[0][i] == exit[i])
	    {
	      counter++;
	      if(counter == 4)
		{
		  return 1;
		}
	    }
	
	}
        return 0;
    }

/**
 * Summary of freeMem
 * Frees memory allocated by the token vector
 * @param char ** tokenVec
 * */

void freeMem(char ** tokenVec)
{
  for (int i = 0 ; tokenVec[i] != '\0' ; i++)
    {
      free(tokenVec[i]);
    }
}

/**
 * Summary of saferFork
 * Creates a new child process
 * @returns pid_t
 * Written by Dr. Freudenthal
 * */

pid_t saferFork()
{
  /*fprintf(stderr, "process <%d> calling fork() in 5 seconds...", getpid()); */
  sleep(5);
  /*fprintf(stderr, "calling fork now!\n"); */
  return fork();
}

/**
 * Summary of merge
 * Merges two strings
 * @param char * path
 * @param char * cmd
 * @returns char *
 * */


  
char *  merge(char * path, char *cmd)
{
  int i = strlen(path) + 1;
  int k = strlen(cmd);
  int j = 0;
  char * fullPath  = (char *)malloc(i  + k);
	   
        
	  
  for( j = 0 ; j < i ; j++)
    {
      fullPath[j] = path[j];
    }
  fullPath[j - 1] = '/';

	 

	  
  for( j = 0; cmd[j] != '\0' ; i++, j++)
    {
      fullPath[i] = cmd[j]; 
    }
  fullPath[i] = '\0';

  return fullPath;
	 

}

/**
 * Summary of checkCommand
 * Checks to see if the file exists with the given path
 * @param char * path
 * @return int;
 * */



int checkCommand(char * path)
{
  struct stat buffer2;
  int status;

  status = stat(path, &buffer2);
  if(status == 0)
    return 1;
  else
    return 0;

}
