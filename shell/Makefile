# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

mytoc: shell.o mytoc.o
	gcc -o shell shell.c mytoc.c

shell.o: shell.c
	gcc -c shell.c -o shell.o

mytoc.o: mytoc.c
	gcc -c mytoc.c -o mytoc.o

clean:
	rm -f *.o shell

