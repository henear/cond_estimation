CC          = icc -mkl
CFLAGS      = -O2 -g -I$(BLIS_INC) -I$(FLAME_INC) -std=c99
LINKER      = $(CC)

OBJS        = cond.o myrandom.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)
	$(LINKER) $(OBJS) $(OTHER_LIBS) $(LAPACK_LIB) $ -o main.exe

clean:
	rm -f *.exe *~ *.o

