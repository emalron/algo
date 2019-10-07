#include<iostream>

struct Node {
    int data;
    Node *next;
};

struct List {
    Node *head;
    Node *tail;
    Node *current;
    int size;
};

List* ListInit();
void addNode(List *, int);
void insertNode(List *, int, int);
void deleteNode(List *, int);
Node* traverseNode(List*, int);

int main() {
    List* list = ListInit();

    for(int i=0; i<10; i++) {
        addNode(list, i);
    }

    insertNode(list, 1, 0);
    insertNode(list, 1, 2);
    insertNode(list, 0, 3); // 3 0 2 0 1 2 ... 9

    addNode(list, 10);
    deleteNode(list, 1);
    deleteNode(list, 0);
    deleteNode(list, 0);

    Node* node_ = list->head;
    while(node_ != nullptr) {
        std::cout << node_->data << " ";
        node_ = node_->next;
    }
    std::cout << std::endl;
}

List* ListInit() {
    List* plist = (List*) malloc(sizeof(List));
    plist->head = nullptr;
    plist->tail = nullptr;
    plist->current = nullptr;
    plist->size = 0;

    return plist;
}

void addNode(List* plist, int data) {
    Node* node_ = (Node*) malloc(sizeof(Node));
    node_->data = data;
    node_->next = nullptr;
    
    if(!plist->head) {
        plist->head = node_;
    }
    else {
        Node *temp = plist->tail;
        plist->tail->next = node_;
    }

    plist->tail = node_;
    plist->size++;

    std::cout << "add " << data << " at " << plist->size-1 << std::endl;
}

void insertNode(List * plist, int index, int data) {
    if(index > plist->size-1) {
        std::cout << "index is out of bound." << std::endl;
        return;
    }

    Node* node_ = (Node*) malloc(sizeof(Node));
    node_->data = data;

    if(index == 0) {
        Node* head = plist->head;

        plist->head = node_;
        plist->head->next = head;
    }
    else {
        Node* cur = traverseNode(plist, index-1);
        Node* curNext = cur->next;
        
        cur->next = node_;
        cur->next->next = curNext;
    }

    std::cout << "insert " << node_->data << " at " << index << std::endl;
}

void deleteNode(List * plist, int index) {
    int data = 0;

    plist->current = plist->head;
    if(index == 0) {
        Node* temp = plist->head->next;

        data = plist->head->data;

        free(plist->head);
        plist->head = temp;
    }
    else {
        Node* cur = traverseNode(plist, index-1);
        Node* curNext = cur->next->next;

        data = cur->next->data;

        free(cur->next);
        cur->next = curNext;
    }

    std::cout << "delete " << data << " at " << index << std::endl;
}

Node* traverseNode(List* plist, int index) {
    if(index == 0) {
        return plist->head;
    }

    plist->current = plist->head;
    for(int i=0; i<index; i++) {
        plist->current = plist->current->next;
    }

    return plist->current;
}