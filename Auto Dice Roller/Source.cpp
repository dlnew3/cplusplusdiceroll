/*
Code Created by Dennis Newman
10/24/2019
https://github.com/dlnew3
*/

/*
10-30-19
	Partial implementation of Dice Roller function
	Need to Implement: 
*/

#include <iostream>
#include <array>
#include <ctime>


using namespace std;

//initial_menu is true by default.
bool initial_menu = true;
int input_read(int selection, int upbound, int lowbound) {
	do {
		cin >> selection;
		if (cin.fail() || selection > upbound || selection < lowbound) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid number (from " << lowbound << " to " << upbound << ")." << endl;
		}
	} while(cin.fail() || selection > upbound || selection < lowbound);
	return selection;
}


int menu(int selection) {
	system("cls");
	cout << "\t*****Dice Roller*****" << endl;
	if (initial_menu) {	//Runs the first time menu func. is run
		//Simple instructions for first-time users
		cout << "Please enter the number of the menu item you want to begin." << endl;
		cout << "\teg. Entering \"6\" to exit the application." << endl;
		initial_menu = false;
	}
	else {
		//console will display blank newlines instead of instructions on subsequent menus
		cout << endl << endl;
	}
	cout << "1)\tRoll Dice" << endl;
	cout << "2)\tAbility Score Roll" << endl;
	cout << "3)\tCreate Spell" << endl;
	cout << "4)\tUse Spell" << endl;
	cout << "5)\tView Spells" << endl;
	cout << "6)\tCast Fireball" << endl;
	cout << "7)\tExit Application" << endl;
	//loop until valid input of selection variable is made
	cout << "Please enter a menu number: ";
	selection = input_read(selection, 7, 1);
	return selection;
}

void dice_roll() {
	int dice_sides = -1;
	int num_dice = -1;
	array <int,6> legal_sides = { 4, 6, 8, 10, 12, 20 };
	bool legal_input = false;
	do {
		cout << "What sided dice are we rolling?: ";
		cin >> dice_sides;	//10-30-19: Need to implement try-catch statement for exceptions
							//Need to prevent bad input from happening, implement loop until good input
		for (int i = 0; i < legal_sides.size(); ++i) {
			if (dice_sides == legal_sides[i]) {
				legal_input = true;
			}
		}
	} while (legal_input == false);
	cout << endl << "How many " << dice_sides << "-sided dice are we rolling?: ";
	num_dice = input_read(num_dice, 100, 0);
	cout << endl << "Rolling..." << endl;
	for (int i = 0; i < num_dice; ++i) {
		cout << (rand() % dice_sides + 1) << "\t";		//Rolls random integer from 1 - specified dice side
		if (i % 10 == 0) { cout << endl; }				//Displays in columns of 10
	}
	cout << endl;
	system("pause");
}

int main() {
	srand(time(NULL));
	int menu_select = -1;
	do {
		menu_select = menu(menu_select);
		switch (menu_select) {
		case 1:
			cout << "Dice Result: ";
			dice_roll();
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			cout << "Thank you for using Dice Roller" << endl;
			break;
		}
	} while (menu_select != 7);
	system("cls");

	system("pause");
	return 0;
};