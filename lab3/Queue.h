#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string> 
#include <iostream> 
using namespace std;



class Queue
{
	char *p;
	int n;
	int si,ei;
		public:
	Queue(int n)
	{
		p = new char [n];
		this->n = n;
		ei = 1;
		si = 0;
	}

	bool isEmpty()
	{
		return (ei+1)%n == si;
	}

	bool isFull()
	{
		return (ei)%n == si;
	}

	void push(int m)
	{
		if (isFull())
			throw "exception";
		ei = (ei + 1)% n;
		p[ei] = m;
	}

	int pop()
	{
		if (isEmpty())
			throw "Queue is Empty";
		int temp = p[si];
		si = (si + 1)% n;
		return temp;
	}
	void show()
	{
		for (int i = 0; i < n; i++)
		printf("%c",p[i]);
	}

/*	friend ostream &operator <<(ostream &v, Queue &ob)
	{
		for( int i = si; i != (ei+1)%n; i = (i+1)%n)
		{
			v<<ob.p[i];
		}
		return v;
	}
	*/

};
