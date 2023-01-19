client: client.o InputFile.o Geometry.o KnnClassification.o SocketIO.o DefaultIO.o
	g++ -std=c++11 -pthread client.o InputFile.o Geometry.o KnnClassification.o SocketIO.o DefaultIO.o -o client
client.o: client.cpp
	g++ -std=c++11  -c   client.cpp
InputFile.o: 	../InputFile.cpp ../InputFile.h
	g++ -std=c++11  -c   ../InputFile.cpp
Geometry.o: 	../ass1/Geometry.h ../ass1/Geometry.cpp
	g++ -std=c++11  -c   ../ass1/Geometry.cpp
KnnClassification.o: ../KnnClassification.cpp ../KnnClassification.h
	g++ -std=c++11  -c    ../KnnClassification.cpp
SocketIO.o: ../SocketIO.cpp ../SocketIO.h
	g++ -std=c++11 -c    ../SocketIO.cpp
DefaultIO.o: ../DefaultIO.cpp ../DefaultIO.h
	g++ -std=c++11  -c   ../DefaultIO.cpp
.PHONY clean:
	 rm -f *.o