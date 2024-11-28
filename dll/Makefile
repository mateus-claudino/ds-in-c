# Compiler
CC = gcc

# Directories
APPS_DIR = apps
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Files
MAIN = $(APPS_DIR)/main.c
DEQUE_SRC = $(SRC_DIR)/dll.c
DEQUE_OBJ = $(OBJ_DIR)/dll.o
DEQUE_HEADER = $(INC_DIR)/dll.h
OUTPUT = $(BIN_DIR)/main

# Flags
CFLAGS = -I$(INC_DIR) -Wall

# Ensure obj and bin directories exist before compiling
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Rule for creating the object file for deque
$(DEQUE_OBJ): $(DEQUE_SRC) $(DEQUE_HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(DEQUE_SRC) -o $(DEQUE_OBJ)

# Rule for linking the object files into the final executable
$(OUTPUT): $(MAIN) $(DEQUE_OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(MAIN) $(DEQUE_OBJ) -o $(OUTPUT)

# Build target to compile everything
.PHONY: build
build: $(OUTPUT)

# Clean up the build artifacts
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Default target (alias for build)
.PHONY: all
all: build
