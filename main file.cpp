#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

const int MAX_VALUE = 100;
int Table_Occupied[MAX_VALUE], Table_Available[MAX_VALUE];

void show_table() {
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
	int customer = 0, all_available_table = 20, full_table = 0;
	char YorN;

	for (int i = 0; i < MAX_VALUE; i++) {
		Table_Available[i] = 4;
		Table_Occupied[i] = 0;
	}

	while (customer != -999) {
		for (int i = 0; i < 20; i++) {
			if (Table_Available[i] == 4) {
				all_available_table += 1;
			}
			else if (Table_Available[i] == 0) {
				full_table += 1;
			}
		}

		cout << "Number of available table: " << 20 << endl;
		cout << "Number of full table: " << full_table << endl;
		cout << "Number of available seat: " << all_available_table << endl;
		cout << "Number of occupied seat: " << 0 << endl;
		show_table();
		cout << "Number of customer(s): ";
		cin >> customer;
		//cout << "Recommendation(s) of table:" << endl;

		/*for (int i = 0; i < 20; i++) {
			if (customer <= Table_Available[i]) {
				cout << (i + 1) << " ";
			}
		}*/

		cout << endl;

		for (int i = 0; i < 20; i++) {
			if (customer <= Table_Available[i]) {
				Table_Available[i] -= customer;
				Table_Occupied[i] += customer;
				break;
			}
			else if (customer > Table_Available[i] && Table_Available[i] != 0) {
				cout << "Separate into different tables? (Y/N)";
				cin >> YorN;
				if (YorN == 'Y') {
					while (Table_Available[i] > 0) {
						Table_Available[i] -= 1;
						Table_Occupied[i] += 1;
						customer -= 1;
					}
				}
			}
			else if (Table_Available[i] == 0) {
				continue;
			}
		}

		cout << "//////////////////////////////////////////////////////////////////////////" << endl;
		cout << endl;
	}
	return 0;
}
