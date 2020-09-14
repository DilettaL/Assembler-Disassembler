#make -f Makefile
#!bin/bash

OBJS=	main.o\
	Diss.o\
	Ass.o\
	pic.o\
  
.PHONY: out clean

out: $(OBJS)
	gcc $(OBJS) -o Ass_Diss.out
	rm -rf $(OBJS)

main.o: src/main.c include/Diss.h include/Ass.h
	gcc -c src/main.c src/Diss.c src/Ass.c -I./src -I./include

Diss.o: src/Diss.c include/Diss.h
	gcc -c src/Diss.c src/pic.c -I./src -I./include

Ass.o: src/Ass.c include/Ass.h
	gcc -c src/Ass.c src/pic.c -I./src -I./include

pic.o: src/pic.c include/pic.h
	gcc -c src/pic.c -I./src -I./include 

clean:
	rm -rf $(OBJS)
