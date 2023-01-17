#-std=c++11
all: Server client clean
Server:  Server.o  InputFile.o KnnClassification.o Data.o ClassifyData.o CLI.o Command.o AlgoSettings.o  Geometry.o SocketIO.o StandareIO.o Upload.o DisplayResults.o DownloadResults.o DefaultIO.o
	g++ -std=c++11  Server.o  InputFile.o KnnClassification.o Data.o ClassifyData.o CLI.o Command.o AlgoSettings.o  Geometry.o SocketIO.o StandareIO.o Upload.o DisplayResults.o DownloadResults.o DefaultIO.o -o Server
InputFile.o: InputFile.cpp InputFile.h
	g++ -std=c++11  -c   InputFile.cpp
SocketIO.o: SocketIO.cpp SocketIO.h
	g++ -std=c++11  -c   SocketIO.cpp
StandareIO.o: StandareIO.cpp StandareIO.h
	g++ -std=c++11  -c   StandareIO.cpp
Upload.o: Upload.cpp Upload.h
	g++ -std=c++11  -c   Upload.cpp
DownloadResults.o: DownloadResults.cpp DownloadResults.h
	g++ -std=c++11  -c   DownloadResults.cpp
DisplayResults.o: DisplayResults.cpp DisplayResults.h
	g++ -std=c++11  -c   DisplayResults.cpp
DefaultIO.o: DefaultIO.cpp DefaultIO.h
	g++ -std=c++11  -c   DefaultIO.cpp
Data.o: Data.cpp Data.h
	g++ -std=c++11  -c  Data.cpp
ClassifyData.o: ClassifyData.cpp ClassifyData.h
	g++ -std=c++11  -c  ClassifyData.cpp
CLI.o: CLI.cpp CLI.h
	g++ -std=c++11  -c  CLI.cpp
Command.o: Command.cpp Command.h
	g++ -std=c++11  -c  Command.cpp
AlgoSettings.o: AlgoSettings.cpp AlgoSettings.h
	g++ -std=c++11  -c  AlgoSettings.cpp
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
