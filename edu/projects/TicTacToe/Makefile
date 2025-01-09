PROJECT_NAME := TicTacToe
BUILD_DIR    := bin

CC = gcc

SRCS := tictactoe.c

all : $(SRCS) 
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$(PROJECT_NAME) $^ -g -W

.PHONY: run
run:
	./$(BUILD_DIR)/$(PROJECT_NAME)

.PHONY: debug
debug:
	gdb $(BUILD_DIR)/$(PROJECT_NAME) --eval-command=starti

.PHONY: clean
clean:
	rm $(BUILD_DIR)/*