#-std=c++11
all: Server client clean
Server:  Server.o  InputFile.o KnnClassification.o Geometry.o
	g++ -std=c++11  Server.o  InputFile.o KnnClassification.o Geometry.o -o Server
InputFile.o: InputFile.cpp InputFile.h
	g++ -std=c++11  -c   InputFile.cpp
KnnClassification.o: KnnClassification.cpp KnnClassification.h
	g++ -std=c++11  -c    KnnClassification.cpp
Geometry.o: ass1/Geometry.cpp ass1/Geometry.h
	g++ -std=c++11 -c    ass1/Geometry.cpp
Server.o: Server.cpp Server.h
	g++ -std=c++11 -c   Server.cpp
client: client.o
	g++ -std=c++11 client.o -o client
client.o: client.cpp
	g++ -std=c++11  -c   client.cpp
.PHONY clean:
	 rm -f *.o
