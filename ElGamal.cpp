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
#include "infint_lib/InfInt.h"

//#define INFINT_USE_EXCEPTIONS
using namespace std;
//Algorithm to convert binary string to decimal value. taken from https://www.geeksforgeeks.org/program-binary-decimal-conversion/
InfInt binaryToDecimal(string n)
{
    string num = n;
    InfInt dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    InfInt base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
//overloding power function that works with big integers
InfInt pow(InfInt base, InfInt exponent){
    InfInt power = 1;
    for(InfInt i = 0; i < exponent; i++){
        power *= base;
    }
    return power;
}

//convert a decimal to its binary form in reverse order
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
string DecToBin (InfInt n){

    string binary = "";
    int i = 0;
    while(n > 0){
        binary = (n % 2).toString() + binary;
        n = n / 2;
        i++;
    }
    return binary;
}

//Generate N bit binary string and uses binaryToDecimal(string n) to returns its decimal value
InfInt randomGenerator(int bitsize){
    srand(time(NULL));
    string randomNumber = "1";
    
    for (int i = 0; i < bitsize-1; i++){
        int num = ((int)rand() % 2);
        randomNumber += to_string(num);
        //cout << randomNumber.length() << endl;
    }
    InfInt number_string = binaryToDecimal(randomNumber);
    //cout << randomNumber << endl;
    return number_string;
}
InfInt randomGenerator(InfInt upperBound, InfInt lowerBound){
    InfInt randomNumber = "0";

    InfInt random = randomGenerator(DecToBin(upperBound).length() - 1);
    randomNumber = (random % (upperBound - lowerBound + 1) + lowerBound);
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
/*
string convertToText(InfInt number){
    
}

*/

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
    if(bitsize <= 64){
        t = 100;
    }
    else if(bitsize <= 256){
        t = 300;
    }
    else{
        t = 300;
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
/*
InfInt alphaGenerator(InfInt upperBound, InfInt lowerBound){
    InfInt randomNumber = "0";

    InfInt random = randomGenerator(DecToBin(upperBound).length() - 1);
    randomNumber = (random % (upperBound - lowerBound + 1) + lowerBound);
    cout << random << endl;
    return randomNumber;
}
    */
char* whatIsTheTime(){
    time_t now = time(0);
    char* date_time = ctime(&now);

    return date_time;
}
int main (){
    //start time
    cout << "start time: " << whatIsTheTime() << endl;

    InfInt p = "10";
    InfInt q = "1";
    cout << PrimeNumberGenerator(256) << endl;
    
    //End time
    cout << endl << "end time: " << whatIsTheTime();

    return 0;
}