#include <iostream>
#include <queue>
#include <cassert>
#include <vector>

std::vector<std::string> generateBinaryNumbers(int N) {
    std::queue<std::string> binary;
    binary.push("1");
    std::string front;
    std::vector<std::string> answer;
    for (int i = 0; i < N; i++) {
        front = binary.front();
        binary.push(front + "0");
        binary.push(front + "1");
        binary.pop();
        answer.push_back(front);
    }
    return answer;
}

void test_generateBinaryNumbers() {
    std::vector<std::string> result = generateBinaryNumbers(5);
    assert(result[0] == "1");
    assert(result[1] == "10");
    assert(result[2] == "11");
    assert(result[3] == "100");
    assert(result[4] == "101");
}

int main() {
    test_generateBinaryNumbers();
    std::cout << "All tests pass\n";
}