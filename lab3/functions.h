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
	if((s == '+')||(s == '-'))
		return 1;
	else
		return 0;
}

int thisoperator(string temp)
{
	if (temp == "*")
		return 3;
	if (temp == "/")
		return 2;
	if (temp == "+")
		return 1;
	else 
		return 0;
}

float transformation(string t1)
{
	char *temp;
	temp =  new char[t1.length()];
	float result;
	for (int i = 0; i< t1.length();i++)
	{
		temp[i] = t1[i];
	}
	int t2;
	t2 = atoi(temp);
	result = static_cast<float>(t2);
	return result;
}


int symvolreserv(string s)
{
	if((s == "*")||(s == "-")||(s == "/")||(s == "+"))
		return 1;
	else
		return 0;
}

bool right(string s)
{
	int f = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '(')
			f++;
		if (s[i] == ')')
			f--;
		i++;
	}
	return f == 0;
}
// if((s == "0")||(s == "1")||(s == "2")||(s == "3")||(s == "4")||(s == "5")||(s == "6")||(s == "7")||(s == "")||(s == '9'))
	 // if((s == '0')||(s == '1')||(s == '2')||(s == '3')||(s == '4')||(s == '5')||(s == '6')||(s == '7')||(s == '8')||(s == '9'))