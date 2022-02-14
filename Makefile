CC = gcc
OBJ = src/main.o
BIN = statics
CFLAGS = -g

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $(BIN) $(OBJ)

clean:
	rm -rf $(OBJ) $(BIN)
