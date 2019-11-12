#include <iostream>

struct BTreeNode {
    int data;
    BTreeNode *left;
    BTreeNode *right;
};

int main() {
    BTreeNode bt;

    bt.data = 1;

    std::cout << bt.data << std::endl;
}
