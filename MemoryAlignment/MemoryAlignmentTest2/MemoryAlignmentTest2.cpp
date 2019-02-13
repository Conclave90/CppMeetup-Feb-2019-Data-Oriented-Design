// This example demonstrates how compiler can add hidden byte padding after each variable if it doesn't fit in a CPU register size
//

#include "pch.h"
#include <iostream>

struct UnalignedDocument {
	bool is_cached_{};
	// char padding[7]; automatically added by compiler
	double rank_{};
	int id_{};
	// char padding[4]; automatically added by compiler
};

struct AlignedDocument{
	double rank_{};
	int id_{};
	bool is_cached_{};
	// char padding[3]; automatically added by compiler
};

int main()
{
    std::cout << sizeof(UnalignedDocument) << "\n";

	std::cout << sizeof(AlignedDocument) << "\n";

}