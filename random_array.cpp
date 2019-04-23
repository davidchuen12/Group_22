#include <iostream>
using namespace std;

const int MAX_VALUE = 100;

int main() {
	int Waiting_list[MAX_VALUE];
	for (int i = 0; i < MAX_VALUE; i++) {
		Waiting_list[i] = (rand() % 6 ) + 1;
		cout << Waiting_list[i] << " ";
	}
	return 0;
}
