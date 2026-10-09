#include <iostream>
#include <string>

template <typename T>
class Range {
private:
    T _start;
    T _end;

public:
    Range(T start, T end) : _start(start), _end(end) {}

    bool contains(const T& value) const {
        if (value >= _start && value <= _end) return true;
        return false;
    }

    int length() const {
        return (_end - _start);
    }

    void print() const {
        std::cout << "start: " << _start << "\nend: " << _end << "\n";
    }
};

void test_Range() {
    {
        Range<int> r(4, 10);
        if (r.contains(7)) std::cout << "range contains 7\n";
        else std::cout << "range does not contain 7\n";
        if (r.contains(36)) std::cout << "range contains 36\n";
        else std::cout << "range does not contain 36\n";
        std::cout << "length: " << r.length() << "\n";
        r.print();
    }
    {
        Range<double> r(4.56, 10.01);
        if (r.contains(4.56)) std::cout << "range contains 4.56\n";
        else std::cout << "range does not contain 4.56\n";
        if (r.contains(10.02)) std::cout << "range contains 10.02\n";
        else std::cout << "range does not contain 10.02\n";
        std::cout << "length: " << r.length() << "\n";
        r.print();
    }
    {
        Range<char> r('a', 'z');
        if (r.contains('g')) std::cout << "range contains g\n";
        else std::cout << "range does not contain g\n";
        if (r.contains('%')) std::cout << "range contains %\n";
        else std::cout << "range does not contain %\n";
        std::cout << "length: " << r.length() << "\n";
        r.print();
    }
}

int main() {
    test_Range();
}
