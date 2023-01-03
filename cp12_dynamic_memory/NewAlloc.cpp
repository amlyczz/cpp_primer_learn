#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main() {
    //pi指向动态分配的/未初始化的无名对象
    int *pi = new int;
    cout << "*pi: " << *pi << endl;

    string *ps = new string;    //初始化为空string
    cout << "*ps: " << *ps << endl;

    int *pi2 = new int(1024);
    string *ps2 = new string(10, '8');
    vector<int> *pv = new vector<int>{0, 1, 2, 3, 4, 5, 7};

    int *pii = new int;     //值未定义
    int *piii = new int();   //（对内置类型有区别）值初始化为0，

    auto p1 = new auto(1);  //p1指向值为1的int

    const int *pci = new const int(1024);
    const string *pcs = new const string;

    delete pci;
    delete pcs;

    //shared_ptr 和 new 结合使用
    shared_ptr<int> sp1(new int(42));
    //如果指向该对象的共享指针不唯一，则拷贝该对象，让sp1指向它
    if (!sp1.unique()) {
        sp1.reset(new int(*sp1));
    }
    *sp1 += 12;

}