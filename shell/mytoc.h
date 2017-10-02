/**
 * mytoc.h
 *
 * This file contains the necessary functions in order to call them throughout other c files
 * such as test.c
 * @author Erik Corral
 * @version 1.0
 */



int countTokens(char *str, char delim);
void getTokenLength(int * tokenLengths, char * str, char delim, int numTokens);
void setTokens(char ** tokenVec, char * str, char delim, int numTokens, int * tokenLength);
char ** mytoc( char * str, char delim);
int checkExit(char ** tokenVec);
void freeMem(char ** tokenVec);
pid_t saferFork();
char * merge(char * path, char *cmd);
int checkCommand(char * path);
