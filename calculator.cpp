#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<stack>

char* get_rawdata(int, char**);
std::vector<std::string> make_expression(std::string&);
std::vector<std::string> make_postfix(const std::vector<std::string>&);
bool check_operator(const char&);
int calculate_postfix(std::vector<std::string>&);

int main(int argc, char** argv) {
    std::string raw_data = get_rawdata(argc, argv);
    std::vector<std::string> expression = make_expression(raw_data);
    std::vector<std::string> postfixed = make_postfix(expression);
    int result = calculate_postfix(postfixed);

    std::cout << result << std::endl;
}

char* get_rawdata(int argc, char** argv) {
    char* result = argv[1];

    for(int i=2; i<argc; i++) {
        strcat(result, argv[i]);
    }

    return result;
}

std::vector<std::string> make_expression(std::string& rawdata) {
    std::vector<std::string> tokens;
    std::string expression;

    std::cout << rawdata << std::endl;

    int num = 0, finger;
    for(int i=0; i<rawdata.length(); i++) {
        finger = i;
        std::string buffer;

        while(finger < rawdata.length()) {
            if(check_operator(rawdata[finger])) {
                i = finger;
                break;
            }
            buffer += rawdata[finger];
            finger++;
        }

        tokens.push_back(buffer);
        num++;

        if(rawdata[finger] != '\0') {
            buffer.clear();
            buffer += rawdata[finger];
            tokens.push_back(buffer);
            num++;
        }
    }

    std::cout << "# of tokens: " << num <<std::endl;
    for(auto& token : tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;
    return tokens;
}

bool check_operator(const char& ch) {
    switch(ch) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

bool check_operator(const std::string& ch) {
    switch(ch[0]) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

std::vector<std::string> make_postfix(const std::vector<std::string>& tokens) {
    std::stack<std::string> opers;
    std::vector<std::string> result;
    result.reserve(tokens.size());

    for(auto& token : tokens) {
        if(check_operator(token)) {
            switch(token[0]) {
                case '+':
                case '-':
                    if(opers.empty()) {
                        opers.push(token);
                    }
                    else {
                        while(!opers.empty()) {
                            result.push_back(opers.top());
                            std::cout << opers.top() << " ";
                            opers.pop();
                        }
                        opers.push(token);
                    }
                    break;
                case '*':
                case '/':
                    if(opers.empty()) {
                        opers.push(token);
                    }
                    else {
                        if(opers.top()[0] == '*' || opers.top()[0] == '/') {
                            result.push_back(opers.top());
                            std::cout << opers.top() << std::endl;
                            opers.pop();
                            opers.push(token);
                        }
                        else {
                            opers.push(token);
                        }
                    }
                    break;
            }
        } // if token is an operator
        else {
            result.push_back(token);
            std::cout << token << " ";
        }
    }

    while(!opers.empty()) {
        result.push_back(opers.top());
        std::cout << opers.top() << " ";
        opers.pop();
    }
    std::cout << std::endl;

    return result;
}

int calculate_postfix(std::vector<std::string>& expression) {
    std::stack<std::string> s;

    int lvalue, rvalue, value;
    for(auto& token : expression) {
        if(check_operator(token)) {
            std::cout << "OPeration: ";
            rvalue = std::stoi(s.top());
            s.pop();
            lvalue = std::stoi(s.top());
            s.pop();

            switch(token[0]) {
                case '+':
                    std::cout << lvalue << "+" << rvalue << " = ";
                    value = lvalue + rvalue;
                    std::cout << value << std::endl;
                    s.push(std::to_string(value));
                    break;
                case '-':
                    std::cout << lvalue << "-" << rvalue << " = ";
                    value = lvalue - rvalue;
                    std::cout << value << std::endl;
                    s.push(std::to_string(value));
                    break;
                case '*':
                    std::cout << lvalue << "*" << rvalue << " = ";
                    value = lvalue * rvalue;
                    std::cout << value << std::endl;
                    s.push(std::to_string(value));
                    break;
                case '/':
                    std::cout << lvalue << "/" << rvalue << " = ";
                    value = lvalue / rvalue;
                    std::cout << value << std::endl;
                    s.push(std::to_string(value));
                    break;
            }

        } // if token is 
        else {
            s.push(token);
        }
    }

    value = std::stoi(s.top());
    s.pop();
    return value;
}