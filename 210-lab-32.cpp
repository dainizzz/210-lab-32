// COMSC-210 | Lab 33 | Dainiz Almazan
// IDE used: CLion

#include "Car.h"
#include <deque>

using namespace std;

const int INITIAL_SIZE = 2;
const int NUM_LANES = 4;
const int CHANCE_PAY = 46;
const int CHANCE_JOIN = 39;
const int CHANCE_SWITCH = 15;

// printQueue() calls the print() method on each object in the queue of Car objects.
// arguments: a deque of Car objects
// returns: nothing
void printQueue(const deque<Car> &);

// getRandomNewLane() returns the number of a random lane that isn't the current lane
// arguments: an int value representing the current lane as a 0-based index
// returns: an int value representing a new lane as a 0-based index
int getRandomNewLane(int);

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
		for (int j = 0; j < INITIAL_SIZE; j++) {
			// Populating the plaza with 2 cars before the simulation runs
			Car newCar;
			tollBoothLanes[i].push_back(newCar);
		}
	}

	// Outputting current deque status before simulation
	cout << "Initial queue:" << endl;
	for (const deque<Car> &lane: tollBoothLanes) {
		static int laneNum = 1;
		cout << "Lane " << laneNum << ':' << endl;
		printQueue(lane);
		laneNum++;
	}
	cout << endl;

	// Running the simulation for 20 time periods
	for (int i = 0; i < 20; i++) {
		cout << " Time: " << count++ << endl;
		// OPERATIONS
		for (int lane = 0; lane < NUM_LANES; lane++) {
			cout << "Lane: " << lane + 1;

			// Generating a random number between 1 and 100
			int eventProbability = rand() % 100 + 1;

			// Operation 1: Car at the head pays its toll and leaves the toll booth
			if (eventProbability <= CHANCE_PAY) {
				if (!tollBoothLanes[lane].empty()) {
					// Added to avoid error of trying to pop from empty deque
					cout << " Paid: ";
					tollBoothLanes[lane].front().print();
					tollBoothLanes[lane].pop_front();
				}
			}

			// Operation 2: Car joins the line for the toll booth
			if (eventProbability <= CHANCE_JOIN) {
				cout << " Joined: ";
				Car newCar;
				tollBoothLanes[lane].push_back(newCar);
				tollBoothLanes[lane].back().print();
			}

			// Operation 3: Rear car switches lanes
			if (eventProbability <= CHANCE_SWITCH) {
				cout << " Switched: ";
				tollBoothLanes[lane].back().print();
				int newLane = getRandomNewLane(lane);
				tollBoothLanes[newLane].push_back(tollBoothLanes[lane].back());
				tollBoothLanes[lane].pop_back();
			}
		}
		// QUEUE AFTER OPERATIONS
		int laneNum = 1;
		for (const deque<Car> &lane: tollBoothLanes) {
			cout << "Lane " << laneNum++ << " Queue:" << endl;
			printQueue(lane);
		}
	}
}

void printQueue(const deque<Car> &tollBoothLane) {
	if (tollBoothLane.empty())
		cout << "\tEmpty" << endl;
	else {
		for (Car car: tollBoothLane) {
			cout << '\t';
			car.print();
		}
	}
}

int getRandomNewLane(int curLane) {
	int newLane = rand() % 4;
	while (newLane == curLane)
		newLane = rand() % 4;
	return newLane;
}
