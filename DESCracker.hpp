//
// Created by Athor on 11.02.2020.
//

#ifndef DES_CRACKER_DESCRACKER_HPP
#define DES_CRACKER_DESCRACKER_HPP


#include <iomanip>
#include <vector>
#include "aligned_allocator.h"


// aligned_vector is a 64 byte aligned std::vector
template<class T>
using aligned_vector = std::vector<T, aligned_allocator<T, 64>>;
//using aligned_vector = std::vector<T>;
using namespace std;

///zum Testen http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm

class DESCracker {
private:
    aligned_vector<int> calc;

public:
    DESCracker();

    void encrypt(aligned_vector<int> expansionBits, unsigned long long int numberkey);

    void setRight();

    void loadRight();

    void keyToBits(unsigned long long int number);

    void expansion();

    void permutedChoiceTwoAndKeyAddition1();
    void permutedChoiceTwoAndKeyAddition2();
    void permutedChoiceTwoAndKeyAddition3();
    void permutedChoiceTwoAndKeyAddition4();
    void permutedChoiceTwoAndKeyAddition5();
    void permutedChoiceTwoAndKeyAddition6();
    void permutedChoiceTwoAndKeyAddition7();
    void permutedChoiceTwoAndKeyAddition8();
    void permutedChoiceTwoAndKeyAddition9();
    void permutedChoiceTwoAndKeyAddition10();
    void permutedChoiceTwoAndKeyAddition11();
    void permutedChoiceTwoAndKeyAddition12();

    void permutedChoiceTwoAndKeyAddition13();

    void permutedChoiceTwoAndKeyAddition14();

    void permutedChoiceTwoAndKeyAddition15();

    void permutedChoiceTwoAndKeyAddition16();

    void substitute();

    void permutateAndAddLeftSide();

    unsigned long long int crackEncryption(string plainText, string cryptoText);

    unsigned long long int crackEncryptionNotParallel(string plainText, string cryptoText);

    unsigned long long int crackEncryptionFirstOneMil(string plainText, string cryptoText);

    string encryptAndReturn(string plainText, unsigned long long int key);

    aligned_vector<int> createFirstExpansion(string plainText);

    aligned_vector<int> plainTextToPlainBits(string plainText);

    aligned_vector<int> initialPermutation(aligned_vector<int> plainBits);

    aligned_vector<int> setRight(aligned_vector<int> initialPermutationBits);

    aligned_vector<int> expansion(aligned_vector<int> setRightBits);

    aligned_vector<int> createInverseInitialAndSwapLeftRight(string cryptoText);

    aligned_vector<int> swapLeftAndRight(aligned_vector<int> initialPermutationBits);

    aligned_vector<int> inverseInitialPermutation(aligned_vector<int> swapLeftAndRightBits);

    string cryptoBitsToHexCryptoText(aligned_vector<int> cryptoBits);
};

#endif //DES_CRACKER_DESCRACKER_HPP
