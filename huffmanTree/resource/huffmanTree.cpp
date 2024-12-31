// 创建 Huffman 树
void huffman::createTree() {
    // 使用自定义比较器的优先队列
    priority_queue<nodePtr, vector<nodePtr>, CompareNode> pq;

    // 将所有叶节点添加到优先队列
    for (auto& node : character) {
        pq.push(node);
    }

    // 合并节点构建 Huffman 树
    while (pq.size() > 1) {
        nodePtr left = pq.top(); pq.pop();
        nodePtr right = pq.top(); pq.pop();

        // 创建一个新节点，频率为左右子节点频率之和
        nodePtr parent = new treeNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    // 设置根节点
    root = pq.top();
}

// 打印 Huffman 编码
void huffman::printCodes(nodePtr root, const string& code) {
    if (!root) return;

    // 如果是叶节点，打印字符及其编码
    if (!root->left && !root->right) {
        cout << root->id << ": " << code << endl;
        return;
    }

    // 遍历左子树和右子树
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffman::storeCodes(nodePtr root, const string& code){
    if (!root) {
        return;
    }

    // 如果是叶节点，存储字符及其编码
    if (!root->left && !root->right) {
        codes.insert(make_pair(root->id, code));
    }

    // 遍历左子树和右子树
    storeCodes(root->left, code + "0");
    storeCodes(root->right, code + "1");
}
