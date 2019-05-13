#include<iostream>
using namespace std;
#include <cassert>

#include "Multiset.h"
#include "Set.h"
#include "Iterator.h"

int main(void)
{
	cout << "Multiset" << endl;
	Multiset<int> a;
	a.add(10);
	a.add(2);
	a.add(2);
	cout << a;
	cout <<"Multiset size: "<< a.size() << endl;
	cout <<"Count element:(line18) "<< a.countEl(2) << endl;

	cout << endl;
	
	////

	cout << "Set" << endl;
	Set<double> b;
	b.add(2.2);
	b.add(2.2);
	b.add(10);
	b.add(3.333333);
	cout << b;
	cout << "Set size: " << b.size() << endl;
	cout << "Count element:(line32) " << b.countEl(100) << endl;
	cout << "Count element:(line33) " << b.countEl(3.333333) << endl;
	cout << "Find(line34): " << b.find(10) << endl;

	cout << endl;

	//Exercise 7
	cout << "Ex7" << endl;
	Set<char> c;
	int k = 1;
	for (char i = 'a'; i <= 'z'; ++i) {
		for(int j =0;j<k;j++)
		c.add(i);

		
		k++;
	}
	//Exercise 8
	for (char i = 'a'; i <= 'z'; i++)
	{
		assert(1 == c.countEl(i));
	}
	cout << c << endl;

	//Exercise 9
	cout << "Ex9" << endl;
	Multiset<char> d;
	k = 1;
	for (char i = 'a'; i <= 'z'; ++i) 
	{
		for (int j = 0; j < k; j++)
			d.add(i);

		k++;
	}

	//Exercise 10
	int  g = 0;
	for (char i = 'a'; i <= 'z'; i++)
	{
		assert(g + 1 == d.countEl(i));
		g++;
	}

	cout << d << endl;
	return 0;
}