#include <iostream>
#include <string>

template <typename T>
int linearSearch(std::vector<T> vec, T element) {
    for (int i = 0; i<vec.size(); i++) {
        if (vec[i] == element) return i;
    }
    return -1;
}

void test_search() {
    {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::cout << linearSearch(vec, 3) << "\n";
    }
    {
        std::vector<double> vec = {1.1, 2.2, 3.3, 4.4, 5.5};
        std::cout << linearSearch(vec, 1.1) << "\n";
    }
    {
        std::vector<std::string> vec = {"1", "2", "3", "4", "5"};
        std::string str = "5";
        std::cout << linearSearch(vec, str) << "\n";
    }
}

int main() {
    test_search();
}
