#include <iostream>
#include <windows.h>
#include <array>
#include <time.h>
using namespace std;

int main() {
	srand((unsigned)time(NULL));

	array<array<bool, 10>, 10> field;
	array<array<bool, 10>, 10> field_future;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j] = rand() % 5 == 0;
		}
	}

	while (true) {
		for (array<bool, 10> a : field) {
			for (bool b : a) {
				cout << (b ? 'X' : ' ');
			}
			cout << endl;
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				bool cell = field[i][j];
				int n = 0;

				for (int k = max(i - 1, 0); k <= min(i + 1, 20); k++) {
					for (int l = max(j - 1, 0); l <= min(j + 1, 20); l++) {
						if (!(k == i && l == j) && field[k][l]) n++;
					}
				}

				 
			}
		}

		Sleep(500);
		system("cls");
	}
}