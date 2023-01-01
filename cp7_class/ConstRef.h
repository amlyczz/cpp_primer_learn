class ConstRef {
public:
    ConstRef(int ii);

private:
    int i;
    const int ci;
    int &ri;
};

//不能在函数体初始化const和引用,只能在构造函数初始值阶段初始化值
ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i) {
    i = ii;
//    ci = ii;    ❌
//    ri = i;    ❌
}

class X{
    int i;
    int j;
public:
    //错误，编译器按照成员变量顺序初始化
    //i初始化时使用了未定义的j
    X(int val): j(val), i(j) {}
};