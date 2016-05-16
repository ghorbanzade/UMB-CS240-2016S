CC = gcc
BIN_DIR = .
INC_DIR = .
SRC_DIR = .

CFLAGS = -Werror -Wall -std=gnu99 -I$(INC_DIR)

_TARGETS = fast-prime
LIBS =
FILES = fast-prime
ARTIFACTS = primes.log
TARGETS = $(addprefix $(BIN_DIR)/, $(_TARGETS))
DEPS = $(foreach FILE, $(FILES), $(INC_DIR)/$(FILE).h)
OBJS = $(foreach FILE, $(FILES), $(BIN_DIR)/$(FILE).o)

.PHONY: all clean

all: $(TARGETS)

$(BIN_DIR)/fast-prime: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFALGS)

clean:
	rm -rf $(TARGETS)
	rm -rf $(ARTIFACTS)
	find $(BIN_DIR) -name '*.o' -delete
