#include<iostream>
#include<unordered_map>
#include<string>

std::unordered_map<std::string, int> lookup;

int minsum(int* set, int n, int sum1, int sum2) {
    if(n < 0) {
        return abs(sum1 - sum2);
    }

    std::string key = std::to_string(n) + "|" + std::to_string(sum1);

    if(lookup.find(key) == lookup.end()) {
        int temp1 = minsum(set, n-1, sum1+set[n], sum2);
        int temp2 = minsum(set, n-1, sum1, sum2 + set[n]);

        lookup[key] = std::min(temp1, temp2);

        std::cout << "created key: " << key << " " << lookup[key] << std::endl;
    }
    
    std::cout << "found key: " << key << " " << lookup[key] << std::endl;
    return lookup[key];
}

int main() {
    int set[] = {10, 20, 15, 25};

    int sol = minsum(set, sizeof(set) / sizeof(int)-1,  0, 0);

    std::cout << sol << std::endl;

    for(auto item : lookup) {
        std::cout << item.first << " " << item.second << std::endl;
    }
}