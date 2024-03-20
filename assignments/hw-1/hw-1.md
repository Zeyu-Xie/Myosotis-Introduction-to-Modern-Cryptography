# HW-1 RSA Encryption/Decryption Cryptosystem Implementation

## Description

In this project, I independently implemented an RSA encryption/decryption cryptosystem using C++, which has been verified for reliability by 334 groups of RSA-128 random tests.

However, there are still two unresolved disadvantages with this project:

1. I employed the Miller-Rabin Test to generate random large prime numbers. However, I have only identified 8 pseudoprimes up to the first eight prime numbers. I have not found research on larger pseudoprimes, nor can I compute them using my MacBook. This implies that although the likelihood is small, it is still possible to generate composite numbers.
2. I packaged the entire project within a Docker container and ran it on both my MacBook and Lenovo PC. Surprisingly, it runs approximately 5 times faster on the Mac than on the PC. Nonetheless, it still takes 10 seconds to process one group of data. Despite attempting various optimization methods, the speed remains unsatisfactory.

Despite these two disadvantages, I completed the testing and recorded the data in `log.txt`, while other files comprise the codes and executable files. `Bint.hpp` serves as the header file for a class designed to process very large integers, whereas `func.hpp` contains simple functions necessary for the process.

For validation purposes, you can execute `docker build -t gcc_11 .` to construct the Docker image based on the current file. To run the container, please utilize `docker run -i -v .:/app -t gcc_11`. If you are utilizing a Unix-based system, it is preferable to directly execute `./main.sh`, which is a simple script file for smoother execution of the Dockerfile.

P.S. Alternatively, you may choose to run the makefile independently without using Docker. However, please be aware that the random seed I have employed might not function as anticipated, particularly on Windows platforms.

## Algorithm

### RSA Encryption/Decryption

### Miller-Rabin Test

## References