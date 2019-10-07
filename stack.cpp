#include<iostream>

struct stack
{
    /* data */
    int top = -1;
    int size = 0;
    int* arr;
};

stack create(int);
int peek(stack&);
bool push(stack&, int);
bool pop(stack&);
bool destroy(stack&);

int main() {
    stack s = create(10);
    for(int i=0; i<10; i++) {
        push(s, i);
    }
    for(int j=0; j<10; j++) {
        std::cout << peek(s) << std::endl;
        pop(s);
    }

    push(s, 10);
    push(s, 5);
    push(s, 1);

    /*
    for(int j=0; j<10; j++) {
        std::cout << peek(s) << std::endl;
        pop(s);
    }
    */

    destroy(s);

    for(int i=0; i<s.size; i++) {
        std::cout << s.arr[i] << " ";
    }
    std::cout << std::endl;

}

stack create(int n) {
    stack s_;

    s_.size = n;
    s_.arr = new int[s_.size];

    std::cout << "[create] stack.size: " << s_.size << std::endl;
    return s_;
}

int peek(stack& s) {
    if(s.top == -1) {
        std::cout << "[peek] Empty stack" << std::endl;
        return -1;
    }
    else {
        return s.arr[s.top];
    }
    
}

bool push(stack& s, int item) {
    if(s.size == s.top-1) {
        std::cout << "[push] Full of stack" << std::endl;
        return false;
    }
    else {
        s.arr[++s.top] = item;
        std::cout << "[push] top: " << s.top << "= " << item << std::endl;
        return true;
    }
}

bool pop(stack& s) {
    if(s.top < 0) {
        std::cout << "[pop] No item" << std::endl;
        return false;
    }
    else {
        s.arr[s.top] = 0;
        s.top--;
        return true;
    }
}

bool destroy(stack& s) {
    delete [] s.arr;
    s.arr = NULL;

    return true;
}