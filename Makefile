IDIR=include
SDIR=src
TDIR=target
ODIR=$(TDIR)/obj

TESTFILE=res/eatit.fuck

CC=g++
CFLAGS=-I$(IDIR)

DEST=$(TDIR)/yummy.exe

_DEPS=listener.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o listener.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o $(DEST) $^ $(CFLAGS)

test:
	./$(DEST) $(TESTFILE)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~