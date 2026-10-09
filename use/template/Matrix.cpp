#include <iostream>
#include <string>

template <typename T, int N, int M>
class Matrix {
private:
    T _matrix[N][M];

public:
    Matrix(T val=T()) {
        for (int i = 0; i<N; i++) {
            for (int j = 0; j<M; j++) {
                _matrix[i][j] = val;
            }
        }
    }

    void set(int row, int col, T value) {
        if (row>=N || col>=M || row<0 || col<0) throw std::invalid_argument("index out of range");
        _matrix[row][col] = value;
    }

    T get(int row, int col) const {
        if (row>=N || col>=M || row<0 || col<0) throw std::invalid_argument("index out of range");
        return _matrix[row][col];
    }

    void print() const {
        for (int i = 0; i<N; i++) {
            for (int j = 0; j<M; j++) {
                std::cout << _matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    Matrix<T, N, M> operator+(Matrix m) {
        Matrix<T, N, M> res;
        for (int i = 0; i<N; i++) {
            for (int j = 0; j<M; j++) {
                res._matrix[i][j] = _matrix[i][j] + m._matrix[i][j];
            }
        }
        return res;
    }
};

void test_Matrix() {
    {
        Matrix<int, 7, 8> m(0);
        m.print();
        m.set(3, 2, 1);
        m.print();
        std::cout << "set element: " << m.get(3, 2) << "\n";
    }
    {
        Matrix<double, 7, 8> m(0.60065);
        m.print();
        m.set(3, 2, 1.34);
        m.print();
        std::cout << "set element: " << m.get(3, 2) << "\n";
    }
    {
        Matrix<std::string, 7, 8> m("hi");
        m.print();
        m.set(3, 2, "hello");
        m.print();
        std::cout << "set element: " << m.get(3, 2) << "\n";
    }
}

int main() {
    test_Matrix();
}
