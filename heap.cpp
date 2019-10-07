#include<iostream>

class Heap {
    public:
    int *HeapArrp;
    int maxSize;
    int size;

    Heap(int size) {
        this->maxSize = size;
        this->HeapArrp = new int[size];
        this->HeapArrp[0] = 0;
        this->size = 0;
    }
    ~Heap();
    void insert(int i);
    void peek();

    private:
    void remove();
};

Heap::~Heap() {
    free(this->HeapArrp);
}

void Heap::insert(int data) {
    int parent, child, idx;
    child = ++this->size;
    parent = child / 2;

    idx = child;
    while((idx != 1) && (data < this->HeapArrp[parent])) {
        this->HeapArrp[idx] = this->HeapArrp[parent];
        idx = idx / 2;
        parent = idx / 2;
    }
    this->HeapArrp[idx] = data;

    std::cout << "heap push: " << data << std::endl;
}

void Heap::remove() {
    int temp = this->HeapArrp[this->size--];
    int idx = 1;
    int child = idx*2;

    while(idx < this->size) {
        if(idx*2 + 1 <= this->size) {
            if(this->HeapArrp[idx*2] > this->HeapArrp[idx*2 + 1]) {
                child = idx * 2 + 1;
            }
        }

        if(temp > this->HeapArrp[child]) {
            this->HeapArrp[idx] = this->HeapArrp[child];
            idx = child;
            child = idx*2;
        }
        else {
            break;
        }
    }

    this->HeapArrp[idx] = temp;
}

void Heap::peek() {
    std::cout << "peek: " << this->HeapArrp[1] << std::endl;
    this->remove();
}

int main() {
    Heap heap(10);

    heap.insert(5);
    heap.insert(4);
    heap.insert(3);
    heap.insert(10);
    heap.insert(2);
    heap.insert(23);
    heap.insert(1);

    std::cout << std::endl << "Heap values: ";
    for(int i=1; i<=heap.size; i++) {
        std::cout << heap.HeapArrp[i] << " ";
    }
    std::cout << std::endl;


    for(int j=1;j<=7; j++) {
        heap.peek();

        std::cout << "Heap values: ";
        for(int i=1; i<=heap.size; i++) {
            std::cout << heap.HeapArrp[i] << " ";
        }
        std::cout << std::endl;
    }

}