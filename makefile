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
MSLLTNAME  = mslltest
DLLTNAME   = dlltest
CLLTNAME   = clltest
LSTKTNAME  = lstktest
default: $(TARGET)

all: sll.o dll.o
	@echo 'Starting linking process...'
	#$(CC) $(LFLAGS) rbtree.o errors.o -o $(BUILD)/$(NAME)
	@echo '...done!'

slltest: sll-test.o sll.o
	@echo 'Building sll-test program..'
	$(CC) sll-test.o sll.o -o $(BUILD)/$(SLLTNAME)
	@echo '..done!'

mslltest: msll-test.o msll.o
	@echo 'Building msll-test program..'
	$(CC) msll-test.o msll.o -o $(BUILD)/$(MSLLTNAME)
	@echo '..done!'

dlltest: dll-test.o dll.o
	@echo 'Building dll-test program..'
	$(CC) dll-test.o dll.o -o $(BUILD)/$(DLLTNAME)
	@echo '..done!'

clltest: cll-test.o cll.o
	@echo 'Building cll-test program..'
	$(CC) cll-test.o cll.o -o $(BUILD)/$(CLLTNAME)
	@echo '..done!'

lstktest: lstk-test.o lstk.o
	@echo 'Building lstk-test program...'
	$(CC) lstk-test.o lstk.o $(BUILD)/$(LSTKTNAME)
	@echo '...done!'

sll-test.o: sll-test.c sll.h
	$(CC) $(CFLAGS) $(INCLUDE) $<

dll-test.o: dll-test.c dll.h
	$(CC) $(CFLAGS) $(INCLUDE) $<

msll-test.o: msll-test.c msll.h
	$(CC) $(CFLAGS) $(INCLUDE) $<

cll-test.o: cll-test.c cll.h
	$(CC) $(CFLAGS) $(INCLUDE) $<

lstk-test.o: lstk-test.c lstk.h
	$(CC) $(CFLAGS) $(INCLUDE) $<

sll.o: sll.c sll.h
	@echo 'Building singly linked list module...'
	$(CC) $(CFLAGS) $(INCLUDE) $<
	@echo '...done!'

msll.o: msll.c msll.h
	@echo 'Building macro singly linked list module...'
	$(CC) $(CFLAGS) $(INCLUDE) $<
	@echo '...done!'

dll.o: dll.c dll.h
	@echo 'Building doubly linked list module...'
	$(CC) $(CFLAGS) $(INCLUDE) $<
	@echo '...done!'

cll.o: cll.c cll.h
	@echo 'Building Circularly linked list module...'
	$(CC) $(CFLAGS) $(INCLUDE) $<
	@echo '...done!'

lstk.o: lstk.o lstk.h
	@echo 'Building linked list stack module...'
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
