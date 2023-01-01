
#include <iostream>

using namespace std;

int main() {
    //类型别名
    typedef int tni;
    tni a = 123;
    cout << a << endl;
    //cpp 11
    using cnm = int;
    cnm aa = 321;
    cout << "using cnm aa: " << aa << endl;
    int i1 = 123;
    double i2 = 123.123;
    auto i3 = i1 + i2;
    cout << "i3: " << i3 << endl;
    //auto 一般忽略顶层const
    //指向常量的指针
    int i = 2;
    const int ci = i;
    auto pc = &ci;
    cout << "pc: " << *pc << endl;
    //希望推断出是顶层const，需要加const
    const auto f = ci;
    //引用的auto
    auto &go = ci;
    //不能为非常量引用绑定字面值
//    auto &h = 12;
    const auto &hh = 12;


}