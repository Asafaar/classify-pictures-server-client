part 4 of advanced programming class

In this assignment the program recievs input from the client indicating how and where to run a knn algorithm.
The algorithm classifies an unclassified vector according to a list with classified vectors.
The k of the algorithm - the number of the k closest classified vectors to classify the vector with, is given as input.
The client may enter a chosen distance calculation metric. He may choos one of the metrics below:
Minkowski - MIN
Euclidean - AUC
Manhattan - MAN
Chebyshev - CHB
Canberra - CAN

Please note that the k param needs to be larger then the number of vectors in the classified file.

To run the program:

make

to run the Server- ./Server {port}

to run the clinet ./client {ip} {port}


important things:
1.The program needs two free ports,the port you write in the coomand line and the port after him.(For example: ./Server 12345. so the server needs the ports 12345 and 12346)
2.It is recommended to read the files from the folder names "fiels",so if you want read new file move him to this folder.
