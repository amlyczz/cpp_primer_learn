#include <iostream>

using namespace std;

//函数指针(返回值，形参)
bool (*pf)(const string &s1, const string &s2);

bool lengthCompare(const string &s1, const string &s2);

void ff(int *a);

bool useFunctionPointer(bool (*pf)(const string &s1, const string &s2), const string &s1, const string &s2);

string::size_type sumLength(const string &, const string &);

string::size_type largeLength(const string &, const string &);

int main() {
    //函数指针
    pf = lengthCompare;    //pf指针指向lengthCompare函数
    pf = &lengthCompare;    //和上面等价
    cout << R"(pf("abc", "bcd"): )" << pf("abc", "bcd") << endl;
    cout << R"((*pf)("bcd", "abcd"): )" << (*pf)("bcd", "abcd") << endl;
    cout << R"(lengthCompare("abc", "bcd"): )" << lengthCompare("abc", "bcd") << endl;

    void (*pff)(int *a) = ff;

    //函数形参传递函数指针
    useFunctionPointer(pf, "abc", "bcd");

    //函数别名
    typedef bool Func(const string &s1, const string &s2);
    typedef decltype(lengthCompare) Func2;  //2个等价

    //函数指针别名
    typedef bool (*funcP)(const string &s1, const string &s2);
    typedef decltype(lengthCompare) &funcP2;   //2个等价

    //返回指向函数的指针
    using F = int(int *, int);  //是函数
    using FF = int (*)(int *, int);     //函数指针

    //从内向外阅读,f1返回指针后外面又有形参列表，说明返回的是函数指针
    //f1是返回函数指针的函数
    int (*f1(int))(int *, int);
    auto f1(int) -> int (*)(int *, int);    //和上面等价


    decltype(sumLength) *getFcn(const string &);

}

bool lengthCompare(const string &s1, const string &s2) {
    return s1 < s2;
}

void ff(int *a) {

}

bool useFunctionPointer(bool (*pf)(const string &s1, const string &s2), const string &s1, const string &s2) {
    cout << "pf: " << pf("eeee", "ddd") << endl;
}

string::size_type sumLength(const string &s1, const string &s2) {
    return s1.size() + s2.size();
}
