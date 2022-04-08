#include <iostream>
#include <regex>
using namespace std;

int convert(char n) {
	int x = (int)n;
	if (x >= 97) {
		return (x - 97) * 2 + 2;
	} else {
		return (x - 65) * 2 + 1;
	}
}

int compare(char a, char b) {
	int a_int = convert(a);
	int b_int = convert(b);
	return a_int - b_int;
}

string sort_string(string in) {
	int changes = 1;
	while (changes != 0) {
		changes = 0;
		for (int i = 1; i < in.size(); i++) {
			if (compare(in[i - 1], in[i]) > 0) {
				swap(in[i - 1], in[i]);
				changes++;
			} 
		}
	}
	return in;
}

int main() {
	string input; // EOrzjluaNfDmOwkfQGUuVcAJwZbaZj
	cout << "Input line of 30 letters: ";
	cin >> input;
	if (!cin || input.size() != 30 || regex_search(input, regex(R"([^a-zA-Z]+)"))) {
		cout << "Wrong input";
		return -1;
	}
	input = sort_string(input);
	cout << input;
}