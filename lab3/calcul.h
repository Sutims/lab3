#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
#include <iostream> 
#include <string> 
#include <conio.h>
#include "functions.h"
using namespace std;



void ring(char *str)
{
	int pr;
	int n = StringSize(str);
	Queue temp(n+2);
	Stack tempStack(n);
	char p;
	int sym;
	for (int i = 0;i < n; i++)
	{
		sym = symvol(str[i]);
		if (sym == 0)
			temp.push(str[i]);
		else
		{
			pr = prioritet(str[i]);
			switch (pr)
			{
			case 1:
					if (tempStack.isEmpty())
						tempStack.push(str[i]);
					else
					{
						temp.push(tempStack.pop());
						tempStack.push(str[i]);
					}
					break;

			case 2:
					if (tempStack.isEmpty())
						tempStack.push(str[i]);
					else
					{
						int p = tempStack.pop();
						if (prioritet(p) == 2)
						{
							temp.push(p);
							tempStack.push(str[i]);
						}
						else
						{
						tempStack.push(p);
						tempStack.push(str[i]);
						}
					}
					break;
			}
		}
	}
	while (tempStack.isEmpty()!=true)
	{
		temp.push(tempStack.pop());
	}
temp.show();
}