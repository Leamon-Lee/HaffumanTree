#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
#include <map>

using namespace std;

struct treeNode {
    char id;
    int freq;
    treeNode* left;
    treeNode* right;

    treeNode(char c, int f) : id(c), freq(f), left(nullptr), right(nullptr) {}

    bool operator>(const treeNode& other) const {
        return freq > other.freq;
    }
};
typedef treeNode* nodePtr;

struct CompareNode {
    bool operator()(nodePtr lhs, nodePtr rhs) const {
        return lhs->freq > rhs->freq;  // 按频率比较
    }
};

class huffman {
private:
    vector<pair<char, int>> store{ 
        {'A', 820}, {'B', 150}, {'C', 280}, {'D', 430}, {'E',1270}, {'F', 220},
        {'G', 200}, {'H', 610}, {'I', 700}, {'J',  15}, {'K',  77}, {'L', 400},
        {'M', 240}, {'N', 670}, {'O', 750}, {'P', 190}, {'Q',  10}, {'R', 600},
        {'S', 630}, {'T', 910}, {'U', 280}, {'V',  98}, {'W', 240}, {'X',  15},
        {'Y', 200}, {'Z',   7}
    };
    
public:
    vector<nodePtr> character;
    nodePtr root = nullptr;
     map<char, string> codes;

    huffman() {
        for (const auto& item : store) {
            character.push_back(new treeNode(item.first, item.second));
        }
    }

    ~huffman() {
        clearTree(root);
    }

    void createTree();
    void printCodes(nodePtr root, const string& code);
    void storeCodes(nodePtr root, const string& code);


    void encode(string cipherTextAddress, string plainTextAddress);
    void decode(nodePtr root, string cipherTextAddress, string plainTextAddress);

private:
    void clearTree(nodePtr node) {
        if (node) {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
    }
};

#endif

#include "../resource/huffmanTree.cpp"
#include "../resource/decode.cpp"
#include "../resource/encode.cpp"