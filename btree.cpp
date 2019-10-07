#include <iostream>

struct BTreeNode {
    int data;
    BTreeNode *left;
    BTreeNode *right;
};

typedef void visitFunc(BTreeNode *node);

BTreeNode* MakeTreeNode();
int GetData(BTreeNode *bt);
int SetData(BTreeNode *bt, int data);
BTreeNode* GetLeftSubTree(BTreeNode *bt);
BTreeNode* GetRightSubTree(BTreeNode *bt);
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);
void InorderTraverse(BTreeNode *tree, visitFunc action);
void printData(BTreeNode *node);
void DeleteNode(BTreeNode *node);

int main() {
    BTreeNode *head = MakeTreeNode();
    MakeLeftSubTree(head, MakeTreeNode());
    MakeRightSubTree(head, MakeTreeNode());
    MakeLeftSubTree(GetLeftSubTree(head), MakeTreeNode());

    SetData(head, 1);
    SetData(GetLeftSubTree(head), 2);
    SetData(GetRightSubTree(head), 3);
    SetData(GetLeftSubTree(GetLeftSubTree(head)), 4);

    InorderTraverse(head, printData);
    InorderTraverse(head, DeleteNode);
    InorderTraverse(head, printData);
}

BTreeNode* MakeTreeNode() {
    BTreeNode* bt = (BTreeNode*)malloc(sizeof(BTreeNode));

    bt->left = nullptr;
    bt->right = nullptr;

    return bt;
}

int GetData(BTreeNode *bt) {
    return bt->data;
}

int SetData(BTreeNode *bt, int data) {
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode *bt) {
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode *bt) {
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
    if(main->left != nullptr) {
        free(main->left);
    }
    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
    if(main->right != nullptr) {
        free(main->right);
    }
    main->right = sub;
}

void InorderTraverse(BTreeNode *tree, visitFunc action) {
    if(tree == nullptr) {
        return;
    }

    InorderTraverse(GetLeftSubTree(tree), action);
    action(tree);
    InorderTraverse(GetRightSubTree(tree), action);
}

void printData(BTreeNode *node) {
    if(node != nullptr)
        std::cout << " - " << GetData(node) << " = " << std::endl;
}

void DeleteNode(BTreeNode *node) {
    std::cout << GetData(node) << " ";
    free(node);
    node = nullptr;
    std::cout << "deleted" << std::endl;
}