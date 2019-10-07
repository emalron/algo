#include<iostream>
#include<string>

class Person {
    public:
    int age;
    std::string name;
    Person *bestFriend;

    Person(int age, std::string name) {
        this->age = age;
        this->name = name;
        this->bestFriend = nullptr;
    }
};

class List {
    public:
    Person *head;

    List(Person *p) {
        this->head = p;
        this->nP = p->bestFriend;
    }

    void add(int age, std::string name) {
        Person *p = new Person(age, name);
        p->bestFriend = this->head;
        this->head = p;
        this->nP = this->head->bestFriend;
    }

    Person* getNow() {
        return this->nP;
    }

    void next() {
        this->nP = this->nP->bestFriend;
    }

    private:
    static Person *nP;
};

Person* List::nP = nullptr;

int main() {
    Person p1(1, "Jack");
    List li(&p1);

    li.add(2, "Jane");
    li.add(3, "John");
    li.add(4, "Jeus");
    li.add(5, "Jinx");

    while(li.getNow() != nullptr) {
        std::cout << li.getNow()->age << " Name: " << li.getNow()->name << std::endl;
        li.next();
    }

}