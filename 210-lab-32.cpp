// COMSC-210 | Lab 32 | Dainiz Almazan
// IDE used: CLion

#include "Car.h"
#include <deque>

using namespace std;

const int INITIAL_SIZE = 2;

// printQueue() calls the
void printQueue(deque<Car> &);

int main() {
	/*Use the Car class to create Car objects, which are placed in the std::deque representing the toll booth lane.
	 *After each time period, display the queue using the .print() method in the Car class.*/

	deque<Car> cars(INITIAL_SIZE);

	cout << "Initial queue:" << endl;
	for (auto car : cars) {
		car.print();
	}

	while (!cars.empty()) {
		// Each loop simulates the time period
		// 55% chance: Car at the head pays its toll and leaves the toll booth
		// 45% chance: Car joins the line for the toll booth
	}
}