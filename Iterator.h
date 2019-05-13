#pragma once
#include "AIterator.h"
template <class T, class Container>
class Iterator : public AIterator<T>
{
private:
	Container& _container;
	T* _start;
	mutable T* _end;
	mutable T* _current;

public:
	Iterator(Container& container)
		:_container(container), _start(&_container[0]),_end(_start+_container.size()), _current(_start)
	{}
	
	Iterator(const Iterator& it)
		: _container(it._container), _start(it._start),
		_end(it._end), _current(it._current) {}
	
	~Iterator() {};
	
	void start()
	{
		_current = &_container[0];
		_end = _start + _container.size();
	}
	
	const Iterator& operator++() const 
	{
		++_current;
		return*this;
	}
	
	bool stop() const 
	{
		return _current == _end;
	}
	
	const T& operator*()const 
	{
		return *_current;
	}
	T& operator*() 
	{
		return *_current;
	}


};
