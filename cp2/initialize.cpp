#include <iostream>

using namespace std;

int main() {
    int unit1 = 0;
    int unit2 = {1};
    int unit3{2};   //cpp11
    int unit4(3);
    cout << "unit1:" << unit1 << endl;
    cout << "unit2:" << unit2 << endl;
    cout << "unit3:" << unit3 << endl;
    cout << "unit4:" << unit4 << endl;

    std::string empty;
    cout << "empty:" << empty << endl;
    //声明变量
    extern int define_var;
    cout << "define_var:" << define_var << endl;
}

