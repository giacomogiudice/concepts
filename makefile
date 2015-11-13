CXX = g++
CXXFLAGS = -std=c++11 
CXXFLAGS += -march=native -mtune=native # Create code specific for the native architecture
CXXFLAGS += -O3 						# Biggest optimization level
#CXXFLAGS += -ffast-math 				# Use with care, can break everything

LDFLAGS = -Llib -lalglib -fopenmp

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

all: $(ALGLIB) $(APP)

debug: CXXFLAGS +=  -g -Wall -pedantic -DDEBUG
debug: $(APP)

lib: $(ALGLIB)

$(APP): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(APP) $(LDFLAGS)

$(ALGLIB): $(LIBOBJ)
	$(AR) -csru $@ $(LIBOBJ)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ) $(LIBOBJ)

distclean:
	$(RM) $(APP) $(ALGLIB) $(OBJ) $(LIBOBJ)
