# Compiler
CC = gcc
CFLAGS = -Wall -g

# Files
SRC = main.c storage.c crypto.c keygen.c
OBJ = $(SRC:.c=.o)
TARGET = password_manager.exe

# Default target
all: $(TARGET)

# Build executable from object files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean temporary and output files
clean:
	del /Q $(OBJ) $(TARGET) 2>nul
	del /Q vault.dat 2>nul
