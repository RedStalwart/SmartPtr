// smartpointerimplementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "smartptrimplementation.h"
class test
{
public:
	test()
	{
		std::cout << "test class created" << std::endl;
	}
	void letswaitsomemore()
	{
		std::cout << "lets wait some more and see if this works" << std::endl;
	}
	~test()
	{
		std::cout << "test class destroyed" << std::endl;
	}
};
int main()
{
	smartptr<test> ptr(new test());
	std::cout << "lets wait" << std::endl;
	ptr->letswaitsomemore();
	(*ptr).letswaitsomemore();
}
