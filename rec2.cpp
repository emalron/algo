#include<iostream>

int map[2][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

int check[2][4];

void rec(int x, int y) {
    if(y >= 2) {
        std::cout << std::endl;
        return;
    }
    if(x >= 4) {
        std::cout << std::endl;
        return;
    }

    if(check[y][x] != 0) {
        return;
    }

    std::cout << map[y][x] << " ";
    check[y][x] = map[y][x];

    rec(x+1, y);
    rec(x, y+1);
}

int main() {
    rec(0, 0);
}