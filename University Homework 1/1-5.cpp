#include <iostream>
using namespace std;

int main() {
	system("chcp 1251");
	bool t, c, l;
	cout << "Enter the time of day: 0 - night, 1 - day\n";
	cin >> t;
	cout << "Enter the state of the curtains: 0 - closed, 1 - open\n";
	cin >> c;
	cout << "Enter the state of the lamp: 0 - off, 1 - on\n";
	cin >> l;
	
	if (!cin) {
		cout << "\033[1;31mWrong input\033[0m\n";
		return -1;
	} else {
		if ((t && c) || l) {
			cout << "The room is light";
		} else {
			cout << "The room is dark";
		}
	}
}