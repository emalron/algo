#include "person.hpp"

person::person(int age, std::string name)
{
    this->age = age;
    this->name = name;
    this->gold = 0;
    this->id = this->number++;
}

person::~person()
{
}

void person::changeGold(int amount) {
    this->gold += amount;
}

int person::callID() {
    return this->id;
}

int person::number = 0;