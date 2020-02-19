#include <iostream>
#include "DESCracker.hpp"

using namespace std;

int main(int argc, char** argv) {

    /*
    if(argc != 3)
    {
        cout << "Please enter either" << endl;
        cout << "1. 'PLAINTEXT' 'CRYPTOTEXT'    /Both must be a 16 hexadecimal String" << endl;
        cout << "2. 'PLAINTEXT' 'KEY'           /PLAINTEXT must be a 16 hexadecimal String and 0 <= KEY <= 72057594037927936" << endl;
        basic_istream<char> x = cin;
    }
     */

    string plainText = "0123456789abcdef";
    string cryptoText = "0123456789abcdef";

    DESCracker::crackEncryption(plainText, cryptoText);

    return 0;
}
