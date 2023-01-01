#include <iostream>

int f();

using namespace std;

int main() {
    // cpp 11新特性
    // 推断表达式类型，用这个推断出的类型定义变量，但不用该表达式初始化值
    decltype(f()) sum = 12;
    cout << "sum: " << sum << endl;
    const int ci = 1;
    //为 const int类型
    decltype(ci) x = 0;
    //为 const int&引用类型
    decltype(ci) y = x;
    //如果表达式是解引用类型，则推测的是引用类型
    int a = 123;
    int *p = &a;
    int b = 312;
//    delctype(*p) z =123;

}


int f() {
    return 1 + 2;
}