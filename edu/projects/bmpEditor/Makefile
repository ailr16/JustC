PROJECT_NAME := bmpEditor
BUILD_DIR    := bin

CC = gcc

SRCS   := src/main.c
SRCS   += src/bmpEditor.c
INCDIR := inc/

all : $(SRCS) 
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$(PROJECT_NAME) $^ -I $(INCDIR)-g -W

.PHONY: run
run:
	./$(BUILD_DIR)/$(PROJECT_NAME)

.PHONY: debug
debug:
	gdb $(BUILD_DIR)/$(PROJECT_NAME) --eval-command=starti

.PHONY: clean
clean:
	rm $(BUILD_DIR)/*