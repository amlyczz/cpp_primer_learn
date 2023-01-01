#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        char *begin = argv[i];
        for (auto b = begin; *b != '\0'; b++) {
            cout << *b;
        }
        cout << endl;
    }
}