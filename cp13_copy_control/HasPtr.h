class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
            ps(new std::string(s), i(0) { }    // new返回的是一个对象的指针

    // 像值一样拷贝，通过p对象的值生成一个自己的副本，二者相互独立
    HasPtr(const HasPtr &p):
            ps(new std::string(*p.ps)), i(p.i) { }

    HasPtr& operator=(const HasPtr &);
    ~HasPtr() { delete ps; }
private:
    std::string *ps;    // 这个指针的拷贝，决定了像值还是像指针
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);   // 先拷贝rhs的值，再删除rhs的值，因为可能出现自赋值的情况
    delete ps;                         // ps将会有新的值，需要释放旧内存
    ps = newp;                         // ps的新值
    i = rhs.i;
    return *this;
}