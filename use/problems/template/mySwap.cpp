#include <iostream>
#include <string>

template <typename T>
void mySwap(T &val1, T &val2) {
    T tmp = val1;
    val1 = val2;
    val2 = tmp;
}

void test_swap() {
    {
        int val1 = 5;
        int val2 = 8;
        mySwap(val1, val2);
        std::cout << val1 << ", " << val2 << "\n";
    }
    {
        double val1 = 5.6;
        double val2 = 3.141592653589793238462643383279;
        mySwap(val1, val2);
        std::cout << val1 << ", " << val2 << "\n";
    }
    {
        std::string val1 = "aplle";
        std::string val2 = "pie";
        mySwap(val1, val2);
        std::cout << val1 << ", " << val2 << "\n";
    }
}

int main() {
    test_swap();
}
