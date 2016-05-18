CC = gcc
TOP_DIR = ../../../..
BIN_DIR = $(TOP_DIR)/bin
EXE_DIR = $(BIN_DIR)/exe
DST_DIR = $(EXE_DIR)/ls16
INC_DIR = .
SRC_DIR = .

CFLAGS = -Werror -Wall -std=gnu99 -I$(INC_DIR)

_TARGETS = daltons student1 student2

TARGETS = $(foreach TARGET, $(_TARGETS), $(DST_DIR)/$(TARGET))

.PHONY: all clean

all: $(TARGETS)

$(DST_DIR)/%: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFALGS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TARGETS)
