// This example demonstrates how cache miss is caused by showing one loop jumping 4 byte per iteration and the other jumping 64 bytes per iteration
//

#include "pch.h"
#include <iostream>

#include <vector>
#include <chrono>

const int ROWCOUNT = 100000000;

void iterate1() {
	int* array = new int[ROWCOUNT];

	std::chrono::high_resolution_clock::time_point t_start = std::chrono::high_resolution_clock::now();

	unsigned int sum = 0;
	for (int index = 0; index < 1000000; index++) {
		sum += array[index];
	}

	std::chrono::high_resolution_clock::time_point t_end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();

	std::cout << "time taken: " << duration << " milliseconds" << std::endl;
	std::cout << "sum: " << sum << std::endl;

	delete[] array;
}

void iterate2() {
	int* array = new int[ROWCOUNT];

	std::chrono::high_resolution_clock::time_point t_start = std::chrono::high_resolution_clock::now();

	unsigned int sum = 0;
	for (int index1 = 0; index1 < 16000000; index1 += 16) {
		sum += array[index1];
	}

	std::chrono::high_resolution_clock::time_point t_end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
	std::cout << "time taken: " << duration << " milliseconds" << std::endl;
	std::cout << "sum: " << sum << std::endl;


	delete[] array;
}

int main()
{
	iterate1();

	iterate2();
}
