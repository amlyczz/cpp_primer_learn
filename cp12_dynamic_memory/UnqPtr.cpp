#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<double> p1;
    unique_ptr<int> p2(new int(12));

    //不支持拷贝或赋值

    //将所有权从p3转移给p4
    unique_ptr<string> p3(new string("dsfsd"));
    unique_ptr<string> p4(p3.release());

    unique_ptr<string> p5(new string("RTEs"));
    //所有权转移给p5，p5释放掉了内存
    p3.reset(p5.release());

    //传递删除器
    //p指向类型为objT的对象，使用类型为delT的对象的fcn函数来释放objT对象
//    unique_ptr<objT, delT> p(new objT, fcn);


}