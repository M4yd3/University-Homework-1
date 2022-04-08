#include <iostream>
#include <fstream>
#include <string>
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
}