CC=g++
CFLAGS=-Wall
LDFLAGS=-Llib -lalglib

SRCDIR=src
LIBDIR=include/alglib
OBJDIR=build
INCLUDES= -I$(LIBDIR)

SRC=$(shell find $(SRCDIR) -name '*.cpp')
LIBSRC=$(shell find $(LIBDIR) -name '*.cpp')
OBJ=$(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))
LIBOBJ=$(patsubst %.cpp,$(OBJDIR)/%.o,$(LIBSRC))

ALGLIB=lib/libalglib.a
APP=bin/main

all: $(APP)

$(APP): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(APP)

lib: $(ALGLIB)

$(ALGLIB): $(LIBOBJ)
	$(AR) -csru $@ $(LIBOBJ)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(LIBOBJ)

distclean:
	$(RM) $(APP) $(ALGLIB)
