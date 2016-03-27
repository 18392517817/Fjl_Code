SER=udp_server
CLI=udp_client
CC=gcc
FLAGS=#-static
.PHONY:all
all: $(CLI) $(SER)
server:udp_server.c
	gcc -o $@ $^ $(FLAGS)
client:udp_client.c
	gcc -o $@ $^ $(FLAGS)
.PHONY:clean
clean:
	rm -f $(SER) $(CLI)
