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



Queue* PolishRecord(string str)
{
	std::string tempstr; 
	string tempbracket;
	int pr;
	int n = str.length();
	Queue * temp = new Queue(n+2);
	Stack tempStack(n);
	char peremen1;
	std::string peremen2;
	int sym;
	for (int i = 0;i < n; i++)
	{
		sym = symvol(str[i]);
		if (sym == 0)
		{
			tempstr = str[i];
			while ((str[i+1] == '0')||(str[i+1] == '1')||(str[i+1] == '2')||(str[i+1] == '3')||(str[i+1] == '4')||(str[i+1] == '5')||(str[i+1] == '6')||(str[i+1] == '7')||(str[i+1] == '8')||(str[i+1] == '9'))
			{
				tempstr += str[i+1];
				i++;
			}
			temp->push(tempstr);
			
		}
		else
		{
			pr = prioritet(str[i]);
			switch (pr)
			{
			case 0:
				if (str[i] == '(')
				{
					tempStack.push(str[i]);
				}
				else 
				{
					tempbracket = tempStack.pop();
					while (tempbracket != "(" )
					{
						temp->push(tempbracket);
						tempbracket = tempStack.pop();
					}
				}
				break;
			case 1:
					if (tempStack.isEmpty())
						tempStack.push(str[i]);
					else
					{
						peremen1 = tempStack.pop();
						if (peremen1 == '(')
						{
							tempStack.push(peremen1);
							tempStack.push(str[i]);
						}
						else
						{
							while (prioritet(peremen1) >= 1)
							{
								peremen2 = "";
								peremen2 += peremen1;

								temp->push(peremen2);
								peremen2 = "";
								if (tempStack.isEmpty())
								{
									break;
								}
								peremen1 = tempStack.pop();
							}
							tempStack.push(str[i]);
						}
					}
					break;

			case 2:
					if (tempStack.isEmpty())
						tempStack.push(str[i]);
					else
					{
						peremen1 = tempStack.pop();
						if (prioritet(peremen1) == 2)
						{
							peremen2[0] = peremen1;
							temp->push(peremen2);
							tempStack.push(str[i]);
							peremen2 = "";
						}
						else
						{
						tempStack.push(peremen1);
						tempStack.push(str[i]);
						}
					}
					break;
			}
		}
	}
	while (tempStack.isEmpty()!=true)
	{
		peremen2 += tempStack.pop();
	//	cout<<peremen2;
		std::cout << peremen2 << std::endl; 
		temp->push(peremen2);
		peremen2 ="";
	}
temp->show();
return temp;
}