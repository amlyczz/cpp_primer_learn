#include <iostream>
#include <functional>
#include <map>
#include "../cp7_class/Sales_data.h"
#include "StrVec.h"

using namespace std;


//重载<<
ostream &operator<<(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << endl;
    return os;
}

//重载>>
istream &operator>>(istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    return is;
}

//算术运算符
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

//相等运算符
bool operator==(const Sales_data &l, const Sales_data &r) {
    return l.isbn() == r.isbn();
}

//关系运算符
bool operator<(const Sales_data &l, const Sales_data &r) {
    return l.isbn() < r.isbn();
}

//可调用对象
int addi(int i, int j) { return i + j; }

auto modi = [](int i, int j) { return i % j; };

struct divi {
    int operator()(int up, int dow) {
        return up / dow;
    }
};

int main() {
    StrVec obj;
    cout << "obj(1): " << obj(1) << endl;

    function<int(int, int)> f1 = addi;      //函数指针
    function<int(int, int)> f2 = divi();    //函数对象类的对象
    function<int(int, int)> f3 = modi;       //lambda

    cout << f1(4, 2) << endl;
    cout << f2(4, 2) << endl;
    cout << f3(4, 2) << endl;
    int (*fp)(int, int) = addi;

    map<string, function<int(int, int)>> binops = {
            {"+",  addi},
            {"-",  std::minus<int>()},
            {"/",  divi()},
            {"*",  modi},
            {"++", fp}
    };
    cout << "binops[\"+\"](6, 2): " << endl;
    cout << binops["+"](6, 2) << endl;


}