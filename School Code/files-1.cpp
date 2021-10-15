#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
using namespace std;

struct Book {
    string title;
    int year;
    vector<int> age;

    Book(string name, double cost, vector<int> age) {
        this->title = name;
        this->year = cost;
        this->age = age;
    }

    string convert_to_string() {
        return title + ";" + to_string(year) + ";" + to_string(age[0]) + "," + to_string(age[1]);
    }

    bool fits(int value) {
        return value >= age[0] && value <= age[1];
    }
};

static Book parse_from_string(string value) {
    vector<string> parts;
    while (value.find(";") != -1) {
        parts.push_back(value.substr(0, value.find(";")));
        value = value.substr(value.find(";") + 1, value.size());
    }
    if (value.size() != 0) parts.push_back(value);

    int comma = parts[2].find(",");
    vector<int> age = {stoi(parts[2].substr(0, comma)), stoi(parts[2].substr(comma + 1, parts[2].size() - 1)) };

    return Book(parts[0], stoi(parts[1]), age);
}

const vector<string> names = {"Toy Soldier", "Toy Doll", "Toy Car", "Lego Set", "Building Blocks", "Ball", "Tetris", "NERF Gun"};

int main() {
    cout << "Input amount of toys to generate: ";
    int n; cin >> n;
    if (!cin || n == 0) {
        cout << "Invalid input";
        return -1;
    }
    cout << "Generating toys and writing them into file..." << endl;

    srand((unsigned)time(NULL));
    ofstream file_write("text.txt");
    for (int i = 0; i < n; i++) {
        int a1 = 3 + rand() % 15;
        int a2 = a1 + 1 + rand() % (18 - a1);
        Book toy = Book(names[rand() % names.size()] + " " + to_string(i), 
            50 + rand() % 4951, {a1, a2});
        file_write << toy.convert_to_string() << endl;
    }
    file_write.close();
    cout << "File created successfully" << endl << endl;

    ifstream file_read("text.txt");
    string line;

    cout << "Answer A:" << endl;
    while (getline(file_read, line)) {
        Book toy = parse_from_string(line);
        if (toy.year <= 400 && toy.fits(8)) cout << toy.title << endl;
    }
    file_read.close();

    file_read.open("text.txt");
    int m = -1;
    while (getline(file_read, line)) {
        Book toy = parse_from_string(line);
        m = max(m, toy.year);
    }
    cout << endl << "Answer B: " << m << endl << endl;
    file_read.close();

    file_read.open("text.txt");
    cout << "Answer C:" << endl;
    while (getline(file_read, line)) {
        Book toy = parse_from_string(line);
        if (toy.fits(4) && toy.fits(10)) cout << toy.title << ", " << toy.year << endl;
    }
    file_read.close();
}