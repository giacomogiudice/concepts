CC = g++
CFLAGS = -std=c++11 
CFLAGS += -Wall			# For debugging
#CFLAGS += -O3 			# Optimization
#CFLAGS += -ffast-math 	# Use with care, can break everything

LDFLAGS = -Llib -lalglib

SRCDIR = src
LIBDIR = include/alglib
OBJDIR = build
INCLUDES = -I include

SRC = $(shell find $(SRCDIR) -name '*.cpp')
LIBSRC = $(shell find $(LIBDIR) -name '*.cpp')
OBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))
LIBOBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(LIBSRC))

ALGLIB = lib/libalglib.a
APP = bin/main

all: $(APP)

$(APP): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(APP)

lib: $(ALGLIB)

$(ALGLIB): $(LIBOBJ)
	$(AR) -csru $@ $(LIBOBJ)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ) $(LIBOBJ)

distclean:
	$(RM) $(APP) $(ALGLIB)
