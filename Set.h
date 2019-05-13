#pragma once
#include "Multiset.h"
#include "Sequence.h"
#include "Iterator.h"

template <class T>
class Set :public Multiset<T>
{

public:

	void add(const T& elem) override
	{
		if(!this->find(elem))
		Multiset<T>::add(elem);	
	}
};
