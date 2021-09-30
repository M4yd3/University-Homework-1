#include <iostream>
#include <windows.h>  
using namespace std;

const string stars(" * * * * * * * * ");
const string one = ("                 ");
const string two("                                  ");
const string three("                                                   ");

const int blue(31), red(64), white(240);

void set_line_color(int i, HANDLE hConsole) {
    if (i % 2 == 0) {
        SetConsoleTextAttribute(hConsole, red);
    }
    else {
        SetConsoleTextAttribute(hConsole, white);
    }
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 6; i++) {
        SetConsoleTextAttribute(hConsole, blue);
        cout << stars;
        set_line_color(i, hConsole);
        cout << two << endl;
    }

    SetConsoleTextAttribute(hConsole, blue);
    cout << one;
    SetConsoleTextAttribute(hConsole, red);
    cout << two << endl;

    for (int i = 0; i < 6; i++) {
        set_line_color(i + 1, hConsole);
        cout << three << endl;
    }

    SetConsoleTextAttribute(hConsole, 1);
}