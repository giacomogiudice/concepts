CC= g++
CFLAGS=	-O3
LOBJS= alglibinternal.o alglibmisc.o ap.o dataanalysis.o diffequations.o fasttransforms.o integration.o interpolation.o linalg.o optimization.o solvers.o specialfunctions.o statistics.o

INCLUDES= -I.
LIBNAME=libalglib.a
LIBPATH=

.SUFFIXES:.cpp .o

.cpp.o:
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

all: $(LIBNAME)

$(LIBNAME): $(LOBJS)
	$(AR) -csru $@ $(LOBJS)

clean:
	rm -fr *.o *.a
