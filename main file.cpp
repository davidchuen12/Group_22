#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

const int MAX_VALUE = 100;
int Table_Occupied[MAX_VALUE], Table_Available[MAX_VALUE];

void show_table() {
	cout << endl;
	cout << setw(50) << right << "***********************************************" << endl;
	cout << setw(10) << "* Table" << setw(20) << right << "(Available seat) " << setw(20)<< right << "[Occupied seat] *" << endl;
	cout << setw(50) << right << "***********************************************" << endl;
	cout << endl;
	cout << " +------------+------------+------------+------------+----------- +" << endl;
	for (int i = 0; i < 20; i++) {
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

int main() {
	char YorN, move = ' ';

	for (int i = 0; i < MAX_VALUE; i++) {
		Table_Available[i] = 4;
		Table_Occupied[i] = 0;
	}

	while (move != 'E') {
		int table_num, customer = 0, all_available_table = 20, full_table = 0, all_available_seat = 0;

		for (int i = 0; i < all_available_table; i++) {
			all_available_seat += Table_Available[i];
			if (Table_Available[i] == 0) {
				full_table += 1;
			}
		}
		cout << "Number of available table: " << all_available_table - full_table << endl;
		cout << "Number of full table: " << full_table << endl;
		cout << "Number of available seat: " << all_available_seat << endl;
		cout << "Number of occupied seat: " << 20 * 4 - all_available_seat << endl;
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
			for (int i = 0; i < 20; i++) {
				if (customer <= Table_Available[i]) {
					Table_Available[i] -= customer;
					Table_Occupied[i] += customer;
					break;
				}
				else if (customer > Table_Available[i] && Table_Available[i] != 0) {
					cout << "Separate into different tables? (Y/N) ";
					cin >> YorN;
					if (YorN == 'Y') {
						while (Table_Available[i] > 0) {
							Table_Available[i] -= 1;
							Table_Occupied[i] += 1;
							customer -= 1;
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
			while (customer > Table_Occupied[table_num]) {
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
	return 0;
}
