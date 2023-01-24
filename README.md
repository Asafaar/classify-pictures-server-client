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

to run the Server- ./Server {file name} {port}

to run the clinet ./client {ip} {port}
