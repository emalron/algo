#include<string>

class person
{
private:
    /* data */
    static int number;
    int id;
public:
    person(int age, std::string name);
    ~person();

    int age;
    int gold;
    std::string name;

    void changeGold(int amount);
    int callID();
};
