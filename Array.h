#pragma once

#include<iostream>
using namespace std;

template<class T>
class Array
{
private:
	size_t _size;
	Array(const Array&);
	Array& operator=(const Array&);
protected:
	T* _allocator;

public:
	explicit Array(size_t size)
		:_size(size), _allocator(new T[_size])
	{
		//if (_allocator == 0)
		//{

		//}
		for (int i = 0; i < _size; i++)
		{
			operator[](i) = 0;
		}
	}

	~Array()
	{
		delete[] _allocator;
		_allocator = 0;
	}

	T& operator[](const size_t i)
	{
		return _allocator[i];
	}

	size_t size() const
	{
		return _size;
	}

	const T & operator[](const size_t index) const
	{
		return _allocator[index];
	}

};

template<class T>
ostream& operator<<(ostream& os, const Array<T>& arr)
{
	for (size_t i = 0; i <= arr.length() - 1; i++) {
		os << arr[i] << ", ";
	}
	//os << arr[arr.length() - 1];
	return os;
}