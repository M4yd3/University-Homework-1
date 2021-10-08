#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
using namespace std;

struct Toy {
    string name;
    double cost;
    vector<int> age;

    Toy(string name, double cost, vector<int> age) {
        this->name = name;
        this->cost = cost;
        this->age = age;
    }

    string convert_to_string() {
        return name + ";" + to_string(cost) + ";" + to_string(age[0]) + "," + to_string(age[1]);
    }
};

static Toy parse_from_string(string value) {
    vector<string> parts;
    while (value.find(";") != -1) {
        parts.push_back(value.substr(0, value.find(";")));
        value = value.substr(value.find(";") + 1, value.size());
    }
    if (value.size() != 0) parts.push_back(value);
    
    if (parts.size() > 3) {
        int size = parts.size();
        string name;
        for (int i = 0; i < size - 2; i++) {
            name += parts[i];
        }
        parts.at(0) = name;
        parts.at(1) = parts[size - 2];
        parts.at(2) = parts[size - 1];
        parts.resize(3);
    }

    int comma = parts[2].find(",");
    vector<int> age = {stoi(parts[2].substr(0, comma)), stoi(parts[2].substr(comma + 1, parts[2].size() - 1)) };

    return Toy(parts[0], stoi(parts[1]), age);
}

int main() {
    //ofstream file_write("text.json");
    Toy toy = Toy("Soldier", 400, {3, 7});
    cout << parse_from_string("Sol;di;er;400;3,7").convert_to_string();

}