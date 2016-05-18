CC = gcc
TOP_DIR = ../../../..
BIN_DIR = $(TOP_DIR)/bin
EXE_DIR = $(BIN_DIR)/exe
DST_DIR = $(EXE_DIR)/ls03
INC_DIR = .
SRC_DIR = .

CFLAGS = -Werror -Wall -std=gnu99 -I$(INC_DIR)

_TARGETS = comment hello-world printf

TARGETS = $(foreach TARGET, $(_TARGETS), $(DST_DIR)/$(TARGET))

.PHONY: all clean

all: $(TARGETS)

$(DST_DIR)/%: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFALGS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TARGETS)
