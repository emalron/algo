#include<iostream>
#include<malloc.h>

class charStack {
    public:
    char* buf;
    int max_size;
    int current;

    charStack(int i) {
        this->max_size = i;
        this->buf = new char[this->max_size];
        this->current = -1;
    }
    ~charStack() {
        delete[] buf;
    }

    void push(char input);
    char pop();
};

void charStack::push(char input) {
    if(this->current-1 < this->max_size) {
        this->buf[++this->current] = input;
    }    
}

char charStack::pop() {
    return this->buf[this->current--];
}

int main() {
    charStack cs(10);

    for(int i=0;i<10; i++) {
        cs.push('a' + i);
    }

    while(cs.current > -1) {
        std::cout << cs.pop() << " ";
    }

    std::cout << std::endl;
}