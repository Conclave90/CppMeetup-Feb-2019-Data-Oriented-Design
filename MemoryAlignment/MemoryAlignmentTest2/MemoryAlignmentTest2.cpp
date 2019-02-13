// MemoryAlignmentTest2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

struct UnalignedDocument {
	bool is_cached_{};
	double rank_{};	
	int id_{};
};

struct AlignedDocument{
	double rank_{};
	int id_{};
	bool is_cached_{};
};

int main()
{
    std::cout << sizeof(UnalignedDocument) << "\n";

	std::cout << sizeof(AlignedDocument) << "\n";

}