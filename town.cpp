#include "person.hpp"
#include<iostream>
#include<vector>

int main() {
    std::vector<person> persons;

    persons.push_back(person(10, "Jack"));
    persons.push_back(person(25, "Jessi"));
    persons.push_back(person(31, "Jason"));
    persons.push_back(person(15, "Jane"));

    for(auto p : persons) {
        std::cout << "ID: " << p.callID() << " is " << p.name << std::endl;
    }
}