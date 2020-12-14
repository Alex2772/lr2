#include <iostream>
#include <sstream>
#include <stack>
#include <cassert>

int main() {
    std::cout << "Expr: ";
    std::string wholeExpr;
    std::getline(std::cin, wholeExpr);
    std::stringstream ss(wholeExpr);

    std::stack<char> ops;

    std::cout << "PLSK: ";

    std::string token;
    while (!ss.eof()) {
        ss >> token;
        if (token.empty()) {
            continue;
        }
        try {
            std::cout << std::stod(token) << ' ';
        } catch (...) {
            if (token.length() != 1) {
                std::cout << std::endl << "invalid operation: " << token;
                return -1;
            }
            switch (token[0]) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '(':
                case '^':
                    ops.push(token[0]);
                    break;
                case ')':
                    while (ops.top() != '(') {
                        std::cout << ops.top() << ' ';
                        ops.pop();
                        if (ops.empty()) {
                            std::cout << std::endl << "brackets are not consistent";
                            return -1;
                        }
                    }
                    ops.pop();
                    break;

                default:
                    std::cout << std::endl << "invalid operation: " << token[0];
                    return -1;
            }
        }
    }

    while (!ops.empty()) {
        if (ops.top() == '(') {
            std::cout << std::endl << "brackets are not consistent";
            return -1;
        }
        std::cout << ops.top() << ' ';
        ops.pop();
    }


    return 0;
}
