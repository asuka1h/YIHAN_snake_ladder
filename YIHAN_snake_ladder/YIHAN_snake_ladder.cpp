#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

class player {
public:
	player():atHome(1), position(0) {}
	~player() {}
	void changeStatus() { atHome = !atHome; }
	bool isAtHome() { return atHome == 1; }
	int getposition() { return position; }
	void changePosition(int newPosition) { position = newPosition; }
private:
	int atHome;
	int position;
};

// each round of the game
void gameRound(class player& player1, int *map) {
	int dice = rand() % 6 + 1; // roll the dice
	cout << "Dice value :" << dice << endl;
	int currPosition = player1.getposition();
	if (currPosition < 100) {
		if (player1.isAtHome()) {
			if (dice == 6) {
				player1.changeStatus();
			}
		}
		else {
			player1.changePosition(map[currPosition + dice]);
		}
		
	}
	
	cout << endl;
	cout << "After the dice is rolled:" << endl;
	currPosition = player1.getposition();
	cout << "CurrentPosition :" << currPosition << endl;
	cout << "CurrentState :";
	if (player1.isAtHome()) {
		cout << "AtHome" << endl;
	}
	else {
		cout << "RomeFree" << endl;
	}
	cout << endl;
	cout << endl;

}
void gamebegin() {
	int map[106];
	class player player1;
	for (int i = 0; i < 106; i++) {
		map[i] = i;
	}
	srand(time(NULL));

	// use value in the array to be snakes and ladders
	// for example, curr position of player is 1, the dice is 1, its positon will be map[curr + 1] which is 10
	// in this way, the player will aomaticaly get the ladder or be eatten by the snake
	map[2] = 10;
	map[90] = 98;
	map[55] = 59;
	map[23] = 15;
	map[60] = 54;
	map[97] = 91;
	cout << "Ladders: [(2, 10), (55, 59), (90, 98)]" << endl;
	cout << "Snakes : [(23, 15), (60, 54), (97, 91)]" << endl;
	int i = 0;

	while (true) {
		// print out some infomation for the player
		cout << "--------Total Dice rolls before this: " << i << "------------" << endl;
		cout << "CurrentPosition :" << player1.getposition() << endl;
		cout << "CurrentState :";
		if (player1.isAtHome()) {
			cout << "AtHome" << endl;
		}
		else {
			cout << "RomeFree" << endl;
		}
		cout << "Press 1 to roll a die and 2 to exit!!" << endl;
		int press;
		cin >> press;
		// continue the game or end according to player's input
		if (press == 1) {
			cout << "Pressed 1, rolling a die" << endl;
			gameRound(player1, map);
		}
		else {
			break;
		}
		//check whether player win or not
		if (player1.getposition() == 100) {
			cout << "Hurray you won!!Bye bye : )" << endl;
			break;
		}
		++i;
	}
}
int main()
{
	gamebegin();
	
	
    return 0;
}

