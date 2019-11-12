#include<iostream>
#include<vector>

int lds(std::vector<int> input, int current, int end, std::vector<int> output, int &c) {
    if(current == end) {
        std::cout << "Case [" << c << "] " ;
        for(int i=1; i<output.size() ; i++) {
            std::cout << output[i] << " ";
        }
        std::cout << std::endl;
        
        c++;
        return 0;
    }

    lds(input, current+1, end, output, c);
    
    int prev = output.back();
    int cur = input[current];
    bool descending_check = cur < prev;

    if(descending_check) {
        output.push_back(cur);
    }
    lds(input, current+1, end, output, c);
    
    return 0;
}

int main() {
    std::vector<int> input, output(1, 100);
    input.push_back(0);
    input.push_back(2);
    input.push_back(1);

    std::cout << "input: ";
    for(auto &e : input) {
        std::cout << e << " ";
    }
    std::cout << std::endl << std::endl;

    int c = 0;

    lds(input, 0, 3, output, c);
}