# h8d makefile

# source
SOURCE = h8d.c

# compiler
CC = gcc

# compiler flags
# -ansi for ansi c standard
# - Wall for compiler warnings
CFLAGS = -Wall -ansi -pedantic

# output file (executable)
OUT = h8d

# compile
all :	$(SOURCE)
	$(CC) $(SOURCE) $(CFLAGS) -o $(OUT)

# clean
clean :
	-rm $(OUT)

