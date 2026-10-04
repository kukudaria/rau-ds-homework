#include <iostream>
#include <string>

template <typename T>
T sumArray(T* data, int size) {
    T sum = data[0];
    for (int i = 1; i<size; i++) {
        sum += data[i];
    }
    return sum;
}

void test_sum() {
    {
        int data[] = {1, 2, 3, 4};
        std::cout << sumArray(data, 4) << "\n";
    }
    {
        double data[] = {1.5, 2.8, 3, 4.345678};
        std::cout << sumArray(data, 4) << "\n";
    }
    {
        std::string data[] = {"one", "two", "free", "four"};
        std::cout << sumArray(data, 4) << "\n";
    }
}

int main() {
    test_sum();
}
