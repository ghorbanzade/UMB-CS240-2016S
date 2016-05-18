CC = gcc
TOP_DIR = ../../../..
BIN_DIR = $(TOP_DIR)/bin
EXE_DIR = $(BIN_DIR)/exe
DST_DIR = $(EXE_DIR)/hw03
INC_DIR = .
SRC_DIR = .

CFLAGS = -Werror -Wall -std=gnu99 -I$(INC_DIR)

_TARGETS = bmi prime reverse

TARGETS = $(foreach TARGET, $(_TARGETS), $(DST_DIR)/$(TARGET))

.PHONY: all clean

all: $(TARGETS)

$(DST_DIR)/bmi: $(SRC_DIR)/bmi.c
	$(CC) -c -o $@ $< $(CFALGS)
	$(CC) -o $@ $^ $(CFLAGS)

$(DST_DIR)/prime: $(SRC_DIR)/prime.c
	$(CC) -c -o $@ $< $(CFALGS)
	$(CC) -o $@ $^ $(CFLAGS)

$(DST_DIR)/reverse: $(SRC_DIR)/reverse.c
	$(CC) -c -o $@ $< $(CFALGS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(TARGETS)
