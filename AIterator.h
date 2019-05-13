#pragma once
template <class T>
class AIterator
{
public:
	
	virtual void start() = 0;
	virtual const AIterator& operator++() const = 0;
	virtual bool stop() const = 0;
	virtual const T& operator*() const = 0;
	virtual T& operator*() = 0;
	virtual ~AIterator() {};
};