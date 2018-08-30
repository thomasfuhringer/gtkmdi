CFLAGS = `pkg-config --cflags gtk+-3.0` -g
LIBS = `pkg-config --libs gtk+-3.0`
OBJ = test-mdi.o gtkmdiarea.o gtkmdichild.o
LDFLAGS = -lm 
CC	    = gcc --std=c99
LD	    = gcc

test-mdi: $(OBJ)
	$(CC) -o test-mdi $(OBJ) $(LIBS) $(LDFLAGS)

clean:
	$(RM) $(OBJ) test-mdi

all: test-mdi

run: test-mdi
	 G_MESSAGES_DEBUG=all  /lib64/ld-linux-x86-64.so.2 ./test-mdi
