client: client.o SocketIO.o
	g++ -std=c++11 client.o -o client SocketIO.o
SocketIO.o: ../SocketIO.cpp ../SocketIO.h
	g++ -std=c++11 -c    SocketIO.cpp
client.o: client.cpp
	g++ -std=c++11  -c   client.cpp
.PHONY clean:
	 rm -f *.o