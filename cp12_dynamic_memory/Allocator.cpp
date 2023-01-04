#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
    allocator<string> alloc;
    //为n个string分配内存
    auto const p = alloc.allocate(5);

    auto q = p; //指向最后构造的元素之后的位置
    alloc.construct(q++);   //在该内存构造空string
    //通过构造器构造元素
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");

    cout << "*p: " << *p << endl;
    cout << "*p+1: " << *(p + 1) << endl;
    cout << "*p+2: " << *(p + 2) << endl;
    //销毁元素，对对象执行析构函数
    while (q != p) {
        alloc.destroy(q--);
    }

    //释放内存
    alloc.deallocate(p, 5);

    vector<int> vi = {1, 2, 3};
    //拷贝和填充未初始化内存
    auto np = alloc.allocate(vi.size() * 2);
    //把vector全部元素拷贝到p开始的位置,返回最后元素之后的指针
    auto nq = uninitialized_copy(vi.begin(), vi.end(), p);
    //将剩余元素初始化为42
    uninitialized_fill_n(nq, vi.size(), 42);



}