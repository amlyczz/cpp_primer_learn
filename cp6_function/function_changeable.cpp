#include <iostream>
#include <initializer_list>
#include <vector>
#include <cassert>
#include "function_changeable.h"
//#define NDEBUG
using namespace std;

int main() {
    //initializer_list 实参数量未知但类型相同
    //元素都是常量,initializer_list初始化时，和原副本共享元素
    initializer_list<string> list = {"logic error", "exception error", "range error"};
    err_msg(list);
    err_msg({"gg", "rubbish", "stupid"});
    err_msg({"what", "wtf"});

    cout << "vec: " << endl;
    string sb = "sb";
    vector<string> vec = process(sb);
    for (auto v: vec) {
        cout << v << endl;
    }

    //返回数组指针
    typedef int arrT1[10];
    using arrT = int[10];

    //constexpr
    auto fz = fooz();
    cout << "constexpr: " << fz << endl;

    //debug
    cout << "__FILE__ :" << __FILE__ << endl;
    cout << "__LINE__ :" << __LINE__ << endl;
    cout << "__func__ :" << __func__ << endl;

    assert(1>2);


}

void err_msg(initializer_list<string> list) {
    for (auto cur = list.begin(); cur != list.end(); cur++) {
        cout << *cur << endl;
    }
}

vector<string> process(const string &s) {
    if (s.empty()) {
        return {};
    } else {
        return {"sb", "hehe"};
    }
}

arrT *func(int i) {

}

int odd[] = {1, 3, 5, 7};
int even[] = {2, 4, 6, 8};

decltype(odd) *arrPtr(int i) {
    return (i % 2) ? &odd : &even;
}

//内联函数，再调用点直接展开函数内容，避免函数调用开销
inline const string &shorterString(const string &s1, const string &s2) {
    return s1.size() <= s2.size() ? s1 : s2;
}

//constexpr隐式指定为内联函数
constexpr int fooz() {
    return 42;
}