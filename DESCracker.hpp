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
    static unsigned long long int crackEncryption(const string& plainText, const string& cryptoText);
    string encryptAndReturn(const string& plainText, unsigned long long int key);
    static aligned_vector<int> createFirstExpansion(const string& plainText);
    static aligned_vector<int> plainTextToPlainBits(const string& plainText);
    static aligned_vector<int> initialPermutation(aligned_vector<int> plainBits);
    static aligned_vector<int> setRight(aligned_vector<int> initialPermutationBits);
    static aligned_vector<int> expansion(aligned_vector<int> setRightBits);
    static aligned_vector<int> createInverseInitialAndSwapLeftRight(const string& cryptoText);
    static aligned_vector<int> swapLeftAndRight(aligned_vector<int> initialPermutationBits);
    static aligned_vector<int> inverseInitialPermutation(aligned_vector<int> swapLeftAndRightBits);
    static string cryptoBitsToHexCryptoText(aligned_vector<int> cryptoBits);
};

#endif //DES_CRACKER_DESCRACKER_HPP
