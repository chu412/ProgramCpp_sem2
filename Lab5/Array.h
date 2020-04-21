#pragma once
#include "Exception.h"
#include <iostream>

using namespace std;

template <class TArray>
class Array
{
private:
	TArray* data;
	int size;
public:
	Array()
	{
		size = 0;
		data = nullptr;
	}
	explicit Array(int _size)
	{
		size = _size;
		data = new TArray[size];
	}
	void inArray()
	{
		for (int i = 0; i < size; i++)
		{
			cin >> data[i];
		}
	}
	
	TArray& operator[](int index)
	{
		if (index > 0 && index < size)
		{
             return data[index];
		}
		else
		{
			throw myException("Index out of range!", -1);
		}
		
	}
	
};