CC = gcc
CXXFLAGS = -W -Wall -Wextra -Werror -pedantic -std=c99 -O0 -g -ggdb
INCLUDE =
LIBS =

EXEC = s19
SRC = conversion.c io.c check.c decode.c file.c display.c main.c
OFILES = ${SRC:.cc=.o}

all: .depend $(OFILES)
	$(CC) $(CXXFLAGS) $(LIBS) $(OFILES) -o $(EXEC)

%.o: %.cc
	$(CC) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -f .depend
	rm -f $(OFILES)

depend: .depend

.depend: $(SRC)
	rm -f .depend
	$(CC) -MM $(INCLUDE) $^ > .depend

include .depend
