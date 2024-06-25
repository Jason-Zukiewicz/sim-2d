# Variables
PROJECT_DIR := project
BUILD_DIR := $(PROJECT_DIR)/build
TARGET := app

# Default target
all:  make build run

# Create build directory if it doesn't exist, then configure and build the project
make:
	cd $(PROJECT_DIR) && cmake .

build:
	cd $(PROJECT_DIR) && cmake --build .

# Run the application
run: build
	./$(PROJECT_DIR)/$(TARGET)

# Clean build files
clean: clear
clear:
	rm -rf $(PROJECT_DIR)/app

# PHONY targets
.PHONY: all build run clean
