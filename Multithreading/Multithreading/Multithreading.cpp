// This example shows a situation where false sharing occurs by having multiple threads sharing the same cache line
#include "pch.h"
#include <thread>
#include <iostream>
#include <ctime>
#include <memory>
#include <mutex>

const int THREAD_COUNT = 3;
const long long M = 8e8;

class Work {
public:
	void run() {
		for (; _counter < M; _counter += _counter % 3);
	}

	long int _counter{ 1 };
	//char padding[64];  adding this will ensure each thread's cache line does not overlap with each other
};

void runMultithread() {
	Work work[THREAD_COUNT];
	std::thread threads[THREAD_COUNT];

	for (int index = 0; index < THREAD_COUNT; index++) {
		threads[index] = std::thread(&Work::run, &work[index]);
	}
	for (int index = 0; index < THREAD_COUNT; index++) {
		threads[index].join();
	}


	std::cout << "multithreaded work completed" << std::endl;

}

void runSingleThread() {
	Work work[THREAD_COUNT];

	for (int index = 0; index < 3; index++) {
		work[index].run();
	}
	
	std::cout << "single-threaded work completed" << std::endl;
}



time_t start, end;
double diff;

int main(int argc, char* argv[]) {
	/* Multithread work
	*/
	time(&start);
	runMultithread();
	time(&end);

	diff = difftime(end, start);
	std::cout << diff << " seconds elapsed for " << THREAD_COUNT << " threads calculation." << std::endl;


	/* Single thread work
	*/
	time(&start);
	runSingleThread();
	time(&end);

	diff = difftime(end, start);
	std::cout << diff << " seconds elapsed for 1 thread calculation." << std::endl;
}