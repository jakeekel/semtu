# Source file
SRC = /home/jake/Documents/KLEE_MCDC/test_output/TestProblemII.c
# Compiler
CC = clang
# Flags
CFLAGS=-Wall -g
# Optimization
COPT=-O0
# LLVM flags
LLVMFLAGS=-S -emit-llvm
# Include files
INCLUDES=
# Folder with libraries
LFLAGS=
# Link libraries
LIBS=
# Object files
OBJS=$(SRC:.c=.o)
# Executable
MAIN=TestProblemII
# Byte code
LLVMIR=$(SRC:.c=.bc)
all: $(MAIN)
	@echo Compiled!
$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
bc:
	$(CC) $(LLVMFLAGS) $(CFLAGS) $(INCLUDES) -c $(SRC) -o $(LLVMIR) $(LFLAGS) $(LIBS) $(INCLUDES)
	@echo Bitcode file succesfully created.
# $< - the name of the prerequisite
# <@ the name of the target of the rule
s:
	$(CC) $(LLVMFLAGS) $(CFLAGS) $(INCLUDES) -c $(SRC) 
	@echo Human readable bitcode file succesfully created.
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@
clean:
	$(RM) *.o *~ $(MAIN)
