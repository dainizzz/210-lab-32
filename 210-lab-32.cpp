// COMSC-210 | Lab 32 | Dainiz Almazan
// IDE used: CLion

#include "Car.h"
#include <deque>

using namespace std;

const int INITIAL_SIZE = 2;

// printQueue() calls the print() method on each object in the queue of Car objects.
// arguments: a deque of Car objects
// returns: nothing
void printQueue(const deque<Car> &);

int main() {
	deque<Car> tollBoothLane(INITIAL_SIZE);

	// Demonstrating deque methods
	// Accessing the first element and calling the print() method
	cout << "The first car in the queue is: ";
	tollBoothLane.front().print();
	// Accessing the element at index 1 and calling the print() method
	cout << "The car at index 1 is: ";
	tollBoothLane[1].print();
	// Checking how many items are in the deque
	cout << "The number of cars currently in the queue is: " << tollBoothLane.size() << endl << endl;

	cout << "Initial queue:" << endl;
	printQueue(tollBoothLane);

	// Initializing variable to track how many cycles it takes until the queue is empty
	int count = 1;

	while (!tollBoothLane.empty()) {
		cout << "Time " << count++ << " Operation: ";

		// 55% chance: Car at the head pays its toll and leaves the toll booth

		// 45% chance: Car joins the line for the toll booth

		cout << "Queue:" << endl;
		printQueue(tollBoothLane);
	}
}

void printQueue(const deque<Car> &tollBoothLane) {
	if (tollBoothLane.empty())
		cout << "\tEmpty" << endl;
	else {
		for (Car car : tollBoothLane) {
			cout << '\t';
			car.print();
		}
	}
}