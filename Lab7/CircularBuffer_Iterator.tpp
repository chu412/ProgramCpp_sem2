#include "CircularBuffer_Iterator.h"

template <typename T>
CirIterator<T>::CirIterator(T* buffer, size_t& _capacity, int& _front, int& _back, int _position):
data (buffer), capacity ( _capacity), front (_front), back (_back), position (_position) {}

template <typename T>
typename CirIterator<T> CirIterator<T>:: operator+ (const int& _pos) const
    {
        CirIterator iter = *this;
        iter.position = (position + _pos) % capacity;
        return iter;
    }

template <typename T>
typename CirIterator<T> CirIterator<T>::operator- (const int& _pos) const
    {
        CirIterator iter = *this;
        iter.position = (position + capacity - _pos) % capacity;
        return iter;
    }

template <typename T>
typename CirIterator<T> CirIterator<T>::operator++ ()
    {
        this->position++;
        return *this;
    }

template <typename T>
typename CirIterator<T> CirIterator<T>::operator++ (int)
    {
        CirIterator t(*this);
        operator++ ();
        return t;
    }

template <typename T>
typename CirIterator<T> CirIterator<T>::operator-- ()
    {
        this->position--;
        return *this;
    }

template <typename T>
typename CirIterator<T> CirIterator<T>::operator-- (int)
    {
        CirIterator t(*this);
        operator-- ();
        return t;
    }

template <typename T>
bool CirIterator<T>::operator!= (CirIterator const& _other_iterator) const
    {
        return this->position % capacity != _other_iterator.position % capacity;
    }

template <typename T>
bool CirIterator<T>::operator== (CirIterator const& _other_iterator) const
    {
        return this->position % capacity == _other_iterator.position % capacity;
    }

template <typename T>
bool CirIterator<T>::operator> (const CirIterator& ob) const
    {
        if (front > back)
        {
            if (position < capacity && ob.position < capacity)
            {
                return position > ob.position;
            }
            else if (position < capacity) 
            {
                return false;
            }
            else if (ob.position < capacity) 
            {
                return true;
            }
            else {
                return position > ob.position;
            }
        }
        else {
            return position > ob.position;
        }
    }

template <typename T>
bool CirIterator<T>::operator< (const CirIterator& ob) const
    {
        if (front > back) {
            if (position < capacity && ob.position < capacity)
            {
                return position < ob.position;

            }
            else if (position < capacity)
            {
                return true;
            }
            else if (ob.position < capacity)
            {
                return false;
            }
            else
            {
                return position < ob.position;
            }
        }
        else
        {
            return position < ob.position;
        }
    }

template <typename T>
bool CirIterator<T>::operator>= (const CirIterator& ob) const
    {
        if (front > back)
        {
            if (position < capacity && ob.position < capacity)
            {
                return position >= ob.position;
            }
            else if (position < capacity)
            {
                return false;
            }
            else if (ob.position < capacity)
            {
                return true;
            }
            else {
                return position >= ob.position;
            }
        }
        else
            return position >= ob.position;
    }

template <typename T>
bool CirIterator<T>::operator<= (const CirIterator& ob) const
    {
        if (front > back)
        {
            if (position < capacity && ob.position < capacity)
            {
                return position <= ob.position;
            }
            else if (position < capacity) 
            {
                return true;
            }
            else if (ob.position < capacity) 
            {
                return false;
            }
            else 
            {
                return position <= ob.position;
            }
        }
        else 
        {
            return position <= ob.position;
        }
    }


