#include <iostream>

using namespace std;

int main() {
    int val = 1;
    int &ref = val;
    //引用不是对象，没有地址，指针不能指向引用
//    int *p = ref;
    double val1 = 12.32;
    double *p1 = &val1;
    double *p2 = p1;
    cout << "p2:" << *p2 << endl;
    double val2 = 32.32;
    p1 = &val2;
    cout << "p2:" << *p2 << endl;

    //多级指针
    int v1 = 1234;
    int *p = &v1;
    int **pp = &p;
    int ***ppp = &pp;

    cout << "p:" << *p << " pp: " << **pp << " ppp: " << ***ppp << endl;
    cout << "p的地址: " << *pp << endl;
    // 指针的引用（引用不是对象，不存在指向引用的指针）
    int *&refp = p;
    cout << "refp指向的指针的值：" << refp << endl;
    cout << "refp指向的指针指向的值：" << *refp << endl;
}