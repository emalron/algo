#include<iostream>
#include<algorithm>

int ws[5] = {3, 4, 1, 2, 3};
int ps[5] = {2, 3, 2, 3, 6};
int dp[10];
int ret = 0, maxw = 10;

void knaps(int, int, int);
int knaps(int, int);

int main() {
    ret = knaps(1, 0);
    std::cout << ret << std::endl;
}

void knaps(int n, int w, int p) {
    
}

int knaps(int n, int w) {
    if(w > maxw) return -1;
    if(n >= 5) return 0;

    return std::max(knaps(n+1, w), knaps(n+1,w+ws[n]) + ps[n]);
}