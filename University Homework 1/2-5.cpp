#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "  x  | y " << endl;
	for (float x = -4; x <= 4; x += 0.5) {
		string temp = to_string(x);
		temp.resize(4, ' ');
		temp.shrink_to_fit();
		cout << temp << " | ";
		if (x - 1 != 0) {
			cout << ((x * x - 2 * x + 2) / (x - 1)) << endl;
		} else {
			cout << "NO VALUE" << endl;
		}
	}

}
