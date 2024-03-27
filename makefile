PROJECT_NAME := justc
BUILD_DIR    := bin

CC = gcc

SRCS := main.c
SRCS += src/slist.c

INC_DIR := inc

all : $(SRCS) 
	$(CC) -o $(BUILD_DIR)/$(PROJECT_NAME) $^ -I $(INC_DIR) -g
	./$(BUILD_DIR)/$(PROJECT_NAME)

clean:
	rm bin/*