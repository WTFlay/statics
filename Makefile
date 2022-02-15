CC = gcc
OBJ = src/main.o
BIN = statics
CFLAGS = -g
LDFLAGS = -lm

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(LDFLAGS)

clean:
	rm -rf $(OBJ) $(BIN)
