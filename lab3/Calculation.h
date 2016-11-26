
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
#include <iostream> 
#include <string> 
#include "functions.h"
#include "PolishRecord.h"
using namespace std;

float calculation(Queue *temp)
{
	float denominator;
	float numerator;
	float temprecord;
	char tempsymvol;
	int size = temp->getsize();
	floatStack resultStack(size);
	Stack tempStack(size);
	int sym;
	while (temp->isEmpty()!=true)
	{
		tempsymvol = temp->pop();
		sym = symvol(tempsymvol);
		if (sym == 0)
		{
			if (tempStack.isFull()!=true)
			{
				resultStack.push(transformation(tempsymvol));
			}
			else
				throw "Stack is Full";
		}
		else
		{
			int Toperator = thisoperator(tempsymvol);
			switch (Toperator)
			{
			case 0:
				temprecord = resultStack.pop() - resultStack.pop();
				resultStack.push(temprecord);
				break;
			case 1:
				temprecord = resultStack.pop() + resultStack.pop();
				resultStack.push(temprecord);
				break;
			case 2:
				denominator = resultStack.pop();
				numerator = resultStack.pop();
				temprecord = numerator / denominator;
				resultStack.push(temprecord);
				break;
			case 3:
				temprecord = resultStack.pop() * resultStack.pop();
				resultStack.push(temprecord);
				break;
			}
		}
	}
	return resultStack.pop();
}