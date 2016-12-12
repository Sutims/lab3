
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
	 std::string str; 
    std::cout << "Inter a string " << std::endl; 
    getline(std::cin,str); 
  //  std::cout << str << std::endl; 
	float result;
	Queue *polish;
/*	floatStack test(10);
	char *str= new char[];
	cin >> str; 
	Stack tempsts(2);
	tempsts.pop(); */


	try{
		polish = PolishRecord(str);
		result = calculation(polish);
	cout<<"\n";
	cout<<result;
	cout<<"\n";
	}
	catch (...)
	{
		cout << "error";
	}
	
	return 0; 
};

