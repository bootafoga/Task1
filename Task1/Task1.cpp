#include "pch.h"
#include <iostream>
#include "List.h"
using namespace std;


int main()
{
	List<int> lst;
	
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	
	cout << lst; 

	return 0;
}