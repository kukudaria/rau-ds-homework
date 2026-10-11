#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <utility>

template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;
    
    void _resize_capacity(size_t new_capacity) {
        if (new_capacity < _size) throw std::invalid_argument("invalid capacity");
        T* new_data = new T[new_capacity];
        for (int i = 0; i<_size; i++) {
            new_data[i] = std::move(_data[i]);
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

public:
    /// 1. Конструктор по умолчанию
    Vector() : _size(0), _capacity(10), _data(new T[10]) {}
    
    /// 2. Конструктор с начальным размером
    Vector(size_t initial_size) : _size(initial_size), _capacity(initial_size), 
    _data(new T[initial_size]) {
        if (initial_size == 0) {
            _capacity = 10;
            _data = new T[10];
        }
    }
    
    /// 3. Деструктор
    ~Vector() {
        delete[] _data;
    }
    
    /// 4. Конструктор копирования
    Vector(const Vector& other) : _size(other._size), _capacity(other._capacity), 
    _data(new T[other._capacity]) {
        for (int i = 0; i<_size; i++) {
            _data[i] = other._data[i];
        }
    }
    
    /// 5. Оператор присваивания
    Vector& operator=(const Vector& other) {
        if (this == &other) return *this;
        _size = other._size;
        _capacity = other._capacity;
        delete[] _data;
        _data = new T[other._capacity];
        for (int i = 0; i<_size; i++) {
            _data[i] = other._data[i];
        }
        return *this;
    }
    
    /// 6. push_back(const T& value) - добавить в конец
    void push_back(const T& value) {
        if (_size==_capacity) _resize_capacity(_capacity*2);
        _data[_size] = value;
        _size++;
    }
    
    /// 7. pop_back() - удалить последний элемент
    void pop_back() {
        if (_size > 0) {
            _data[_size-1] = T();
            _size--;
        }
    }
    
    /// 8. operator[](size_t index) - доступ по индексу
    T& operator[](size_t index) {
        return _data[index];
    }

    const T& operator[](size_t index) const {
        return _data[index];
    }
    
    /// 9. at(size_t index) - доступ с проверкой границ
    T& at(size_t index) {
        if (index<0 || index>=_size) throw std::invalid_argument("index out of range");
        return _data[index];
    }

    const T& at(size_t index) const {
        if (index<0 || index>=_size) throw std::invalid_argument("index out of range");
        return _data[index];
    }
    
    /// 10. front() - первый элемент
    T& front() {
        if (_size==0) throw std::runtime_error("nothing to return");
        return _data[0];
    }

    const T& front() const {
        if (_size==0) throw std::runtime_error("nothing to return");
        return _data[0];
    }
    
    /// 11. back() - последний элемент
    T& back() {
        if (_size==0) throw std::runtime_error("nothing to return");
        return _data[_size-1];
    }
    const T& back() const {
        if (_size==0) throw std::runtime_error("nothing to return");
        return _data[_size-1];
    }
    
    /// 12. size() - количество элементов
    size_t size() const {
        return _size;
    }
    
    /// 13. capacity() - выделенная память
    size_t capacity() const {
        return _capacity;
    }
    
    /// 14. empty() - пуст ли вектор
    bool empty() const {
        return _size==0;
    }
    
    /// 15. reserve(size_t new_capacity) - выделить память
    void reserve(size_t new_capacity) {
        _resize_capacity(new_capacity);
    }

    void resize(size_t new_size) {
        if (new_size >= _capacity) _resize_capacity(new_size);
        _size = new_size;
    }
    
    /// 16. clear() - очистить вектор
    void clear() {
        for (int i = 0; i<_size; i++) {
            _data[i] = T();
        }
        _size = 0;
    }

    void insert(int pos, const T &val) {
        if (pos>_size || pos<0) throw std::invalid_argument("position out of range");
        if (_size==_capacity) _resize_capacity(_capacity*2);
        for (int i = _size; i>pos; i--) {
            _data[i] = _data[i-1];
        }
        _data[pos] = val;
        _size++;
    }

    void erase(int pos) {
        if (pos>=_size || pos<0) throw std::invalid_argument("position out of range");
        for (int i = pos; i<_size-1; i++) {
            _data[i] = _data[i+1];
        }
        _size--;
    }

    void swap(Vector& other) {
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);
        std::swap(_data, other._data);
    }
    
    /// 17. begin() - начало вектора
    T* begin() {
        return &front();
    }

    const T* begin() const {
        return &front();
    }
    
    /// 18. end() - конец вектора
    T* end() {
        return &back();
    }

    const T* end() const {
        return &back();
    }
};

#endif // VECTOR_H
