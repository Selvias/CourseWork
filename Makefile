CC = gcc
CFLAGS = -Wall
CAFLAGS = -fPIC
SHRDFLAGS = -shared

APP = appsort

BIN_D = bin
SRC_D = src
OBJ_D = obj
LIB_D = libs
DLS_D = dls

APPPATH = $(BIN_D)/$(APP)
SLIBPATH = $(OBJ_D)/$(LIB_D)/libshell.so
MLIBPATH = $(OBJ_D)/$(LIB_D)/libmerge.so

SHELL_PATH = $(OBJ_D)/$(LIB_D)/ShellSort.o
MREGE_PATH = $(OBJ_D)/$(LIB_D)/MergeSort.o

#LIBRARIES
CSPATH = $(wildcard src/dls/*.c)
OSPATH = $(patsubst src/dls/%.c, obj/libs/%.o, $(CSPATH))

#OBJECTS
CPATH = $(wildcard src/*.c)
OPATH = $(patsubst src/%.c, obj/%.o, $(CPATH))

$(APPPATH) : $(OPATH)
	$(CC) $^ -L./obj/libs -lshell -lmerge -o $@

.PHONY : libs
libs : $(MLIBPATH) $(SLIBPATH)

$(MLIBPATH) : $(MREGE_PATH)
	$(CC) $(SHRDFLAGS) -o $@ $^

$(SLIBPATH) : $(SHELL_PATH)
	$(CC) $(SHRDFLAGS) -o $@ $^

$(OSPATH) : obj/libs/%.o : src/dls/%.c
	$(CC) $(CAFLAGS) $(CFLAGS) -c $< -o $@

.PHONY : obj
obj : $(OPATH)

$(OPATH) : obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean : 
	$(RM) $(APPPATH) $(SLIBPATH) $(MLIBPATH)
	find $(OBJ_D) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_D) -name '*.d' -exec $(RM) '{}' \;