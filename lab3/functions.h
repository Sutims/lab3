#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
#include <iostream> 
#include <string> 
#include <conio.h>
using namespace std;

int StringSize(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
			i++;
	}
	return i; 
}

int symvol(char s)
{
	if((s == '0')||(s == '1')||(s == '2')||(s == '3')||(s == '4')||(s == '5')||(s == '6')||(s == '7')||(s == '8')||(s == '9'))
		return 0;
	else
		return 1;
}

int prioritet(char s)
{
	if((s == '*')||(s == '/'))
		return 2;
	else 
		return 1;
}

int thisoperator(char temp)
{
	if (temp == '*')
		return 3;
	if (temp == '/')
		return 2;
	if (temp == '+')
		return 1;
	else 
		return 0;
}

float transformation(char t1)
{
	float result;
	int t2;
	t2 = static_cast<int>(t1) - 48;
	result = static_cast<float>(t2);
	return result;
}

