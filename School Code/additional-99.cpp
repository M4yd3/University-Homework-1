#include <iostream>
#include <regex>
using namespace std;

int main() {
	srand((unsigned)time(NULL));

	string num = "";
	for (int i = 0, r; i < 4; i++) {
		do {
			r = rand() % 10;
		} while (num.find(to_string(r)) != -1 || (i == 0 && r == 0));
		num += to_string(r);
	}

	int input, pluses, minuses;
	string input_str;
	while (true) {
		cin >> input;
		if (!cin || input > 9999 || input < 1000) continue;
		input_str = to_string(input);
		pluses = minuses = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (input_str[i] == num[j]) {
					if (i == j) pluses++;
					else minuses++;
				}
			}
		}

		if (pluses == 4) {
			cout << "You won!";
			break;
		}
	
		cout << pluses << " +, " << minuses << " -" << endl;
	}
}