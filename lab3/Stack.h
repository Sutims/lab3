#pragma once
#include <stdio.h>
#include <stdlib.h>

class Stack
{
	char *mem;
	int size;
	int ind;
	bool isArend;
public:
	Stack(int n)
	{
		size = n;
		isArend = false;
		mem = new char [n];
		ind = -1;
	}

	~Stack()
	{
		if (!isArend)
			delete [] mem;
	}

	bool isEmpty()
	{
		return ind <= -1;
	}

	bool isFull()
	{
		return ind >= size - 1;
	}

	void push (char val)
	{
		if (isFull())
			throw "stack if Full";
		ind++;
		mem[ind] = val;
	}

	int pop()
	{
		if (isEmpty())
			throw "stack is Empty";
		ind--;
		return mem[ind + 1];
	}

	void *getmem()
	{
		return mem;
	}

	int getCount()
	{
		return ind++;
	}
};

class floatStack
{
	float *mem;
	int size;
	int ind;
	bool isArend;
public:
	floatStack(int n)
	{
		size = n;
		isArend = false;
		mem = new float [n];
		ind = -1;
	}

	~floatStack()
	{
		if (!isArend)
			delete [] mem;
	}

	bool isEmpty()
	{
		return ind <= -1;
	}

	bool isFull()
	{
		return ind >= size - 1;
	}

	void push (float val)
	{
		if (isFull())
			throw "stack if Full";
		ind++;
		mem[ind] = val;
	}

	int pop()
	{
		if (isEmpty())
			throw "stack is Empty";
		ind--;
		return mem[ind + 1];
	}

	void *getmem()
	{
		return mem;
	}

	int getCount()
	{
		return ind++;
	}
};