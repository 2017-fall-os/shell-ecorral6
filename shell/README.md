# os-shell-lab

This directory contains:
* code that implements a shell by using the tokenizer lab


This demo contains the following files:
 mytoc.h: header file for mytoc.c functions
 mytoc.c: implementation of string tokenizer
 shell.c: Main program for shell 
 

To compile:
~~~
$ make
~~~

To test it, try:
~~~
$ ./shell
~~~

To delete binaries:
~~~
$ make clean
~~~

current-version-changes:

1. execve now works, and shell can run programs found in the PATH location.

2. Fixed a bug with the tokenizer returning a \n when a user entered a command.



Current issues:

1. simple  pipes still wip
2. background tasks still wip
3. cd command still wip


