BIN=bigdatatest
SRC=bigdatatest.c bigdata.c
INCLUDE=-I./
CC=g++
FLSGE=-g

$(BIN):$(SRC)
	$(CC) -o $@ $^ $(FLSGE) $(INCLUDE)

.PHONY:clean
clean:
	rm -rf $(BIN)
