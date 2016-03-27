SER=msg_ser
SER_SRC=comm.c msg_ser.c
CLI=msg_cli
SER_SRC=comm.c msg_ser.c

CLI=msg_cli
CC=gcc
FLAGS=-g
.PHONY:all
all:$(SER) $(CLI)

BIN=pipe
CC=gcc
FLAG=-g -D_DEBUG_
SRC=pipe.c

$(BIN):$(SRC)
	$(CC) -o $@ $^ $(FLAG)
.PHONY:clean
clean:
	rm -rf $(BIN)
