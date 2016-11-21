
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
#include <iostream> 
#include <string> 
#include "functions.h"
#include "Polish.h"
using namespace std;

int main()
{
/*	 std::string str; 
    std::cout << "Inter a string " << std::endl; 
    getline(std::cin,str); 
    std::cout << str << std::endl; */
	Queue *p;
	char *str= new char[];
	cin >> str;
	p = Polishz(str);
	return 0;
};

