#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main() {
    ofstream file_write("text.txt");
    string input = "1 12d d12 35 1-1  -21 -2 20.1 -03.13 .13 -.31 ..1 1.1";
    //getline(cin, input);
    file_write << input;
    file_write.close();

    ifstream file_read("text.txt");
    string line;
    getline(file_read, line);        
    cout << line << endl;
    file_read.close();

    smatch m;
    try {
        const regex e(R"((?:\s|^)(-?(?:\d+(?:\.\d+)?|\.\d+))(?=\s|,|$))");
        while (regex_search(line, m, e)) {
            cout << m[1] << endl;
            line = m.suffix().str();
        }
    } catch (exception e) {
        cout << "Error";
    }
}
