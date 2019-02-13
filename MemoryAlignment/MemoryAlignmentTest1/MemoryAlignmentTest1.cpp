// MemoryAlignmentTest1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


int main()
{
	auto p = new int();
	auto address = reinterpret_cast<std::uintptr_t>(p);
	std::cout << "Alignment offset: " << (address % 4ul) << '\n';
	
	std::cout << "Alignment requirement: " << alignof(double) << '\n';

	typedef __declspec(align(64)) double bigDouble;

	std::cout << "Alignment requirement: " << alignof(bigDouble) << '\n';

}