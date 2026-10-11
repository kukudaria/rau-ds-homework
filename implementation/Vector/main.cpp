#include "Vector.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Vector<T>:
//
//   1. Vector()                        - конструктор по умолчанию
//   2. ~Vector()                       - деструктор
//   3. Vector(const Vector& other)     - конструктор копирования
//   4. operator=(const Vector& other)  - оператор присваивания
//   5. push_back(const T& x)           - добавить в конец
//   6. pop_back()                      - удалить с конца
//   7. operator[](int index)           - доступ по индексу
//   8. back()                          - последний элемент
//   9. insert(int pos, const T& val)   - вставить
//  10. erase(int pos)                  - удалить
//  11. swap(Vector& other)             - обменять содержимое
//  12. clear()                         - очистить
//  13. resize(int new_size)            - изменить размер
//  14. front()                         - первый элемент
//
// Напишите для каждой функции один тест:
//   void test_<название_функции>() { ... }
//
// Каждый тест должен проверять:
//   - Нормальный случай
//   - Граничные случаи


void test_push_back() {
    Vector<int> v;
    
    // Нормальный случай
    v.push_back(5);
    assert(v.size() == 1);
    assert(v[0] == 5);
    
    v.push_back(10);
    v.push_back(15);
    assert(v.size() == 3);
    assert(v.back() == 15);
    
    std::cout << "test_push_back passed" << std::endl;
}

void test_pop_back() {
    Vector<int> v;

    v.push_back(3);
    v.push_back(5);
    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 3);

    v.push_back(10);
    v.push_back(15);
    v.pop_back();
    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 3);

    std::cout << "test_pop_back passed" << std::endl;
}


void test_operator_bracket() {
    Vector<int> v;

    v.push_back(3);
    v.push_back(5);

    assert(v[0] == 3);
    assert(v[1] == 5);

    v.push_back(8);
    assert(v[2] == 8);

    v.pop_back();
    assert(v[0] == 3);
    assert(v[1] == 5);

    std::cout << "test_operator_bracket passed" << std::endl;
}

void test_at() {
    Vector<int> v;

    v.push_back(3);
    v.push_back(5);

    assert(v.at(0) == 3);
    assert(v.at(1) == 5);

    v.push_back(8);
    assert(v.at(2) == 8);

    v.pop_back();
    assert(v.at(0) == 3);
    assert(v.at(1) == 5);

    std::cout << "test_at passed" << std::endl;
}

void test_empty() {
    Vector<int> v;

    assert(v.empty());

    v.push_back(8);
    assert(!v.empty());

    v.pop_back();
    assert(v.empty());

    std::cout << "test_empty passed" << std::endl;
}

void test_back() {
    Vector<int> v;

    v.push_back(3);
    assert(v.back() == 3);

    v.push_back(10);
    v.push_back(15);
    assert(v.back() == 15);

    std::cout << "test_back passed" << std::endl;
}

void test_front() {
    Vector<int> v;

    v.push_back(3);
    assert(v.front() == 3);

    v.pop_back();
    v.push_back(10);
    v.push_back(15);
    assert(v.front() == 10);

    std::cout << "test_front passed" << std::endl;
}

void test_begin() {
    Vector<int> v;

    v.push_back(3);
    assert(v.begin() == &v.front());

    std::cout << "test_begin passed" << std::endl;
}

void test_end() {
    Vector<int> v;

    v.push_back(3);
    assert(v.end() == &v.back());

    std::cout << "test_end passed" << std::endl;
}

void test_insert() {
    Vector<int> v;

    v.insert(0, 2);
    assert(v.front() == 2);

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.insert(2, 3);
    assert(v[2] == 3);
    assert(v.size() == 5);
    assert(v[3] == 10);
    
    v.insert(5, 7);
    assert(v.back() == 7);
    
    std::cout << "test_insert passed" << std::endl;
}

void test_erase() {
    Vector<int> v;

    v.push_back(3);
    v.push_back(5);
    v.erase(0);
    assert(v.size() == 1);
    assert(v[0] == 5);

    v.push_back(10);
    v.push_back(15);
    v.erase(1);
    assert(v.size() == 2);
    assert(v[1] == 15);

    v.erase(1);
    assert(v.size() == 1);
    assert(v[0] == 5);

    std::cout << "test_erase passed" << std::endl;
}

void test_swap() {
    Vector<int> v;

    v.push_back(3);
    v.push_back(10);
    v.push_back(15);
    
    Vector<int> v2;

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(12);
    v2.push_back(67);

    v.swap(v2);

    assert(v2.size() == 3);
    assert(v.size() == 5);
    assert(v2[1] == 10);
    assert(v[1] == 2);
    assert(v2.back() == 15);
    assert(v.back() == 67);

    v.resize(0);

    v2.swap(v);

    assert(v2.size() == 0);
    assert(v.size() == 3);

    std::cout << "test_swap passed" << std::endl;
}

void test_clear() {
    Vector<int> v;

    v.push_back(3);
    v.push_back(10);
    v.push_back(15);

    v.clear();
    assert(v.size() == 0);

    std::cout << "test_clear passed" << std::endl;
}

void test_reserve() {
    Vector<int> v;

    v.push_back(3);
    v.push_back(10);
    v.push_back(15);

    v.reserve(20);
    assert(v.size() == 3);
    assert(v.capacity() == 20);

    std::cout << "test_reserve passed" << std::endl;
}

void test_resize() {
    Vector<int> v;

    v.push_back(3);
    v.push_back(10);
    v.push_back(15);

    v.resize(2);
    assert(v.size() == 2);

    v.resize(20);
    assert(v.capacity() == 20);
    assert(v.size() == 20);

    std::cout << "test_resize passed" << std::endl;
}

void test_copy_constructor() {
    Vector<int> v;

    v.push_back(3);
    v.push_back(10);
    v.push_back(15);
    
    Vector<int> v2(v);

    assert(v2.size() == 3);
    assert(v2[1] == 10);
    assert(v2.front() == 3);

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    Vector<int> v;

    v.push_back(3);
    v.push_back(10);
    v.push_back(15);
    
    Vector<int> v2 = v;

    assert(v2.size() == 3);
    assert(v2[1] == 10);
    assert(v2.front() == 3);
    assert(v.size() == 3);

    std::cout << "test_assignment_operator passed" << std::endl;
}


int main() {
    std::cout << "Running Vector tests" << std::endl;
    
    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_at();
    test_empty();
    test_back();
    test_front();
    test_begin();
    test_end();
    test_insert();
    test_erase();
    test_swap();
    test_clear();
    test_reserve();
    test_resize();
    test_copy_constructor();
    test_assignment_operator();
    
    std::cout << "All tests passed" << std::endl;
    return 0;
}
