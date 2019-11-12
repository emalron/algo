#include<iostream>

typedef struct State {
    int num;
    char from;
    char by;
    char to;
} State;

int hanoi(State state, void (*fp)(State), int&);
void print(State);

int main(int argc, char** argv) {
    int total = atoi(argv[1]);
    int count = 0;
    int &cnt = count;
    State state = {total, 'a', 'b', 'c'};

    std::cout << "Number of disks is " << total << std::endl;
    hanoi(state, print, cnt);

    std::cout << "Total moves: " << count << std::endl;
}

int hanoi(State state, void (*fp)(State), int& cnt) {
    if(state.num == 1) {
        fp(state);
        cnt++;
        return -1;
    }
    else {
        State s1 = {state.num-1, state.from, state.to, state.by};
        State s2 = {state.num-1, state.by, state.from, state.to};
        
        hanoi(s1, fp, cnt);
        fp(state);
        cnt++;
        hanoi(s2, fp, cnt);

void print(State state) {
    std::cout << "Disk " << state.num << " is moved " << state.from << " -> " << state.to << std::endl;
}
