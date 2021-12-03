#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <array>
using namespace std;

int main() {
	srand((unsigned)time(NULL));

	// Fill work.dat with initial random data.
	ofstream home("work.dat");
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			string x = rand() % 2 ? "X" : "O";
			home << x;
		}
		home << endl;
	}
	home.close();

	array<array<int, 21>, 21> present;
	array<array<int, 21>, 21> future;
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			cout << endl;
		}
	}

	ofstream out("work.out");
}