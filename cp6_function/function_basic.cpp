#include <iostream>

using namespace std;

string::size_type find_char(const string &sz, char c, string::size_type &occurs);

//数组
void print(const int[]);

void print(const int *);

void print(const int[10]);

void print(const int *beg, const int *end);

void print(int (&arr)[6]);

void print(int (*arr)[5], int rows);

//等价于上面这个
void print(int arr[][5], int rows);

int main() {
    string s = "cao ni ma le ge bi";
    string::size_type rst = s.size();
    auto size = find_char(s, 'i', rst);
    cout << "size: " << size << " occurs: " << rst << endl;

    //数组
    cout << "数组a: " << endl;
    int a[] = {1, 2, 3, 4, 5, 6};
    cout << "指针:" << endl;
    print(begin(a), end(a));
    cout << "引用:" << endl;
    print(a);

    //多维数组
    cout << "多维数组ma: " << endl;
    int ma[][5] = {
            {1, 2, 3, 4, 5},
            {2, 4, 6, 8, 10},
            {3, 1, 2, 5, 6}
    };
    cout << "第三行:";
    print(ma, 2);
}

string::size_type find_char(const string &sz, char c, string::size_type &occurs) {
    auto ret = sz.size();
    occurs = 0;
    for (decltype(ret) i = 0; i < ret; i++) {
        if (sz[i] == c) {
            occurs++;
        }
    }
    return ret;
}

void print(const int *beg, const int *end) {
    while (beg != end) {
        cout << *beg++ << endl;
    }
}

//限制了数组的大小
void print(int (&arr)[6]) {
    for (auto v: arr) {
        cout << v << endl;
    }
}

void print(int (*arr)[5], int rows) {
    arr += rows;
    for (auto p = *arr; p != *arr + 5; p++) {
        cout << *p << " ";
    }
    cout << endl;
}