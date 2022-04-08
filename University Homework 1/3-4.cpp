#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main() {
    ofstream file_write("text.txt");
    string input;
    getline(cin, input);
    file_write << input;
    file_write.close();

    ifstream file_read("text.txt");
    string line;
    getline(file_read, line);        
    cout << line << endl;
    file_read.close();

    smatch m;
    const regex r(R"((?:\s|^)(-?(?:\d+(?:\.\d+)?|\.\d+))(?=\s|,|$))");
    while (regex_search(line, m, r)) {
        cout << m[1] << endl;
        line = m.suffix().str();
    }
}
