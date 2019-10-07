#include<iostream>

class test {
    public:
    static int count;
    test() {
        this->count++;
    }
};
int test::count = 0;

int main() {
    test *t1, *t2;

    t1 = new test();
    t2 = new test();


    std::cout << t1->count << std::endl;

    delete t1;
    delete t2;
}