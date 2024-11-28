# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = src
INCLUDE_DIR = include
APPS_DIR = apps
BIN_DIR = bin
OBJ_DIR = obj

# Source and object files
TREE_SRC = $(SRC_DIR)/tree.c
TREE_OBJ = $(OBJ_DIR)/tree.o
MAIN_SRC = $(APPS_DIR)/main.c
MAIN_OBJ = $(OBJ_DIR)/main.o

# Executable name
EXEC = $(BIN_DIR)/myapp

# Default target
all: $(EXEC)

# Build the executable
$(EXEC): $(TREE_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Build the tree library object
$(TREE_OBJ): $(TREE_SRC) $(INCLUDE_DIR)/tree.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

# Build the main object
$(MAIN_OBJ): $(MAIN_SRC) $(INCLUDE_DIR)/tree.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

# Run the executable
run: all
	./$(EXEC)

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all run clean
