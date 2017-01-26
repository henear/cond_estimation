CC          = icc -mkl
CFLAGS      = -O2 -g -pg -I$(BLIS_INC) -I$(FLAME_INC) -std=c99
LINKER      = $(CC) -pg

OBJS        = main.o hager.o norm1v.o normiv.o sign.o print.o oneNrm.o infNrm.o utyb.o upyb.o loyb.o ltyb.o lufac.o copy.o myrandom.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)
	$(LINKER) $(OBJS) $(LAPACK_LIBS) $(OTHER_LIBS) -o main.exe

clean:
	rm -f *.exe *~ *.o

