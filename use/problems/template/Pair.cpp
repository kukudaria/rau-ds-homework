#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair {
public:
    T1 val1;
    T2 val2;

    Pair(T1 v1, T2 v2) : val1(v1), val2(v2) {}

    void print() const {
        std::cout << "(" << val1 << ", " << val2 << ")";
    }
};

int main() {
}
