//#include <"../include/huffmanTree.h">
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void huffman::encode(string cipherTextAddress, string plainTextAddress) {    
    ifstream plainText(cipherTextAddress);
    ofstream cipherText(plainTextAddress);

    char ch;
    while(plainText.get(ch)){
        cipherText << codes[ch];
    }
    plainText.close();
    cipherText.close();
}
