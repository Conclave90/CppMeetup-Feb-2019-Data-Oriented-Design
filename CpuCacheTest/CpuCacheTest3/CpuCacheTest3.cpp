// This example demonstrates how compiler can auto-vectorize a loop with struct of arrays, making it faster than looping an array of structs
//

#include "pch.h"
#include <iostream>

#include <vector>
#include <memory>
#include <chrono>

const long long INSTANCE_COUNT = 1e7; // 10 million


struct Instance {
	int data1{ 0 };
	float data2{ 0 };
};

// Array of Structures Test
void iterateAOS() {
	std::vector<Instance> container;
	container.resize(INSTANCE_COUNT);

	std::cout << "Iterating a vector of objects..." << std::endl;
	std::chrono::high_resolution_clock::time_point t_start = std::chrono::high_resolution_clock::now();

	auto ptr = container.data();
	for (int index = 0; index < INSTANCE_COUNT; index++) {
		ptr[index].data1 = 1;
		ptr[index].data2 = 1.f;
	}
	std::chrono::high_resolution_clock::time_point t_end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
	std::cout << "time taken: " << duration << " milliseconds" << std::endl;
}



// Structure of arrays
struct InstanceArray {
	std::vector<int> data1;
	std::vector<float> data2;
};


// Structure of Arrays Test
void iterateSOA() {
	InstanceArray instance;

	instance.data1.resize(INSTANCE_COUNT);
	instance.data2.resize(INSTANCE_COUNT);
	   
	std::cout << "Iterating a struct of arrays" << std::endl;
	std::chrono::high_resolution_clock::time_point t_start = std::chrono::high_resolution_clock::now();

	auto data1Ptr = instance.data1.data();
	auto data2Ptr = instance.data2.data();

	for (int index = 0; index < INSTANCE_COUNT; index++) {
		data1Ptr[index] = 1;
		data2Ptr[index] = 1.f;
	}
	std::chrono::high_resolution_clock::time_point t_end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
	std::cout << "time taken: " << duration << " milliseconds" << std::endl;
}


int main()
{
	iterateAOS();

	iterateSOA();

	return 0;
}
