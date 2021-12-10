#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <array>
using namespace std;

// 97 - 122, %26
char rand_char() { return (97 + rand() % 5); }

int cell_int(char cell) { return (int)cell - 48; }

int main() {
	srand((unsigned)time(NULL));
	
	// Fill work.dat with initial random data.
	ofstream work_dat("work.dat");
	fstream work_out("work.out");
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			char ch = rand_char();
			work_dat << ch << " ";
		}
		work_dat << endl;
	}
	work_dat.close();

	array<array<int, 21>, 21> present;
	array<array<int, 21>, 21> future;

	cout << "Enter number of generations: ";
	int steps; cin >> steps;
	if (!cin) return 1;

	char symbol = rand_char();
	ifstream fin("work.dat");
	cout << endl << "Generation 0" << endl;
	int c = 0;
	for (int i = 0; i < 21; i++) {
		char ch;
		for (int j = 0; j < 21 && fin >> ch; j++) {
			char cell = (ch == symbol ? '1' : 'x');
			work_out << cell << " ";
			cout << cell << " ";
			present[i][j] = cell;
			c += cell != 'x';
		}
		cout << endl;
		work_out << endl;
	}
	fin.close();

	cout << "Living cells: " << c << endl;

	for (int i = 0; i < steps && c != 0; i++) {
		cout << endl << "Generation " << i + 1;
		c = 0;
		cout << endl;
		work_out.clear();
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				char cell = present[i][j];
				if (cell == 'x') {
					cout << cell;
				}
				else {
					if (cell_int(cell) > 0 && cell_int(cell) < 11) {
						int n = 0;
						for (int k = max(i - 1, 0); k <= min(i + 1, 20); k++) {
							for (int l = max(j - 1, 0); l <= min(j + 1, 20); l++) {
								int t = cell_int(present[k][l]);
								if (!(k == i && l == j) && present[k][l] != 'x' && t >= 1 && t <= 11) n++;
							}
						}
						if (n == 2 || n == 3) {
							cell++;
							c++;
						}
						else cell = '0';
					}
					else if (cell_int(cell) == 0) {
						cell++;
						c++;
					}
					else if (cell_int(cell) == 11) cell = '0';
					cout << cell_int(cell);
				}
				cout << " ";
				future[i][j] = cell;
				work_out << cell << " ";
			}
			cout << endl;
			work_out << endl;
		}
		cout << "Living cells: " << c << endl;
		present = future;
	}
	if (c == 0) cout << endl << "Oh no! Everyone died!" << endl;
	work_out.close();
}