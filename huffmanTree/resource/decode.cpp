//#include <"../include/huffmanTree.h">
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void huffman::decode(nodePtr root, string cipherTextAddress, string plainTextAddress) {    
    ifstream cipherText(cipherTextAddress);
    ofstream plainText(plainTextAddress);

    char ch; 
    auto it = root;
    while(cipherText.get(ch)){
        if(ch == '0'){
            it = it->left;
        }else{
            it = it->right;
        }
        if(it->left == nullptr && it->right == nullptr){
            plainText << it->id;
            it = root;
        }
    }
    plainText.close();
    cipherText.close();
}
