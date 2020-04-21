#pragma once
#include <iterator>

template <typename T, typename object>
bool all_of(const T begin, const T end, bool(&function)(object))
{
    for (auto it = begin; it != end; it++)
    {
        if (function(*it))
            return true;
    }
    return false;
}


template <typename T, typename object>
bool is_sorted(T obj, bool (*function)(object, object))
{
    typename T::const_iterator it = obj.begin();
    typename T::const_iterator it_next = it + 1;
    if (it == obj.end() or it_next == obj.end())
    {
        return true;
    }
    while (it_next != obj.end())
    {
        if (!function(*it, *it_next))
            return false;
        ++it;
        ++it_next;
    }
    return true;
}


template <typename T, typename object >
bool is_palindrome(T obj, bool (*function)(object, object))
{
    typename T::const_iterator it = obj.begin();
    typename T::const_iterator it_end = obj.end() - 1;
    while (it < it_end)
    {
        if (!function(*it, *it_end))
        {
            return false;
        }
        ++it;
        --it_end;
    }
    return true;
}