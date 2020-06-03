#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

template <typename T>
class CirIterator : public std::iterator<std::random_access_iterator_tag, T>
{
private:
    T* data;
    int position;
    int front;
    int back;
    size_t capacity;
public:
    using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
   
    typename CirIterator::reference operator* () const
    {
        return data[position % capacity];
    }
    
    CirIterator(T* buffer, size_t& _capacity, int& _front, int& _back, int _position);
    bool operator!= (CirIterator const& _other_iterator) const;
    bool operator== (CirIterator const& _other_iterator) const;
    bool operator> (const CirIterator& ob) const;
    bool operator< (const CirIterator& ob) const;
    bool operator>= (const CirIterator& ob) const;
    bool operator<= (const CirIterator& ob) const; 
    CirIterator operator+ (const int& _pos) const;
    CirIterator operator- (const int& _pos) const;
    CirIterator operator++ ();
    CirIterator operator++ (int);
    CirIterator operator-- ();
    CirIterator operator-- (int);
    difference_type operator- (const CirIterator& i) const
    {
        CirIterator iter = *this;
        iter.position -= i.position;
        return *iter;
    }
    difference_type operator+ (const CirIterator& i) const
    {
        CirIterator iter = *this;
        iter.position += i.position;
        return *iter;
    }
   
};

#include "CircularBuffer_Iterator.tpp"