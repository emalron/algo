#include<iostream>

int combi(int, int, int, int&, int*, int*);
int combi(int, int, int, int&, char*, int*);

int main(int argc, char** argv) {
    int n = atoi(argv[1]), r = atoi(argv[2]), count = 0;
    // int flag[n], pool[n];
    int flag[n];
    char pool[n];
    int& cnt = count;    

    for(auto i = 0; i < n; i++) {
        flag[i] = 0;
        pool[i] = i+97;
    }

    if(n >= r) {
        combi(n, r, n, cnt, pool, flag);
        std::cout << "result: " << count << std::endl;        
    }
    else {
        std::cout << "n has to be greater than r" << std::endl;
    }
    
} // end of main()

int combi(int n, int r, int length, int& cnt, int* pool, int* flag) {
    if(r == 1) {
        std::cout << "[!] " << n << "C" << r << std::endl;
        for(int i=0; i<n; i++) {
            flag[i] = 1;
            for(int j=0; j<length; j++) {
                if(flag[j] == 1) {
                    std::cout << pool[j] << " ";
                }
            }
            flag[i] = 0;
            cnt++;
            std::cout << std::endl;
        }
        return n;
    }
    else if(r == n) {
        std::cout << "[!] " << n << "C" << r << std::endl;
        for(int i=0; i<n; i++) {
            std::cout << pool[i] << " ";
        }
        for(int j=0; j<length; j++) {
            if(flag[j] == 1) {
                std::cout << pool[j] << " ";
            }
        }

        cnt++;
        std::cout << std::endl;
        return 1;
    }
    else {
        flag[n-1] = 1;
        combi(n-1, r-1, length, cnt, pool, flag);
        flag[n-1] = 0;
        combi(n-1, r, length, cnt, pool, flag);
    }
} // end of combi()

int combi(int n, int r, int length, int& cnt, char* pool, int* flag) {
    if(r == 1) {
        std::cout << "[!] " << n << "C" << r << std::endl;
        for(int i=0; i<n; i++) {
            flag[i] = 1;
            for(int j=0; j<length; j++) {
                if(flag[j] == 1) {
                    std::cout << pool[j] << " ";
                }
            }
            flag[i] = 0;
            cnt++;
            std::cout << std::endl;
        }
        return n;
    }
    else if(r == n) {
        std::cout << "[!] " << n << "C" << r << std::endl;
        for(int i=0; i<n; i++) {
            std::cout << pool[i] << " ";
        }
        for(int j=0; j<length; j++) {
            if(flag[j] == 1) {
                std::cout << pool[j] << " ";
            }
        }

        cnt++;
        std::cout << std::endl;
        return 1;
    }
    else {
        flag[n-1] = 1;
        combi(n-1, r-1, length, cnt, pool, flag);
        flag[n-1] = 0;
        combi(n-1, r, length, cnt, pool, flag);
    }
} // end of combi()