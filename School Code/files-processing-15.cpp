#include <iostream>
#include <fstream>
#include <regex>
#include <windows.h>
using namespace std;

int main() {
	cout << "Enter your file content:" << endl;
	string input;
	getline(cin, input);

	ofstream file_write("text.txt");
	file_write << input;
	file_write.close();

	cout << "Input your word: ";
	string word; cin >> word;

	ifstream file_read("text.txt");
	getline(file_read, input);
	do {
		input = regex_replace(input, regex(R"(\s\s)"), " ");
	} while (input.find("  ") != -1);
	smatch m; 
	regex r("((\\s|^)" + word + "(\\s|$))");

	if (regex_search(input, m, r)) {
		int c = 1 + (m.prefix() != "");
		for (char i : m.prefix().str()) if (i == ' ') c++;
		cout << "Your word is number " << c;
	} else {
		cout << "Your word was not found";
	}
	file_read.close();
}