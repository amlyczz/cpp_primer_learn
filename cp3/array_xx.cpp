#include <iostream>
#include <cstring>

using namespace std;

int main() {
    //初始化
    unsigned cnt = 12;
    int arr[] = {1, 2, 3};
    int a2[12] = {1, 2, 3};
    //有10个整形指针的数组
    int *parr[10];
    string bad[cnt];
    //字符串赋值给数组结尾的\0会复制进去
    char a3[] = "abc";
    cout << "a3: " << endl;
    for (char c: a3) {
        cout << c << endl;
    }

    //数组间不能赋值
    int a4[] = {1, 2, 3};
//    int a2[] = a4;

    //数组的指针和引用
    int (*pa4)[3] = &a4;
    int (&ra4)[3] = a4;
    cout << "a4:" << endl;
    cout << "pointer: " << **pa4 << endl;
    cout << "ref: " << *ra4 << endl;

    //指针把数组推断为指针
    int *(&arrRef)[10] = parr;
    auto pointer4(a4);
    cout << "pointer4: " << *pointer4 << endl;
    //decltype不会把数组推断为指针
    decltype(a4) na4 = {2, 4, 6};
    cout << "na4: " << endl;
    for (auto v: na4) {
        cout << v << endl;
    }

    //cpp11 begin end
    int *begina = begin(a4);
    int *enda = end(a4);
    cout << "cpp11 begin end a4: " << endl;
    for (int *cur = begina; cur != enda; cur++) {
        cout << *cur << endl;
    }

    //多维数组
    //初始化
    int ma[2][3] = {
            {3, 2, 1},
            {7, 5, 6}
    };
    int ma2[2][3] = {1, 2, 3, 4, 5, 6};
    int ma3[2][3] = {
            {1}, {2}
    };
    int (&row)[3] = ma[1]; //将row引用到ma的第2行数组
    cout << "row: " << endl;
    for (auto v: row) {
        cout << v << endl;
    }

    for (auto &row: ma) {
        for (auto &item: row) {
            item = 1;
        }
    }
    cout << "ma: " << endl;
    for (auto &row: ma) {
        for (auto &item: row) {
            cout << item << endl;
        }
    }

    //多维数组与指针
    int ia[3][4];
    int (*p)[4] = ia;
    p = &ia[2];
    cout << "ma2: " << endl;
    //cpp11
    for (auto p = ma2; p != ma2 + 2; p++) {
        for (auto q = *p; q != *p + 3; q++) {
            cout << "value:" << *q << endl;
        }
    }
    //标准库
    for (auto p = begin(ma2); p != end(ma2); p++) {
        for (auto q = begin(*p); q != end(*p); q++) {
            cout << *q << endl;
        }
    }
}