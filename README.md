# DES-Cracker
author: Henning Woydt, henningmartin.woydt@uni-jena.de

Introduction:
This Project deals with cracking the Data Encryption Standard (DES) published in 1977. The Standard is used to encrypt data with a 64- more specifically 56-bit key and was widly used all around the world, especially in the financial market. Because of its insufficient key bit size, it was replaced with the Advanced Encryption Standard (AES) in 2002. Although DES is not in use anymore (or should not be used anymore) this project aims to crack the encryption by Brute Force. This method is very computation heavy and will therefore use the entire CPU-Power.

How to Use:
You can use the programm either to crack the encryption or to encrypt one block of data.

1. Crack the encryption
To do this you need two components: the plaintext and the cryptotext, both of these must be hexadecimal Strings with a length of 16. The Programm will test every possible key from 0 to 72057594037927936 starting by 0. Once a key is found which encrypts the plaintext to the cryptotext the programm will stop and return the found key.
You can start the crack by locating to the directory with the DESCracker.exe in the command line and and typing

DES_Cracker 'PLAINTEXT' c 'CRYPTOTEXT'

PLAINTEXT should contain the 16 hexadecimals plaintext and CRYPTOTEXT the 16 hexadecimals cryptotext. If these strings are not 16 chars long or contain different chars than "0 1 2 3 4 5 6 7 8 9 a b c d e f", the programm will print an error message and closes. If its correct the programm will start.
The first thing the programm will print is:

Limit: 72057594037927936
Tasksize: 16777216
Iterations: 4294967296
PLAINTEXT: xxxxxxxxxxxxxxxx CRYPTOTEXT: yyyyyyyyyyyyyyyy

The limit means, that the the programm will try all keys from 0 to the limit, which is set to 72057594037927936
The Tasksize indicates how many keys are tested in one "run". These runs open a paralell region, try the number of Tasksize keys and then close the parallel region. This variable should be high, so the programm does not open and close these regions rapidly, but rather opens them and then computes for a long time before closing again.
The Iterations count shows how often we have to calculate "runs". After each run the programm prints some statistics.
The last line, PLAINTEXT... , indicates the plaintext, which is tested, and the cryptotext, which should be the result.

The statitics are printed like this:

Abs: xxx in yyy s Rel: zzz % Est time : iii h keys/sec: jjj

xxx - number of total keys tested
yyy - time the programm is running
zzz - number of keys tested in relation to how many total keys there are
iii - the estimated time it will take to test the remaining keys
jjj - how many keys the programm checks every second


2. Encrypt one block of Data
You need a data-block of 16 hexadecimal chars and your key to encrypt with. The Programm will then combine these both to compute the cryptotext.

