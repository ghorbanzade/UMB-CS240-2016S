CC = gcc
BIN_DIR = .
INC_DIR = .
SRC_DIR = .

CFLAGS = -Werror -Wall -std=gnu99 -I$(INC_DIR)

_TARGETS = fruit-basket slow-prime
LIBS1 = 
LIBS2 =
FILES1 = fruit-basket
FILES2 = slow-prime 
TARGETS = $(addprefix $(BIN_DIR)/, $(_TARGETS))
DEPS1 = $(foreach FILE, $(FILES1), $(INC_DIR)/$(FILE).h)
OBJS1 = $(foreach FILE, $(FILES1), $(BIN_DIR)/$(FILE).o)
DEPS2 = $(foreach FILE, $(FILES2), $(INC_DIR)/$(FILE).h)
OBJS2 = $(foreach FILE, $(FILES2), $(BIN_DIR)/$(FILE).o)

.PHONY: all clean

all: $(TARGETS)

$(BIN_DIR)/fruit-basket: $(OBJS1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS1)

$(BIN_DIR)/slow-prime: $(OBJS2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS2)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS1)
	$(CC) -c -o $@ $< $(CFALGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS2)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(TARGETS)
	find $(BIN_DIR) -name '*.o' -delete
