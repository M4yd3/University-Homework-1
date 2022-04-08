#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

int main() {
    ofstream file_write("text.txt");
    string input;
    cout << "Input 10 numbers: " << endl;
    getline(cin, input);

    string new_line(""), temp = input;
    int size(0);
    smatch m;
    const regex e(R"((?:\s|^)(-?(?:\d+(?:\.\d+)?|\.\d+))(?=\s|,|$))");

    for (int i = 0; i < 10 && regex_search(temp, m, e); i++) {
        new_line += m[1];
        size++;
        temp = m.suffix().str();
    }

    if (new_line != regex_replace(input, regex(R"( )"), "") || size != 10) {
        cout << "Invalid input";
        return -1;
    }

    file_write << input;
    file_write.close();

    ifstream file_read("text.txt");
    string line;
    getline(file_read, line);
    file_read.close();
    
    double sum(0);
    while (regex_search(line, m, e)) {
        sum += stod(m[1]);
        line = m.suffix().str();
    }
    cout << sum;
}
