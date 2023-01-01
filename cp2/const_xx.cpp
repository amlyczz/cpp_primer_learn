#include <iostream>

using namespace std;

static constexpr int size_z = 123;

int main() {
    //引用
    const int val = 1024;
    const int &ref = val;
    //非常量引用不能指向const常量
//    int &ref2 = val;
    //允许常量引用绑定非常量对象
    int val2 = 10234;
    const int &ref2 = val2;

    //指针
    const double pi = 3.1415;
    const double *p1 = &pi;
    //不能给pointer to const赋值
//    *p1 = 123.4;
    double val3 = 123.4;
    //pointer to const可以重新指向别的对象
    p1 = &val3;

    //常量指针(不变的是指针本身,而不是指向的值)
    int num = 231;
    int *const ptr = &num;
    //可以给指向的对象赋值
    *ptr = 321;
    int np = 0;
    //不能改变常量指针的指向
//    ptr = np;
    //指向常量(指向的对象不一定是常量)的常量指针
    const int *const pip = &num;

    //constexpr 常量表达式
    int size = 24;
    const int max_size = size;
    //constexpr由编译器检查是否是常量，constexpr变量一定是常量，并用常量表达式初始化
    constexpr int size_t = 123;
    constexpr int limit = size_t + 1;
//    constexpr int sd = sizet();
    //为常量指针
    constexpr int *q = nullptr;
    //pz为指向常量的常量指针
    constexpr const int *pz = &size_z;

}



constexpr int sizet() {
    return 0;
}