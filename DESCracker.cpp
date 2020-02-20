//
// Created by Athor on 11.02.2020.
//

#include <iomanip>
#include <utility>
#include <vector>
#include <omp.h>
#include <iostream>

#include "DESCracker.hpp"

using namespace std;

// aligned_vector is a 64 byte aligned std::vector
template<class T>
using aligned_vector = std::vector<T, aligned_allocator<T, 64>>;

DESCracker::DESCracker() {
    calc = aligned_vector<int>(176,
                               0); // 0 - 111 bits for text, 112-113 help bits, 114-169 key bits (114 - 141 left, 142 - 169 right),170-191 Padding for cache
}

void DESCracker::encrypt(aligned_vector<int> expansionBits, const unsigned long long int numberkey) {
    calc = move(expansionBits);
    keyToBits(numberkey);

    //Runde 1
    permutedChoiceTwoAndKeyAddition1();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 2
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition2();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 3
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition3();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 4
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition4();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 5
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition5();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 6
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition6();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 7
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition7();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 8
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition8();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 9
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition9();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 10
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition10();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 11
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition11();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 12
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition12();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 13
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition13();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 14
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition14();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 15
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition15();
    substitute();
    permutateAndAddLeftSide();
    loadRight();

    //Runde 16
    setRight();
    expansion();
    permutedChoiceTwoAndKeyAddition16();
    substitute();
    permutateAndAddLeftSide();
    loadRight();
}

void DESCracker::setRight() {
    for (int i = 0; i < 32; i++) {
        calc[i + 80] = calc[i + 32];
    }
}

void DESCracker::loadRight() {
    for (int i = 0; i < 32; i++) {
        calc[i] = calc[i + 80];
    }
}

void DESCracker::keyToBits(unsigned long long int number) {
    for (int i = 0; i < 56; i++) {
        calc[169 - i] = 0 != (number & 0x01);
        number = number >> 1;
    }
}

void DESCracker::expansion() {
    calc[112] = calc[33];
    calc[79] = calc[32];
    calc[78] = calc[63];
    calc[77] = calc[62];
    calc[76] = calc[61];
    calc[75] = calc[60];
    calc[74] = calc[59];
    calc[73] = calc[60];
    calc[72] = calc[59];
    calc[71] = calc[58];
    calc[70] = calc[57];
    calc[69] = calc[56];
    calc[68] = calc[55];
    calc[67] = calc[56];
    calc[66] = calc[55];
    calc[65] = calc[54];
    calc[64] = calc[53];
    calc[33] = calc[32];
    calc[32] = calc[63];
    calc[62] = calc[51];
    calc[61] = calc[52];
    calc[60] = calc[51];
    calc[63] = calc[52];
    calc[52] = calc[45];
    calc[55] = calc[48];
    calc[57] = calc[48];
    calc[59] = calc[50];
    calc[48] = calc[43];
    calc[50] = calc[43];
    calc[45] = calc[40];
    calc[43] = calc[40];
    calc[40] = calc[37];
    calc[56] = calc[47];
    calc[54] = calc[47];
    calc[47] = calc[42];
    calc[58] = calc[49];
    calc[49] = calc[44];
    calc[51] = calc[44];
    calc[42] = calc[39];
    calc[44] = calc[39];
    calc[37] = calc[36];
    calc[39] = calc[36];
    calc[53] = calc[46];
    calc[46] = calc[41];
    calc[41] = calc[38];
    calc[36] = calc[35];
    calc[38] = calc[35];
    calc[35] = calc[34];
    calc[34] = calc[112];
}

void DESCracker::permutedChoiceTwoAndKeyAddition1() {
    calc[79] = (calc[79] ^ calc[146]); //47   //145+1
    calc[78] = (calc[78] ^ calc[143]); //46   //142+1
    calc[77] = (calc[77] ^ calc[150]); //45   //149+1
    calc[76] = (calc[76] ^ calc[164]); //44   //163+1
    calc[75] = (calc[75] ^ calc[156]); //43   //155+1
    calc[74] = (calc[74] ^ calc[160]); //42   //159+1
    calc[73] = (calc[73] ^ calc[167]); //41   //166+1
    calc[72] = (calc[72] ^ calc[148]); //40   //147+1
    calc[71] = (calc[71] ^ calc[142]); //39   //169+1
    calc[70] = (calc[70] ^ calc[153]); //38   //152+1
    calc[69] = (calc[69] ^ calc[163]); //37   //162+1
    calc[68] = (calc[68] ^ calc[158]); //36   //157+1
    calc[67] = (calc[67] ^ calc[162]); //35   //161+1
    calc[66] = (calc[66] ^ calc[147]); //34   //146+1
    calc[65] = (calc[65] ^ calc[159]); //33   //158+1
    calc[64] = (calc[64] ^ calc[165]); //32   //164+1
    calc[63] = (calc[63] ^ calc[154]); //31   //153+1
    calc[62] = (calc[62] ^ calc[144]); //30   //143+1
    calc[61] = (calc[61] ^ calc[169]); //29   //168+1
    calc[60] = (calc[60] ^ calc[161]); //28   //160+1
    calc[59] = (calc[59] ^ calc[151]); //27   //150+1
    calc[58] = (calc[58] ^ calc[145]); //26   //144+1
    calc[57] = (calc[57] ^ calc[166]); //25   //165+1
    calc[56] = (calc[56] ^ calc[155]); //24   //154+1
    calc[55] = (calc[55] ^ calc[116]); //23   //115+1
    calc[54] = (calc[54] ^ calc[127]); //22   //126+1
    calc[53] = (calc[53] ^ calc[134]); //21   //133+1
    calc[52] = (calc[52] ^ calc[141]); //20   //140+1
    calc[51] = (calc[51] ^ calc[121]); //19   //120+1
    calc[50] = (calc[50] ^ calc[130]); //18   //129+1
    calc[49] = (calc[49] ^ calc[122]); //17   //121+1
    calc[48] = (calc[48] ^ calc[140]); //16   //139+1
    calc[47] = (calc[47] ^ calc[118]); //15   //117+1
    calc[46] = (calc[46] ^ calc[126]); //14   //125+1
    calc[45] = (calc[45] ^ calc[133]); //13   //132+1
    calc[44] = (calc[44] ^ calc[137]); //12   //136+1
    calc[43] = (calc[43] ^ calc[124]); //11   //123+1
    calc[42] = (calc[42] ^ calc[135]); //10   //134+1
    calc[41] = (calc[41] ^ calc[120]); //9    //119+1
    calc[40] = (calc[40] ^ calc[129]); //8    //128+1
    calc[39] = (calc[39] ^ calc[114]); //7    //141+1
    calc[38] = (calc[38] ^ calc[117]); //6    //116+1
    calc[37] = (calc[37] ^ calc[119]); //5    //118+1
    calc[36] = (calc[36] ^ calc[115]); //4    //114+1
    calc[35] = (calc[35] ^ calc[138]); //3    //137+1
    calc[34] = (calc[34] ^ calc[125]); //2    //124+1
    calc[33] = (calc[33] ^ calc[131]); //1    //130+1
    calc[32] = (calc[32] ^ calc[128]); //0    //127+1
}

void DESCracker::permutedChoiceTwoAndKeyAddition2() {
    calc[79] = (calc[79] ^ calc[147]); //47  //146+1
    calc[78] = (calc[78] ^ calc[144]); //46  //143+1
    calc[77] = (calc[77] ^ calc[151]); //45  //150+1
    calc[76] = (calc[76] ^ calc[165]); //44  //164+1
    calc[75] = (calc[75] ^ calc[157]); //43  //156+1
    calc[74] = (calc[74] ^ calc[161]); //42  //160+1
    calc[73] = (calc[73] ^ calc[168]); //41  //167+1
    calc[72] = (calc[72] ^ calc[149]); //40  //148+1
    calc[71] = (calc[71] ^ calc[143]); //39  //142+1
    calc[70] = (calc[70] ^ calc[154]); //38  //153+1
    calc[69] = (calc[69] ^ calc[164]); //37  //163+1
    calc[68] = (calc[68] ^ calc[159]); //36  //158+1
    calc[67] = (calc[67] ^ calc[163]); //35  //162+1
    calc[66] = (calc[66] ^ calc[148]); //34  //147+1
    calc[65] = (calc[65] ^ calc[160]); //33  //159+1
    calc[64] = (calc[64] ^ calc[166]); //32  //165+1
    calc[63] = (calc[63] ^ calc[155]); //31  //154+1
    calc[62] = (calc[62] ^ calc[145]); //30  //144+1
    calc[61] = (calc[61] ^ calc[142]); //29  //169+1
    calc[60] = (calc[60] ^ calc[162]); //28  //161+1
    calc[59] = (calc[59] ^ calc[152]); //27  //151+1
    calc[58] = (calc[58] ^ calc[146]); //26  //145+1
    calc[57] = (calc[57] ^ calc[167]); //25  //166+1
    calc[56] = (calc[56] ^ calc[156]); //24  //155+1
    calc[55] = (calc[55] ^ calc[117]); //23  //116+1
    calc[54] = (calc[54] ^ calc[128]); //22  //127+1
    calc[53] = (calc[53] ^ calc[135]); //21  //134+1
    calc[52] = (calc[52] ^ calc[114]); //20  //141+1
    calc[51] = (calc[51] ^ calc[122]); //19  //121+1
    calc[50] = (calc[50] ^ calc[131]); //18  //130+1
    calc[49] = (calc[49] ^ calc[123]); //17  //122+1
    calc[48] = (calc[48] ^ calc[141]); //16  //140+1
    calc[47] = (calc[47] ^ calc[119]); //15  //118+1
    calc[46] = (calc[46] ^ calc[127]); //14  //126+1
    calc[45] = (calc[45] ^ calc[134]); //13  //133+1
    calc[44] = (calc[44] ^ calc[138]); //12  //137+1
    calc[43] = (calc[43] ^ calc[125]); //11  //124+1
    calc[42] = (calc[42] ^ calc[136]); //10  //135+1
    calc[41] = (calc[41] ^ calc[121]); //9   //120+1
    calc[40] = (calc[40] ^ calc[130]); //8   //129+1
    calc[39] = (calc[39] ^ calc[115]); //7   //114+1
    calc[38] = (calc[38] ^ calc[118]); //6   //117+1
    calc[37] = (calc[37] ^ calc[120]); //5   //119+1
    calc[36] = (calc[36] ^ calc[116]); //4   //115+1
    calc[35] = (calc[35] ^ calc[139]); //3   //138+1
    calc[34] = (calc[34] ^ calc[126]); //2   //125+1
    calc[33] = (calc[33] ^ calc[132]); //1   //131+1
    calc[32] = (calc[32] ^ calc[129]); //0   //128+1
}

void DESCracker::permutedChoiceTwoAndKeyAddition3() {
    calc[79] = (calc[79] ^ calc[149]); //47 //147+2
    calc[78] = (calc[78] ^ calc[146]); //46 //144+2
    calc[77] = (calc[77] ^ calc[153]); //45 //151+2
    calc[76] = (calc[76] ^ calc[167]); //44 //165+2
    calc[75] = (calc[75] ^ calc[159]); //43 //157+2
    calc[74] = (calc[74] ^ calc[163]); //42 //161+2
    calc[73] = (calc[73] ^ calc[142]); //41 //168+2
    calc[72] = (calc[72] ^ calc[151]); //40 //149+2
    calc[71] = (calc[71] ^ calc[145]); //39 //143+2
    calc[70] = (calc[70] ^ calc[156]); //38 //154+2
    calc[69] = (calc[69] ^ calc[166]); //37 //164+2
    calc[68] = (calc[68] ^ calc[161]); //36 //159+2
    calc[67] = (calc[67] ^ calc[165]); //35 //163+2
    calc[66] = (calc[66] ^ calc[150]); //34 //148+2
    calc[65] = (calc[65] ^ calc[162]); //33 //160+2
    calc[64] = (calc[64] ^ calc[168]); //32 //166+2
    calc[63] = (calc[63] ^ calc[157]); //31 //155+2
    calc[62] = (calc[62] ^ calc[147]); //30 //145+2
    calc[61] = (calc[61] ^ calc[144]); //29 //142+2
    calc[60] = (calc[60] ^ calc[164]); //28 //162+2
    calc[59] = (calc[59] ^ calc[154]); //27 //152+2
    calc[58] = (calc[58] ^ calc[148]); //26 //146+2
    calc[57] = (calc[57] ^ calc[169]); //25 //167+2
    calc[56] = (calc[56] ^ calc[158]); //24 //156+2
    calc[55] = (calc[55] ^ calc[119]); //23 //117+2
    calc[54] = (calc[54] ^ calc[130]); //22 //128+2
    calc[53] = (calc[53] ^ calc[137]); //21 //135+2
    calc[52] = (calc[52] ^ calc[116]); //20 //114+2
    calc[51] = (calc[51] ^ calc[124]); //19 //122+2
    calc[50] = (calc[50] ^ calc[133]); //18 //131+2
    calc[49] = (calc[49] ^ calc[125]); //17 //123+2
    calc[48] = (calc[48] ^ calc[115]); //16 //141+2
    calc[47] = (calc[47] ^ calc[121]); //15 //119+2
    calc[46] = (calc[46] ^ calc[129]); //14 //127+2
    calc[45] = (calc[45] ^ calc[136]); //13 //134+2
    calc[44] = (calc[44] ^ calc[140]); //12 //138+2
    calc[43] = (calc[43] ^ calc[127]); //11 //125+2
    calc[42] = (calc[42] ^ calc[138]); //10 //136+2
    calc[41] = (calc[41] ^ calc[123]); //9  //121+2
    calc[40] = (calc[40] ^ calc[132]); //8  //130+2
    calc[39] = (calc[39] ^ calc[117]); //7  //115+2
    calc[38] = (calc[38] ^ calc[120]); //6  //118+2
    calc[37] = (calc[37] ^ calc[122]); //5  //120+2
    calc[36] = (calc[36] ^ calc[118]); //4  //116+2
    calc[35] = (calc[35] ^ calc[141]); //3  //139+2
    calc[34] = (calc[34] ^ calc[128]); //2  //126+2
    calc[33] = (calc[33] ^ calc[134]); //1  //132+2
    calc[32] = (calc[32] ^ calc[131]); //0  //129+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition4() {
    calc[79] = (calc[79] ^ calc[151]); //47 //149+2
    calc[78] = (calc[78] ^ calc[148]); //46 //146+2
    calc[77] = (calc[77] ^ calc[155]); //45 //153+2
    calc[76] = (calc[76] ^ calc[169]); //44 //167+2
    calc[75] = (calc[75] ^ calc[161]); //43 //159+2
    calc[74] = (calc[74] ^ calc[165]); //42 //163+2
    calc[73] = (calc[73] ^ calc[144]); //41 //142+2
    calc[72] = (calc[72] ^ calc[153]); //40 //151+2
    calc[71] = (calc[71] ^ calc[147]); //39 //145+2
    calc[70] = (calc[70] ^ calc[158]); //38 //156+2
    calc[69] = (calc[69] ^ calc[168]); //37 //166+2
    calc[68] = (calc[68] ^ calc[163]); //36 //161+2
    calc[67] = (calc[67] ^ calc[167]); //35 //165+2
    calc[66] = (calc[66] ^ calc[152]); //34 //150+2
    calc[65] = (calc[65] ^ calc[164]); //33 //162+2
    calc[64] = (calc[64] ^ calc[142]); //32 //168+2
    calc[63] = (calc[63] ^ calc[159]); //31 //157+2
    calc[62] = (calc[62] ^ calc[149]); //30 //147+2
    calc[61] = (calc[61] ^ calc[146]); //29 //144+2
    calc[60] = (calc[60] ^ calc[166]); //28 //164+2
    calc[59] = (calc[59] ^ calc[156]); //27 //154+2
    calc[58] = (calc[58] ^ calc[150]); //26 //148+2
    calc[57] = (calc[57] ^ calc[143]); //25 //169+2
    calc[56] = (calc[56] ^ calc[160]); //24 //158+2
    calc[55] = (calc[55] ^ calc[121]); //23 //119+2
    calc[54] = (calc[54] ^ calc[132]); //22 //130+2
    calc[53] = (calc[53] ^ calc[139]); //21 //137+2
    calc[52] = (calc[52] ^ calc[118]); //20 //116+2
    calc[51] = (calc[51] ^ calc[126]); //19 //124+2
    calc[50] = (calc[50] ^ calc[135]); //18 //133+2
    calc[49] = (calc[49] ^ calc[127]); //17 //125+2
    calc[48] = (calc[48] ^ calc[117]); //16 //115+2
    calc[47] = (calc[47] ^ calc[123]); //15 //121+2
    calc[46] = (calc[46] ^ calc[131]); //14 //129+2
    calc[45] = (calc[45] ^ calc[138]); //13 //136+2
    calc[44] = (calc[44] ^ calc[114]); //12 //140+2
    calc[43] = (calc[43] ^ calc[129]); //11 //127+2
    calc[42] = (calc[42] ^ calc[140]); //10 //138+2
    calc[41] = (calc[41] ^ calc[125]); //9  //123+2
    calc[40] = (calc[40] ^ calc[134]); //8  //132+2
    calc[39] = (calc[39] ^ calc[119]); //7  //117+2
    calc[38] = (calc[38] ^ calc[122]); //6  //120+2
    calc[37] = (calc[37] ^ calc[124]); //5  //122+2
    calc[36] = (calc[36] ^ calc[120]); //4  //118+2
    calc[35] = (calc[35] ^ calc[115]); //3  //141+2
    calc[34] = (calc[34] ^ calc[130]); //2  //128+2
    calc[33] = (calc[33] ^ calc[136]); //1  //134+2
    calc[32] = (calc[32] ^ calc[133]); //0  //131+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition5() {
    calc[79] = (calc[79] ^ calc[153]); //47 //151+2
    calc[78] = (calc[78] ^ calc[150]); //46 //148+2
    calc[77] = (calc[77] ^ calc[157]); //45 //155+2
    calc[76] = (calc[76] ^ calc[143]); //44 //169+2
    calc[75] = (calc[75] ^ calc[163]); //43 //161+2
    calc[74] = (calc[74] ^ calc[167]); //42 //165+2
    calc[73] = (calc[73] ^ calc[146]); //41 //144+2
    calc[72] = (calc[72] ^ calc[155]); //40 //153+2
    calc[71] = (calc[71] ^ calc[149]); //39 //147+2
    calc[70] = (calc[70] ^ calc[160]); //38 //158+2
    calc[69] = (calc[69] ^ calc[142]); //37 //168+2
    calc[68] = (calc[68] ^ calc[165]); //36 //163+2
    calc[67] = (calc[67] ^ calc[169]); //35 //167+2
    calc[66] = (calc[66] ^ calc[154]); //34 //152+2
    calc[65] = (calc[65] ^ calc[166]); //33 //164+2
    calc[64] = (calc[64] ^ calc[144]); //32 //142+2
    calc[63] = (calc[63] ^ calc[161]); //31 //159+2
    calc[62] = (calc[62] ^ calc[151]); //30 //149+2
    calc[61] = (calc[61] ^ calc[148]); //29 //146+2
    calc[60] = (calc[60] ^ calc[168]); //28 //166+2
    calc[59] = (calc[59] ^ calc[158]); //27 //156+2
    calc[58] = (calc[58] ^ calc[152]); //26 //150+2
    calc[57] = (calc[57] ^ calc[145]); //25 //143+2
    calc[56] = (calc[56] ^ calc[162]); //24 //160+2
    calc[55] = (calc[55] ^ calc[123]); //23 //121+2
    calc[54] = (calc[54] ^ calc[134]); //22 //132+2
    calc[53] = (calc[53] ^ calc[141]); //21 //139+2
    calc[52] = (calc[52] ^ calc[120]); //20 //118+2
    calc[51] = (calc[51] ^ calc[128]); //19 //126+2
    calc[50] = (calc[50] ^ calc[137]); //18 //135+2
    calc[49] = (calc[49] ^ calc[129]); //17 //127+2
    calc[48] = (calc[48] ^ calc[119]); //16 //117+2
    calc[47] = (calc[47] ^ calc[125]); //15 //123+2
    calc[46] = (calc[46] ^ calc[133]); //14 //131+2
    calc[45] = (calc[45] ^ calc[140]); //13 //138+2
    calc[44] = (calc[44] ^ calc[116]); //12 //114+2
    calc[43] = (calc[43] ^ calc[131]); //11 //129+2
    calc[42] = (calc[42] ^ calc[114]); //10 //140+2
    calc[41] = (calc[41] ^ calc[127]); //9  //125+2
    calc[40] = (calc[40] ^ calc[136]); //8  //134+2
    calc[39] = (calc[39] ^ calc[121]); //7  //119+2
    calc[38] = (calc[38] ^ calc[124]); //6  //122+2
    calc[37] = (calc[37] ^ calc[126]); //5  //124+2
    calc[36] = (calc[36] ^ calc[122]); //4  //120+2
    calc[35] = (calc[35] ^ calc[117]); //3  //115+2
    calc[34] = (calc[34] ^ calc[132]); //2  //130+2
    calc[33] = (calc[33] ^ calc[138]); //1  //136+2
    calc[32] = (calc[32] ^ calc[135]); //0  //133+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition6() {
    calc[79] = (calc[79] ^ calc[155]); //47 //153+2
    calc[78] = (calc[78] ^ calc[152]); //46 //150+2
    calc[77] = (calc[77] ^ calc[159]); //45 //157+2
    calc[76] = (calc[76] ^ calc[145]); //44 //143+2
    calc[75] = (calc[75] ^ calc[165]); //43 //163+2
    calc[74] = (calc[74] ^ calc[169]); //42 //167+2
    calc[73] = (calc[73] ^ calc[148]); //41 //146+2
    calc[72] = (calc[72] ^ calc[157]); //40 //155+2
    calc[71] = (calc[71] ^ calc[151]); //39 //149+2
    calc[70] = (calc[70] ^ calc[162]); //38 //160+2
    calc[69] = (calc[69] ^ calc[144]); //37 //142+2
    calc[68] = (calc[68] ^ calc[167]); //36 //165+2
    calc[67] = (calc[67] ^ calc[143]); //35 //169+2
    calc[66] = (calc[66] ^ calc[156]); //34 //154+2
    calc[65] = (calc[65] ^ calc[168]); //33 //166+2
    calc[64] = (calc[64] ^ calc[146]); //32 //144+2
    calc[63] = (calc[63] ^ calc[163]); //31 //161+2
    calc[62] = (calc[62] ^ calc[153]); //30 //151+2
    calc[61] = (calc[61] ^ calc[150]); //29 //148+2
    calc[60] = (calc[60] ^ calc[142]); //28 //168+2
    calc[59] = (calc[59] ^ calc[160]); //27 //158+2
    calc[58] = (calc[58] ^ calc[154]); //26 //152+2
    calc[57] = (calc[57] ^ calc[147]); //25 //145+2
    calc[56] = (calc[56] ^ calc[164]); //24 //162+2
    calc[55] = (calc[55] ^ calc[125]); //23 //123+2
    calc[54] = (calc[54] ^ calc[136]); //22 //134+2
    calc[53] = (calc[53] ^ calc[115]); //21 //141+2
    calc[52] = (calc[52] ^ calc[122]); //20 //120+2
    calc[51] = (calc[51] ^ calc[130]); //19 //128+2
    calc[50] = (calc[50] ^ calc[139]); //18 //137+2
    calc[49] = (calc[49] ^ calc[131]); //17 //129+2
    calc[48] = (calc[48] ^ calc[121]); //16 //119+2
    calc[47] = (calc[47] ^ calc[127]); //15 //125+2
    calc[46] = (calc[46] ^ calc[135]); //14 //133+2
    calc[45] = (calc[45] ^ calc[114]); //13 //140+2
    calc[44] = (calc[44] ^ calc[118]); //12 //116+2
    calc[43] = (calc[43] ^ calc[133]); //11 //131+2
    calc[42] = (calc[42] ^ calc[116]); //10 //114+2
    calc[41] = (calc[41] ^ calc[129]); //9  //127+2
    calc[40] = (calc[40] ^ calc[138]); //8  //136+2
    calc[39] = (calc[39] ^ calc[123]); //7  //121+2
    calc[38] = (calc[38] ^ calc[126]); //6  //124+2
    calc[37] = (calc[37] ^ calc[128]); //5  //126+2
    calc[36] = (calc[36] ^ calc[124]); //4  //122+2
    calc[35] = (calc[35] ^ calc[119]); //3  //117+2
    calc[34] = (calc[34] ^ calc[134]); //2  //132+2
    calc[33] = (calc[33] ^ calc[140]); //1  //138+2
    calc[32] = (calc[32] ^ calc[137]); //0  //135+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition7() {
    calc[79] = (calc[79] ^ calc[157]); //47 //155+2
    calc[78] = (calc[78] ^ calc[154]); //46 //152+2
    calc[77] = (calc[77] ^ calc[161]); //45 //159+2
    calc[76] = (calc[76] ^ calc[147]); //44 //145+2
    calc[75] = (calc[75] ^ calc[167]); //43 //165+2
    calc[74] = (calc[74] ^ calc[143]); //42 //169+2
    calc[73] = (calc[73] ^ calc[150]); //41 //148+2
    calc[72] = (calc[72] ^ calc[159]); //40 //157+2
    calc[71] = (calc[71] ^ calc[153]); //39 //151+2
    calc[70] = (calc[70] ^ calc[164]); //38 //162+2
    calc[69] = (calc[69] ^ calc[146]); //37 //144+2
    calc[68] = (calc[68] ^ calc[169]); //36 //167+2
    calc[67] = (calc[67] ^ calc[145]); //35 //143+2
    calc[66] = (calc[66] ^ calc[158]); //34 //156+2
    calc[65] = (calc[65] ^ calc[142]); //33 //168+2
    calc[64] = (calc[64] ^ calc[148]); //32 //146+2
    calc[63] = (calc[63] ^ calc[165]); //31 //163+2
    calc[62] = (calc[62] ^ calc[155]); //30 //153+2
    calc[61] = (calc[61] ^ calc[152]); //29 //150+2
    calc[60] = (calc[60] ^ calc[144]); //28 //142+2
    calc[59] = (calc[59] ^ calc[162]); //27 //160+2
    calc[58] = (calc[58] ^ calc[156]); //26 //154+2
    calc[57] = (calc[57] ^ calc[149]); //25 //147+2
    calc[56] = (calc[56] ^ calc[166]); //24 //164+2
    calc[55] = (calc[55] ^ calc[127]); //23 //125+2
    calc[54] = (calc[54] ^ calc[138]); //22 //136+2
    calc[53] = (calc[53] ^ calc[117]); //21 //115+2
    calc[52] = (calc[52] ^ calc[124]); //20 //122+2
    calc[51] = (calc[51] ^ calc[132]); //19 //130+2
    calc[50] = (calc[50] ^ calc[141]); //18 //139+2
    calc[49] = (calc[49] ^ calc[133]); //17 //131+2
    calc[48] = (calc[48] ^ calc[123]); //16 //121+2
    calc[47] = (calc[47] ^ calc[129]); //15 //127+2
    calc[46] = (calc[46] ^ calc[137]); //14 //135+2
    calc[45] = (calc[45] ^ calc[116]); //13 //114+2
    calc[44] = (calc[44] ^ calc[120]); //12 //118+2
    calc[43] = (calc[43] ^ calc[135]); //11 //133+2
    calc[42] = (calc[42] ^ calc[118]); //10 //116+2
    calc[41] = (calc[41] ^ calc[131]); //9  //129+2
    calc[40] = (calc[40] ^ calc[140]); //8  //138+2
    calc[39] = (calc[39] ^ calc[125]); //7  //123+2
    calc[38] = (calc[38] ^ calc[128]); //6  //126+2
    calc[37] = (calc[37] ^ calc[130]); //5  //128+2
    calc[36] = (calc[36] ^ calc[126]); //4  //124+2
    calc[35] = (calc[35] ^ calc[121]); //3  //119+2
    calc[34] = (calc[34] ^ calc[136]); //2  //134+2
    calc[33] = (calc[33] ^ calc[114]); //1  //140+2
    calc[32] = (calc[32] ^ calc[139]); //0  //137+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition8() {
    calc[79] = (calc[79] ^ calc[159]); //47 //157+2
    calc[78] = (calc[78] ^ calc[156]); //46 //154+2
    calc[77] = (calc[77] ^ calc[163]); //45 //161+2
    calc[76] = (calc[76] ^ calc[149]); //44 //147+2
    calc[75] = (calc[75] ^ calc[169]); //43 //167+2
    calc[74] = (calc[74] ^ calc[145]); //42 //143+2
    calc[73] = (calc[73] ^ calc[152]); //41 //150+2
    calc[72] = (calc[72] ^ calc[161]); //40 //159+2
    calc[71] = (calc[71] ^ calc[155]); //39 //153+2
    calc[70] = (calc[70] ^ calc[166]); //38 //164+2
    calc[69] = (calc[69] ^ calc[148]); //37 //146+2
    calc[68] = (calc[68] ^ calc[143]); //36 //169+2
    calc[67] = (calc[67] ^ calc[147]); //35 //145+2
    calc[66] = (calc[66] ^ calc[160]); //34 //158+2
    calc[65] = (calc[65] ^ calc[144]); //33 //142+2
    calc[64] = (calc[64] ^ calc[150]); //32 //148+2
    calc[63] = (calc[63] ^ calc[167]); //31 //165+2
    calc[62] = (calc[62] ^ calc[157]); //30 //155+2
    calc[61] = (calc[61] ^ calc[154]); //29 //152+2
    calc[60] = (calc[60] ^ calc[146]); //28 //144+2
    calc[59] = (calc[59] ^ calc[164]); //27 //162+2
    calc[58] = (calc[58] ^ calc[158]); //26 //156+2
    calc[57] = (calc[57] ^ calc[151]); //25 //149+2
    calc[56] = (calc[56] ^ calc[168]); //24 //166+2
    calc[55] = (calc[55] ^ calc[129]); //23 //127+2
    calc[54] = (calc[54] ^ calc[140]); //22 //138+2
    calc[53] = (calc[53] ^ calc[119]); //21 //117+2
    calc[52] = (calc[52] ^ calc[126]); //20 //124+2
    calc[51] = (calc[51] ^ calc[134]); //19 //132+2
    calc[50] = (calc[50] ^ calc[115]); //18 //141+2
    calc[49] = (calc[49] ^ calc[135]); //17 //133+2
    calc[48] = (calc[48] ^ calc[125]); //16 //123+2
    calc[47] = (calc[47] ^ calc[131]); //15 //129+2
    calc[46] = (calc[46] ^ calc[139]); //14 //137+2
    calc[45] = (calc[45] ^ calc[118]); //13 //116+2
    calc[44] = (calc[44] ^ calc[122]); //12 //120+2
    calc[43] = (calc[43] ^ calc[137]); //11 //135+2
    calc[42] = (calc[42] ^ calc[120]); //10 //118+2
    calc[41] = (calc[41] ^ calc[133]); //9  //131+2
    calc[40] = (calc[40] ^ calc[114]); //8  //140+2
    calc[39] = (calc[39] ^ calc[127]); //7  //125+2
    calc[38] = (calc[38] ^ calc[130]); //6  //128+2
    calc[37] = (calc[37] ^ calc[132]); //5  //130+2
    calc[36] = (calc[36] ^ calc[128]); //4  //126+2
    calc[35] = (calc[35] ^ calc[123]); //3  //121+2
    calc[34] = (calc[34] ^ calc[138]); //2  //136+2
    calc[33] = (calc[33] ^ calc[116]); //1  //114+2
    calc[32] = (calc[32] ^ calc[141]); //0  //139+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition9() {
    calc[79] = (calc[79] ^ calc[160]); //47 //159+1
    calc[78] = (calc[78] ^ calc[157]); //46 //156+1
    calc[77] = (calc[77] ^ calc[164]); //45 //163+1
    calc[76] = (calc[76] ^ calc[150]); //44 //149+1
    calc[75] = (calc[75] ^ calc[142]); //43 //169+1
    calc[74] = (calc[74] ^ calc[146]); //42 //145+1
    calc[73] = (calc[73] ^ calc[153]); //41 //152+1
    calc[72] = (calc[72] ^ calc[162]); //40 //161+1
    calc[71] = (calc[71] ^ calc[156]); //39 //155+1
    calc[70] = (calc[70] ^ calc[167]); //38 //166+1
    calc[69] = (calc[69] ^ calc[149]); //37 //148+1
    calc[68] = (calc[68] ^ calc[144]); //36 //143+1
    calc[67] = (calc[67] ^ calc[148]); //35 //147+1
    calc[66] = (calc[66] ^ calc[161]); //34 //160+1
    calc[65] = (calc[65] ^ calc[145]); //33 //144+1
    calc[64] = (calc[64] ^ calc[151]); //32 //150+1
    calc[63] = (calc[63] ^ calc[168]); //31 //167+1
    calc[62] = (calc[62] ^ calc[158]); //30 //157+1
    calc[61] = (calc[61] ^ calc[155]); //29 //154+1
    calc[60] = (calc[60] ^ calc[147]); //28 //146+1
    calc[59] = (calc[59] ^ calc[165]); //27 //164+1
    calc[58] = (calc[58] ^ calc[159]); //26 //158+1
    calc[57] = (calc[57] ^ calc[152]); //25 //151+1
    calc[56] = (calc[56] ^ calc[169]); //24 //168+1
    calc[55] = (calc[55] ^ calc[130]); //23 //129+1
    calc[54] = (calc[54] ^ calc[141]); //22 //140+1
    calc[53] = (calc[53] ^ calc[120]); //21 //119+1
    calc[52] = (calc[52] ^ calc[127]); //20 //126+1
    calc[51] = (calc[51] ^ calc[135]); //19 //134+1
    calc[50] = (calc[50] ^ calc[116]); //18 //115+1
    calc[49] = (calc[49] ^ calc[136]); //17 //135+1
    calc[48] = (calc[48] ^ calc[126]); //16 //125+1
    calc[47] = (calc[47] ^ calc[132]); //15 //131+1
    calc[46] = (calc[46] ^ calc[140]); //14 //139+1
    calc[45] = (calc[45] ^ calc[119]); //13 //118+1
    calc[44] = (calc[44] ^ calc[123]); //12 //122+1
    calc[43] = (calc[43] ^ calc[138]); //11 //137+1
    calc[42] = (calc[42] ^ calc[121]); //10 //120+1
    calc[41] = (calc[41] ^ calc[134]); //9  //133+1
    calc[40] = (calc[40] ^ calc[115]); //8  //114+1
    calc[39] = (calc[39] ^ calc[128]); //7  //127+1
    calc[38] = (calc[38] ^ calc[131]); //6  //130+1
    calc[37] = (calc[37] ^ calc[133]); //5  //132+1
    calc[36] = (calc[36] ^ calc[129]); //4  //128+1
    calc[35] = (calc[35] ^ calc[124]); //3  //123+1
    calc[34] = (calc[34] ^ calc[139]); //2  //138+1
    calc[33] = (calc[33] ^ calc[117]); //1  //116+1
    calc[32] = (calc[32] ^ calc[114]); //0  //141+1
}

void DESCracker::permutedChoiceTwoAndKeyAddition10() {
    calc[79] = (calc[79] ^ calc[162]); //47 //160+2
    calc[78] = (calc[78] ^ calc[159]); //46 //157+2
    calc[77] = (calc[77] ^ calc[166]); //45 //164+2
    calc[76] = (calc[76] ^ calc[152]); //44 //150+2
    calc[75] = (calc[75] ^ calc[144]); //43 //142+2
    calc[74] = (calc[74] ^ calc[148]); //42 //146+2
    calc[73] = (calc[73] ^ calc[155]); //41 //153+2
    calc[72] = (calc[72] ^ calc[164]); //40 //162+2
    calc[71] = (calc[71] ^ calc[158]); //39 //156+2
    calc[70] = (calc[70] ^ calc[169]); //38 //167+2
    calc[69] = (calc[69] ^ calc[151]); //37 //149+2
    calc[68] = (calc[68] ^ calc[146]); //36 //144+2
    calc[67] = (calc[67] ^ calc[150]); //35 //148+2
    calc[66] = (calc[66] ^ calc[163]); //34 //161+2
    calc[65] = (calc[65] ^ calc[147]); //33 //145+2
    calc[64] = (calc[64] ^ calc[153]); //32 //151+2
    calc[63] = (calc[63] ^ calc[142]); //31 //168+2
    calc[62] = (calc[62] ^ calc[160]); //30 //158+2
    calc[61] = (calc[61] ^ calc[157]); //29 //155+2
    calc[60] = (calc[60] ^ calc[149]); //28 //147+2
    calc[59] = (calc[59] ^ calc[167]); //27 //165+2
    calc[58] = (calc[58] ^ calc[161]); //26 //159+2
    calc[57] = (calc[57] ^ calc[154]); //25 //152+2
    calc[56] = (calc[56] ^ calc[143]); //24 //169+2
    calc[55] = (calc[55] ^ calc[132]); //23 //130+2
    calc[54] = (calc[54] ^ calc[115]); //22 //141+2
    calc[53] = (calc[53] ^ calc[122]); //21 //120+2
    calc[52] = (calc[52] ^ calc[129]); //20 //127+2
    calc[51] = (calc[51] ^ calc[137]); //19 //135+2
    calc[50] = (calc[50] ^ calc[118]); //18 //116+2
    calc[49] = (calc[49] ^ calc[138]); //17 //136+2
    calc[48] = (calc[48] ^ calc[128]); //16 //126+2
    calc[47] = (calc[47] ^ calc[134]); //15 //132+2
    calc[46] = (calc[46] ^ calc[114]); //14 //140+2
    calc[45] = (calc[45] ^ calc[121]); //13 //119+2
    calc[44] = (calc[44] ^ calc[125]); //12 //123+2
    calc[43] = (calc[43] ^ calc[140]); //11 //138+2
    calc[42] = (calc[42] ^ calc[123]); //10 //121+2
    calc[41] = (calc[41] ^ calc[136]); //9  //134+2
    calc[40] = (calc[40] ^ calc[117]); //8  //115+2
    calc[39] = (calc[39] ^ calc[130]); //7  //128+2
    calc[38] = (calc[38] ^ calc[133]); //6  //131+2
    calc[37] = (calc[37] ^ calc[135]); //5  //133+2
    calc[36] = (calc[36] ^ calc[131]); //4  //129+2
    calc[35] = (calc[35] ^ calc[126]); //3  //124+2
    calc[34] = (calc[34] ^ calc[141]); //2  //139+2
    calc[33] = (calc[33] ^ calc[119]); //1  //117+2
    calc[32] = (calc[32] ^ calc[116]); //0  //114+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition11() {
    calc[79] = (calc[79] ^ calc[164]); //47 //162+2
    calc[78] = (calc[78] ^ calc[161]); //46 //159+2
    calc[77] = (calc[77] ^ calc[168]); //45 //166+2
    calc[76] = (calc[76] ^ calc[154]); //44 //152+2
    calc[75] = (calc[75] ^ calc[146]); //43 //144+2
    calc[74] = (calc[74] ^ calc[150]); //42 //148+2
    calc[73] = (calc[73] ^ calc[157]); //41 //155+2
    calc[72] = (calc[72] ^ calc[166]); //40 //164+2
    calc[71] = (calc[71] ^ calc[160]); //39 //158+2
    calc[70] = (calc[70] ^ calc[143]); //38 //169+2
    calc[69] = (calc[69] ^ calc[153]); //37 //151+2
    calc[68] = (calc[68] ^ calc[148]); //36 //146+2
    calc[67] = (calc[67] ^ calc[152]); //35 //150+2
    calc[66] = (calc[66] ^ calc[165]); //34 //163+2
    calc[65] = (calc[65] ^ calc[149]); //33 //147+2
    calc[64] = (calc[64] ^ calc[155]); //32 //153+2
    calc[63] = (calc[63] ^ calc[144]); //31 //142+2
    calc[62] = (calc[62] ^ calc[162]); //30 //160+2
    calc[61] = (calc[61] ^ calc[159]); //29 //157+2
    calc[60] = (calc[60] ^ calc[151]); //28 //149+2
    calc[59] = (calc[59] ^ calc[169]); //27 //167+2
    calc[58] = (calc[58] ^ calc[163]); //26 //161+2
    calc[57] = (calc[57] ^ calc[156]); //25 //154+2
    calc[56] = (calc[56] ^ calc[145]); //24 //143+2
    calc[55] = (calc[55] ^ calc[134]); //23 //132+2
    calc[54] = (calc[54] ^ calc[117]); //22 //115+2
    calc[53] = (calc[53] ^ calc[124]); //21 //122+2
    calc[52] = (calc[52] ^ calc[131]); //20 //129+2
    calc[51] = (calc[51] ^ calc[139]); //19 //137+2
    calc[50] = (calc[50] ^ calc[120]); //18 //118+2
    calc[49] = (calc[49] ^ calc[140]); //17 //138+2
    calc[48] = (calc[48] ^ calc[130]); //16 //128+2
    calc[47] = (calc[47] ^ calc[136]); //15 //134+2
    calc[46] = (calc[46] ^ calc[116]); //14 //114+2
    calc[45] = (calc[45] ^ calc[123]); //13 //121+2
    calc[44] = (calc[44] ^ calc[127]); //12 //125+2
    calc[43] = (calc[43] ^ calc[114]); //11 //140+2
    calc[42] = (calc[42] ^ calc[125]); //10 //123+2
    calc[41] = (calc[41] ^ calc[138]); //9  //136+2
    calc[40] = (calc[40] ^ calc[119]); //8  //117+2
    calc[39] = (calc[39] ^ calc[132]); //7  //130+2
    calc[38] = (calc[38] ^ calc[135]); //6  //133+2
    calc[37] = (calc[37] ^ calc[137]); //5  //135+2
    calc[36] = (calc[36] ^ calc[133]); //4  //131+2
    calc[35] = (calc[35] ^ calc[128]); //3  //126+2
    calc[34] = (calc[34] ^ calc[115]); //2  //141+2
    calc[33] = (calc[33] ^ calc[121]); //1  //119+2
    calc[32] = (calc[32] ^ calc[118]); //0  //116+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition12() {
    calc[79] = (calc[79] ^ calc[166]); //47 //164+2
    calc[78] = (calc[78] ^ calc[163]); //46 //161+2
    calc[77] = (calc[77] ^ calc[142]); //45 //168+2
    calc[76] = (calc[76] ^ calc[156]); //44 //154+2
    calc[75] = (calc[75] ^ calc[148]); //43 //146+2
    calc[74] = (calc[74] ^ calc[152]); //42 //150+2
    calc[73] = (calc[73] ^ calc[159]); //41 //157+2
    calc[72] = (calc[72] ^ calc[168]); //40 //166+2
    calc[71] = (calc[71] ^ calc[162]); //39 //160+2
    calc[70] = (calc[70] ^ calc[145]); //38 //143+2
    calc[69] = (calc[69] ^ calc[155]); //37 //153+2
    calc[68] = (calc[68] ^ calc[150]); //36 //148+2
    calc[67] = (calc[67] ^ calc[154]); //35 //152+2
    calc[66] = (calc[66] ^ calc[167]); //34 //165+2
    calc[65] = (calc[65] ^ calc[151]); //33 //149+2
    calc[64] = (calc[64] ^ calc[157]); //32 //155+2
    calc[63] = (calc[63] ^ calc[146]); //31 //144+2
    calc[62] = (calc[62] ^ calc[164]); //30 //162+2
    calc[61] = (calc[61] ^ calc[161]); //29 //159+2
    calc[60] = (calc[60] ^ calc[153]); //28 //151+2
    calc[59] = (calc[59] ^ calc[143]); //27 //169+2
    calc[58] = (calc[58] ^ calc[165]); //26 //163+2
    calc[57] = (calc[57] ^ calc[158]); //25 //156+2
    calc[56] = (calc[56] ^ calc[147]); //24 //145+2
    calc[55] = (calc[55] ^ calc[136]); //23 //134+2
    calc[54] = (calc[54] ^ calc[119]); //22 //117+2
    calc[53] = (calc[53] ^ calc[126]); //21 //124+2
    calc[52] = (calc[52] ^ calc[133]); //20 //131+2
    calc[51] = (calc[51] ^ calc[141]); //19 //139+2
    calc[50] = (calc[50] ^ calc[122]); //18 //120+2
    calc[49] = (calc[49] ^ calc[114]); //17 //140+2
    calc[48] = (calc[48] ^ calc[132]); //16 //130+2
    calc[47] = (calc[47] ^ calc[138]); //15 //136+2
    calc[46] = (calc[46] ^ calc[118]); //14 //116+2
    calc[45] = (calc[45] ^ calc[125]); //13 //123+2
    calc[44] = (calc[44] ^ calc[129]); //12 //127+2
    calc[43] = (calc[43] ^ calc[116]); //11 //114+2
    calc[42] = (calc[42] ^ calc[127]); //10 //125+2
    calc[41] = (calc[41] ^ calc[140]); //9  //138+2
    calc[40] = (calc[40] ^ calc[121]); //8  //119+2
    calc[39] = (calc[39] ^ calc[134]); //7  //132+2
    calc[38] = (calc[38] ^ calc[137]); //6  //135+2
    calc[37] = (calc[37] ^ calc[139]); //5  //137+2
    calc[36] = (calc[36] ^ calc[135]); //4  //133+2
    calc[35] = (calc[35] ^ calc[130]); //3  //128+2
    calc[34] = (calc[34] ^ calc[117]); //2  //115+2
    calc[33] = (calc[33] ^ calc[123]); //1  //121+2
    calc[32] = (calc[32] ^ calc[120]); //0  //118+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition13() {
    calc[79] = (calc[79] ^ calc[168]); //47 //166+2
    calc[78] = (calc[78] ^ calc[165]); //46 //163+2
    calc[77] = (calc[77] ^ calc[144]); //45 //142+2
    calc[76] = (calc[76] ^ calc[158]); //44 //156+2
    calc[75] = (calc[75] ^ calc[150]); //43 //148+2
    calc[74] = (calc[74] ^ calc[154]); //42 //152+2
    calc[73] = (calc[73] ^ calc[161]); //41 //159+2
    calc[72] = (calc[72] ^ calc[142]); //40 //168+2
    calc[71] = (calc[71] ^ calc[164]); //39 //162+2
    calc[70] = (calc[70] ^ calc[147]); //38 //145+2
    calc[69] = (calc[69] ^ calc[157]); //37 //155+2
    calc[68] = (calc[68] ^ calc[152]); //36 //150+2
    calc[67] = (calc[67] ^ calc[156]); //35 //154+2
    calc[66] = (calc[66] ^ calc[169]); //34 //167+2
    calc[65] = (calc[65] ^ calc[153]); //33 //151+2
    calc[64] = (calc[64] ^ calc[159]); //32 //157+2
    calc[63] = (calc[63] ^ calc[148]); //31 //146+2
    calc[62] = (calc[62] ^ calc[166]); //30 //164+2
    calc[61] = (calc[61] ^ calc[163]); //29 //161+2
    calc[60] = (calc[60] ^ calc[155]); //28 //153+2
    calc[59] = (calc[59] ^ calc[145]); //27 //143+2
    calc[58] = (calc[58] ^ calc[167]); //26 //165+2
    calc[57] = (calc[57] ^ calc[160]); //25 //158+2
    calc[56] = (calc[56] ^ calc[149]); //24 //147+2
    calc[55] = (calc[55] ^ calc[138]); //23 //136+2
    calc[54] = (calc[54] ^ calc[121]); //22 //119+2
    calc[53] = (calc[53] ^ calc[128]); //21 //126+2
    calc[52] = (calc[52] ^ calc[135]); //20 //133+2
    calc[51] = (calc[51] ^ calc[115]); //19 //141+2
    calc[50] = (calc[50] ^ calc[124]); //18 //122+2
    calc[49] = (calc[49] ^ calc[116]); //17 //114+2
    calc[48] = (calc[48] ^ calc[134]); //16 //132+2
    calc[47] = (calc[47] ^ calc[140]); //15 //138+2
    calc[46] = (calc[46] ^ calc[120]); //14 //118+2
    calc[45] = (calc[45] ^ calc[127]); //13 //125+2
    calc[44] = (calc[44] ^ calc[131]); //12 //129+2
    calc[43] = (calc[43] ^ calc[118]); //11 //116+2
    calc[42] = (calc[42] ^ calc[129]); //10 //127+2
    calc[41] = (calc[41] ^ calc[114]); //9  //140+2
    calc[40] = (calc[40] ^ calc[123]); //8  //121+2
    calc[39] = (calc[39] ^ calc[136]); //7  //134+2
    calc[38] = (calc[38] ^ calc[139]); //6  //137+2
    calc[37] = (calc[37] ^ calc[141]); //5  //139+2
    calc[36] = (calc[36] ^ calc[137]); //4  //135+2
    calc[35] = (calc[35] ^ calc[132]); //3  //130+2
    calc[34] = (calc[34] ^ calc[119]); //2  //117+2
    calc[33] = (calc[33] ^ calc[125]); //1  //123+2
    calc[32] = (calc[32] ^ calc[122]); //0  //120+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition14() {
    calc[79] = (calc[79] ^ calc[114]); //47 //168+2
    calc[78] = (calc[78] ^ calc[167]); //46 //165+2
    calc[77] = (calc[77] ^ calc[146]); //45 //144+2
    calc[76] = (calc[76] ^ calc[160]); //44 //158+2
    calc[75] = (calc[75] ^ calc[152]); //43 //150+2
    calc[74] = (calc[74] ^ calc[156]); //42 //154+2
    calc[73] = (calc[73] ^ calc[163]); //41 //161+2
    calc[72] = (calc[72] ^ calc[144]); //40 //142+2
    calc[71] = (calc[71] ^ calc[166]); //39 //164+2
    calc[70] = (calc[70] ^ calc[149]); //38 //147+2
    calc[69] = (calc[69] ^ calc[159]); //37 //157+2
    calc[68] = (calc[68] ^ calc[154]); //36 //152+2
    calc[67] = (calc[67] ^ calc[158]); //35 //156+2
    calc[66] = (calc[66] ^ calc[143]); //34 //169+2
    calc[65] = (calc[65] ^ calc[155]); //33 //153+2
    calc[64] = (calc[64] ^ calc[161]); //32 //159+2
    calc[63] = (calc[63] ^ calc[150]); //31 //148+2
    calc[62] = (calc[62] ^ calc[168]); //30 //166+2
    calc[61] = (calc[61] ^ calc[165]); //29 //163+2
    calc[60] = (calc[60] ^ calc[157]); //28 //155+2
    calc[59] = (calc[59] ^ calc[147]); //27 //145+2
    calc[58] = (calc[58] ^ calc[169]); //26 //167+2
    calc[57] = (calc[57] ^ calc[162]); //25 //160+2
    calc[56] = (calc[56] ^ calc[151]); //24 //149+2
    calc[55] = (calc[55] ^ calc[140]); //23 //138+2
    calc[54] = (calc[54] ^ calc[123]); //22 //121+2
    calc[53] = (calc[53] ^ calc[130]); //21 //128+2
    calc[52] = (calc[52] ^ calc[137]); //20 //135+2
    calc[51] = (calc[51] ^ calc[117]); //19 //115+2
    calc[50] = (calc[50] ^ calc[126]); //18 //124+2
    calc[49] = (calc[49] ^ calc[118]); //17 //116+2
    calc[48] = (calc[48] ^ calc[136]); //16 //134+2
    calc[47] = (calc[47] ^ calc[142]); //15 //140+2
    calc[46] = (calc[46] ^ calc[122]); //14 //120+2
    calc[45] = (calc[45] ^ calc[129]); //13 //127+2
    calc[44] = (calc[44] ^ calc[133]); //12 //131+2
    calc[43] = (calc[43] ^ calc[120]); //11 //118+2
    calc[42] = (calc[42] ^ calc[131]); //10 //129+2
    calc[41] = (calc[41] ^ calc[116]); //9  //114+2
    calc[40] = (calc[40] ^ calc[125]); //8  //123+2
    calc[39] = (calc[39] ^ calc[138]); //7  //136+2
    calc[38] = (calc[38] ^ calc[141]); //6  //139+2
    calc[37] = (calc[37] ^ calc[115]); //5  //141+2
    calc[36] = (calc[36] ^ calc[139]); //4  //137+2
    calc[35] = (calc[35] ^ calc[134]); //3  //132+2
    calc[34] = (calc[34] ^ calc[121]); //2  //119+2
    calc[33] = (calc[33] ^ calc[127]); //1  //125+2
    calc[32] = (calc[32] ^ calc[124]); //0  //122+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition15() {
    calc[79] = (calc[79] ^ calc[116]); //47 //114+2
    calc[78] = (calc[78] ^ calc[169]); //46 //167+2
    calc[77] = (calc[77] ^ calc[148]); //45 //146+2
    calc[76] = (calc[76] ^ calc[162]); //44 //160+2
    calc[75] = (calc[75] ^ calc[154]); //43 //152+2
    calc[74] = (calc[74] ^ calc[158]); //42 //156+2
    calc[73] = (calc[73] ^ calc[165]); //41 //163+2
    calc[72] = (calc[72] ^ calc[146]); //40 //144+2
    calc[71] = (calc[71] ^ calc[168]); //39 //166+2
    calc[70] = (calc[70] ^ calc[151]); //38 //149+2
    calc[69] = (calc[69] ^ calc[161]); //37 //159+2
    calc[68] = (calc[68] ^ calc[156]); //36 //154+2
    calc[67] = (calc[67] ^ calc[160]); //35 //158+2
    calc[66] = (calc[66] ^ calc[145]); //34 //143+2
    calc[65] = (calc[65] ^ calc[157]); //33 //155+2
    calc[64] = (calc[64] ^ calc[163]); //32 //161+2
    calc[63] = (calc[63] ^ calc[152]); //31 //150+2
    calc[62] = (calc[62] ^ calc[142]); //30 //168+2
    calc[61] = (calc[61] ^ calc[167]); //29 //165+2
    calc[60] = (calc[60] ^ calc[159]); //28 //157+2
    calc[59] = (calc[59] ^ calc[149]); //27 //147+2
    calc[58] = (calc[58] ^ calc[143]); //26 //169+2
    calc[57] = (calc[57] ^ calc[164]); //25 //162+2
    calc[56] = (calc[56] ^ calc[153]); //24 //151+2
    calc[55] = (calc[55] ^ calc[114]); //23 //140+2
    calc[54] = (calc[54] ^ calc[125]); //22 //123+2
    calc[53] = (calc[53] ^ calc[132]); //21 //130+2
    calc[52] = (calc[52] ^ calc[139]); //20 //137+2
    calc[51] = (calc[51] ^ calc[119]); //19 //117+2
    calc[50] = (calc[50] ^ calc[128]); //18 //126+2
    calc[49] = (calc[49] ^ calc[120]); //17 //118+2
    calc[48] = (calc[48] ^ calc[138]); //16 //136+2
    calc[47] = (calc[47] ^ calc[144]); //15 //142+2
    calc[46] = (calc[46] ^ calc[124]); //14 //122+2
    calc[45] = (calc[45] ^ calc[131]); //13 //129+2
    calc[44] = (calc[44] ^ calc[135]); //12 //133+2
    calc[43] = (calc[43] ^ calc[122]); //11 //120+2
    calc[42] = (calc[42] ^ calc[133]); //10 //131+2
    calc[41] = (calc[41] ^ calc[118]); //9  //116+2
    calc[40] = (calc[40] ^ calc[127]); //8  //125+2
    calc[39] = (calc[39] ^ calc[140]); //7  //138+2
    calc[38] = (calc[38] ^ calc[115]); //6  //141+2
    calc[37] = (calc[37] ^ calc[117]); //5  //115+2
    calc[36] = (calc[36] ^ calc[141]); //4  //139+2
    calc[35] = (calc[35] ^ calc[136]); //3  //134+2
    calc[34] = (calc[34] ^ calc[123]); //2  //121+2
    calc[33] = (calc[33] ^ calc[129]); //1  //127+2
    calc[32] = (calc[32] ^ calc[126]); //0  //124+2
}

void DESCracker::permutedChoiceTwoAndKeyAddition16() {
    calc[79] = (calc[79] ^ calc[117]); //47 //116+1
    calc[78] = (calc[78] ^ calc[142]); //46 //169+1
    calc[77] = (calc[77] ^ calc[149]); //45 //148+1
    calc[76] = (calc[76] ^ calc[163]); //44 //162+1
    calc[75] = (calc[75] ^ calc[155]); //43 //154+1
    calc[74] = (calc[74] ^ calc[159]); //42 //158+1
    calc[73] = (calc[73] ^ calc[166]); //41 //165+1
    calc[72] = (calc[72] ^ calc[147]); //40 //146+1
    calc[71] = (calc[71] ^ calc[169]); //39 //168+1
    calc[70] = (calc[70] ^ calc[152]); //38 //151+1
    calc[69] = (calc[69] ^ calc[162]); //37 //161+1
    calc[68] = (calc[68] ^ calc[157]); //36 //156+1
    calc[67] = (calc[67] ^ calc[161]); //35 //160+1
    calc[66] = (calc[66] ^ calc[146]); //34 //145+1
    calc[65] = (calc[65] ^ calc[158]); //33 //157+1
    calc[64] = (calc[64] ^ calc[164]); //32 //163+1
    calc[63] = (calc[63] ^ calc[153]); //31 //152+1
    calc[62] = (calc[62] ^ calc[143]); //30 //142+1
    calc[61] = (calc[61] ^ calc[168]); //29 //167+1
    calc[60] = (calc[60] ^ calc[160]); //28 //159+1
    calc[59] = (calc[59] ^ calc[150]); //27 //149+1
    calc[58] = (calc[58] ^ calc[144]); //26 //143+1
    calc[57] = (calc[57] ^ calc[165]); //25 //164+1
    calc[56] = (calc[56] ^ calc[154]); //24 //153+1
    calc[55] = (calc[55] ^ calc[115]); //23 //114+1
    calc[54] = (calc[54] ^ calc[126]); //22 //125+1
    calc[53] = (calc[53] ^ calc[133]); //21 //132+1
    calc[52] = (calc[52] ^ calc[140]); //20 //139+1
    calc[51] = (calc[51] ^ calc[120]); //19 //119+1
    calc[50] = (calc[50] ^ calc[129]); //18 //128+1
    calc[49] = (calc[49] ^ calc[121]); //17 //120+1
    calc[48] = (calc[48] ^ calc[139]); //16 //138+1
    calc[47] = (calc[47] ^ calc[145]); //15 //144+1
    calc[46] = (calc[46] ^ calc[125]); //14 //124+1
    calc[45] = (calc[45] ^ calc[132]); //13 //131+1
    calc[44] = (calc[44] ^ calc[136]); //12 //135+1
    calc[43] = (calc[43] ^ calc[123]); //11 //122+1
    calc[42] = (calc[42] ^ calc[134]); //10 //133+1
    calc[41] = (calc[41] ^ calc[119]); //9  //118+1
    calc[40] = (calc[40] ^ calc[128]); //8  //127+1
    calc[39] = (calc[39] ^ calc[141]); //7  //140+1
    calc[38] = (calc[38] ^ calc[116]); //6  //115+1
    calc[37] = (calc[37] ^ calc[118]); //5  //117+1
    calc[36] = (calc[36] ^ calc[114]); //4  //141+1
    calc[35] = (calc[35] ^ calc[137]); //3  //136+1
    calc[34] = (calc[34] ^ calc[124]); //2  //123+1
    calc[33] = (calc[33] ^ calc[130]); //1  //129+1
    calc[32] = (calc[32] ^ calc[127]); //0  //126+1
}

void DESCracker::substitute() {
    int number = 0;
    //Box Nr 0
    number += calc[32] * 32 + calc[33] * 16 + calc[34] * 8 + calc[35] * 4 + calc[36] * 2 + calc[37];
    switch (number) {
        case (28):
        case (1):
        case (64):
        case (59): {
            //0
            calc[35] = 0;
            calc[34] = 0;
            calc[33] = 0;
            calc[32] = 0;
            break;
        }
        case (6):
        case (15):
        case (34):
        case (45): {
            //1
            calc[35] = 1;
            calc[34] = 0;
            calc[33] = 0;
            calc[32] = 0;
            break;
        }
        case (8):
        case (11):
        case (44):
        case (39): {
            //2
            calc[35] = 0;
            calc[34] = 1;
            calc[33] = 0;
            calc[32] = 0;
            break;
        }
        case (16):
        case (29):
        case (56):
        case (53): {
            //3
            calc[35] = 1;
            calc[34] = 1;
            calc[33] = 0;
            calc[32] = 0;
            break;
        }
        case (2):
        case (7):
        case (32):
        case (41): {
            //4
            calc[35] = 0;
            calc[34] = 0;
            calc[33] = 1;
            calc[32] = 0;
            break;
        }
        case (24):
        case (27):
        case (60):
        case (49): {
            //5
            calc[35] = 1;
            calc[34] = 0;
            calc[33] = 1;
            calc[32] = 0;
            break;
        }
        case (20):
        case (19):
        case (42):
        case (61): {
            //6
            calc[35] = 0;
            calc[34] = 1;
            calc[33] = 1;
            calc[32] = 0;
            break;
        }
        case (30):
        case (5):
        case (54):
        case (47): {
            //7
            calc[35] = 1;
            calc[34] = 1;
            calc[33] = 1;
            calc[32] = 0;
            break;
        }
        case (14):
        case (31):
        case (38):
        case (37): {
            //8
            calc[35] = 0;
            calc[34] = 0;
            calc[33] = 0;
            calc[32] = 1;
            break;
        }
        case (26):
        case (25):
        case (52):
        case (43): {
            //9
            calc[35] = 1;
            calc[34] = 0;
            calc[33] = 0;
            calc[32] = 1;
            break;
        }
        case (18):
        case (17):
        case (58):
        case (57): {
            //10
            calc[35] = 0;
            calc[34] = 1;
            calc[33] = 0;
            calc[32] = 1;
            break;
        }
        case (12):
        case (23):
        case (46):
        case (51): {
            //11
            calc[35] = 1;
            calc[34] = 1;
            calc[33] = 0;
            calc[32] = 1;
            break;
        }
        case (22):
        case (21):
        case (50):
        case (35): {
            //12
            calc[35] = 0;
            calc[34] = 0;
            calc[33] = 1;
            calc[32] = 1;
            break;
        }
        case (4):
        case (13):
        case (40):
        case (63): {
            //13
            calc[35] = 1;
            calc[34] = 0;
            calc[33] = 1;
            calc[32] = 1;
            break;
        }
        case (0):
        case (9):
        case (36):
        case (55): {
            //14
            calc[35] = 0;
            calc[34] = 1;
            calc[33] = 1;
            calc[32] = 1;
            break;
        }
        case (10):
        case (3):
        case (48):
        case (33): {
            //15
            calc[35] = 1;
            calc[34] = 1;
            calc[33] = 1;
            calc[32] = 1;
            break;
        }
        default:
            break;
    }

    //Box Nr 1
    number = 0;
    number += calc[38] * 32 + calc[39] * 16 + calc[40] * 8 + calc[41] * 4 + calc[42] * 2 + calc[43];
    switch (number) {
        case (26):
        case (19):
        case (32):
        case (57): {
            //0
            calc[39] = 0;
            calc[38] = 0;
            calc[37] = 0;
            calc[36] = 0;
            break;
        }

        case (2):
        case (21):
        case (46):
        case (39): {
            //1
            calc[39] = 1;
            calc[38] = 0;
            calc[37] = 0;
            calc[36] = 0;
            break;
        }

        case (20):
        case (11):
        case (60):
        case (47): {
            //2
            calc[39] = 0;
            calc[38] = 1;
            calc[37] = 0;
            calc[36] = 0;
            break;
        }

        case (12):
        case (1):
        case (58):
        case (41): {
            //3
            calc[39] = 1;
            calc[38] = 1;
            calc[37] = 0;
            calc[36] = 0;
            break;
        }

        case (14):
        case (5):
        case (42):
        case (45): {
            //4
            calc[39] = 0;
            calc[38] = 0;
            calc[37] = 1;
            calc[36] = 0;
            break;
        }

        case (28):
        case (31):
        case (48):
        case (59): {
            //5
            calc[39] = 1;
            calc[38] = 0;
            calc[37] = 1;
            calc[36] = 0;
            break;
        }

        case (8):
        case (25):
        case (54):
        case (51): {
            //6
            calc[39] = 0;
            calc[38] = 1;
            calc[37] = 1;
            calc[36] = 0;
            break;
        }

        case (18):
        case (7):
        case (36):
        case (53): {
            //7
            calc[39] = 1;
            calc[38] = 1;
            calc[37] = 1;
            calc[36] = 0;
            break;
        }

        case (4):
        case (13):
        case (50):
        case (35): {
            //8
            calc[39] = 0;
            calc[38] = 0;
            calc[37] = 0;
            calc[36] = 1;
            break;
        }

        case (16):
        case (27):
        case (56):
        case (63): {
            //9
            calc[39] = 1;
            calc[38] = 0;
            calc[37] = 0;
            calc[36] = 1;
            break;
        }

        case (30):
        case (23):
        case (40):
        case (37): {
            //10
            calc[39] = 0;
            calc[38] = 1;
            calc[37] = 0;
            calc[36] = 1;
            break;
        }

        case (10):
        case (29):
        case (38):
        case (49): {
            //11
            calc[39] = 1;
            calc[38] = 1;
            calc[37] = 0;
            calc[36] = 1;
            break;
        }

        case (24):
        case (17):
        case (52):
        case (55): {
            //12
            calc[39] = 0;
            calc[38] = 0;
            calc[37] = 1;
            calc[36] = 1;
            break;
        }

        case (22):
        case (3):
        case (44):
        case (33): {
            //13
            calc[39] = 1;
            calc[38] = 0;
            calc[37] = 1;
            calc[36] = 1;
            break;
        }

        case (6):
        case (15):
        case (34):
        case (61): {
            //14
            calc[39] = 0;
            calc[38] = 1;
            calc[37] = 1;
            calc[36] = 1;
            break;
        }

        case (0):
        case (9):
        case (62):
        case (43): {
            //15
            calc[39] = 1;
            calc[38] = 1;
            calc[37] = 1;
            calc[36] = 1;
            break;
        }
        default:
            break;
    }

    //Box Nr 2
    number = 0;
    number += calc[44] * 32 + calc[45] * 16 + calc[46] * 8 + calc[47] * 4 + calc[48] * 2 + calc[49];
    switch (number) {
        case 2 :
        case 5 :
        case 46 :
        case 39: {
            //0
            calc[43] = 0;
            calc[42] = 0;
            calc[41] = 0;
            calc[40] = 0;
            break;
        }
        case 16 :
        case 31 :
        case 50 :
        case 33: {
            //1
            calc[43] = 1;
            calc[42] = 0;
            calc[41] = 0;
            calc[40] = 0;
            break;
        }
        case 28 :
        case 17 :
        case 52 :
        case 61: {
            //2
            calc[43] = 0;
            calc[42] = 1;
            calc[41] = 0;
            calc[40] = 0;
            break;
        }
        case 10 :
        case 9 :
        case 44 :
        case 55: {
            //3
            calc[43] = 1;
            calc[42] = 1;
            calc[41] = 0;
            calc[40] = 0;
            break;
        }
        case 26 :
        case 11 :
        case 36 :
        case 49: {
            //4
            calc[43] = 0;
            calc[42] = 0;
            calc[41] = 1;
            calc[40] = 0;
            break;
        }
        case 14 :
        case 21 :
        case 56 :
        case 59: {
            //5
            calc[43] = 1;
            calc[42] = 0;
            calc[41] = 1;
            calc[40] = 0;
            break;
        }
        case 8 :
        case 13 :
        case 34 :
        case 41: {
            //6
            calc[43] = 0;
            calc[42] = 1;
            calc[41] = 1;
            calc[40] = 0;
            break;
        }
        case 22 :
        case 3 :
        case 62 :
        case 47: {
            //7
            calc[43] = 1;
            calc[42] = 1;
            calc[41] = 1;
            calc[40] = 0;
            break;
        }
        case 30 :
        case 19 :
        case 40 :
        case 45: {
            //8
            calc[43] = 0;
            calc[42] = 0;
            calc[41] = 0;
            calc[40] = 1;
            break;
        }
        case 4 :
        case 7 :
        case 38 :
        case 43: {
            //9
            calc[43] = 1;
            calc[42] = 0;
            calc[41] = 0;
            calc[40] = 1;
            break;
        }
        case 0 :
        case 15 :
        case 58 :
        case 35: {
            //10
            calc[43] = 0;
            calc[42] = 1;
            calc[41] = 0;
            calc[40] = 1;
            break;
        }
        case 24 :
        case 27 :
        case 48 :
        case 57: {
            //11
            calc[43] = 1;
            calc[42] = 1;
            calc[41] = 0;
            calc[40] = 1;
            break;
        }
        case 20 :
        case 25 :
        case 54 :
        case 63: {
            //12
            calc[43] = 0;
            calc[42] = 0;
            calc[41] = 1;
            calc[40] = 1;
            break;
        }
        case 18 :
        case 1 :
        case 32 :
        case 37: {
            //13
            calc[43] = 1;
            calc[42] = 0;
            calc[41] = 1;
            calc[40] = 1;
            break;
        }
        case 6 :
        case 23 :
        case 60 :
        case 53: {
            //14
            calc[43] = 0;
            calc[42] = 1;
            calc[41] = 1;
            calc[40] = 1;
            break;
        }
        case 12 :
        case 29 :
        case 42 :
        case 51: {
            //15
            calc[43] = 1;
            calc[42] = 1;
            calc[41] = 1;
            calc[40] = 1;
            break;
        }
        default:
            break;
    }

    //Box Nr 3
    number = 0;
    number += calc[50] * 32 + calc[51] * 16 + calc[52] * 8 + calc[53] * 4 + calc[54] * 2 + calc[55];
    switch (number) {
        case 8 :
        case 13 :
        case 38 :
        case 37: {
            //0
            calc[47] = 0;
            calc[46] = 0;
            calc[45] = 0;
            calc[44] = 0;
            break;
        }
        case 16 :
        case 25 :
        case 50 :
        case 43: {
            //1
            calc[47] = 1;
            calc[46] = 0;
            calc[45] = 0;
            calc[44] = 0;
            break;
        }
        case 18 :
        case 21 :
        case 58 :
        case 61: {
            //2
            calc[47] = 0;
            calc[46] = 1;
            calc[45] = 0;
            calc[44] = 0;
            break;
        }
        case 6 :
        case 15 :
        case 52 :
        case 33: {
            //3
            calc[47] = 1;
            calc[46] = 1;
            calc[45] = 0;
            calc[44] = 0;
            break;
        }
        case 28 :
        case 17 :
        case 62 :
        case 51: {
            //4
            calc[47] = 0;
            calc[46] = 0;
            calc[45] = 1;
            calc[44] = 0;
            break;
        }
        case 22 :
        case 7 :
        case 56 :
        case 53: {
            //5
            calc[47] = 1;
            calc[46] = 0;
            calc[45] = 1;
            calc[44] = 0;
            break;
        }
        case 10 :
        case 9 :
        case 34 :
        case 39: {
            //6
            calc[47] = 0;
            calc[46] = 1;
            calc[45] = 1;
            calc[44] = 0;
            break;
        }
        case 0 :
        case 19 :
        case 44 :
        case 59: {
            //7
            calc[47] = 1;
            calc[46] = 1;
            calc[45] = 1;
            calc[44] = 0;
            break;
        }
        case 20 :
        case 3 :
        case 60 :
        case 47: {
            //8
            calc[47] = 0;
            calc[46] = 0;
            calc[45] = 0;
            calc[44] = 1;
            break;
        }
        case 12 :
        case 31 :
        case 36 :
        case 49: {
            //9
            calc[47] = 1;
            calc[46] = 0;
            calc[45] = 0;
            calc[44] = 1;
            break;
        }
        case 14 :
        case 27 :
        case 32 :
        case 41: {
            //10
            calc[47] = 0;
            calc[46] = 1;
            calc[45] = 0;
            calc[44] = 1;
            break;
        }
        case 24 :
        case 5 :
        case 42 :
        case 55: {
            //11
            calc[47] = 1;
            calc[46] = 1;
            calc[45] = 0;
            calc[44] = 1;
            break;
        }
        case 26 :
        case 23 :
        case 40 :
        case 57: {
            //12
            calc[47] = 0;
            calc[46] = 0;
            calc[45] = 1;
            calc[44] = 1;
            break;
        }
        case 2 :
        case 1 :
        case 46 :
        case 45: {
            //13
            calc[47] = 1;
            calc[46] = 0;
            calc[45] = 1;
            calc[44] = 1;
            break;
        }
        case 4 :
        case 29 :
        case 54 :
        case 63: {
            //14
            calc[47] = 0;
            calc[46] = 1;
            calc[45] = 1;
            calc[44] = 1;
            break;
        }
        case 30 :
        case 11 :
        case 48 :
        case 35: {
            //15
            calc[47] = 1;
            calc[46] = 1;
            calc[45] = 1;
            calc[44] = 1;
            break;
        }
        default:
            break;
    }

    //Box Nr 4
    number = 0;
    number += calc[56] * 32 + calc[57] * 16 + calc[58] * 8 + calc[59] * 4 + calc[60] * 2 + calc[61];
    switch (number) {
        case 26 :
        case 19 :
        case 60 :
        case 53: {
            //0
            calc[51] = 0;
            calc[50] = 0;
            calc[49] = 0;
            calc[48] = 0;
            break;
        }
        case 6 :
        case 15 :
        case 36 :
        case 41: {
            //1
            calc[51] = 1;
            calc[50] = 0;
            calc[49] = 0;
            calc[48] = 0;
            break;
        }
        case 0 :
        case 5 :
        case 34 :
        case 45: {
            //2
            calc[51] = 0;
            calc[50] = 1;
            calc[49] = 0;
            calc[48] = 0;
            break;
        }
        case 20 :
        case 25 :
        case 58 :
        case 63: {
            //3
            calc[51] = 1;
            calc[50] = 1;
            calc[49] = 0;
            calc[48] = 0;
            break;
        }
        case 4 :
        case 9 :
        case 32 :
        case 59: {
            //4
            calc[51] = 0;
            calc[50] = 0;
            calc[49] = 1;
            calc[48] = 0;
            break;
        }
        case 18 :
        case 17 :
        case 54 :
        case 61: {
            //5
            calc[51] = 1;
            calc[50] = 0;
            calc[49] = 1;
            calc[48] = 0;
            break;
        }
        case 14 :
        case 31 :
        case 56 :
        case 49: {
            //6
            calc[51] = 0;
            calc[50] = 1;
            calc[49] = 1;
            calc[48] = 0;
            break;
        }
        case 8 :
        case 11 :
        case 44 :
        case 39: {
            //7
            calc[51] = 1;
            calc[50] = 1;
            calc[49] = 1;
            calc[48] = 0;
            break;
        }
        case 16 :
        case 29 :
        case 46 :
        case 35: {
            //8
            calc[51] = 0;
            calc[50] = 0;
            calc[49] = 0;
            calc[48] = 1;
            break;
        }
        case 30 :
        case 27 :
        case 50 :
        case 55: {
            //9
            calc[51] = 1;
            calc[50] = 0;
            calc[49] = 0;
            calc[48] = 1;
            break;
        }
        case 10 :
        case 23 :
        case 40 :
        case 57: {
            //10
            calc[51] = 0;
            calc[50] = 1;
            calc[49] = 0;
            calc[48] = 1;
            break;
        }
        case 12 :
        case 3 :
        case 38 :
        case 33: {
            //11
            calc[51] = 1;
            calc[50] = 1;
            calc[49] = 0;
            calc[48] = 1;
            break;
        }
        case 2 :
        case 7 :
        case 52 :
        case 37: {
            //12
            calc[51] = 0;
            calc[50] = 0;
            calc[49] = 1;
            calc[48] = 1;
            break;
        }
        case 24 :
        case 13 :
        case 42 :
        case 47: {
            //13
            calc[51] = 1;
            calc[50] = 0;
            calc[49] = 1;
            calc[48] = 1;
            break;
        }
        case 28 :
        case 1 :
        case 62 :
        case 43: {
            //14
            calc[51] = 0;
            calc[50] = 1;
            calc[49] = 1;
            calc[48] = 1;
            break;
        }
        case 22 :
        case 21 :
        case 48 :
        case 51: {
            //15
            calc[51] = 1;
            calc[50] = 1;
            calc[49] = 1;
            calc[48] = 1;
            break;
        }
        default:
            break;
    }

    //Box Nr 5
    number = 0;
    number += calc[62] * 32 + calc[63] * 16 + calc[64] * 8 + calc[65] * 4 + calc[66] * 2 + calc[67];
    switch (number) {
        case 16 :
        case 25 :
        case 50 :
        case 59: {
            //0
            calc[55] = 0;
            calc[54] = 0;
            calc[53] = 0;
            calc[52] = 0;
            break;
        }
        case 2 :
        case 19 :
        case 56 :
        case 53: {
            //1
            calc[55] = 1;
            calc[54] = 0;
            calc[53] = 0;
            calc[52] = 0;
            break;
        }
        case 10 :
        case 7 :
        case 40 :
        case 37: {
            //2
            calc[55] = 0;
            calc[54] = 1;
            calc[53] = 0;
            calc[52] = 0;
            break;
        }
        case 20 :
        case 29 :
        case 46 :
        case 35: {
            //3
            calc[55] = 1;
            calc[54] = 1;
            calc[53] = 0;
            calc[52] = 0;
            break;
        }
        case 22 :
        case 5 :
        case 52 :
        case 33: {
            //4
            calc[55] = 0;
            calc[54] = 0;
            calc[53] = 1;
            calc[52] = 0;
            break;
        }
        case 28 :
        case 15 :
        case 38 :
        case 43: {
            //5
            calc[55] = 1;
            calc[54] = 0;
            calc[53] = 1;
            calc[52] = 0;
            break;
        }
        case 12 :
        case 17 :
        case 62 :
        case 57: {
            //6
            calc[55] = 0;
            calc[54] = 1;
            calc[53] = 1;
            calc[52] = 0;
            break;
        }
        case 26 :
        case 9 :
        case 48 :
        case 55: {
            //7
            calc[55] = 1;
            calc[54] = 1;
            calc[53] = 1;
            calc[52] = 0;
            break;
        }
        case 14 :
        case 31 :
        case 42 :
        case 61: {
            //8
            calc[55] = 0;
            calc[54] = 0;
            calc[53] = 0;
            calc[52] = 1;
            break;
        }
        case 8 :
        case 13 :
        case 32 :
        case 41: {
            //9
            calc[55] = 1;
            calc[54] = 0;
            calc[53] = 0;
            calc[52] = 1;
            break;
        }
        case 4 :
        case 1 :
        case 54 :
        case 47: {
            //10
            calc[55] = 0;
            calc[54] = 1;
            calc[53] = 0;
            calc[52] = 1;
            break;
        }
        case 30 :
        case 27 :
        case 60 :
        case 49: {
            //11
            calc[55] = 1;
            calc[54] = 1;
            calc[53] = 0;
            calc[52] = 1;
            break;
        }
        case 0 :
        case 11 :
        case 44 :
        case 39: {
            //12
            calc[55] = 0;
            calc[54] = 0;
            calc[53] = 1;
            calc[52] = 1;
            break;
        }
        case 18 :
        case 21 :
        case 58 :
        case 63: {
            //13
            calc[55] = 1;
            calc[54] = 0;
            calc[53] = 1;
            calc[52] = 1;
            break;
        }
        case 24 :
        case 23 :
        case 34 :
        case 51: {
            //14
            calc[55] = 0;
            calc[54] = 1;
            calc[53] = 1;
            calc[52] = 1;
            break;
        }
        case 6 :
        case 3 :
        case 36 :
        case 45: {
            //15
            calc[55] = 1;
            calc[54] = 1;
            calc[53] = 1;
            calc[52] = 1;
            break;
        }
        default:
            break;
    }

    //Box Nr 6
    number = 0;
    number += calc[68] * 32 + calc[69] * 16 + calc[70] * 8 + calc[71] * 4 + calc[72] * 2 + calc[73];
    switch (number) {
        case 10 :
        case 3 :
        case 56 :
        case 53: {
            //0
            calc[59] = 0;
            calc[58] = 0;
            calc[57] = 0;
            calc[56] = 0;
            break;
        }
        case 30 :
        case 13 :
        case 32 :
        case 41: {
            //1
            calc[59] = 1;
            calc[58] = 0;
            calc[57] = 0;
            calc[56] = 0;
            break;
        }
        case 4 :
        case 25 :
        case 62 :
        case 59: {
            //2
            calc[59] = 0;
            calc[58] = 1;
            calc[57] = 0;
            calc[56] = 0;
            break;
        }
        case 16 :
        case 19 :
        case 42 :
        case 61: {
            //3
            calc[59] = 1;
            calc[58] = 1;
            calc[57] = 0;
            calc[56] = 0;
            break;
        }
        case 0 :
        case 9 :
        case 34 :
        case 43: {
            //4
            calc[59] = 0;
            calc[58] = 0;
            calc[57] = 1;
            calc[56] = 0;
            break;
        }
        case 24 :
        case 21 :
        case 58 :
        case 51: {
            //5
            calc[59] = 1;
            calc[58] = 0;
            calc[57] = 1;
            calc[56] = 0;
            break;
        }
        case 28 :
        case 31 :
        case 52 :
        case 33: {
            //6
            calc[59] = 0;
            calc[58] = 1;
            calc[57] = 1;
            calc[56] = 0;
            break;
        }
        case 22 :
        case 7 :
        case 44 :
        case 47: {
            //7
            calc[59] = 1;
            calc[58] = 1;
            calc[57] = 1;
            calc[56] = 0;
            break;
        }
        case 12 :
        case 29 :
        case 54 :
        case 39: {
            //8
            calc[59] = 0;
            calc[58] = 0;
            calc[57] = 0;
            calc[56] = 1;
            break;
        }
        case 20 :
        case 11 :
        case 60 :
        case 49: {
            //9
            calc[59] = 1;
            calc[58] = 0;
            calc[57] = 0;
            calc[56] = 1;
            break;
        }
        case 26 :
        case 15 :
        case 48 :
        case 45: {
            //10
            calc[59] = 0;
            calc[58] = 1;
            calc[57] = 0;
            calc[56] = 1;
            break;
        }
        case 2 :
        case 5 :
        case 36 :
        case 35: {
            //11
            calc[59] = 1;
            calc[58] = 1;
            calc[57] = 0;
            calc[56] = 1;
            break;
        }
        case 18 :
        case 23 :
        case 40 :
        case 63: {
            //12
            calc[59] = 0;
            calc[58] = 0;
            calc[57] = 1;
            calc[56] = 1;
            break;
        }
        case 14 :
        case 1 :
        case 38 :
        case 37: {
            //13
            calc[59] = 1;
            calc[58] = 0;
            calc[57] = 1;
            calc[56] = 1;
            break;
        }
        case 6 :
        case 17 :
        case 46 :
        case 57: {
            //14
            calc[59] = 0;
            calc[58] = 1;
            calc[57] = 1;
            calc[56] = 1;
            break;
        }
        case 8 :
        case 27 :
        case 50 :
        case 55: {
            //15
            calc[59] = 1;
            calc[58] = 1;
            calc[57] = 1;
            calc[56] = 1;
            break;
        }
        default:
            break;
    }

    //Box Nr 7
    number = 0;
    number += calc[74] * 32 + calc[75] * 16 + calc[76] * 8 + calc[77] * 4 + calc[78] * 2 + calc[79];
    switch (number) {
        case 26 :
        case 25 :
        case 48 :
        case 55: {
            //0
            calc[63] = 0;
            calc[62] = 0;
            calc[61] = 0;
            calc[60] = 0;
            break;
        }
        case 14 :
        case 1 :
        case 38 :
        case 35: {
            //1
            calc[63] = 1;
            calc[62] = 0;
            calc[61] = 0;
            calc[60] = 0;
            break;
        }
        case 2 :
        case 31 :
        case 46 :
        case 33: {
            //2
            calc[63] = 0;
            calc[62] = 1;
            calc[61] = 0;
            calc[60] = 0;
            break;
        }
        case 20 :
        case 11 :
        case 58 :
        case 57: {
            //3
            calc[63] = 1;
            calc[62] = 1;
            calc[61] = 0;
            calc[60] = 0;
            break;
        }
        case 6 :
        case 15 :
        case 36 :
        case 41: {
            //4
            calc[63] = 0;
            calc[62] = 0;
            calc[61] = 1;
            calc[60] = 0;
            break;
        }
        case 24 :
        case 19 :
        case 60 :
        case 59: {
            //5
            calc[63] = 1;
            calc[62] = 0;
            calc[61] = 1;
            calc[60] = 0;
            break;
        }
        case 8 :
        case 21 :
        case 50 :
        case 61: {
            //6
            calc[63] = 0;
            calc[62] = 1;
            calc[61] = 1;
            calc[60] = 0;
            break;
        }
        case 30 :
        case 13 :
        case 32 :
        case 39: {
            //7
            calc[63] = 1;
            calc[62] = 1;
            calc[61] = 1;
            calc[60] = 0;
            break;
        }
        case 4 :
        case 7 :
        case 62 :
        case 45: {
            //8
            calc[63] = 0;
            calc[62] = 0;
            calc[61] = 0;
            calc[60] = 1;
            break;
        }
        case 18 :
        case 29 :
        case 40 :
        case 53: {
            //9
            calc[63] = 1;
            calc[62] = 0;
            calc[61] = 0;
            calc[60] = 1;
            break;
        }
        case 16 :
        case 9 :
        case 52 :
        case 43: {
            //10
            calc[63] = 0;
            calc[62] = 1;
            calc[61] = 0;
            calc[60] = 1;
            break;
        }
        case 12 :
        case 23 :
        case 34 :
        case 63: {
            //11
            calc[63] = 1;
            calc[62] = 1;
            calc[61] = 0;
            calc[60] = 1;
            break;
        }
        case 28 :
        case 17 :
        case 42 :
        case 51: {
            //12
            calc[63] = 0;
            calc[62] = 0;
            calc[61] = 1;
            calc[60] = 1;
            break;
        }
        case 0 :
        case 5 :
        case 54 :
        case 47: {
            //13
            calc[63] = 1;
            calc[62] = 0;
            calc[61] = 1;
            calc[60] = 1;
            break;
        }
        case 22 :
        case 27 :
        case 44 :
        case 37: {
            //14
            calc[63] = 0;
            calc[62] = 1;
            calc[61] = 1;
            calc[60] = 1;
            break;
        }
        case 10 :
        case 3 :
        case 56 :
        case 49: {
            //15
            calc[63] = 1;
            calc[62] = 1;
            calc[61] = 1;
            calc[60] = 1;
            break;
        }
        default:
            break;
    }
}

void DESCracker::permutateAndAddLeftSide() {
    calc[112] = calc[48];
    calc[48] = calc[33] ^ calc[16];
    calc[33] = calc[38] ^ calc[1];
    calc[38] = calc[59] ^ calc[6];
    calc[59] = calc[37] ^ calc[27];
    calc[37] = calc[43] ^ calc[5];
    calc[43] = calc[57] ^ calc[11];
    calc[57] = calc[44] ^ calc[25];
    calc[44] = calc[36] ^ calc[12];
    calc[36] = calc[60] ^ calc[4];
    calc[60] = calc[53] ^ calc[28];
    calc[53] = calc[58] ^ calc[21];
    calc[58] = calc[61] ^ calc[26];
    calc[61] = calc[42] ^ calc[29];
    calc[42] = calc[54] ^ calc[10];
    calc[54] = calc[34] ^ calc[22];
    calc[34] = calc[51] ^ calc[2];
    calc[51] = calc[45] ^ calc[19];
    calc[45] = calc[49] ^ calc[13];
    calc[49] = calc[39] ^ calc[17];
    calc[39] = calc[112] ^ calc[7];

    calc[112] = calc[62];
    calc[62] = calc[35] ^ calc[30];
    calc[35] = calc[52] ^ calc[3];
    calc[52] = calc[63] ^ calc[20];
    calc[63] = calc[56] ^ calc[31];
    calc[56] = calc[50] ^ calc[24];
    calc[50] = calc[55] ^ calc[18];
    calc[55] = calc[40] ^ calc[23];
    calc[40] = calc[32] ^ calc[8];
    calc[32] = calc[47] ^ calc[0];
    calc[47] = calc[41] ^ calc[15];
    calc[41] = calc[46] ^ calc[9];
    calc[46] = calc[112] ^ calc[14];
}

unsigned long long int DESCracker::crackEncryption(const string &plainText, const string &cryptoText) {
    unsigned long long int completed = 0;
    double overallPercent = 0;
    double estTime = 0;
    double keysPerSec = 0;

    double time = omp_get_wtime();
    double interim = 0;

    const unsigned long long int limit = 72057594037927936;
    auto limitDouble = static_cast<double>(limit);

    const int taskSize = 1 << 24;

    const unsigned long long int iterations = limit / taskSize;

    cout << "Limt: " << limit << endl;
    cout << "Tasksize: " << taskSize << endl;
    cout << "Iterations: " << iterations << endl;
    cout << "PLAINTEXT: " << plainText << " CRYPTOTEXT: " << cryptoText << endl;

    unsigned long long rightKey = limit + 1;
    const aligned_vector<int> firstExpansionBits = createFirstExpansion(plainText);
    const aligned_vector<int> rightResult = createInverseInitialAndSwapLeftRight(cryptoText);
    bool answerFound = false;
    for (unsigned long long int iter = 0; iter < iterations; iter++) {
        if (!answerFound) {
#pragma omp parallel shared(iter, answerFound) reduction(min:rightKey)
            {
                DESCracker *des = new DESCracker();
#pragma omp for
                for (int size = 0; size < taskSize; size++) {
                    const unsigned long long key = iter * taskSize + size;
                    des->encrypt(firstExpansionBits, key);
                    bool error = false;
                    for (int i = 0; i < 64; i++) {
                        if (rightResult[i] != des->calc[i]) {
                            i = 65;
                            error = true;
                        }
                    }
                    if (!error) {
                        rightKey = key;
                        answerFound = true;
                    }
                }
                delete (des);
            }
            completed += taskSize;
            interim = omp_get_wtime() - time;
            overallPercent = (completed / limitDouble) * 100;
            estTime = (((interim / completed) * (limit - completed)) / 3600);
            keysPerSec = completed / interim;
            cout << fixed << "Abs: " << completed << " in " << setprecision(5) << interim
                 << setprecision(16)
                 << " s Rel: "
                 << overallPercent << setprecision(2) << " % Est time : "
                 << estTime << " h "
                 << "keys/sec: " << keysPerSec << endl;
        } else {
            iter = iterations;
        }
    }
    cout << "KEY " << rightKey << " found in " << interim << " seconds" << endl;
    return rightKey;
}

string DESCracker::encryptAndReturn(const string &plainText, const unsigned long long int key) {
    aligned_vector<int> firstExpansionBits = createFirstExpansion(plainText);
    encrypt(firstExpansionBits, key);
    aligned_vector<int> cryptoBits = calc;
    cryptoBits.resize(64);
    return cryptoBitsToHexCryptoText(inverseInitialPermutation(swapLeftAndRight(cryptoBits)));
}

aligned_vector<int> DESCracker::createFirstExpansion(const string &plainText) {
    aligned_vector<int> bits = expansion(setRight(initialPermutation(plainTextToPlainBits(plainText))));
    return bits;
}

aligned_vector<int> DESCracker::plainTextToPlainBits(const string &plainText) {
    //Example: 1234567890abcdef converts to 0001 0010 00011 ... 1111
    aligned_vector<int> plainBits(176, 0);
    for (int j = 0; j < 16; j++) {
        int i = j * 4;
        switch (plainText.at(j)) {
            case ('0'): {
                plainBits[i] = false; //MSB
                plainBits[i + 1] = false;
                plainBits[i + 2] = false;
                plainBits[i + 3] = false; //LSB
                break;
            }
            case ('1'): {
                plainBits[i] = false;
                plainBits[i + 1] = false;
                plainBits[i + 2] = false;
                plainBits[i + 3] = true;
                break;
            }
            case ('2'): {
                plainBits[i] = false;
                plainBits[i + 1] = false;
                plainBits[i + 2] = true;
                plainBits[i + 3] = false;
                break;
            }
            case ('3'): {
                plainBits[i] = false;
                plainBits[i + 1] = false;
                plainBits[i + 2] = true;
                plainBits[i + 3] = true;
                break;
            }
            case ('4'): {
                plainBits[i] = false;
                plainBits[i + 1] = true;
                plainBits[i + 2] = false;
                plainBits[i + 3] = false;
                break;
            }
            case ('5'): {
                plainBits[i] = false;
                plainBits[i + 1] = true;
                plainBits[i + 2] = false;
                plainBits[i + 3] = true;
                break;
            }
            case ('6'): {
                plainBits[i] = false;
                plainBits[i + 1] = true;
                plainBits[i + 2] = true;
                plainBits[i + 3] = false;
                break;
            }
            case ('7'): {
                plainBits[i] = false;
                plainBits[i + 1] = true;
                plainBits[i + 2] = true;
                plainBits[i + 3] = true;
                break;
            }
            case ('8'): {
                plainBits[i] = true;
                plainBits[i + 1] = false;
                plainBits[i + 2] = false;
                plainBits[i + 3] = false;
                break;
            }
            case ('9'): {
                plainBits[i] = true;
                plainBits[i + 1] = false;
                plainBits[i + 2] = false;
                plainBits[i + 3] = true;
                break;
            }
            case ('a'): {
                plainBits[i] = true;
                plainBits[i + 1] = false;
                plainBits[i + 2] = true;
                plainBits[i + 3] = false;
                break;
            }
            case ('b'): {
                plainBits[i] = true;
                plainBits[i + 1] = false;
                plainBits[i + 2] = true;
                plainBits[i + 3] = true;
                break;
            }
            case ('c'): {
                plainBits[i] = true;
                plainBits[i + 1] = true;
                plainBits[i + 2] = false;
                plainBits[i + 3] = false;
                break;
            }
            case ('d'): {
                plainBits[i] = true;
                plainBits[i + 1] = true;
                plainBits[i + 2] = false;
                plainBits[i + 3] = true;
                break;
            }
            case ('e'): {
                plainBits[i] = true;
                plainBits[i + 1] = true;
                plainBits[i + 2] = true;
                plainBits[i + 3] = false;
                break;
            }
            case ('f'): {
                plainBits[i] = true;
                plainBits[i + 1] = true;
                plainBits[i + 2] = true;
                plainBits[i + 3] = true;
                break;
            }
        }
    }
    return plainBits;
}

aligned_vector<int> DESCracker::initialPermutation(aligned_vector<int> plainBits) {
    plainBits[112] = plainBits[6];
    plainBits[6] = plainBits[9];
    plainBits[9] = plainBits[51];
    plainBits[51] = plainBits[36];
    plainBits[36] = plainBits[24];
    plainBits[24] = plainBits[63];
    plainBits[63] = plainBits[112];

    plainBits[112] = plainBits[54];
    plainBits[54] = plainBits[12];
    plainBits[12] = plainBits[27];
    plainBits[27] = plainBits[39];
    plainBits[39] = plainBits[0];
    plainBits[0] = plainBits[57];
    plainBits[57] = plainBits[112];

    plainBits[112] = plainBits[14];
    plainBits[14] = plainBits[11];
    plainBits[11] = plainBits[35];
    plainBits[35] = plainBits[32];
    plainBits[32] = plainBits[56];
    plainBits[56] = plainBits[62];
    plainBits[62] = plainBits[112];

    plainBits[112] = plainBits[52];
    plainBits[52] = plainBits[28];
    plainBits[28] = plainBits[31];
    plainBits[31] = plainBits[7];
    plainBits[7] = plainBits[1];
    plainBits[1] = plainBits[49];
    plainBits[49] = plainBits[112];

    plainBits[112] = plainBits[22];
    plainBits[22] = plainBits[13];
    plainBits[13] = plainBits[19];
    plainBits[19] = plainBits[37];
    plainBits[37] = plainBits[16];
    plainBits[16] = plainBits[61];
    plainBits[61] = plainBits[112];

    plainBits[112] = plainBits[50];
    plainBits[50] = plainBits[44];
    plainBits[44] = plainBits[26];
    plainBits[26] = plainBits[47];
    plainBits[47] = plainBits[2];
    plainBits[2] = plainBits[41];
    plainBits[41] = plainBits[112];

    plainBits[112] = plainBits[30];
    plainBits[30] = plainBits[15];
    plainBits[15] = plainBits[3];
    plainBits[3] = plainBits[33];
    plainBits[33] = plainBits[48];
    plainBits[48] = plainBits[60];
    plainBits[60] = plainBits[112];

    plainBits[112] = plainBits[38];
    plainBits[38] = plainBits[8];
    plainBits[8] = plainBits[59];
    plainBits[59] = plainBits[112];

    plainBits[112] = plainBits[55];
    plainBits[55] = plainBits[4];
    plainBits[4] = plainBits[25];
    plainBits[25] = plainBits[112];

    plainBits[112] = plainBits[46];
    plainBits[46] = plainBits[10];
    plainBits[10] = plainBits[43];
    plainBits[43] = plainBits[34];
    plainBits[34] = plainBits[40];
    plainBits[40] = plainBits[58];
    plainBits[58] = plainBits[112];

    plainBits[112] = plainBits[53];
    plainBits[53] = plainBits[20];
    plainBits[20] = plainBits[29];
    plainBits[29] = plainBits[23];
    plainBits[23] = plainBits[5];
    plainBits[5] = plainBits[17];
    plainBits[17] = plainBits[112];

    plainBits[112] = plainBits[18];
    plainBits[18] = plainBits[45];
    plainBits[45] = plainBits[112];

    plainBits[42] = plainBits[42];
    plainBits[21] = plainBits[21];

    return plainBits;
}

aligned_vector<int> DESCracker::setRight(aligned_vector<int> initialPermutationBits) {
    for (int i = 0; i < 32; i++) {
        initialPermutationBits[i + 80] = initialPermutationBits[i + 32];
    }
    return initialPermutationBits;
}

aligned_vector<int> DESCracker::expansion(aligned_vector<int> setRightBits) {
    setRightBits[112] = setRightBits[33];
    setRightBits[79] = setRightBits[32];
    setRightBits[78] = setRightBits[63];
    setRightBits[77] = setRightBits[62];
    setRightBits[76] = setRightBits[61];
    setRightBits[75] = setRightBits[60];
    setRightBits[74] = setRightBits[59];
    setRightBits[73] = setRightBits[60];
    setRightBits[72] = setRightBits[59];
    setRightBits[71] = setRightBits[58];
    setRightBits[70] = setRightBits[57];
    setRightBits[69] = setRightBits[56];
    setRightBits[68] = setRightBits[55];
    setRightBits[67] = setRightBits[56];
    setRightBits[66] = setRightBits[55];
    setRightBits[65] = setRightBits[54];
    setRightBits[64] = setRightBits[53];
    setRightBits[33] = setRightBits[32];
    setRightBits[32] = setRightBits[63];
    setRightBits[62] = setRightBits[51];
    setRightBits[61] = setRightBits[52];
    setRightBits[60] = setRightBits[51];
    setRightBits[63] = setRightBits[52];
    setRightBits[52] = setRightBits[45];
    setRightBits[55] = setRightBits[48];
    setRightBits[57] = setRightBits[48];
    setRightBits[59] = setRightBits[50];
    setRightBits[48] = setRightBits[43];
    setRightBits[50] = setRightBits[43];
    setRightBits[45] = setRightBits[40];
    setRightBits[43] = setRightBits[40];
    setRightBits[40] = setRightBits[37];
    setRightBits[56] = setRightBits[47];
    setRightBits[54] = setRightBits[47];
    setRightBits[47] = setRightBits[42];
    setRightBits[58] = setRightBits[49];
    setRightBits[49] = setRightBits[44];
    setRightBits[51] = setRightBits[44];
    setRightBits[42] = setRightBits[39];
    setRightBits[44] = setRightBits[39];
    setRightBits[37] = setRightBits[36];
    setRightBits[39] = setRightBits[36];
    setRightBits[53] = setRightBits[46];
    setRightBits[46] = setRightBits[41];
    setRightBits[41] = setRightBits[38];
    setRightBits[36] = setRightBits[35];
    setRightBits[38] = setRightBits[35];
    setRightBits[35] = setRightBits[34];
    setRightBits[34] = setRightBits[112];
    return setRightBits;
}

aligned_vector<int> DESCracker::createInverseInitialAndSwapLeftRight(const string &cryptoText) {
    aligned_vector<int> bits = swapLeftAndRight(initialPermutation(plainTextToPlainBits(cryptoText)));
    return bits;
}

aligned_vector<int> DESCracker::swapLeftAndRight(aligned_vector<int> initialPermutationBits) {
    int help;
    for (int i = 0; i < 32; i++) {
        help = initialPermutationBits[i];
        initialPermutationBits[i] = initialPermutationBits[i + 32];
        initialPermutationBits[i + 32] = help;
    }
    return initialPermutationBits;
}

aligned_vector<int> DESCracker::inverseInitialPermutation(aligned_vector<int> swapLeftAndRightBits) {
    aligned_vector<int> inverseInitialPermutationBits(176, 0);

    inverseInitialPermutationBits[63 - 57] = swapLeftAndRightBits[63];
    inverseInitialPermutationBits[63 - 49] = swapLeftAndRightBits[62];
    inverseInitialPermutationBits[63 - 41] = swapLeftAndRightBits[61];
    inverseInitialPermutationBits[63 - 33] = swapLeftAndRightBits[60];
    inverseInitialPermutationBits[63 - 25] = swapLeftAndRightBits[59];
    inverseInitialPermutationBits[63 - 17] = swapLeftAndRightBits[58];
    inverseInitialPermutationBits[63 - 9] = swapLeftAndRightBits[57];
    inverseInitialPermutationBits[63 - 1] = swapLeftAndRightBits[56];

    inverseInitialPermutationBits[63 - 59] = swapLeftAndRightBits[55];
    inverseInitialPermutationBits[63 - 51] = swapLeftAndRightBits[54];
    inverseInitialPermutationBits[63 - 43] = swapLeftAndRightBits[53];
    inverseInitialPermutationBits[63 - 35] = swapLeftAndRightBits[52];
    inverseInitialPermutationBits[63 - 27] = swapLeftAndRightBits[51];
    inverseInitialPermutationBits[63 - 19] = swapLeftAndRightBits[50];
    inverseInitialPermutationBits[63 - 11] = swapLeftAndRightBits[49];
    inverseInitialPermutationBits[63 - 3] = swapLeftAndRightBits[48];

    inverseInitialPermutationBits[63 - 61] = swapLeftAndRightBits[47];
    inverseInitialPermutationBits[63 - 53] = swapLeftAndRightBits[46];
    inverseInitialPermutationBits[63 - 45] = swapLeftAndRightBits[45];
    inverseInitialPermutationBits[63 - 37] = swapLeftAndRightBits[44];
    inverseInitialPermutationBits[63 - 29] = swapLeftAndRightBits[43];
    inverseInitialPermutationBits[63 - 21] = swapLeftAndRightBits[42];
    inverseInitialPermutationBits[63 - 13] = swapLeftAndRightBits[41];
    inverseInitialPermutationBits[63 - 5] = swapLeftAndRightBits[40];

    inverseInitialPermutationBits[63 - 63] = swapLeftAndRightBits[39];
    inverseInitialPermutationBits[63 - 55] = swapLeftAndRightBits[38];
    inverseInitialPermutationBits[63 - 47] = swapLeftAndRightBits[37];
    inverseInitialPermutationBits[63 - 39] = swapLeftAndRightBits[36];
    inverseInitialPermutationBits[63 - 31] = swapLeftAndRightBits[35];
    inverseInitialPermutationBits[63 - 23] = swapLeftAndRightBits[34];
    inverseInitialPermutationBits[63 - 15] = swapLeftAndRightBits[33];
    inverseInitialPermutationBits[63 - 7] = swapLeftAndRightBits[32];

    inverseInitialPermutationBits[63 - 56] = swapLeftAndRightBits[31];
    inverseInitialPermutationBits[63 - 48] = swapLeftAndRightBits[30];
    inverseInitialPermutationBits[63 - 40] = swapLeftAndRightBits[29];
    inverseInitialPermutationBits[63 - 32] = swapLeftAndRightBits[28];
    inverseInitialPermutationBits[63 - 24] = swapLeftAndRightBits[27];
    inverseInitialPermutationBits[63 - 16] = swapLeftAndRightBits[26];
    inverseInitialPermutationBits[63 - 8] = swapLeftAndRightBits[25];
    inverseInitialPermutationBits[63 - 0] = swapLeftAndRightBits[24];

    inverseInitialPermutationBits[63 - 58] = swapLeftAndRightBits[23];
    inverseInitialPermutationBits[63 - 50] = swapLeftAndRightBits[22];
    inverseInitialPermutationBits[63 - 42] = swapLeftAndRightBits[21];
    inverseInitialPermutationBits[63 - 34] = swapLeftAndRightBits[20];
    inverseInitialPermutationBits[63 - 26] = swapLeftAndRightBits[19];
    inverseInitialPermutationBits[63 - 18] = swapLeftAndRightBits[18];
    inverseInitialPermutationBits[63 - 10] = swapLeftAndRightBits[17];
    inverseInitialPermutationBits[63 - 2] = swapLeftAndRightBits[16];

    inverseInitialPermutationBits[63 - 60] = swapLeftAndRightBits[15];
    inverseInitialPermutationBits[63 - 52] = swapLeftAndRightBits[14];
    inverseInitialPermutationBits[63 - 44] = swapLeftAndRightBits[13];
    inverseInitialPermutationBits[63 - 36] = swapLeftAndRightBits[12];
    inverseInitialPermutationBits[63 - 28] = swapLeftAndRightBits[11];
    inverseInitialPermutationBits[63 - 20] = swapLeftAndRightBits[10];
    inverseInitialPermutationBits[63 - 12] = swapLeftAndRightBits[9];
    inverseInitialPermutationBits[63 - 4] = swapLeftAndRightBits[8];

    inverseInitialPermutationBits[63 - 62] = swapLeftAndRightBits[7];
    inverseInitialPermutationBits[63 - 54] = swapLeftAndRightBits[6];
    inverseInitialPermutationBits[63 - 46] = swapLeftAndRightBits[5];
    inverseInitialPermutationBits[63 - 38] = swapLeftAndRightBits[4];
    inverseInitialPermutationBits[63 - 30] = swapLeftAndRightBits[3];
    inverseInitialPermutationBits[63 - 22] = swapLeftAndRightBits[2];
    inverseInitialPermutationBits[63 - 14] = swapLeftAndRightBits[1];
    inverseInitialPermutationBits[63 - 6] = swapLeftAndRightBits[0];

    return inverseInitialPermutationBits;
}

string DESCracker::cryptoBitsToHexCryptoText(aligned_vector<int> cryptoBits) {
    stringstream stream;
    for (int i = 0; i < 64; i += 4) {
        int number = 0;
        number += cryptoBits[i] * 8;
        number += cryptoBits[i + 1] * 4;
        number += cryptoBits[i + 2] * 2;
        number += cryptoBits[i + 3] * 1;
        stream << std::hex << number;
    }
    return stream.str();
}