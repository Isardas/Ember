CFLAGS=-I./include
SRC_DIR=src
BUILD_DIR=build
CC=gcc
TEST_DIR=tests

$(BUILD_DIR)/ember: $(wildcard $(SRC_DIR)/*.c)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/ember $(CFLAGS) $(wildcard $(SRC_DIR)/*.c)

