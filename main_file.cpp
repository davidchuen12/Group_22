#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_VALUE = 100;
int *Table_Occupied = new int[MAX_VALUE];		//shows how many seats are occupied
int *Table_Available = new int[MAX_VALUE];		//shows how many seats are available
int table_size = 5, num_of_table = 20, total = 0;
ofstream fout;

struct Node						//used to construct an array storing who is the earliest come customer
{
	int table;
	int customer_number;
	Node * next;
};
Node * head = NULL, *tail = NULL;

/* This function shows a 2D picture of our restaurant which included the number of the table,
 the available seat of a table and the seat occupied for that table*/
void show_table() {
	cout << endl;
	fout << endl;

	cout << setw(50) << right << "***********************************************" << endl;
	fout << setw(50) << right << "***********************************************" << endl;

	cout << setw(10) << "* Table" << setw(20) << right << "(Available seat) " << setw(20) << right << "[Occupied seat] *" << endl;
	fout << setw(10) << "* Table" << setw(20) << right << "(Available seat) " << setw(20) << right << "[Occupied seat] *" << endl;

	cout << setw(50) << right << "***********************************************" << endl;
	fout << setw(50) << right << "***********************************************" << endl;

	cout << endl;
	fout << endl;

	cout << " +------------+------------+------------+------------+----------- +" << endl;
	fout << " +------------+------------+------------+------------+----------- +" << endl;

	for (int i = 0; i < num_of_table; i++) {
		if ((i + 1) % 5 == 0) {
			cout << " |" << setw(3) << right << (i + 1) << " (" << Table_Available[i] << ") [" << Table_Occupied[i] << "] |";
			fout << " |" << setw(3) << right << (i + 1) << " (" << Table_Available[i] << ") [" << Table_Occupied[i] << "] |";

			cout << endl;
			fout << endl;

			cout << " +------------+------------+------------+------------+----------- +" << endl;
			fout << " +------------+------------+------------+------------+----------- +" << endl;
		}
		else {
			cout << " |" << setw(3) << right << (i + 1) << " (" << Table_Available[i] << ") [" << Table_Occupied[i] << "]" << right;
			fout << " |" << setw(3) << right << (i + 1) << " (" << Table_Available[i] << ") [" << Table_Occupied[i] << "]" << right;
		}
	}
}
/*This function will read the input of table_num and customer then it search for the specific element
in the array and return the current*/
Node * find_Node(Node *head, int table_num, int customer) {
	Node * current = head;
	Node * p = head;
	if (current->table == table_num && current->customer_number == customer) {
		return current;
	}
	else {
		while (current != NULL) {
			p = current->next;
			if (p->table == (table_num) && p->customer_number == customer) {
				return current;
			}
			else {
				current = current->next;
			}
		}
		return NULL;
	}
}
/*this function read the current and delete one element that after it, it is used for relasing 
the table and clean out the table that released so the checktable function will not show the elements
which has been deleted already*/
void delete_Node(Node * after) {
	if (head != NULL) {
		Node * p = after->next;
		after->next = p->next;
		delete p;
	}
	return;
}
/*this function read the current and delete head if the current is head, it is used for relasing 
the table and clean out the table that released so the checktable function will not show the elements
which has been deleted already,head is returned which means the new head is updated*/
Node * delete_Head(Node * &head) {
	Node * p = head;
	head = head->next;			
	delete p;
	return head;
}

void check_table() {//check the table occupied by earliest customers and show it to remind the waiters release it
	cout << head->customer_number << " customer(s) in Table " << head->table << " may occupy the table for too long !" << endl;
	fout << head->customer_number << " customer(s) in Table " << head->table << " may occupy the table for too long !" << endl;
	cout << "Please invite them to release the table" << endl;
	fout << "Please invite them to release the table" << endl;
	return;
}
/*this function read the table number and the customer number of a group, it is used for occupying
the table.A pointer forward array is construct which store the order ,the table number and how many customers of that group ,
and the tail is keep updating to the newest come customer*/
void record_table(int table_num, int customer) {
	Node * p = new Node;
	p->table = table_num;
	p->customer_number = customer;
	p->next = NULL;
	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
	return;
}
/*This function read the user input which are table number and how many customer of that table are left.It checks for the numbe
r of customer and table numbers that release and pass it to findNode function in order to find the current.It then pass to the delete 
function to delete the particular element in the array which store the order of customer come.*/
void Releasing_table(int &customer, int &table_num) {
	cout << "Which table need to be released? ";
	fout << "Which table need to be released? ";

	cin >> table_num;
	fout << table_num << endl;

	cout << "How many customer(s) out? ";
	fout << "How many customer(s) out? ";

	cin >> customer;
	fout << customer << endl;

	while (customer > Table_Occupied[table_num - 1]) {

		cout << "Error! Enter again. ";
		cout << "How many customer(s) out? ";
		fout << "Error! Enter again. ";
		fout << "How many customer(s) out? ";

		cin >> customer;
		fout << customer << endl;
	}

	Table_Available[table_num - 1] += customer;
	Table_Occupied[table_num - 1] -= customer;
	Node * after;
	after = find_Node(head, table_num, customer);
	cout << (head == after) << endl;    //output  True

	if (after != head) {
		delete_Node(after);
	}
	else if (after == head) {
		head = delete_Head(after);
	}
}
/*This function check if all the table are occupied by at least one person or not and return Ture if all are occupied*/
bool check_all_occupied() {
	for (int i = 0; i < num_of_table; i++) {
		if (Table_Occupied[i] != 0) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

void Occupying_table_Auto(int table_num, int &customer) {

	if (Table_Available[table_num - 1] >= customer) {
		Table_Available[table_num - 1] -= customer;
		Table_Occupied[table_num - 1] += customer;
		customer = 0;
	}

	else {
		while (Table_Available[table_num - 1] != 0) {
			Table_Available[table_num - 1] -= 1;
			Table_Occupied[table_num - 1] += 1;
			customer -= 1;
		}
		cout << "You have to assign tables for " << customer << " more customers" << endl;
		fout << "You have to assign tables for " << customer << " more customers" << endl;
	}
}
/*THis function read the input of number of customer and if all_available seat is less than the customer,it will tell the waiter to release 
the earliest come table,else it will suggest some tables that user can choose and read the choice of user and occupy those table*/
void Occupying_table(int &customer, int &all_available_seat, int &num_of_table, int &table_num, int &count_customer, int &all_available_table, int &full_table) {
	cout << "Number of customer(s): ";
	fout << "Number of customer(s): ";

	cin >> customer;
	fout << customer << endl;

	if (all_available_seat < customer) {
		check_table();
		Releasing_table(customer, table_num);
	}
	else if (all_available_seat >= customer) {
		while (customer != 0) {
			total = 0;
			for (int i = 0; i < num_of_table; i++) {	//this for loop finds how many tables are occupied by at least one person
				if (Table_Occupied[i] > 0) {
					total += 1;
				}
			}
			if (total < num_of_table) {
				cout << "Tables you can choose: ";
				fout << "Tables you can choose: ";

				for (int i = 0; i < num_of_table; i++) {		//this for loop searhing and showing any empty table that don't have any people yet
					if (Table_Occupied[i] == 0) {
						cout << i + 1 << " ";
						fout << i + 1 << " ";
					}
				}
			}
			else if (total = num_of_table) {
				cout << "Tables you can choose: ";
				fout << "Tables you can choose: ";
				int temp = customer, j = 1;
				while (j != 0) {
					for (int i = 0; i < num_of_table; i++) {
						if (Table_Available[i] >= temp) {
							cout << i + 1 << " ";
							fout << i + 1 << " ";
							j = 0;
						}
					}
					if (j != 0) {
						temp--;
					}
				}
			}


			cout << endl;
			cout << "Table(s) you would like to occupy: ";

			fout << endl;
			fout << "Table(s) you would like to occupy: ";

			cin >> table_num;
			fout << table_num << endl;

			if (check_all_occupied() == true) {
				Occupying_table_Auto(table_num, customer);
				if (customer <= 0) {
					return;
				}
				else {
					continue;
				}
			}

			if (Table_Occupied[table_num - 1] != 0) {

				cout << " Table is occupied already. " << endl;
				cout << " Please try again" << endl;

				fout << " Table is occupied already. " << endl;
				fout << " Please try again" << endl;

			}

			else {
				if (Table_Available[table_num - 1] >= customer) {
					record_table(table_num, customer);
					Table_Available[table_num - 1] -= customer;
					Table_Occupied[table_num - 1] += customer;
					customer -= customer;
					show_table();
				}

				if (Table_Available[table_num - 1] < customer) {
					record_table(table_num, table_size);
					Table_Available[table_num - 1] -= table_size;
					Table_Occupied[table_num - 1] += table_size;
					customer -= table_size;

					show_table();
					cout << "You have to assign tables for " << customer << " more customers" << endl;
					fout << "You have to assign tables for " << customer << " more customers" << endl;
				}
			}
		}
	}
}

/*This function read the action that that user want to carry out,'I' or 'O' ,the number of the customers,the number of all available table
,number of full table ,the number of total available seat, and be reminded that these parameter are passed to reference.
this function will fout the output into the target file.It will automatically assign the customer to
the available seat when it is in 'all_table occupied state'(all tables are occupied by at least one person), it will notice
them you have to share table with other and also tell the waiter we don't have enough seat when all available seats are occupied
or the new coming customer number is larger than our available seat. It will let the waiter release the table occupied by earlest come customer*/
void auto_assign_table(char move, int customer, int &count_customer, int &all_available_table, int &full_table, int &all_available_seat, int &num_of_table) {
	int table_num;
	show_table();
	full_table = 0;
	all_available_seat = 0;
	for (int i = 0; i < num_of_table; i++) {		//this for loop finds the number of full table(occupied by number of table size eg.5) and total available seats
		all_available_seat += Table_Available[i];
		if (Table_Available[i] == 0) {
			full_table += 1;
		}
	}
	cout << "Number of available table: " << all_available_table - full_table << endl;
	cout << "Number of full table: " << full_table << endl;
	cout << "Number of available seat: " << all_available_seat << endl;
	cout << "Number of occupied seat: " << num_of_table * table_size - all_available_seat << endl;

	fout << "Number of available table: " << all_available_table - full_table << endl;
	fout << "Number of full table: " << full_table << endl;
	fout << "Number of available seat: " << all_available_seat << endl;
	fout << "Number of occupied seat: " << num_of_table * table_size - all_available_seat << endl;

	cout << endl;
	cout << "  * Input E to exit   " << endl;
	cout << "  * Input I to occupy a table   " << endl;
	cout << "  * Input O to release a table   " << endl;
	cout << endl;
	cout << "What action? (I/O) ";

	fout << endl;
	fout << "  * Input E to exit   " << endl;
	fout << "  * Input I to occupy a table   " << endl;
	fout << "  * Input O to release a table   " << endl;
	fout << endl;
	fout << "What action? (I/O) ";

	cin >> move;
	fout << move << endl;
	if (move == 'I') {
		if (all_available_seat == 0) {
			cout << "********* The restaurant is now full *********" << endl;
			fout << "********* The restaurant is now full *********" << endl;

			check_table();

			cout << endl;
			fout << endl;

			Releasing_table(customer, table_num);
			return;
		}
		if (all_available_seat > 0) {
			cout << " ********* All tables in the restaurant are occupied *********" << endl;		//all table occupied mode
			cout << "You may need to share the table with others!" << endl;
			cout << "Seats are allocated by the system automatically" << endl;
			cout << "Number of customer(s): ";

			fout << " ********* All tables in the restaurant are occupied *********" << endl;
			fout << "You may need to share the table with others!" << endl;
			fout << "Seats are allocated by the system automatically" << endl;
			fout << "Number of customer(s): ";

			cin >> customer;
			fout << customer << endl;
			if (all_available_seat >= customer) {
				int temp = customer;
				while (temp != 0) {
					int k = 0;
					for (int i = 0; i < num_of_table; i++) {
						if (Table_Available[i] >= customer && Table_Available[i] != 0) {
							Table_Available[i] -= customer;
							Table_Occupied[i] += customer;
							cout << customer << " Customer(s) have been assigned to Table " << i + 1 << endl;
							fout << customer << " Customer(s) have been assigned to Table " << i + 1 << endl;
							int j = i + 1;
							record_table(j, customer);
							temp = temp - customer;
							customer = temp;
							k = 1;
							break;

						}
					}
					if (k != 1) {
						customer--;
					}
				}
				return;
			}
			else if (all_available_seat < customer) {
				cout << "We don't have enoguh seats." << endl;
				fout << "We don't have enoguh seats." << endl;
				check_table();

				cout << endl;
				fout << endl;

				Releasing_table(customer, table_num);
				return;
			}
			return;
		}
	}
	if (move == 'O') {
		Releasing_table(customer, table_num);
	}
	if (move == 'E') {
		return;
	}
}
/*This function read the instruction from the user which are 'O','E' or 'I',and occupying a table and pass it to occupying function if choice is
I and release the table if it is 'O'*/
void start_func() {
	int customer = 0, count_customer = 0;
	char YorN, move = ' ';
	for (int i = 0; i < MAX_VALUE; i++) {		//make all table show seat available(= table size) and seat occupied(= 0)
		Table_Available[i] = table_size;
		Table_Occupied[i] = 0;
	}

	while (move != 'E') {
		int table_num, all_available_table = num_of_table, full_table = 0, all_available_seat = 0;
		total = 0;
		for (int i = 0; i < num_of_table; i++) {		//this for loop finds how many tables are occupied by at least one person
			if (Table_Occupied[i] > 0) {
				total += 1;
			}
		}
		for (int i = 0; i < all_available_table; i++) {		//this for loop finds the number of full table(occupied by number of table size eg.5) and total available seats
			all_available_seat += Table_Available[i];
			if (Table_Available[i] == 0) {
				full_table += 1;
			}
		}

		if (total == num_of_table && move != 'O') {
			auto_assign_table(move, customer, count_customer, all_available_table, full_table, all_available_seat, num_of_table);    // Assign the table if all tables are occupied
			continue;
		}
		cout << "Number of available table: " << all_available_table - full_table << endl;
		cout << "Number of full table: " << full_table << endl;
		cout << "Number of available seat: " << all_available_seat << endl;
		cout << "Number of occupied seat: " << num_of_table * table_size - all_available_seat << endl;

		fout << "Number of available table: " << all_available_table - full_table << endl;
		fout << "Number of full table: " << full_table << endl;
		fout << "Number of available seat: " << all_available_seat << endl;
		fout << "Number of occupied seat: " << num_of_table * table_size - all_available_seat << endl;

		show_table();

		cout << endl;
		fout << endl;

		cout << "  * Input E to exit   " << endl;
		cout << "  * Input I to occupy a table   " << endl;
		cout << "  * Input O to release a table   " << endl;
		cout << endl;
		cout << "What action? (I/O) ";

		fout << "  * Input E to exit   " << endl;
		fout << "  * Input I to occupy a table   " << endl;
		fout << "  * Input O to release a table   " << endl;
		fout << endl;
		fout << "What action? (I/O) ";

		cin >> move;
		fout << move << endl;

		if (move == 'I') {
			Occupying_table(customer, all_available_seat, num_of_table, table_num, count_customer, all_available_table, full_table);

		}
		if (move == 'O') {
			Releasing_table(customer, table_num);
		}
		cout << "===========================================================================" << endl;
		cout << endl;
		fout << "===========================================================================" << endl;
		fout << endl;

		count_customer++;

		cout << endl;
		fout << endl;
	}
}
/*This function show the staff name and their ID*/
void Staffs_func() {

	cout << "Name: Chan Kam Chuen\tUID: 3035558197" << endl;
	cout << "Name: Ho Sui Ting\tUID: 3035569330" << endl;
	// ************************************************************
	fout << "Name: Chan Kam Chuen\tUID: 3035558197" << endl;
	fout << "Name: Ho Sui Ting\tUID: 3035569330" << endl;
	// ************************************************************
}
/*This function allow the changing of setting of table size and the number of table*/
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

		fout << endl;
		fout << "What time is it?" << endl;
		fout << "------------------------------------------" << endl;
		fout << "                      Summer Time" << endl;
		fout << "(1) 07:00 - 11:30 - Number of table: 10 Table size: 4" << endl;
		fout << "(2) 12:00 - 14:30 - Number of table: 20 Table size: 5" << endl;
		fout << "(3) 15:00 - 18:00 - Number of table: 10 Table size: 4" << endl;
		fout << "(4) 18:00 - 21:30 - Number of table: 20 Table size: 5" << endl;
		fout << "                      Winter Time" << endl;
		fout << "(5) 07:00 - 11:30 - Number of table: 15 Table size: 5" << endl;
		fout << "(6) 12:00 - 14:30 - Number of table: 20 Table size: 6" << endl;
		fout << "(7) 15:00 - 18:00 - Number of table: 15 Table size: 5" << endl;
		fout << "(8) 18:00 - 21:30 - Number of table: 25 Table size: 6" << endl;
		fout << endl;
		fout << "(9) Exit" << endl;
		fout << "Enter the choice: ";

		cin >> prog_choice;
		fout << prog_choice << endl;

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
/*Main function that read choice from user and pass to different function after that*/
int main()
{
	int prog_choice, num;

	fout.open("Output.txt");
	if (fout.fail()) {
		cout << "Error! Output.txt";
		exit(1);
	}

	do {
		cout << endl;
		cout << "XYZ Restaurant -- Table management system" << endl;
		cout << "------------------------------------------" << endl;
		cout << "(1) Start" << endl;
		cout << "(2) Setting" << endl;
		cout << "(3) Staffs" << endl;
		cout << "(4) Exit" << endl;
		cout << "Enter the choice: ";
		// ************************************************************
		fout << "XYZ Restaurant -- Table management system" << endl;
		fout << "------------------------------------------" << endl;
		fout << "(1) Start" << endl;
		fout << "(2) Setting" << endl;
		fout << "(3) Staffs" << endl;
		fout << "(4) Exit" << endl;
		fout << "Enter the choice: ";
		// ************************************************************
		cin >> prog_choice;
		fout << prog_choice << endl;

		switch (prog_choice) {
		case 1: start_func(); break;
		case 2: setting_func(); break;
		case 3: Staffs_func(); break;
		case 4: break;
		default:
			cout << "Please enter choice 1 - 4 only." << endl;
			// ************************************************************
			fout << "Please enter choice 1 - 4 only." << endl;
			// ************************************************************
			break;
		}
	} while (prog_choice != 4);

	cout << "Program terminates. Good bye!" << endl;
	// ************************************************************
	fout << "Program terminates. Good bye!" << endl;
	// ************************************************************
	fout.close();
	delete Table_Occupied, Table_Available;
	return 0;
}
