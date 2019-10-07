#include<iostream>
#include<algorithm>

void pick(int, int, int, int**&, bool**&);

int score = 0;
int count = 0;
int N, X, Y;
int** memo;

int main() {
    std::cin >> N;
    Y = 2;

    int** stic_;
    bool** avail_;

    for(int n=0; n<N; n++) {
        std::cin >> X;

        stic_ = new int*[Y];
        avail_ = new bool*[Y];
        memo = new int*[Y];

        for(int j=0; j<Y; j++) {
            stic_[j] = new int[X+1];
            avail_[j] = new bool[X+1];
            memo[j] = new int[X+1];
        }

        stic_[0][0] = 0;
        stic_[0][0] = 0;
        avail_[0][0] = false;
        avail_[0][0] = false;

        for(int j=0; j<Y; j++) {
            for(int i=1; i<X+1; i++) {
                std::cin >> stic_[j][i];
                avail_[j][i] = true;
            }
        }

        pick(0, 2, 0, stic_, avail_);
        std::cout << score << std::endl;
    }
}

void pick(int i, int j, int s, int**& stickers, bool**& available) {
    if(i >= X+1) {
        available[0][i] = true;
        available[1][i] = true;
        return;
    }

    if(j == 2) {

    }
    else {
        s += stickers[j][i];
        available[0][i] = false;
        available[1][i] = false;
        available[j][i+1] = false;
        score = std::max(score, s);
    }

    bool prev[2] = {available[0][i+1], available[1][i+1]};

    if(available[0][i+1]) {
        pick(i+1, 0, s, stickers, available); // 0 뜯는다
        available[0][i+1] = prev[0];
        available[1][i+1] = prev[1];
        available[0][i+2] = true; // 상태 되돌리기
    }
    if(available[1][i+1]) {
        pick(i+1, 1, s, stickers, available); // 1 뜯는다 
        available[0][i+1] = prev[0];
        available[1][i+1] = prev[1];
        available[1][i+2] = true; // 상태 되돌리기
    }
    pick(i+1, 2, s, stickers, available); // 아무것도 안뜯음
}