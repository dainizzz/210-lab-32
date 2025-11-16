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
 * - Add switching lanes
 * - Update probabilities
 */

int main() {
	srand(time(0));
	// Variable used to track cycles it takes for queue to be empty
	int count = 1;
	// Initializing an array of 4 toll booth lanes
	deque<Car> tollBoothLanes[NUM_LANES];
	// Iterating through the array to update the values in the deque stored at that index
	for (int i = 0; i < NUM_LANES; i++) {
		for (int j = 0; j < INITIAL_SIZE; j++) { // Populating the plaza with 2 cars before the simulation runs
			Car newCar;
			tollBoothLanes[i].push_back(newCar);
		}
	}

	// Outputting current deque status before simulation
	cout << "Initial queue:" << endl;
	for (deque<Car> lane : tollBoothLanes) {
		static int laneNum = 1;
		cout << "Lane " << laneNum << ':' << endl;
		printQueue(lane);
		laneNum++;
	}

	// Running the simulation for 20 time periods
	for (int i = 0; i < 20; i++) {
		for (deque<Car> lane : tollBoothLanes) {
			cout << "Time: " << count++;

			// Generating a random number between 1 and 100
			int eventProbability = rand() % 100 + 1;

			// 50% chance: Car at the head pays its toll and leaves the toll booth
			if (eventProbability <= 50) {
				cout << " Paid: ";
				lane.front().print();
				lane.pop_front();
			} else { // 50% chance: Car joins the line for the toll booth
				cout << " Joined: ";
				Car newCar;
				lane.push_back(newCar);
				lane.back().print();
			}
		}
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