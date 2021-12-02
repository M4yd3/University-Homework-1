#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <regex>
using namespace std;

struct Toy {
    string author;
    string title;
    int year;

    Toy(string author, string title, double year) {
        this->author = author;
        this->title = title;
        this->year = year;
    }

    string convert_to_string() {
        return author + ";" + title + ";" + to_string(year);
    }
};

static Toy parse_from_string(string value) {
    vector<string> parts;
    while (value.find(";") != -1) {
        parts.push_back(value.substr(0, value.find(";")));
        value = value.substr(value.find(";") + 1, value.size());
    }
    if (value.size() != 0) parts.push_back(value);
    return Toy(parts[0], parts[1], stoi(parts[2]));
}

static string string_to_lower(string data) {
    string new_value;
    for (char i : data) {
        new_value += tolower(i);
    }
    return new_value;
}

int main() {
    const regex r(R"(^\w+\;\w+\;\d+$)");
    ofstream file_write("text.txt");
    string input;

    cout << "Input books like this: \"Author\";\"Title\";\"Year\"" << endl;

    int i(0);
    while (true) {
        cout << "Inputting book #" << i + 1 << endl;
        getline(cin, input);
        if (!regex_match(input, r)) {
            break;
        }
        Toy book = parse_from_string(input);
        file_write << book.convert_to_string() << endl;
        i++;
    }
    file_write.close();
    cout << "Input cancelled" << endl << endl;

    ifstream file_read("text.txt");
    string line;

    cout << "Input author:" << endl;
    string author; cin >> author;
    cout << "Input year:" << endl;
    int year; cin >> year;
    if (!cin) {
        cout << "Invalid input";
        return -1;
    }
    while (getline(file_read, line)) {
        Toy book = parse_from_string(line);
        if (string_to_lower(book.author) == string_to_lower(author) && book.year == year) 
            cout << "Your book is \"" << book.title << "\"" << endl;
    }
    file_read.close();

    file_read.open("text.txt");
    string s = "No such book";
    while (getline(file_read, line)) {
        Toy book = parse_from_string(line);
        if (string_to_lower(book.title).find("pascal") != -1)
            s = "Book's author and year are: " + book.author + ", " + to_string(book.year);
    }
    cout << endl << s << endl << endl;
    file_read.close();
}