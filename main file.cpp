#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

const int MAX_VALUE = 100;
int *Table_Occupied = new int[MAX_VALUE];
int *Table_Available = new int[MAX_VALUE];
int table_size = 5, num_of_table = 20;

/*this function shows a 2D picture of our restaurant which included the number of the table,
the available seat of a table and the seat occupied for that table*/
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

/*this function read user input and process different tasks,like ocuppying a table ,releasing a table*/
void start_func() {
	char YorN, move = ' ';

	for (int i = 0; i < MAX_VALUE; i++) {
		Table_Available[i] = table_size;
		Table_Occupied[i] = 0;
	}

	while (move != 'E') {
		int table_num, customer = 0, all_available_table = num_of_table, full_table = 0, all_available_seat = 0,total=0;
		for (int i = 0;i < num_of_table;i++) {
			if (Table_Occupied[i] > 0) {
				total += 1;
			}
		}
		/*if (total = num_of_table) {
			//autoassigntable();    //asign the table if all tables are occupied
			//continue;  //*****************************************************************Eorror may occur
		}*/
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

		cout << "  * Input E to exit   " << endl;
		cout << "  * Input I to occupy a table   " << endl;
		cout << "  * Input O to release a table   " << endl;
		cout << endl;
		cout << "What action? (I/O) ";
		cin >> move;
		if (move == 'I') {
			cout << "Number of customer(s): ";
			cin >> customer;
			while (customer != 0) {
				cout << "Table(s) you would like to occupy: ";
				cin >> table_num;
				if (Table_Occupied[table_num - 1] != 0) {
					cout << " Table is occupied already " << endl;
					cout << " Please try again"<<endl;
					break;
				}
				else{
					if (Table_Available[table_num - 1] >= customer) {
						Table_Available[table_num - 1] -= customer;
						Table_Occupied[table_num - 1] += customer;
						customer -= customer;
					}
					if (Table_Available[table_num - 1] < customer) {
						Table_Available[table_num - 1] -= 5;
						Table_Occupied[table_num - 1] += 5;
						customer -= 5;
						show_table();
						cout << "You have to separate tables for " << customer << " more customers" << endl;
					}
				}
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

void Staffs_func() {
	cout << "Name: Chan Kam Chuen  UID: 3035558197" << endl;
	cout << "Name: Ho Sui Ting  UID: 3035569330" << endl;
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
		cout << "(3) Staffs" << endl;
		cout << "(4) Exit" << endl;
		cout << "Enter the choice: ";
		cin >> prog_choice;

		switch (prog_choice) {
		case 1: start_func(); break;
		case 2: setting_func(); break;
		case 3: Staffs_func(); break;
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
