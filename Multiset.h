#pragma once
#include "ASet.h"
#include "Sequence.h"
#include "Iterator.h"

template <class T>
class Multiset:public ASet<T>
{
protected:
	Sequence<T>* _seq;

public:
	explicit Multiset();
	~Multiset();
	bool empty();
	void add(const T& elem);
	T& operator[](const size_t index);
	size_t size() const;
	size_t size();
	bool find(const T& a);
	int countEl(const T& a);
};

template<class T>
Multiset<T>::Multiset() :
	_seq(new Sequence<T>(1))
{
}

template<class T>
Multiset<T>::~Multiset() 
{
	delete _seq;
}

template <class T>
T& Multiset<T>::operator[](const size_t index)
{
	return (*_seq)[index];
}

template <class T>
size_t Multiset<T>::size() const
{
	return _seq->sizes();
}

template <class T>
size_t Multiset<T>::size()
{
	return _seq->sizes();
}

template <class T>
bool Multiset<T>::empty()
{
	return _seq->sizes() == 0;
}

template <class T>
void Multiset<T>::add(const T& elem)
{
	_seq->add(elem);
}

template <class T>
bool Multiset<T>::find(const T& a)
{
	Iterator<T, Multiset<T>> itor(*this);
	while (!itor.stop())
	{
		if (*itor == a)
			return true;
		++itor;
	}

	return false;
}

template <class T> 
int Multiset<T>::countEl(const T& a)
{
	int k = 0;
	Iterator<T, Multiset<T>> itor(*this);
	while (!itor.stop())
	{
		if (*itor == a)
		{
			k++;
			
		}
		++itor;
	}
	return k;
}

template <class T>
ostream& operator<<(ostream& os, Multiset<T>& a)
{
	Iterator<T, Multiset<T>> itor(a);
	while (!itor.stop())
	{
		os << *itor << ' ';
		++itor;
	}
	return os << endl;
}