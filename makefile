PROJECT_NAME := justc
BUILD_DIR    := bin

CC = gcc

SRCS := main.c
SRCS += src/dlist.c
SRCS += src/slist.c
SRCS += src/rbuffer.c
SRCS += src/queue.c

SRCS += src/test/TESTqueue.c
SRCS += src/test/TESTdlist.c
SRCS += src/test/TESTslist.c
SRCS += src/test/TESTrbuffer.c


INC_DIR := inc

all : $(SRCS) 
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$(PROJECT_NAME) $^ -I $(INC_DIR) -g
	./$(BUILD_DIR)/$(PROJECT_NAME)

debug:
	gdb $(BUILD_DIR)/$(PROJECT_NAME) --eval-command=starti

clean:
	rm $(BUILD_DIR)/*