
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
#include <iostream> 
#include <string> 
#include "functions.h"
#include "calcul.h"
using namespace std;

int main()
{
/*	 std::string str; 
    std::cout << "Inter a string " << std::endl; 
    getline(std::cin,str); 
 
    std::cout << str << std::endl; */
	char *str= new char[];
	cin >> str;
	ring(str);
	cin>>str;
};

