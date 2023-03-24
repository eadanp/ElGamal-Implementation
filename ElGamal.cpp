/*
* Eadan Plotnizky and Naama Scandarion
* Course:  CIS5371/CIS 4634
* Professor: Mehrdad Nojoumian 
*
* Description: ElGamal Public-Key Encryption implememtation
*/
#include <iostream>
#include <random>
#include <string>
#include <math.h>
#include <bitset>
#include "infint/InfInt.h"

//#define INFINT_USE_EXCEPTIONS
using namespace std;

string RevDecToBin (InfInt n){

    string binary = "";
    string ordered = "";
    int i = 0;
    while(n > 0){
        binary += (n % 2).toString();
        n = n / 2;
        i++;
    }
    return binary;
}

//needs to get int from user and convert to string
InfInt SquareAndMultiply(InfInt base, InfInt exponent, InfInt modulus){
    string binary_exponent = RevDecToBin(exponent);
    InfInt b = 1;
    if(exponent == 0){
        return b;
    }
    InfInt A = base;
    if(binary_exponent[0] == '1'){
        b = base;
    }
    for(int i = 1; i < binary_exponent.length(); i++){
        A = (A*A) % modulus;
        if(binary_exponent[i] == '1'){
            b = (A * b) % modulus;
        }
    }
   return b;
}

bool millerRabin(int oddInt,int t){
    int s = 0;
    int r = 0;
    int n = oddInt - 1;
    while(n % 2 == 0){
        n /= 2;
        s++;
    }
    r = n;
 for(int i = 0; i < t; i++){
    int a; //will be a random interger
    //SandM(); //s and m algorithm 
 }
 return true;
}

int main (){
    InfInt base = 5853;
    InfInt exponent = 5833;
    InfInt modulus = "176773869259263768514900337386132791437";
    InfInt mod = SquareAndMultiply(base, exponent, modulus);
    cout << mod;
    return 0;
}