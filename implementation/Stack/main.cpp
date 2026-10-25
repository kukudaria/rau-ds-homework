#include "Stack.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Stack<T>:
//   1. Stack()                         - конструктор
//   2. ~Stack()                        - деструктор
//   3. Stack(const &)                  - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push(const T&)                  - добавить
//   6. pop()                           - удалить
//   7. top()                           - вершина
//   8. size()                          - размер
//   9. capacity()                      - вместимость
//  10. is_empty()                      - пусто ли
//  11. clear()                         - очистить
//  12. peek()                          - просмотреть вершину
//  13. ...
//  14. ...

void test_push() {
    Stack<int> s;
    
    s.push(5);
    assert(s.size() == 1);
    assert(s.top() == 5);
    
    s.push(10);
    s.push(15);
    assert(s.size() == 3);
    assert(s.top() == 15);
    
    std::cout << "test_push passed" << std::endl;
}

void test_pop() {
    Stack<int> s;

    s.push(3);
    s.push(5);
    s.pop();
    assert(s.size() == 1);
    assert(s.top() == 3);

    s.push(10);
    s.push(15);
    s.pop();
    s.pop();
    assert(s.size() == 1);
    assert(s.top() == 3);

    std::cout << "test_pop passed" << std::endl;
}

void test_is_empty() {
    Stack<int> s;

    assert(s.is_empty());

    s.push(8);
    assert(!s.is_empty());

    s.pop();
    assert(s.is_empty());

    std::cout << "test_is_empty passed" << std::endl;
}

void test_top() {
    Stack<int> s;

    s.push(3);
    assert(s.top() == 3);

    s.push(10);
    s.push(15);
    assert(s.top() == 15);

    std::cout << "test_top passed" << std::endl;
}

void test_peek() {
    Stack<int> s;

    s.push(3);
    assert(s.peek() == 3);

    s.push(10);
    s.push(15);
    assert(s.peek() == 15);

    std::cout << "test_peek passed" << std::endl;
}

void test_clear() {
    Stack<int> s;

    s.push(3);
    s.push(10);
    s.push(15);

    s.clear();
    assert(s.size() == 0);

    std::cout << "test_clear passed" << std::endl;
}

void test_copy_constructor() {
    Stack<int> s;

    s.push(3);
    s.push(10);
    s.push(15);
    
    Stack<int> s2(s);

    assert(s2.size() == 3);
    assert(s2.top() == 15);

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    Stack<int> s;

    s.push(3);
    s.push(10);
    s.push(15);
    
    Stack<int> s2 = s;

    assert(s2.size() == 3);
    assert(s2.top() == 15);
    assert(s.size() == 3);

    std::cout << "test_assignment_operator passed" << std::endl;
}

int main() {
    std::cout << "Running Stack tests" << std::endl;
    test_push();
    test_pop();
    test_is_empty();
    test_top();
    test_peek();
    test_clear();
    test_copy_constructor();
    test_assignment_operator();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
