#include <iostream>
#include "Screen.h"

using namespace std;

int main() {
    Screen myScreen(5, 3);
    const Screen blank(5, 3);
    myScreen.set('#').display(cout);
    blank.display(cout);
}

inline Screen &Screen::move(sst r, sst c) {
    sst row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(sst r, sst c) const {
    sst row = r * width;
    return contents[row + c];
}

/*
 * 因为access_ctr 是mutable 所以即使this是个const也可以修改
 * */
void Screen::some_member() const {
    access_ctr++;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(sst r, sst col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}
