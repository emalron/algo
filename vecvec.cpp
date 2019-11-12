#include<iostream>
#include<vector>

struct Score {
    int number;
    double score;
};

int main() {
    Score DataSet[] =
    {
        1, 877.88,
        2, 176.23,
        3, 365.92,
        4, 162.44,
        5, 224.72,
        6, 121.44
    };

    for(auto& e : DataSet) {
        std::cout << e.number << " " << e.score << std::endl;
    }
}