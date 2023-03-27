/*
* Eadan Plotnizky and Naama Scandarion
* Course:  CIS5371/CIS 4634
* Professor: Mehrdad Nojoumian 
*
* Description: ElGamal Public-Key Encryption implememtation
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <bitset>
#include "infint/InfInt.h"

//#define INFINT_USE_EXCEPTIONS
using namespace std;
/*
InfInt binToDec(string binStr) {
    InfInt dec = 0;
    for(InfInt i = 0; i < binStr.length(); i++){
        int j = i.toInt();
        InfInt base = 2;
        dec += (pow(base,i) * binStr[j]).toString();
    }
    return dec;
}
 */
// InfInt randomGenerator(int bitsize){
//     srand((unsigned) time(0));
//     int numDigits = (bitsize + 3) / 4;  // each digit represents 4 bits
//     string randomNumber = "";
//     for(int i = 0; i < numDigits; i++){
//         randomNumber += to_string(rand() % 10);
//     }
//     InfInt rand = randomNumber;
//     return rand;
// }

InfInt randomGenerator(int bitsize){
    srand(time(NULL));
    string randomNumber = "";
    
    while(randomNumber.length() < bitsize){
        randomNumber += to_string(rand() % 2);
        cout << randomNumber.length() << endl;
    }
    //InfInt number_string = binToDec(randomNumber);
    cout << randomNumber << endl;
    return randomNumber;
}
int randomGenerator(InfInt upperBound, InfInt lowerBound){
    srand((unsigned) time(0));
    int randomNumber = 0;
    int upper = 0;
    int lower = 0;
        int random = rand();
        
        if(upperBound < 32767){
            upper = upperBound.toInt();
            lower = lowerBound.toInt();
            randomNumber = (random % (upper - lower + 1) + lower);
        }
        else if (upperBound > 32767){
            upper = 32767;
            lower = lowerBound.toInt();
            randomNumber = (random % (upper - lower + 1) + lower);
        }
    //int rand = stoi(randomNumber);
    return randomNumber;
}

InfInt convertToASCII(string text)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        char x = text[i];
        result += to_string(int(x));
    }
    InfInt number = result;
    return number;
}
void asciiToSentence(string str, int len)
{
    int num = 0;
    for (int i = 0; i < len; i++) {
 
        // Append the current digit
        num = num * 10 + (str[i] - '0');
 
        // If num is within the required range
        if (num >= 32 && num <= 122) {
 
            // Convert num to char
            char ch = (char)num;
            cout << ch;
 
            // Reset num to 0
            num = 0;
        }
    }
}

string convertToText(InfInt number){
    
}

InfInt pow(InfInt base, InfInt exponent){
    InfInt power = 1;
    for(InfInt i = 0; i < exponent; i++){
        power *= base;
    }
    return power;
}
string RevDecToBin (InfInt n){

    string binary = "";
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
        A = pow(A, 2) % modulus;
        if(binary_exponent[i] == '1'){
            b = (A * b) % modulus;
        }
    }
   return b;
}

bool millerRabin(InfInt oddInt, int bitsize){
    InfInt s = 0;
    InfInt r = 0;
    InfInt n = oddInt - 1;
    InfInt t = 0;
    if(bitsize == 32){
        t = 30;
    }
    else if(bitsize == 64){
        t = 100;
    }
    else if(bitsize == 128){
        t = 300;
    }
    else if(bitsize == 256){
        t = 500;
    }
    else if(bitsize == 512){
        t = 700;
    }
    else if(bitsize == 768){
        t = 700;
    }
    else{
        t = 800;
    }
    while(n % 2 == 0){
        n /= 2;
        s++;
    }
    r = n;
 for(InfInt i = 1; i < t; i++){
        InfInt a = randomGenerator(oddInt - 2, 2); //will be a random interger
        InfInt y = SquareAndMultiply(a,r,oddInt);
        if( y != 1 && y != oddInt-1 ){
            InfInt j=1;
            while(j <= s - 1 && y != oddInt - 1){
                y = pow(y, 2) % oddInt;
                if(y == 1){
                    return false;
                }
                j++;
            }
            if(y != oddInt-1){
                return false;
            }
        }
    }
 return true;
}
InfInt PrimeNumberGenerator(int bitsize){
    InfInt oddInt = "";
    do{
        oddInt = randomGenerator(bitsize);
    }while(millerRabin(oddInt, bitsize) == 0);
    return oddInt;
}
    
    //return prime;
//}
int main (){
    //Testing Square and Multi
    InfInt base = 5853;
    InfInt exponent = 583374743;
    InfInt modulus = "12038821957852645118633071039078919431279167079850496265189354163801320807095724585390948367751175965727677176252712389699346980318553819523587359943199237";
    //InfInt mod = SquareAndMultiply(base, exponent, modulus);
    //cout << mod;

    //Testing Miller Rabin
    InfInt oddInt = "14696103859734266881";
    InfInt t = 64;
    InfInt prime = randomGenerator(64);
    cout << prime;

    return 0;
}