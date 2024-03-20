*谢泽钰 2020012544 致理-数02*

# HW-1 RSA Encryption/Decryption Cryptosystem Implementation

## Description

In this project, I independently implemented an RSA encryption/decryption cryptosystem using C++, which has been verified for reliability by 334 groups of RSA-128 random tests.

However, there are still two unresolved disadvantages with this project:

1. I employed the Miller-Rabin Test to generate random large prime numbers. However, I have only identified 8 pseudoprimes up to the first eight prime numbers. I have not found research on larger pseudoprimes, nor can I compute them using my MacBook. This implies that although the likelihood is small, it is still possible to generate composite numbers.
2. I packaged the entire project within a Docker container and ran it on both my MacBook and Lenovo PC. Surprisingly, it runs approximately 5 times faster on the Mac than on the PC. Nonetheless, it still takes 10 seconds to process one group of data. Despite attempting various optimization methods, the speed remains unsatisfactory. 🐌

Despite these two disadvantages, I completed the testing and recorded the data in `log.txt`, while other files comprise the codes and executable files. `Bint.hpp` serves as the header file for a class designed to process very large integers, whereas `func.hpp` contains simple functions necessary for the process.

For validation purposes, you can execute `docker build -t gcc_11 .` to construct the Docker image based on the current file. To run the container, please utilize `docker run -i -v .:/app -t gcc_11`. If you are utilizing a Unix-based system, it is preferable to directly execute `./main.sh`, which is a simple script file for smoother execution of the Dockerfile.

P.S. Alternatively, you may choose to run the makefile independently without using Docker. However, please be aware that the random seed I have employed might not function as anticipated, particularly on Windows platforms.

## Algorithm

### RSA Encryption/Decryption

Given a short string s (no more than 128 bits), we would like to encrypt and decrypt it with RSA-128.

First, transfer s to a large integer M. We have $M<2^{128}<10^{39}$.

Then find two random prime numbers p and q, such that $p,q\geq10^{40}>10^{39}>M$.

Let $n=pq$ so we have $\phi(n)=(p-1)(q-1)$.

Let $e=2^{16}+1=65537$​, it is proved that e is a prime number. We want $\gcd(e,p-1)=\gcd(e,q-1)=\gcd(e,\phi(n))=1$, otherwise it's necessary to regenerate p and q until success.

Use extended Euclidean algorithm we can find d such that $d\equiv e^{-1}\bmod{\phi(n)}$.

With these variants we define the RSA public key as (n, e) and private key (n, d).

During encryption we calculate $M'\equiv M^e\bmod{n}$, and $M'$ becomes the encrypted data. During decryption we calculate $M''\equiv(M')^d\equiv M^{ed}\bmod{n}$. Accoring to Euler's Theorem we know $M^{\phi{n}}\equiv 1\bmod{n}$, and hence $M^{ed}\equiv M^{k\phi(n)+1}\equiv M\bmod{n}$​.

$M''=M$ is the plaintext and decrypted data.

### Miller-Rabin Test

## References