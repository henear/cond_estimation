BLIS_PREFIX = $(HOME)/blis
BLIS_INC    = $(BLIS_PREFIX)/include/blis
BLIS_LIB    = $(BLIS_PREFIX)/lib/libblis.a

FLAME_HOME := $(HOME)
FLAME_INC  := $(FLAME_HOME)/flame/include
FLAME_LIB  := $(FLAME_HOME)/flame/lib/libflame.a

OTHER_LIBS  = -L/usr/lib -lm -openmp 

CC          = icc
CFLAGS      = -O2 -I$(BLIS_INC) -I$(FLAME_INC) -std=c99
LINKER      = $(CC)
LDFLAGS    := -pg -L/opt/intel/fc/em64t/10.0.026/lib
LDFLAGS    += -L/usr/lib/gcc/x86_64-pc-linux-gnu/3.4.6/
LDFLAGS    += -L/usr/lib/gcc/x86_64-pc-linux-gnu/3.4.6/../../../../lib64
LDFLAGS    += -lifport -lifcore -limf -lsvml -lm -lipgo -lirc -lirc_s -ldl

OBJS        = main.o hager.o sign.o print.o myrandom.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)
	$(LINKER) -pg $(OBJS) $(FLAME_LIB) $(BLIS_LIB) $(OTHER_LIBS) $(LAPACK_LIB) $ -o main.exe

clean:
	rm -f *.exe *~ *.o

