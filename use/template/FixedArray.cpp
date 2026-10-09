#include <iostream>
#include <string>

template <typename T, int N>
class FixedArray {
private:
    T _arr[N];

public:
    FixedArray(T val=T())  {
        for (int i = 0; i<N; i++) {
            _arr[i] = val;
        }
    }

    void set(int index, T value) {
        if (index >= N || index < 0) throw std::invalid_argument("index out of range");
        _arr[index] = value;
    }

    T get(int index) const {
        if (index >= N || index < 0) throw std::invalid_argument("index out of range");
        return _arr[index];
    }

    int size() const {
        return N;
    }

};

void test_FixedArr() {
    {
        FixedArray<int, 6> arr(7);
        arr.set(2, 0);
        std::cout << "changed element: "<< arr.get(2) << "\nbasic element: " 
        << arr.get(0) << "\nsize: " << arr.size() << "\n";
    }
    {
        FixedArray<double, 6> arr(7.7);
        arr.set(2, 6.66);
        std::cout << "changed element: "<< arr.get(2) << "\nbasic element: " 
        << arr.get(0) << "\nsize: " << arr.size() << "\n";
    }
    {
        FixedArray<std::string, 6> arr("hi");
        arr.set(2, "hello");
        std::cout << "changed element: "<< arr.get(2) << "\nbasic element: " 
        << arr.get(0) << "\nsize: " << arr.size() << "\n";
    }
}

int main() {
    test_FixedArr();
}
