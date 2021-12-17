#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <array>
using namespace std;

char rand_char(int n) { return ('a' + rand() % n); }

int cell_int(char cell) { return (int)cell - 48; }

char cell_out(char cell) { return "0123456789AB"[cell_int(cell)]; }

int main() {
	srand((unsigned)time(NULL));

	cout << "Enter number of letters [1-26]: ";
	int n;
	cin >> n;
	if (!cin || n < 1 || n > 26) return -1;
	
	ofstream work_dat("work.dat");
	fstream work_out("work.out");
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			char ch = rand_char(n);
			work_dat << ch << " ";
		}
		work_dat << endl;
	}
	work_dat.close();

	array<array<int, 21>, 21> present;
	array<array<int, 21>, 21> future;

	cout << "Enter number of generations: ";
	int steps;
	cin >> steps;
	if (!cin) return 1;

	char symbol = rand_char(n);
	ifstream fin("work.dat");
	cout << endl << "Generation 0" << endl;
	int c = 0;
	for (int i = 0; i < 21; i++) {
		char ch;
		for (int j = 0; j < 21 && fin >> ch; j++) {
			char cell = (ch == symbol ? '1' : 'X');
			present[i][j] = cell;
			work_out << cell << " ";
			cout << cell << " ";
			c += cell != 'X';
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
		work_out << endl;
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				char cell = present[i][j];
				if (cell == 'X') {
					work_out << "X ";
					cout << "X ";
				}
				else {
					if (cell_int(cell) < 11) {
						int n = 0;
						for (int k = max(i - 1, 0); k <= min(i + 1, 20); k++) {
							for (int l = max(j - 1, 0); l <= min(j + 1, 20); l++) {
								int t = cell_int(present[k][l]);
								if (!(k == i && l == j) && present[k][l] != 'X' && t >= 1) n++;
							}
						}
						if ((cell_int(cell) > 0 && n == 2 || n == 3) || (cell == 0 && n == 3)) {
							cell++;
							c++;
						}
						else cell = '0';
					}
					else cell = '0';
					work_out << cell_out(cell) << " ";
					cout << cell_out(cell) << " ";
				}
				future[i][j] = cell;
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