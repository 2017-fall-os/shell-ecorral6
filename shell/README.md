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


Current issues:

1. execve is still a wip
2. when using stat call to check if path contains a program, the array of chars seems to have extra characters at the end causing stat to always return a -1
3. wait implemention is also a wip
4. reading pipes still wip


