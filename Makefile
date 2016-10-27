CCX=g++
CXXFLAGS=-g

MYLIBRARIES = -lncurses

OBJS = main.o amuleto.o mazmorra.o monstruo.o protagonista.o tablero.o

all: ${OBJS}
	$(CCX) $(CXXFLAGS) -o Rogue ${OBJS} ${MYLIBRARIES}
	rm  *.o
