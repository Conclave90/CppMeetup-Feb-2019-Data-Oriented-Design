// This example demonstrates how cache miss is caused by showing one loop jumping 4 byte per iteration and the other jumping 64 bytes per iteration
//

#include "pch.h"
#include <iostream>

#include <vector>
#include <memory>
#include <chrono>

const long long INSTANCE_COUNT = 1e7; // 10 million


// Array of structures
struct Instance {
	int data1;
	float data2;
};

void iterateVector() {
	std::vector<Instance> v;
	v.reserve(INSTANCE_COUNT);

	for (int index = 0; index < INSTANCE_COUNT; index++) {
		v.emplace_back(Instance());
	}

	std::cout << "Iterating a vector of objects..." << std::endl;
	std::chrono::high_resolution_clock::time_point t_start = std::chrono::high_resolution_clock::now();
	for (int index = 0; index < v.size(); index++) {
		v[index].data1 = 1;
		v[index].data2 = 1.f;
	}

	std::chrono::high_resolution_clock::time_point t_end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
	std::cout << "time taken: " << duration << " milliseconds" << std::endl;
}

void iteratePointerVector() {
	std::vector<std::unique_ptr<Instance>> v;
	v.reserve(INSTANCE_COUNT);

	for (int index = 0; index < INSTANCE_COUNT; index++) {
		v.emplace_back(std::make_unique<Instance>());
	}
	
	std::cout << "Iterating a vector of pointers..." << std::endl;
	std::chrono::high_resolution_clock::time_point t_start = std::chrono::high_resolution_clock::now();
	for (int index = 0; index < v.size(); index++) {
		v[index]->data1 = 1;
		v[index]->data2 = 1.f;
	}
	std::chrono::high_resolution_clock::time_point t_end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
	std::cout << "time taken: " << duration << " milliseconds" << std::endl;
}

int main()
{
	iterateVector();

	iteratePointerVector();	

	return 0;
}
