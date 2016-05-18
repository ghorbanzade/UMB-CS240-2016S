CC = gcc
TOP_DIR = ../../../..
BIN_DIR = $(TOP_DIR)/bin
EXE_DIR = $(BIN_DIR)/exe
DST_DIR = $(EXE_DIR)/hw05
INC_DIR = .
SRC_DIR = .

CFLAGS = -Werror -Wall -std=gnu99 -I$(INC_DIR)

_TARGETS = array-generate array-sort

TARGETS = $(foreach TARGET, $(_TARGETS), $(DST_DIR)/$(TARGET))

.PHONY: all clean

all: $(TARGETS)

$(DST_DIR)/array-generate: $(SRC_DIR)/array-generate.c $(SRC_DIR)/array-utils.c
	$(CC) -c -o $@ $< $(CFALGS)
	$(CC) -o $@ $^ $(CFLAGS)

$(DST_DIR)/array-sort: $(SRC_DIR)/array-sort.c $(SRC_DIR)/array-utils.c
	$(CC) -c -o $@ $< $(CFALGS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TARGETS)
