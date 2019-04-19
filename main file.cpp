#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

const int MAX_VALUE = 100;
int *Table_Occupied = new int [MAX_VALUE];
int *Table_Available = new int[MAX_VALUE];
int table_size = 5, num_of_table = 20;

void show_table() {
	cout << endl;
	cout << setw(50) << right << "***********************************************" << endl;
	cout << setw(10) << "* Table" << setw(20) << right << "(Available seat) " << setw(20) << right << "[Occupied seat] *" << endl;
	cout << setw(50) << right << "***********************************************" << endl;
	cout << endl;
	cout << " +------------+------------+------------+------------+----------- +" << endl;
	for (int i = 0; i < num_of_table; i++) {
		if ((i + 1) % 5 == 0) {
			cout << " |" << setw(3) << right << (i + 1) << " (" << Table_Available[i] << ") [" << Table_Occupied[i] << "] |";
			cout << endl;
			cout << " +------------+------------+------------+------------+----------- +" << endl;
		}
		else {
			cout << " |" << setw(3) << right << (i + 1) << " (" << Table_Available[i] << ") [" << Table_Occupied[i] << "]" << right;
		}
	}
}

void start_func() {
	char YorN, move = ' ';

	for (int i = 0; i < MAX_VALUE; i++) {
		Table_Available[i] = table_size;
		Table_Occupied[i] = 0;
	}

	while (move != 'E') {
		int table_num, customer = 0, all_available_table = num_of_table, full_table = 0, all_available_seat = 0;

		for (int i = 0; i < all_available_table; i++) {
			all_available_seat += Table_Available[i];
			if (Table_Available[i] == 0) {
				full_table += 1;
			}
		}
		cout << "Number of available table: " << all_available_table - full_table << endl;
		cout << "Number of full table: " << full_table << endl;
		cout << "Number of available seat: " << all_available_seat << endl;
		cout << "Number of occupied seat: " << num_of_table * table_size - all_available_seat << endl;
		show_table();

		//cout << "Recommendation(s) of table:" << endl;
		/*for (int i = 0; i < 20; i++) {
			if (customer <= Table_Available[i]) {
				cout << (i + 1) << " ";
			}
		}*/

		cout << endl;

		cout << "What action? (I/O) ";
		cin >> move;
		if (move == 'I') {
			cout << "Number of customer(s): ";
			cin >> customer;
			for (int i = 0; i < num_of_table; i++) {
				if (customer <= Table_Available[i]) {
					Table_Available[i] -= customer;
					Table_Occupied[i] += customer;
					break;
				}
				else if (customer > Table_Available[i] && Table_Available[i] != 0) {
					cout << "Separate into different tables? (Y/N) ";
					cin >> YorN;
					if (YorN == 'Y') {
						for (int j = 0; j < num_of_table; j++) {
							while (Table_Available[j] > 0) {
								Table_Available[j] -= 1;
								Table_Occupied[j] += 1;
								customer -= 1;
							}
						}
						if (customer != 0) {
							cout << "Sorry, you have to wait" << endl;
						}
					}
					else if (YorN == 'N') {
						cout << "Wait" << endl;
						if (customer <= Table_Available[i]) {
							Table_Available[i] -= customer;
							Table_Occupied[i] += customer;
							customer -= customer;
						}
					}
				}
				else if (Table_Available[i] == 0)
					continue;
			}
		}
		else if (move == 'O') {
			cout << "Which table? ";
			cin >> table_num;
			cout << "How many customer(s) out? ";
			cin >> customer;
			while (customer > Table_Occupied[table_num - 1]) {
				cout << "Error! Enter again. ";
				cout << "How many customer(s) out? ";
				cin >> customer;
			}
			Table_Available[table_num - 1] += customer;
			Table_Occupied[table_num - 1] -= customer;
		}
		cout << "===========================================================================" << endl;
		cout << endl;
	}
}

void setting_func() {
	int prog_choice;
	do {
		cout << endl;
		cout << "What time is it?" << endl;
		cout << "------------------------------------------" << endl;
		cout << "(1) 07:00 - 11:30 - Number of table: 10 Table size: 4" << endl;
		cout << "(2) 12:00 - 14:30 - Number of table: 20 Table size: 5" << endl;
		cout << "(3) 15:00 - 18:00 - Number of table: 10 Table size: 4" << endl;
		cout << "(4) 18:00 - 21:30 - Number of table: 20 Table size: 5" << endl;
		cout << "(5) Exit" << endl;
		cout << "Enter the choice: ";
		cin >> prog_choice;

		switch (prog_choice) {
		case 1: table_size = 4, num_of_table = 10;
			break;
		case 2: table_size = 5, num_of_table = 20;
			break;
		case 3: table_size = 4, num_of_table = 10;
			break;
		case 4:  table_size = 5, num_of_table = 20;
			break;
		default:
			cout << "Please enter choice 1 - 5 only." << endl;
			break;
		}
	} while (prog_choice != 5);
}

void Authors_func() {
	cout << "Name: Chan Kam Chuen  UID: 3035558197" << endl;
	cout << "Name: Ho Sui Ting  UID: " << endl;
}

int main()
{
	int prog_choice;

	do {
		cout << endl;
		cout << "XYZ Restaurant -- Table management system" << endl;
		cout << "------------------------------------------" << endl;
		cout << "(1) Starts" << endl;
		cout << "(2) Setting" << endl;
		cout << "(3) Authors" << endl;
		cout << "(4) Exit" << endl;
		cout << "Enter the choice: ";
		cin >> prog_choice;

		switch (prog_choice) {
		case 1: start_func(); break;
		case 2: setting_func(); break;
		case 3: Authors_func(); break;
		case 4: break;
		default:
			cout << "Please enter choice 1 - 4 only." << endl;
			break;
		}
	} while (prog_choice != 4);

	cout << "Program terminates. Good bye!" << endl;
	delete Table_Occupied, Table_Available;
	return 0;
}
