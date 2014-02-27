CC = gcc
CXXFLAGS = -W -Wall -Wextra -Werror -pedantic -std=c99 -O0 -g -ggdb
INCLUDE =
LIBS =

EXEC = s19
SRC = conversion.c io.c check.c decode.c file.c display.c main.c
OFILES = ${SRC:.c=.o}

all: .depend $(OFILES)
	$(CC) $(CXXFLAGS) $(LIBS) $(OFILES) -o $(EXEC)

%.o: %.c
	$(CC) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

doc:
	doxygen Doxyfile

clean:
	rm -f .depend
	rm -f $(OFILES)
	rm -Rf doc

depend: .depend

.depend: $(SRC)
	rm -f .depend
	$(CC) -MM $(INCLUDE) $^ > .depend

.PHONY: doc

include .depend
