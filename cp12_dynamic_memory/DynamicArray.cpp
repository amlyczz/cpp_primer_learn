#include <iostream>
#include <memory>

using namespace std;

int main() {
    //分配对象数组，pia指向第一个元素
    int *pia = new int[12];

    typedef int arrT[42];
    int *p = new arrT;

    int *pia2 = new int[10]; //10个未初始化
    int *pia3 = new int[10]();  //10个值初始化为0
    int *pia4 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //删除动态分配的数组
    delete[] pia;

    unique_ptr<int[]> up(new int[10]);
    up.release();

    for (size_t i = 0; i != 10; i++) {
        up[i] = i;
    }

    //为了使用shared_ptr 必须提供删除器
    shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });
    sp.reset();     //释放数组，使用删除器
    //遍历数组
    for (size_t i = 0; i != 10; i++) {
        *(sp.get() + i) = i;
    }





}