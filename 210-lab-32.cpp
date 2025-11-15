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
	/*Use the Car class to create Car objects, which are placed in the std::deque representing the toll booth lane.
	 *After each time period, display the queue using the .print() method in the Car class.*/

	deque<Car> cars(INITIAL_SIZE);

	// Demonstrating deque methods
	// Accessing the first element and calling the print() method
	cout << "The first car in the queue is: ";
	cars.front().print();
	// Accessing the element at index 1 and calling the print() method
	cout << "The car at index 1 is: ";
	cars[1].print();
	// Checking how many items are in the deque
	cout << "The number of cars currently in the queue is: " << cars.size() << endl;

	cout << "Initial queue:" << endl;
	printQueue(cars);

	//while (!cars.empty()) {
		// Each loop simulates the time period
		// 55% chance: Car at the head pays its toll and leaves the toll booth
		// 45% chance: Car joins the line for the toll booth
	//}
}

void printQueue(const deque<Car> &cars) {
	// TODO: Check for empty queue & print empty
	for (auto car : cars) {
		car.print();
	}
}