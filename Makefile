CC = gcc
CFLAGS = -Wall

APP = appsort

BIN_D = bin
SRC_D = src
OBJ_D = obj

APPPATH = $(BIN_D)/$(APP)
LIBPATH = $(OBJ_D)/mainlib.a

SHELL_PATH = $(OBJ_D)/ShellSort.o
MREGE_PATH = $(OBJ_D)/MergeSort.o
MAIN_PATH = $(OBJ_D)/main.o

$(APPPATH) : $(LIBPATH)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBPATH) : $(SHELL_PATH) $(MREGE_PATH) $(MAIN_PATH)
	ar r $@ $^

$(OBJ_D)/%.o : $(SRC_D)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY : clean
clean : 
	$(RM) $(APPPATH) $(LIBPATH)
	find $(OBJ_D) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_D) -name '*.d' -exec $(RM) '{}' \;