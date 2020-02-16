#include <iostream>
#include "DESCracker.hpp"

using namespace std;

int main() {

    string plainText = "0123456789abcdef";
    string cryptoText = "0123456789abcdef";

    DESCracker::crackEncryption(plainText, cryptoText);

    return 0;
}
