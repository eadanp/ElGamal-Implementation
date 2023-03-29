#include "ElGamal.h"
extern InfInt gammma;
extern InfInt delta; 
extern InfInt p;
extern InfInt a;

int main (){   
    int exit = 0;
    string message = "";
    int bitsize = 0;
    while(exit != 3){
        cout << "Welcome to the ElGamal Encryptor/Decryptor Program!" << endl << endl;
        cout << "1. Encryption" << endl << "2. Decryption" << endl << "3. EXIT" << endl;
        cout << "Choose one of the following options (1-3): ";
        cin >> exit;

        if(exit == 1){
            //secret message input
            cout << endl << "Please enter your secret message: ";
            cin.ignore();
            getline(cin, message);
            
            //bitsize input
            do{
                cout << endl << "Enter a bit size larger than " << message.length()*8 << endl;
                cout << endl << "Please enter the bit size (32, 64, 128, 256, 512, 1024): ";
                cin >> bitsize;
            }while((message.length()*8) >= bitsize);

            if(bitsize > 1024){
                int choice = 0;
                cout << "WARNING: Your bitsize is large! it will take a lot of time to compute. Do you wish to continue (enter 0) or re-enter (enter 1)? : ";
                cin >> choice;
                if(choice == 1){
                    cout << endl << "Please enter the bit size (32, 64, 128, 256, 512, 1024): ";
                    cin >> bitsize;
                }
            }       
            
            encryption(bitsize, message);
            cout << endl << "Ciphertext is Gamma: " << gammma << " + Delta: " << delta << endl;
        }

        else if(exit == 2){
           //secret message input
            cout << endl << "Please enter your Gamma: ";
            cin >> gammma;
            cout << endl << "Please enter your Delta: ";
            cin >> delta;
            cout << endl << "Please enter your Prime Number: ";
            cin >> p;
            cout << endl << "Please enter your Private Key: ";
            cin >> a;
            
            decryption();
        }
        else if(exit == 3){
            cout << endl << "Thank you for using our ElGamal program!";
        }
        else {
            cout << endl << "Please enter a choice from 1-3." << endl << endl;
        }
    }


    //start time
    //InfInt p = PrimeNumberGenerator(32);


    //InfInt q = "1";
    //cout << PrimeNumberGenerator(256) << endl;
    //PublicKeyGenreation();
    //cout << p;
    
    //encryption(64);
    
    //cout << decryption();
    //End time
    //cout << endl << "end time: " << whatIsTheTime();
    //cout << asciiToText(104101108108111);
    //string decMessage = asciiToSentence(message, message.length());
    return 0;
}