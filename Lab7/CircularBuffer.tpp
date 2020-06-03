#include "CircularBuffer.h"
#include <exception>

template <typename T>
CircularBuffer<T>::CircularBuffer(size_t NewCapacity) 
{
    _arr = new T[NewCapacity + 1];
    _capacity = NewCapacity + 1;
    _front = 0;
    _back = 0;
    _count = 0;
}

template <typename T>
CircularBuffer<T>::~CircularBuffer()
{
    delete[] _arr;
}
 
template <typename T>
void CircularBuffer<T>::push_back(const T& value)
{
    if (_front % _capacity - _back % _capacity == 1)
    {
        _front = (_front + 1) % _capacity;
    }
    else
    {
        _count++;
    }
    _arr[_back % _capacity] = value;
    _back = (_back + 1) % _capacity;
}

template <typename T>
void CircularBuffer<T>::push_front(const T& value)
{
    if (_back % _capacity - _front % _capacity == 1 || (_back == _capacity - 1 && _front == 0))
    {
        _back = (_back + _capacity - 1) % _capacity;
    }
    else
    {
        _count++;
    }
    _front = (_front + _capacity - 1) % _capacity;
    _arr[_front % _capacity] = value;
}

template <typename T>
void CircularBuffer<T>::pop_back()
{
    if (_front % _capacity != _back % _capacity)
    {
        _back = (_back + _capacity - 1) % _capacity, _count--;
    }
    else {
        std::cerr << "Buffer is empty!";
    }
}

template <typename T>
void CircularBuffer<T>::pop_front()
{
    if (_front % _capacity != _back % _capacity)
    {
        _front = (_front + 1) % _capacity, _count--;
    }
    else {
        std::cerr << "Buffer is empty!";
    }
}

template <typename T>
typename CirIterator<T> CircularBuffer<T>::insert(const CirIterator<T>& iterator, const T& value)
{
    if (iterator == begin())
    {
        push_front(value);
        return begin();
    }
    else if (iterator == end())
    {
        push_back(value);
        return end() - 1;
    }
    else
    {
        T* buffer = new T[_capacity];
        int max_size = 0;
        int position_in_buffer = -1;
        int i = 0;
        for (auto it = begin(); it != end(), i <= _count; it++, i++)
        {
            if (it == iterator)
            {
                position_in_buffer = i;
                buffer[i] = value;
                max_size++;
                i++;
            }
            buffer[i] = *it;
            max_size++;
        }
        delete[] _arr;
        _arr = new T[_capacity];
        for (int i = 0; i <= max_size; i++)
        {
            _arr[i] = buffer[i];
        }
        _front = 0;
        _back = max_size;
        _count = max_size;
        delete[] buffer;
        return begin() + position_in_buffer;
    }
}

template <typename T>
typename CirIterator<T> CircularBuffer<T>::erase(const CirIterator<T>& iterator)
{
    if (iterator == begin())
    {
        pop_front();
        return begin();
    }
    else if (iterator == end() - 1)
    {
        pop_back();
        return end() - 1;
    }
    else
    {
        T* buffer = new T[_capacity];
        int max_size = 0;
        int position_in_buffer = -1;
        int i = 0;
        for (auto it = begin(); it != end(); it++, i++)
        {
            if (it == iterator) {
                position_in_buffer = i;
                it++;
            }
            buffer[i] = *it;
            max_size = i;
        }
        delete[] _arr;
        _arr = new T[_capacity];
        for (int i = 0; i <= max_size; i++)
        {
            _arr[i] = buffer[i];
        }
        _front = 0;
        _back = max_size + 1;
        _count = max_size + 1;
        delete[] buffer;
        return begin() + position_in_buffer;
    }
}

template <typename T>
void CircularBuffer<T>::resize(const size_t& Newcapacity)
{
    T* buffer = new T[_capacity];
    int max_size = 0;
    for (int i = 0; i < Newcapacity; i++)
    {
        if (i == _count)
        {
            break;
        }
        buffer[i] = operator[](i);
        max_size++;
    }
    delete[] _arr;
    _arr = new T[Newcapacity + 1];
    for (int i = 0; i < max_size; i++)
    {
        _arr[i] = buffer[i];
    }
    _count = max_size;
    _capacity = Newcapacity + 1;
    _front = 0;
    _back = _count;
    delete[] buffer;
}

template <typename T>
T& CircularBuffer<T>::operator[] (const size_t& i) const
{
    return _arr[(_front + i) % _capacity];
}

template <typename T>
typename CirIterator<T> CircularBuffer<T>::begin()
{
    CirIterator<T> iterator(_arr, _capacity, _front, _back, _front);
    return iterator;
}

template <typename T>
typename CirIterator<T> CircularBuffer<T>::end()
{
    CirIterator<T> iterator(_arr, _capacity, _front, _back, _back);
    return iterator;
}

template <class Type>
void print(const CircularBuffer <Type>& Buffer)
{
    for (int i = 0; i < Buffer.size(); i++)
    {
        std::cout << Buffer[i] << ' ';
    }
    std::cout << std::endl;
}