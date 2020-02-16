#include <iostream>
#include "DESCracker.hpp"

using namespace std;

int main() {

    string plainText = "0123456789abcdef";
    string cryptoText = "0123456789abcdef";

    auto *cracker = new DESCracker();

    cout << cracker->encryptAndReturn(plainText, 1) << endl;

    cracker->crackEncryption(plainText, cryptoText);

    delete (cracker);

    return 0;
}
