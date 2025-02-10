PROJECT_NAME := justc
BUILD_DIR    := bin

CC = gcc

# CUSTOM_LIBC, DATA_STRUCTS
MACROS += CUSTOM_LIBC
#MACROS += DATA_STRUCTS

SRCS := main.c

ifeq ($(filter DATA_STRUCTS, $(MACROS)), DATA_STRUCTS)
SRCS += src/dlist.c
SRCS += src/slist.c
SRCS += src/rbuffer.c
SRCS += src/queue.c
SRCS += src/stack.c
SRCS += src/btree.c
SRCS += src/rrsch.c
SRCS += src/evnotif.c
SRCS += src/algos.c

SRCS += src/test/TESTqueue.c
SRCS += src/test/TESTdlist.c
SRCS += src/test/TESTslist.c
SRCS += src/test/TESTrbuffer.c
SRCS += src/test/TESTstack.c
SRCS += src/test/TESTbtree.c
SRCS += src/test/TESTrrsch.c
SRCS += src/test/TESTevnotif.c
endif

ifeq ($(filter CUSTOM_LIBC, $(MACROS)), CUSTOM_LIBC)
SRCS += src/custom_libc/custom_string.c
endif


INC_DIR := inc
CLIBC_INC_DIR := inc/custom_libc

all : $(SRCS) 
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$(PROJECT_NAME) $^ -I $(INC_DIR) -I $(CLIBC_INC_DIR) -g -W $(foreach macro, $(MACROS), -D$(macro)=1)
	./$(BUILD_DIR)/$(PROJECT_NAME)

debug:
	gdb $(BUILD_DIR)/$(PROJECT_NAME) --eval-command=starti

clean:
	rm $(BUILD_DIR)/*