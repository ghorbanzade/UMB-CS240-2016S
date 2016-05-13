CC = gcc
TOP_DIR = .
SRC_DIR = $(TOP_DIR)
BIN_DIR = $(TOP_DIR)

CFLAGS = -Werror -Wall -std=gnu99 -I$(SRC_DIR)

BINS = array-list linked-list
FILES1 = array-list
FILES2 = linked-list

TARGETS = $(foreach TARGET, $(BINS), $(BIN_DIR)/$(TARGET))
DEPS1 = $(foreach FILE, $(FILES1), $(SRC_DIR)/$(FILE).h)
OBJS1 = $(foreach FILE, $(FILES1), $(BIN_DIR)/$(FILE).o)
DEPS2 = $(foreach FILE, $(FILES2), $(SRC_DIR)/$(FILE).h)
OBJS2 = $(foreach FILE, $(FILES2), $(BIN_DIR)/$(FILE).o)

.PHONY: all tidy clean

all: $(BIN_DIR) $(TARGETS)

$(BIN_DIR)/array-list: $(OBJS1)
	$(CC) -o $@ $^ $(CFLAGS)

$(BIN_DIR)/linked-list: $(OBJS2)
	$(CC) -o $@ $^ $(CFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS1)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS2)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

tidy:
	rm -rf $(BIN_DIR)/*.o

clean: tidy
	rm -rf $(BINS)
