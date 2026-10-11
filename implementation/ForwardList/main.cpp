#include "ForwardList.h"
#include <cassert>
#include <iostream>

// Реализуйте методы ForwardList<T>:
//   1. ForwardList()                   - конструктор
//   2. ~ForwardList()                  - деструктор
//   3. ForwardList(const &)            - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push_front(const T&)            - добавить в начало
//   6. pop_front()                     - удалить с начала
//   7. front()                         - первый элемент
//   8. insert_after(Node*, const T&)   - вставить после узла
//   9. erase_after(Node*)              - удалить после узла
//  10. clear()                         - очистить
//  11. reverse()                       - развернуть
//  12. size()                          - размер
//  13. empty()                         - пусто ли
//  14. begin()                         - начало списка

void test_push_front() {
    ForwardList<int> list;
    
    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);
    
    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);
    
    std::cout << "test_push_front passed" << std::endl;
}

void test_pop_front() {
    ForwardList<int> list;
    
    list.push_front(4);
    list.push_front(1);
    list.pop_front();
    assert(list.size() == 1);
    assert(list.front() == 4);
    
    list.push_front(2);
    list.push_front(3);
    list.push_front(9);
    list.pop_front();
    list.pop_front();
    assert(list.size() == 2);
    assert(list.front() == 2);

    list.pop_front();
    list.pop_front();
    assert(list.size() == 0);
    
    std::cout << "test_pop_front passed" << std::endl;
}

void test_front() {
    ForwardList<int> list;
    
    list.push_front(1);
    assert(list.front() == 1);
    
    list.push_front(2);
    list.push_front(3);
    assert(list.front() == 3);

    list.pop_front();
    assert(list.front() == 2);
    
    std::cout << "test_front passed" << std::endl;
}

void test_insert_after() {
    ForwardList<int> list;
    
    list.push_front(6);
    list.insert_after(list.begin(), 5);
    list.pop_front();
    assert(list.size() == 1);
    assert(list.front() == 5);
    
    list.insert_after(list.begin(), 2);
    list.insert_after(list.begin(), 7);
    list.pop_front();
    assert(list.size() == 2);
    assert(list.front() == 7);
    
    std::cout << "test_insert_after passed" << std::endl;
}

void test_erase_after() {
    ForwardList<int> list;
    
    list.push_front(1);
    list.push_front(6);
    list.erase_after(list.begin());
    assert(list.size() == 1);
    assert(list.front() == 6);
    
    list.pop_front();
    list.push_front(2);
    list.push_front(3);
    list.erase_after(list.begin());
    assert(list.size() == 1);
    assert(list.front() == 3);
    
    std::cout << "test_erase_after passed" << std::endl;
}

void test_clear() {
    ForwardList<int> list;
    
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);

    list.clear();
    assert(list.size() == 0);

    std::cout << "test_clear passed" << std::endl;
}

void test_reverse() {
    ForwardList<int> list;
    
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    assert(list.front() == 3);
    
    list.reverse();

    assert(list.front() = 1);
    list.pop_front();
    assert(list.front() = 2);
    list.pop_front();
    assert(list.front() = 3);
    list.pop_front();
    
    std::cout << "test_reverse passed" << std::endl;
}

void test_empty() {
    ForwardList<int> list;

    assert(list.empty());
    
    list.push_front(1);
    assert(!list.empty());

    list.push_front(2);
    list.push_front(3);
    assert(!list.empty());

    std::cout << "test_empty passed" << std::endl;
}

void test_copy_constructor() {
    ForwardList<int> list;
    
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    assert(list.size() == 3);
    assert(list.front() == 3);
    
    ForwardList<int> list2(list);

    assert(list.size() == 3);
    assert(list2.front() = 3);
    list.pop_front();
    assert(list.front() = 2);
    list.pop_front();
    assert(list.front() = 1);
    list.pop_front();
    
    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    ForwardList<int> list;
    
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    assert(list.size() == 3);
    assert(list.front() == 3);
    
    ForwardList<int> list2;

    list2.push_front(10);
    list2.push_front(6);

    list2 = list;

    assert(list.size() == 3);
    assert(list2.front() = 3);
    list.pop_front();
    assert(list.front() = 2);
    list.pop_front();
    assert(list.front() = 1);
    list.pop_front();
    
    std::cout << "test_assignment_operator passed" << std::endl;
}

int main() {
    std::cout << "Running ForwardList tests" << std::endl;

    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_empty();
    test_copy_constructor();
    test_assignment_operator();

    std::cout << "All tests passed" << std::endl;
    return 0;
}
