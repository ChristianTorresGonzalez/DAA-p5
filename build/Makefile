CC=g++
CFLAGS=-I -std=c++11 -g -O2
LDFLAGS=-g -O2

ODIR=../src
IDIR=../include
OBJ=../obj


_OBJ = $(OBJ)/monomio.o $(OBJ)/polinomio.o $(OBJ)/main.o

all: polinomios

$(OBJ)/monomio.o: $(ODIR)/monomio.cc $(IDIR)/monomio.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ)/polinomio.o: $(ODIR)/polinomio.cc $(IDIR)/polinomio.h $(OBJ)/monomio.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ)/main.o: $(ODIR)/main.cc $(OBJ)/polinomio.o $(OBJ)/monomio.o
	$(CC) -c -o $@ $< $(CFLAGS)

polinomios: $(_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY : clean

clean:
	rm -f $(OBJ)/*.o
