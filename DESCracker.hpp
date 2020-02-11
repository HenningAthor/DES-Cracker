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
//a

///Same as DESv9 but uses aligned vectors
class DESv10 {
    aligned_vector<int> calc;
public:
    DESv10() {
        calc = aligned_vector<int>(176,
                                   0); // 0 - 111 bits for text, 112-113 help bits, 114-169 key bits (114 - 141 left, 142 - 169 right),170-191 Padding for cache
    }
    ///zum Testen http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm

public :
    void encrypt(aligned_vector<int> expansionBits, unsigned long long int numberkey);

    ///copies the bits from 32-63 to 80-111, because they are needed later and will be overwritten instead
public:
    void setRight();

    ///copies the bits from 80-111 to 0-31
public:
    void loadRight();

    ///funktioniert
public:
    void keyToBits(unsigned long long int number);

    ///funktioniert
public:
    void expansion();

    ///funktioniert
public:
    void permutedChoiceTwoAndKeyAddition1();

public:
    void permutedChoiceTwoAndKeyAddition2();

public:
    void permutedChoiceTwoAndKeyAddition3();

public:
    void permutedChoiceTwoAndKeyAddition4();

public:
    void permutedChoiceTwoAndKeyAddition5();

public:
    void permutedChoiceTwoAndKeyAddition6();

public:
    void permutedChoiceTwoAndKeyAddition7();

public:
    void permutedChoiceTwoAndKeyAddition8();

public:
    void permutedChoiceTwoAndKeyAddition9();

public:
    void permutedChoiceTwoAndKeyAddition10();

public:
    void permutedChoiceTwoAndKeyAddition11();

public:
    void permutedChoiceTwoAndKeyAddition12();

public:
    void permutedChoiceTwoAndKeyAddition13();

public:
    void permutedChoiceTwoAndKeyAddition14();

public:
    void permutedChoiceTwoAndKeyAddition15();

public:
    void permutedChoiceTwoAndKeyAddition16();

    ///funktioniert
public:
    void substitute();

    ///funktioniert
public:
    void permutateAndAddLeftSide();

public:
    unsigned long long int crackEncryption(string plainText, string cryptoText);

public:
    unsigned long long int crackEncryptionNotParallel(string plainText, string cryptoText);


public:
    unsigned long long int crackEncryptionFirstOneMil(string plainText, string cryptoText);

public:
    string encryptAndReturn(string plainText, unsigned long long int key);
};

#endif //DES_CRACKER_DESCRACKER_HPP
