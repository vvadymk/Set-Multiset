#pragma once
#include<iostream>
using namespace std;

#include "Array.h"

template<class T>
class Sequence
{
private:
	size_t _size;
	static const size_t _default;

	Array<T>* _allocator;

	Sequence& doinsert(const T & elem, size_t index)
	{
		resize();
		for (size_t i = _size; i > index; --i) {
			(*_allocator)[i] = (*_allocator)[i - 1];
		}
		(*_allocator)[_size++] = elem;
		return *this;
	}

	Sequence& doremove(size_t index)
	{
		resize();
		for (int i = index; i < _size - 1; i++) {
			(*_allocator)[i] = (*_allocator)[i + 1];
		}
		_size--;
		return *this;
	}

	Sequence(const Sequence &);

	Sequence& operator=(const Sequence &);

	void enlarge(const size_t times = 2)
	{
		Array* newArray = new Array(times*_default + capacity() + 1);
		for (int i = 0; i < _size; i++)
		{
			(*newArray)[i] = (*_allocator)[i];
		}
		delete _allocator;
		_allocator = newArray;

	}
public:
	class BadSeq;

	explicit Sequence(const size_t capacity = _default)
		:_size(0), _allocator(new Array<T>(capacity))
	{}

	~Sequence()
	{
		delete _allocator;
	}

	size_t capacity() const
	{
		return _allocator->size();
	}

	size_t sizes() const
	{
		return _size;
	}

	bool empty() const
	{
		return _size == 0;
	}

	bool full() const
	{
		_size == _allocator->size();
	}

	Sequence& clear()
	{
		_size = 0;
		return *this;
	}

	const T& operator[](const size_t index) const
	{
		if (_size > index)
			return _allocator[index];
		else
			throw Sequence<T>::BadSeq();
	}

	T& operator[](const  size_t index)
	{
		if (index < _size) {
			return (*_allocator)[index];
		}
		
	}

	Sequence& add(const T& elem)
	{
		return doinsert(elem, _size);
	}

	Sequence& insert(const T& elem, const  size_t index)
	{
		if (index < _size) {
			return doinsert(elem, index);
		}
		else {
			throw Sequence<T>::BadSeq();
		}
	}

	Sequence& cut()
	{
		return doremove(_size);
	}

	Sequence& remove(int index)
	{
		if (index < _size) {
			doremove(index);
		}
		else {
			throw Sequence<T>::BadSeq();
		}

		return *this;
	}

	bool contains(const T& elem)
	{
		for (int i = 0; i < _size; i++)
			if (elem == (*_allocator)[i])
				return true;

		return false;
	}

	void resize()
	{
		if (_size + 1 >= _allocator->size()) {
			Array<T> * new_alloc = new Array<T>(_size * 2 + 1);
			for (int i = 0; i < _allocator->size(); i++) {
				(*new_alloc)[i] = (*_allocator)[i];
			}
			delete _allocator;
			_allocator = new_alloc;
		}
		else if (_size <= _allocator->size() / 4) {
			Array<T> * new_alloc = new Array<T>(_size / 2 + 1);
			for (int i = 0; i < new_alloc->size(); i++) {
				(*new_alloc)[i] = (*_allocator)[i];
			}
			delete _allocator;
			_allocator = new_alloc;
		}
	}
};

template<class T>
ostream & operator<<(ostream & out, Sequence<T> & s)
{

	for (size_t i = 0; i < s.sizes(); i++) {
		out << s[i] << ",";
	}
	return out;
}

template<class T>
class Sequence<T>::BadSeq
{
private:
	char * _message;
public:


	~BadSeq()
	{
	}

	void printStackTrace() const
	{
		cout << "BadSeq" << endl;
	}
};