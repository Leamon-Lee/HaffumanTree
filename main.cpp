#include "huffmanTree\include\huffman.h"
#include <iostream>

using namespace std;

int main() {
    string cipherTextAddress = "D:\\Desktop\\HUFFMAN_TREE\\ioFile\\cipherText.txt";
    string plainTextAddress = "D:\\Desktop\\HUFFMAN_TREE\\ioFile\\plainText.txt";
    cout << "Enter 1 to encode" << endl;
    cout << "Enter 2 to decode" << endl;

    huffman h;
    h.createTree();
    h.storeCodes(h.root, "");

    char chioce; cin >> chioce;
    switch (chioce) {
    case '1':
        //h.printCodes(h.root, "");
        h.encode(cipherTextAddress, plainTextAddress);
        break;
    
    case '2':
        //h.printCodes(h.root, "");
        h.decode(h.root, cipherTextAddress, plainTextAddress);
        break;
    default:
        cout << "Invalid choice" << endl;
        cout << "Please enter 1 or 2" << endl;
    }
    return 0;
}