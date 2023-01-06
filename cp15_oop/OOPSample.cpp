#include <iostream>
#include <vector>
#include <memory>
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

class Base {
public:
    std::size_t size() const { return n; }

protected:
    std::size_t n;
};

class Derived : private Base {
public:
    //Derived 的用户将可以使用size成员,
    using Base::size;
protected:
    // 而Derived 的派生类将能使用n
    using Base::n;
};

int main() {
    Quote item;
    Bulk_quote bulk;
    Quote *p = &item;
    p = &bulk;
    Quote &r = bulk;

    //强制指定动态类型版本
    double d = p->Quote::net_price(2);


    //在容器中存储智能指针而非对象
    vector<shared_ptr<Quote>> basket;
    //放入Quote
    basket.push_back(make_shared<Quote>("0-231-421321-1", 50));
    //放入Bulk_quote
    basket.push_back(
            make_shared<Bulk_quote>("0-234-412122-4", 50, 10, .25)
    );
    cout << basket.back()->net_price(15) << endl;


}