// COMSC-210 | Lab 33 | Dainiz Almazan
// IDE used: CLion

#include "Car.h"
#include <deque>

using namespace std;

const int INITIAL_SIZE = 2;
const int NUM_LANES = 4;

// printQueue() calls the print() method on each object in the queue of Car objects.
// arguments: a deque of Car objects
// returns: nothing
void printQueue(const deque<Car> &);

/* TODO:
 * - Add more lanes
 * - Add switching lanes
 * - Update probabilities
 * - Update how long simulation runs
 */


int main() {
	srand(time(0));
	// Variable used to track cycles it takes for queue to be empty
	int count = 1;
	// Initializing an array of 4 toll booth lanes
	deque<Car> tollBoothLanes[NUM_LANES];
	// Iterating through the array to update its values
	for (int i = 0; i < NUM_LANES; i++) {
		printQueue(tollBoothLanes[i]);
		tollBoothLanes[i] = deque<Car>(INITIAL_SIZE);
		printQueue(tollBoothLanes[i]);
	}

	// cout << "Initial queue:" << endl;
	// printQueue(tollBoothLane);
	//
	// while (!tollBoothLane.empty()) {
	// 	cout << "Time: " << count++ << " Operation: ";
	//
	// 	// Generating a random number between 1 and 100
	// 	int eventProbability = rand() % 100 + 1;
	//
	// 	// 55% chance: Car at the head pays its toll and leaves the toll booth
	// 	if (eventProbability <= 55) {
	// 		cout << "Car paid: ";
	// 		tollBoothLane.front().print();
	// 		tollBoothLane.pop_front();
	// 	} else { // 45% chance: Car joins the line for the toll booth
	// 		cout << "Joined lane: ";
	// 		Car newCar;
	// 		tollBoothLane.push_back(newCar);
	// 		tollBoothLane.back().print();
	// 	}
	//
	// 	cout << "Queue:" << endl;
	// 	printQueue(tollBoothLane);
	// }
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