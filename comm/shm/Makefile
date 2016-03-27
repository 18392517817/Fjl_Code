SER_BIN=shm_ser
CLI_BIN=shm_cli
SER_SRC=comm.c shm_ser.c
CLI_SRC=comm.c shm_cli.c
INCLUDE=-I./
CC=gcc
FLSGE=-g 

.PHONY:all
all:$(SER_BIN) $(CLI_BIN) 

$(SER_BIN):$(SER_SRC)
	$(CC) -o $@ $^  $(FLSGE) $(INCLUDE)
$(CLI_BIN):$(CLI_SRC)
	$(CC) -o $@ $^  $(FLSGE) $(INCLUDE)

.PHONY:clean
clean:
	rm -rf $(SER_BIN) $(CLI_BIN)
