#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include <stdlib.h>
using namespace std;

const int MAX_VALUE = 100;
int *Order_list1 = new int[MAX_VALUE];
int *Order_list2 = new int[MAX_VALUE];
int *Table_Occupied = new int[MAX_VALUE];
int *Table_Available = new int[MAX_VALUE];
int *Waiting_list = new int[MAX_VALUE];
int table_size = 5, num_of_table = 20,z=0,x=0;

// This function shows a 2D picture of our restaurant which included the number of the table, 
// the available seat of a table and the seat occupied for that table
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

/*void Waiting_lists(int &count_customer) {
	cout << endl;
	cout << "Waiting List: " << endl;
	for (int i = count_customer; i < MAX_VALUE; i++) {
		if ((i + 1) % 10 == 0) {
			cout << setw(2) << right << Waiting_list[i] << endl;
		}
		else {
			cout << setw(2) << right << Waiting_list[i] << " ";
		}
	}
	cout << endl;
}*/

void auto_assign_table(char move, int customer, int &count_customer, int &all_available_table, int &full_table, int &all_available_seat) {
	int table_num;
	show_table();

	cout << "Number of available table: " << all_available_table - full_table << endl;
	cout << "Number of full table: " << full_table << endl;
	cout << "Number of available seat: " << all_available_seat << endl;
	cout << "Number of occupied seat: " << num_of_table * table_size - all_available_seat << endl;

	cout << endl;
	cout << "  * Input E to exit   " << endl;
	cout << "  * Input I to occupy a table   " << endl;
	cout << "  * Input O to release a table   " << endl;
	cout << endl;
	cout << "What action? (I/O) ";
	cin >> move;

	if (move == 'I') {
		if (all_available_seat == 0) {
			cout << "********* The restaurant is now full *********" << endl;
			cout << Order_list2[x] << " customer(s) in Table " << Order_list1[x] << " may occupy the table for too long !"<<endl;
			cout << endl;
			x++;
			move = 'O';
		}
		else if (all_available_seat >= customer) {
			cout << " ********* All tables in the restaurant are occupied *********" << endl;
			cout << "You have to share the table with others!" << endl;
			cout << "Number of customer(s): ";
			//cout << customer;
			cin >> customer;
			for (int i = 0; i < num_of_table; i++) {
				if (customer <= Table_Available[i]) {
					Table_Available[i] -= customer;
					Table_Occupied[i] += customer;
					cout << customer << " Customer(s) have been assigned to Table " << i + 1 << endl;
					Order_list1[z] = i+1;
					Order_list2[z] = customer;
					z++;
					break;
				}
				else if (customer > Table_Available[i] && Table_Available[i] != 0) {
					int temp = customer;
					while (Table_Available[i] > 0) {
						Table_Available[i] -= 1;
						Table_Occupied[i] += 1;
						customer -= 1;
					}
					cout << temp - customer << " Customer(s) have been assigned to Table " << i + 1 << endl;
					Order_list1[z] = i + 1;
					Order_list2[z] = temp-customer;
					z++;
				}

				else if (all_available_seat < customer) {
					cout << "We don't have enoguh seats."<<endl;
					cout << Order_list2[x] << " customer(s) in Table " << Order_list1[x] << " may occupy the table for too long !";
					cout << endl;
					x++;
					move = 'O';
					return;
				}

				else if (Table_Available[i] == 0) {
					continue;
				}
			}
		}
		else if (all_available_seat < customer) {
			cout << "We don't have enoguh seats."<<endl;
			cout << Order_list2[x] << " customer(s) in Table " << Order_list1[x] << " may occupy the table for too long !";
			cout << endl;
			x++;
			move = 'O';
			return;
		}
		count_customer++;
	}

	if (move == 'O') {
		cout << "Which table need to be released? ";
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

	for (int i = 0; i < all_available_table; i++) {
		all_available_seat += Table_Available[i];
		if (Table_Available[i] == 0) {
			full_table += 1;
		}
	}
}

void start_func() {
	int customer = 0, count_customer = 0;
	char YorN, move = ' ';

	for (int i = 0; i < MAX_VALUE; i++) {
		Table_Available[i] = table_size;
		Table_Occupied[i] = 0; // Original = 0;
	}

	//Waiting_lists(count_customer);

	while (move != 'E') {
		int table_num, /*customer = 0, */all_available_table = num_of_table, full_table = 0, all_available_seat = 0, total = 0;

		for (int i = 0; i < num_of_table; i++) {
			if (Table_Occupied[i] > 0) {
				total += 1;
			}
		}

		customer = Waiting_list[count_customer];
		// Waiting_list[count_customer] = NULL;

		for (int i = 0; i < all_available_table; i++) {
			all_available_seat += Table_Available[i];
			if (Table_Available[i] == 0) {
				full_table += 1;
			}
		}

		if (total == num_of_table && move != 'O') {
			auto_assign_table(move, customer, count_customer, all_available_table, full_table, all_available_seat);    // Assign the table if all tables are occupied
			continue;
		}

		cout << "Number of available table: " << all_available_table - full_table << endl;
		cout << "Number of full table: " << full_table << endl;
		cout << "Number of available seat: " << all_available_seat << endl;
		cout << "Number of occupied seat: " << num_of_table * table_size - all_available_seat << endl;
		show_table();

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
			//cout << customer << endl;
			if (all_available_seat < customer) {
				cout << "We don't have enoguh seats." << endl;
				cout << Order_list2[x] << " customer(s) in Table " << Order_list1[x] << " may occupy the table for too long !"<<endl;
				x++;
				move = 'O';
			}
			else if (all_available_seat >= customer) {
				while (customer != 0) {
					cout << "Tables you can choose: ";
					for (int i = 0; i < num_of_table; i++) {
						if (Table_Occupied[i] == 0) {
							cout << i + 1 << " ";
						}
					}
					cout << endl;
					cout << "Table(s) you would like to occupy: ";
					cin >> table_num;
					if (Table_Occupied[table_num - 1] != 0) {
						cout << " Table is occupied already " << endl;
						cout << " Please try again" << endl;
						break;
					}
					else {
						if (Table_Available[table_num - 1] >= customer) {
							Order_list1[z] = table_num;
							Order_list2[z] = customer;
							z++;
							Table_Available[table_num - 1] -= customer;
							Table_Occupied[table_num - 1] += customer;
							customer -= customer;
						}
						if (Table_Available[table_num - 1] < customer) {
							Order_list1[z] = table_num;
							Order_list2[z] = table_size;
							z++;
							Table_Available[table_num - 1] -= table_size;
							Table_Occupied[table_num - 1] += table_size;
							customer -= table_size;
							show_table();
							cout << "You have to assign tables for " << customer << " more customers" << endl;
						}
					}
				}
			}
		}
		 if (move == 'O') {
			cout << "Which table need to be released? ";
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
		count_customer++;
		system("cls");
		//cout << "Waiting List: " << endl;
		//Waiting_lists(count_customer);
		cout << endl;
	}
}


void setting_func() {
	int prog_choice;
	do {
		cout << endl;
		cout << "What time is it?" << endl;
		cout << "------------------------------------------" << endl;
		cout << "                      Summer Time" << endl;
		cout << "(1) 07:00 - 11:30 - Number of table: 10 Table size: 4" << endl;
		cout << "(2) 12:00 - 14:30 - Number of table: 20 Table size: 5" << endl;
		cout << "(3) 15:00 - 18:00 - Number of table: 10 Table size: 4" << endl;
		cout << "(4) 18:00 - 21:30 - Number of table: 20 Table size: 5" << endl;
		cout << "                      Winter Time" << endl;
		cout << "(5) 07:00 - 11:30 - Number of table: 15 Table size: 5" << endl;
		cout << "(6) 12:00 - 14:30 - Number of table: 20 Table size: 6" << endl;
		cout << "(7) 15:00 - 18:00 - Number of table: 15 Table size: 5" << endl;
		cout << "(8) 18:00 - 21:30 - Number of table: 25 Table size: 6" << endl;
		cout << endl;
		cout << "(9) Exit" << endl;
		cout << "Enter the choice: ";
		cin >> prog_choice;

		switch (prog_choice) {
		case 1: table_size = 4, num_of_table = 10;
			prog_choice = 9;
			break;
		case 2: table_size = 5, num_of_table = 20;
			prog_choice = 9;
			break;
		case 3: table_size = 4, num_of_table = 10;
			prog_choice = 9;
			break;
		case 4:  table_size = 5, num_of_table = 20;
			prog_choice = 9;
			break;
		case 5: table_size = 5, num_of_table = 15;
			prog_choice = 9;
			break;
		case 6: table_size = 6, num_of_table = 20;
			prog_choice = 9;
			break;
		case 7: table_size = 5, num_of_table = 15;
			prog_choice = 9;
			break;
		case 8: table_size = 6, num_of_table = 25;
			prog_choice = 9;
			break;
		default:
			cout << "Please enter choice 1 - 8 only." << endl;
			break;
		}
	} while (prog_choice != 9);
}

void Staffs_func() {
	cout << "Name: Chan Kam Chuen\tUID: 3035558197" << endl;
	cout << "Name: Ho Sui Ting\tUID: 3035569330" << endl;
}

int main()
{
	int prog_choice;

	/*for (int i = 0; i < MAX_VALUE; i++) {
		Waiting_list[i] = (rand() % 6) + 1;
	}*/

	do {
		cout << endl;
		cout << "XYZ Restaurant -- Table management system" << endl;
		cout << "------------------------------------------" << endl;
		cout << "(1) Start" << endl;
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
	delete Table_Occupied, Table_Available, Waiting_list;
	return 0;
}
