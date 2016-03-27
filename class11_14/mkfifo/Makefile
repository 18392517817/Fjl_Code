BIN=mkfifo
CC=gcc
FLAG=-g
SRC=mkfifo.c

$(BIN):$(SRC)
	$(CC) -o $@ $^ $(FLAG)
.PHONY:clean
clean:
	rm -rf $(BIN)
