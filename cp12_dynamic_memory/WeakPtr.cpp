#include <iostream>
#include <memory>

using namespace std;

int main() {

    //weak_ptr不控制所指对象生存期，不改变引用计数

    //初始化
    auto p = make_shared<int>(21);
    weak_ptr<int> wp(p);

    //lock()检查weak_ptr指向的对象是否存在,返回shared_ptr
    if(shared_ptr<int> np = wp.lock()){

    }

}