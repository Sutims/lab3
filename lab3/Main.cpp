
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
#include <iostream> 
#include <string> 
#include "functions.h"
#include "PolishRecord.h"
#include "Calculation.h"
using namespace std;

int main()
{
/*	 std::string str; 
    std::cout << "Inter a string " << std::endl; 
    getline(std::cin,str); 
    std::cout << str << std::endl; */
	float result;
	Queue *polish;
	char *str= new char[];
	cin >> str;
	polish = PolishRecord(str);
	result = calculation(polish);
	cout<<result;
	return 0;
};

