# VectorVision: Precise Vector Classification Software

VectorVision stands as a sophisticated software solution meticulously crafted to deliver pinpoint vector classification using the K-Nearest Neighbors (KNN) algorithm. Empowering users with unparalleled precision, this potent tool seamlessly integrates client inputs to orchestrate the execution of the KNN algorithm, ensuring optimal performance and accuracy.

## Key Features

- **Customizable K Parameter**: Users wield the power to customize the 'k' parameter, dictating the number of nearest classified vectors utilized to ascertain the classification of an unclassified vector. The 'k' value must surpass the count of vectors within the classified dataset, guaranteeing precise classification.
- **Flexible Distance Metrics**: VectorVision offers a spectrum of distance calculation metrics, catering to diverse analytical requirements. Users can effortlessly select from a range of metrics, including:
  - Minkowski (MIN)
  - Euclidean (AUC)
  - Manhattan (MAN)
  - Chebyshev (CHB)
  - Canberra (CAN)
  
## Installation and Usage
### Installation
Begin by cloning the code repository from GitHub.

### Compilation
To compile the project, navigate to the project directory, open the command prompt, and execute the following commands:
```bash``` 
```make```

### Server
Initiate a server by opening a port using the following command in the command prompt:
```./Server {port}```

### Client
In the project directory, open a new command prompt window and input the following commands:
```bash```
```./client {ip} {ServerPort}```

For local testing, it's recommended to use the IP address 127.0.0.1.

## <br /><br />Authors
- [Aharon Gross](https://github.com/AharonGross1)
- [Asaf Rozen](https://www.github.com/asafaar)
