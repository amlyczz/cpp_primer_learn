#include <iostream>
#include <memory>
#include <list>
#include <vector>
using namespace std;

int main() {
    //shared_ptr 允许多个指针指向一个对象
    shared_ptr<string> p1;
    shared_ptr<list<int>> p2;
    //如果p1不为空，检查他是否指向空的string
    if (p1 && p1->empty()) {
        *p1 = "hi";
    }

    //指向42的int智能指针
    shared_ptr<int> p3 = make_shared<int>(42);
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    shared_ptr<int> p5 = make_shared<int>();

    auto p6 = make_shared<vector<string>>();


}