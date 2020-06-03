#pragma once
#include "CircularBuffer_Iterator.h"

template <typename T>
class CircularBuffer
{
public:
    explicit CircularBuffer(size_t Newcapacity);
    ~CircularBuffer();
    CirIterator<T> begin();
    CirIterator<T> end();
    CirIterator<T> insert(const CirIterator<T>& iterator, const T& value);
    CirIterator<T> erase(const CirIterator<T>& iterator);
    void push_back(const T& value);  
    void push_front(const T& value); 
    void pop_back();
    void pop_front();
    void resize(const size_t& Newcapacity);
    T& operator[] (const size_t& i) const;
    size_t size() const
    {
        return _count;
    }
private:
    size_t _capacity;
    size_t _count;
    int _front;
    int _back;
    T* _arr;
};

#include "CircularBuffer.tpp"