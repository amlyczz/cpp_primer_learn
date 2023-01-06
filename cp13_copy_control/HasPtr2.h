

#ifndef CPP_PRIMER_LEARN_HasPtr22_H
#define CPP_PRIMER_LEARN_HasPtr22_H

#endif //CPP_PRIMER_LEARN_HasPtr22_H
class HasPtr2 {
    friend void swap (HasPtr &, HasPtr&);  // swap可以访问HasPtr的数据成员

public:
    HasPtr2(const std::string &s = std::string()):
            ps(new std::string(s), i(0), use(new std::size_t(1) { }    //最开始有1个指针引用

    // 直接拷贝p中的ps指针，这两个指针指向同一个内存
    HasPtr2(const HasPtr2 &p):
            ps(p.ps), i(p.i), use(p.use) { ++*use; }

    HasPtr2& operator=(const HasPtr2 &);
    ~HasPtr22() {  }
private:
    std::string *ps;
    int i;
    std::size_t *use;    // 记录着有多少指针引用内存
};

HasPtr2& HasPtr2::operator=(const HasPtr2 &rhs)
{
    ++*rhs.use;          // 先增加use值，再减少use值，因为可能出现自赋值的情况
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;         // 直接拷贝指针
    use = rhs.use;
    i = rhs.i;
    return *this;
}

HasPtr2::~HasPtr2()
{
    if (--*use == 0) {  // 只有当引用为0时，才销毁
        delete ps;
        delete use;
    }
}

inline
void swap(HasPtr &a, HasPtr&b)
{
    using std::swap;
    swap(a.ps, b.ps);    // 交换指针，而不是string数据
    swap(a.i, b.i);
}