#include <iostream>
#include <stack>
#include <cassert>
#include <vector>
#include <string>

int evaluateRPN(const std::vector<std::string> &expression) {
    std::stack<int> numbers;
    for (int i = 0; i<expression.size(); i++) {
        if (expression[i] == "+") {
            if (numbers.size() < 2) throw std::invalid_argument("invalid expression");
            int a = numbers.top();
            numbers.pop();
            int b = numbers.top();
            numbers.pop();
            numbers.push(a+b);
        }
        else if(expression[i] == "-") {
            if (numbers.size() < 2) throw std::invalid_argument("invalid expression");
            int a = numbers.top();
            numbers.pop();
            int b = numbers.top();
            numbers.pop();
            numbers.push(a-b);
        }
        else if (expression[i] == "*") {
            if (numbers.size() < 2) throw std::invalid_argument("invalid expression");
            int a = numbers.top();
            numbers.pop();
            int b = numbers.top();
            numbers.pop();
            numbers.push(a*b);
        }
        else if (expression[i] == "/") {
            if (numbers.size() < 2) throw std::invalid_argument("invalid expression");
            int a = numbers.top();
            numbers.pop();
            int b = numbers.top();
            if (b==0) throw std::invalid_argument("division by zero");
            numbers.pop();
            numbers.push(a/b);
        }
        else {
            numbers.push(std::atoi(expression[i].c_str()));
        }
    }
    if (numbers.size() != 1) throw std::invalid_argument("invalid expression");
    return numbers.top();
}

void test_evaluateRPN() {
    std::vector<std::string> expr = {"2", "1", "+", "3", "*"};
    assert(evaluateRPN(expr) == 9);
    std::vector<std::string> expr = {"2"};
    assert(evaluateRPN(expr) == 2);
}

int main() {
    test_evaluateRPN();
    std::cout << "All tests pass\n";
}