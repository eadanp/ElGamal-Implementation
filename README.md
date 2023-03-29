# ElGamal-Implementation

***Authors: Eadan Plotnizky, Naama Scandarion***

**Programming Language: C++**

## Description:
This program lets a user choose if he wants to encrypt or decrypt a message using ElGamal cryptosystem, or the user can exit the program.

The testing of the random number to verify its primality is done using the Miller-Rabin primality test.

Encryption: The user will input a secret message to be encrypted and the bitsize to generate a random prime. 

The output will show the prime number, private key, and cyphertext (**gamma and delta**).

Decryption: The user will input the prime number, private key, gamma and delta in order to decrypt the message.
The output will be the message in decimal and text format

**To run the program through VSCode make sure you have a G++ compiler.**

## Dependencies:
InfInt.h by sercantutar - https://github.com/sercantutar/infint
This program uses the InfInt library for simple lightweight large integer opereration and storage.

## Instructions:
1. open Terminal
2. make sure you are in the right directory
### Windows:
3. type `g++ .\ElGamal.cpp .\main.cpp -o .\main.exe -w` to compile the program and to create an executable file.
4. type `./main.exe` to run the executable through the terminal.
### MacOS (with bash terminal):
3. type `g++ .\ElGamal.cpp .\main.cpp -o .\main.out -w` to compile the program and to create an executable file.
4. type `./main.out` to run the executable through the terminal.
