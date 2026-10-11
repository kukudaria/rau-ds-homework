#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <stdexcept>
template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d=T(), Node* n=nullptr) : data(d), next(n) {}
    };
    
    Node* _head;
    int _size;

public:
    /// 1. Конструктор по умолчанию
    ForwardList() : _head(new Node()), _size(0) {}
    
    /// 2. Деструктор
    ~ForwardList() {
        clear();
        delete _head;
    }
    
    /// 3. Конструктор копирования
    ForwardList(const ForwardList& other) {
        _head = new Node();
        Node* tmp1 = _head;
        Node* tmp2 = other._head;
        while (tmp2->next != nullptr) {
            tmp1->next = new Node(tmp2->next->data);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        _size = other._size;
    }
    
    /// 4. Оператор присваивания
    ForwardList& operator=(const ForwardList& other) {
        if (this==&other) return *this;
        _head = new Node();
        Node* tmp1 = _head;
        Node* tmp2 = other._head;
        while (tmp2->next != nullptr) {
            tmp1->next = new Node(tmp2->next->data);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        _size = other._size;
        return *this;
    }
    
    /// 5. push_front(const T& x) - добавить в начало
    void push_front(const T& x) {
        insert_after(_head, x);
    }
    
    /// 6. pop_front() - удалить с начала
    void pop_front() {
        erase_after(_head);
    }
    
    /// 7. front() - первый элемент
    T& front() {
        if (_head->next==nullptr) throw std::logic_error("list is empty");
        return _head->next->data;
    }

    const T& front() const {
        if (_head->next==nullptr) throw std::logic_error("list is empty");
        return _head->next->data;
    }
    
    /// 8. insert_after(Node* node, const T& value) - вставить после узла
    void insert_after(Node* node, const T& value) {
        if (node == nullptr) throw std::invalid_argument("node cannot be nullptr");
        Node* new_node = new Node(value, node->next);
        node->next = new_node;
        _size++;
    }
    
    /// 9. erase_after(Node* node) - удалить после узла
    void erase_after(Node* node) {
        if (node==nullptr || node->next==nullptr) throw std::invalid_argument("invalid node");
        Node* tmp = node->next->next;
        delete node->next;
        node->next = tmp;
        _size--;
    }
    
    /// 10. clear() - очистить
    void clear() {
        while (_size != 0) {
            pop_front();
        }
    }
    
    /// 11. reverse() - развернуть
    void reverse() {
        ForwardList tmp;
        while(_size) {
            tmp.push_front(front());
            pop_front();
        }
        _size = tmp._size;
        delete _head;
        _head = tmp._head;
        tmp._size = 0;
        tmp._head = nullptr;
    }
    
    /// 12. size() - количество элементов
    int size() const {
        return _size;
    }
    
    /// 13. empty() - пуст ли
    bool empty() const {
        return _size==0;
    }
    
    /// 14. begin() - начало списка
    Node* begin() {
        if (_head->next==nullptr) throw std::logic_error("list is empty");
        return _head->next;
    }

    Node* begin() const {
        if (_head->next==nullptr) throw std::logic_error("list is empty");
        return _head->next;
    }
};

#endif // FORWARDLIST_H
