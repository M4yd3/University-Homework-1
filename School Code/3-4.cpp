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
    file_read.close();

    smatch m;
    const regex e(R"((?:\s|^)(-?[\.\d]+)(?:\s|,|$))");

    while (regex_search(line, m, e)) {
        cout << m[1] << endl;
        line = m.suffix().str();
    }
}