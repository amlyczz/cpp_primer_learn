#include <string>
#include <iostream>

using namespace std;
//聚合类，都是public，无构造函数，没有初始值，没有基类
struct Data {
    int iva;
    string s;
};

//字面值常量类
class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}

    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

    constexpr bool any() {
        return hw || io || other;
    }

    void set_io(bool b) { io = b; }

    void set_hw(bool b) { hw = b; }

    void set_other(bool b) { other = b; }

private:
    bool hw;
    bool io;
    bool other;
};

int main() {
    Data val1 = {0, "sb"};

    constexpr Debug io_sub = Debug(false, true, false);
    if (io_sub.any()) {
        cerr << "appropriate error msg" << endl;
    } else {
        cerr << "an error msg" << endl;
    }
}
