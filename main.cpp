#include <iostream>
#include "DESCracker.hpp"

using namespace std;

int main(int argc, char** argv) {

    if(argc != 4) {
        cout << "Please enter either" << endl;
        cout << "1. 'PLAINTEXT' c 'CRYPTOTEXT'    /Both must be a 16 hexadecimal String" << endl;
        cout << "2. 'PLAINTEXT' k 'KEY'           /PLAINTEXT must be a 16 hexadecimal String and 0 <= KEY <= 72057594037927936" << endl;
        //cin >> *argv;
        return -1;
    }
    //read first parameter
    int i = 0;
    string plainText = "";
    while(argv[1][i] != '\0')
    {
        if((48 <= argv[1][i] && argv[1][i] <= 57) || (97 <= argv[1][i] && argv[1][i] <= 102))
        {
            plainText.push_back(argv[1][i]);
        } else{
            cerr << "PLAINTEXT is not in hexadecmial text" << endl;
            return -1;
        }
        i++;
    }
    if(i != 16)
    {
        cerr << "PLAINTEXT does not have the length of 16!" << endl;
        return -1;
    }

    bool modeEncrypt = true; //if true, starts decrypting the message. if false, encrypts the message
    string cryptoText = "";
    unsigned long long int key = 0;
    //Read the third parameter as a hex-string
    if(argv[2][0] == 'c')
    {
        modeEncrypt = true;
        i = 0;
        while(argv[3][i] != '\0')
        {
            if((48 <= argv[3][i] && argv[3][i] <= 57) || (97 <= argv[3][i] && argv[3][i] <= 102))
            {
                cryptoText.push_back(argv[3][i]);
            } else{
                cerr << "CRYPTOTEXT is not in hexadecimal text" << endl;
                return -1;
            }
            i++;
        }
        if(i != 16)
        {
            cerr << "CRYPTOTEXT does not have the length of 16!" << endl;
            return -1;
        }
    }
    //Read the third parameter as the key
    if(argv[2][0] == 'k')
    {
        modeEncrypt = false;
        i = 0;
        while(argv[3][i] != '\0') {
            if (argv[3][i] >= 48 && argv[3][i] <= 57) {
                key = key * 10 + (argv[3][i] - 48);
            } else {
                cerr << "KEY is not numerical!" << endl;
                return -1;
            }
            i++;
        }
    }
    if(!(0 <= key && key <= 72057594037927936))
    {
        cerr << "KEY is not in the valid space of 0 to 72057594037927936" << endl;
        return -1;
    }
    //Wrong second parameter inserted
    if(argv[2][0] != 'c' && argv[2][0] != 'k')
    {
        cout << "Please enter either" << endl;
        cout << "1. 'PLAINTEXT' c 'CRYPTOTEXT'    /Both must be a 16 hexadecimal String" << endl;
        cout << "2. 'PLAINTEXT' k 'KEY'           /PLAINTEXT must be a 16 hexadecimal String and 0 <= KEY <= 72057594037927936" << endl;
        //cin >> *argv;
        return -1;
    }

    if(modeEncrypt) {
        cout << "Starting KEY search" << endl;
        cout << plainText << " " << cryptoText << endl;
        DESCracker::crackEncryption(plainText, cryptoText);
    }else{
        auto *cracker = new DESCracker();
        cout << "Encrypting PLAINTEXT" << endl;
        cout << plainText << " to " << cracker->encryptAndReturn(plainText, key) << " with key " << key << endl;
        delete(cracker);
    }

    return 0;
}
