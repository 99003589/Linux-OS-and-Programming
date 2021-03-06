all: server client

server: server.c 
	gcc -o server.out server.c -lrt
	
client: client.c 
	gcc -o client.out client.c -lrt
	
client:
	./client.out

runsol4send:
	./client.out

clean:
	rm -rf *.out *.o
