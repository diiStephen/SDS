# makefile for rbtree

.SUFFIXES: .o .c .h

vpath %.c src tests
vpath %.h include

CC        = gcc
CFLAGS    = -c -Wall -pedantic -Wextra -g
SLIBFLAGS = -c -Wall -pedantic -Wextra -g -fPIC
LFLAGS    = -shared

TARGET     = all
INCLUDEDIR = include
INCLUDE    = -I $(INCLUDEDIR)
SRC        = src
BUILD      = build
SLLTNAME   = slltest

default: $(TARGET)

all: sll.o
	@echo 'Starting linking process...'
	#$(CC) $(LFLAGS) rbtree.o errors.o -o $(BUILD)/$(NAME)
	@echo '...done!'

slltest: sll-test.o sll.o
	@echo 'Building sll-test program..'
	$(CC) sll-test.o sll.o -o $(BUILD)/$(SLLTNAME)
	@echo '..done!'

sll-test.o: sll-test.c sll.h
	$(CC) $(CFLAGS) $(INCLUDE) $<

sll.o: sll.c sll.h
	@echo 'Building singly linked list module...'
	$(CC) $(CFLAGS) $(INCLUDE) $<
	@echo '...done!'

clean:
	@echo 'Cleaning...'
	rm -f *.o
	rm -f core
	rm -f ${INCLUDEDIR}/*.h~
	rm -f ${SRC}/*.c~
	rm -f makefile~
	@echo '...done!'

cleanTEX:
	@echo 'Removing latex temp. files...'
	rm -f *.aux
	rm -f *.log
	rm -f *.out
	rm -f *.pdf
	@echo '...done!'
