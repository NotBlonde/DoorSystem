# Compiler and Flags
CC = gcc
CFLAGS = -g -Wall -Werror

# Program Name
PROG = main.exe

# Source Files
SRC = main.c SafeInput.c cardholder.c

# Object Files (Derived from Source Files)
OBJ = $(SRC:.c=.o)

# Default Target
all: $(PROG)

# Build the Program
$(PROG): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ)

# Compile Source Files into Object Files
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Clean Target
clean:
	del /f $(PROG) $(OBJ)

.PHONY: all clean
