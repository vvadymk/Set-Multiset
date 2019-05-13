#pragma once

//Task 1
template <class T>
class ASet
{
public:
	virtual ~ASet() {}
	virtual void add(const T& elem) = 0;
	virtual size_t size() const = 0;
	virtual T& operator[](const size_t index) = 0;
	//virtual T& operator[](const size_t index) = 0;
};