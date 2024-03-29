#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++.exe
WINDRES = windres

INC = 
CFLAGS = 
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -Wall -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB) -lopengl32 -lglu32
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/libglstereo.a

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -Wall -O2 -march=native
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB) -lopengl32 -lglu32
LDFLAGS_RELEASE = $(LDFLAGS)
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/libglstereo.a

ifeq ($(findstring MINGW, $(uname)), MINGW)
OBJ_DEBUG = $(OBJDIR_DEBUG)/resources/resource.o $(OBJDIR_DEBUG)/src/glstereo.o $(OBJDIR_DEBUG)/src/glstereoerror.o $(OBJDIR_DEBUG)/src/glstereomath.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/resources/resource.o $(OBJDIR_RELEASE)/src/glstereo.o $(OBJDIR_RELEASE)/src/glstereoerror.o $(OBJDIR_RELEASE)/src/glstereomath.o
else
OBJ_DEBUG = $(OBJDIR_DEBUG)/src/glstereo.o $(OBJDIR_DEBUG)/src/glstereoerror.o $(OBJDIR_DEBUG)/src/glstereomath.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/src/glstereo.o $(OBJDIR_RELEASE)/src/glstereoerror.o $(OBJDIR_RELEASE)/src/glstereomath.o
endif


all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/resources || mkdir -p $(OBJDIR_DEBUG)/resources
	test -d $(OBJDIR_DEBUG)/src || mkdir -p $(OBJDIR_DEBUG)/src

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(AR) rcs $(OUT_DEBUG) $(OBJ_DEBUG)

ifeq ($(findstring MINGW, $(uname)), MINGW)
$(OBJDIR_DEBUG)/resources/resource.o: resources/resource.rc
	$(WINDRES) -i resources/resource.rc -J rc -o $(OBJDIR_DEBUG)/resources/resource.o -O coff $(INC_DEBUG)
endif

$(OBJDIR_DEBUG)/src/glstereo.o: src/glstereo.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/glstereo.c -o $(OBJDIR_DEBUG)/src/glstereo.o

$(OBJDIR_DEBUG)/src/glstereoerror.o: src/glstereoerror.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/glstereoerror.c -o $(OBJDIR_DEBUG)/src/glstereoerror.o

$(OBJDIR_DEBUG)/src/glstereomath.o: src/glstereomath.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/glstereomath.c -o $(OBJDIR_DEBUG)/src/glstereomath.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/resources
	rm -rf $(OBJDIR_DEBUG)/src

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/resources || mkdir -p $(OBJDIR_RELEASE)/resources
	test -d $(OBJDIR_RELEASE)/src || mkdir -p $(OBJDIR_RELEASE)/src

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(AR) rcs $(OUT_RELEASE) $(OBJ_RELEASE)

ifeq ($(findstring MINGW, $(uname)), MINGW)

$(OBJDIR_RELEASE)/resources/resource.o: resources/resource.rc
	$(WINDRES) -i resources/resource.rc -J rc -o $(OBJDIR_RELEASE)/resources/resource.o -O coff $(INC_RELEASE)
endif

$(OBJDIR_RELEASE)/src/glstereo.o: src/glstereo.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/glstereo.c -o $(OBJDIR_RELEASE)/src/glstereo.o

$(OBJDIR_RELEASE)/src/glstereoerror.o: src/glstereoerror.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/glstereoerror.c -o $(OBJDIR_RELEASE)/src/glstereoerror.o

$(OBJDIR_RELEASE)/src/glstereomath.o: src/glstereomath.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/glstereomath.c -o $(OBJDIR_RELEASE)/src/glstereomath.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/resources
	rm -rf $(OBJDIR_RELEASE)/src

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

