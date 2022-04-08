#include <iostream>
#include <fstream>
#include <regex>
#include <set>
#include <vector>
using namespace std;

int main() {
	cout << "Input symbols to exclude, in single line, without separators: ";
	string symbols_string, input; getline(cin, input);
	set<char> symbols;
	for (char c : input) symbols.insert(c);

	cout << "Symbols that will be removed: ";
	for (char c : symbols) {
		symbols_string += c;
		cout << "\"" << c << "\"" << " ";
	}

	symbols_string = regex_replace(symbols_string, regex(R"(\^)"), "\\^");
	regex r("([" + symbols_string + "]+)");


	ifstream file_read("text.txt");
	string line;

	cout << endl << "Removing symbols..." << endl;
	vector<string> lines;
	while (getline(file_read, line)) {
		lines.push_back(regex_replace(line, r, ""));
	}
	file_read.close();

	ofstream file_write("text.txt");
	for (string s : lines) file_write << s << endl;
	file_write.close();
	cout << "Done";
}