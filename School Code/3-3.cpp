#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream file_write("text.txt");
    file_write << "Random text";
    file_write.close();
    
    ifstream file_read("text.txt");
    string line;
    while (getline(file_read, line)) {
        cout << line << endl;
    }
    file_read.close();
    
    file_write.close();
}