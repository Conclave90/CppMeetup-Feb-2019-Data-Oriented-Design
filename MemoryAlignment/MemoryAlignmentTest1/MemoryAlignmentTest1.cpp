// This example demonstrates how to determine alignement of memory address and alignment requirement of a variable
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