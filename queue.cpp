#include<iostream>

struct queue
{
    /* data */
    int front = 0;
    int rear = 0;
    int size = 0;
    int* arr;
};

queue create(int n);
void push(queue&, int);
int peek(queue&);
bool pop(queue&);
bool is_full(queue&);

int main() {
    queue q = create(10);

    for(int i=0; i< 5; i++) {
        push(q, i);
    }
    for(int i=0; i< 5; i++) {
        std::cout << peek(q) << " ";
        pop(q);
    }
        for(int i=0; i< 5; i++) {
        push(q, i+10);
    }
    for(int i=0; i< 5; i++) {
        std::cout << peek(q) << " ";
        pop(q);
    }
    std::cout << std::endl;
}

queue create(int n) {
    queue q_;
    q_.arr = new int[n];
    q_.size = n;

    return q_;
}

void push(queue& q, int item) {
    if(is_full(q)) {
        std::cout << "[add] queue is full" << std::endl;
    }
    else {
        std::cout << "[add] queue " << q.front << " " << q.rear << " " << item << std::endl;
        q.arr[q.rear++] = item;
    }
}

int peek(queue& q) {
    bool is_empty = q.front == q.rear;
    if(is_empty) {
        std::cout << "[peek] queue is empty" << std::endl;
        return -1;
    }
    else {
        return q.arr[q.front];
    }
}

bool pop(queue& q) {
    bool is_empty = q.front == q.rear;
    if(is_empty) {
        std::cout << "[pop] queue is empty" << std::endl;
    }
    else {
        q.front++;
        std::cout << "[pop] queue " << q.front << " " << q.rear << std::endl;
    }
}

bool is_full(queue& q) {
    if(q.rear == q.size) {
        return true;
    }
    else {
        return false;
    }
}