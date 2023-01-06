#include <iostream>

using namespace std;

class Foo {
public:
    Foo();

    Foo(const Foo &);    //拷贝构造函数

    Foo &operator=(const Foo &);  // 赋值运算符

    ~Foo();  // 析构函数
//我们可以通过将拷贝控制成员定义为=default来显式地要求编译器生成合成的版本。
//    Sales (const Sales&) = default;
//    Sales operator=(const Sales&) = default;

//    Sales(const Sales&) = delete;            // 阻止拷贝
//    Sales &operator=(const Sales&) = delete; // 阻止赋值

    /*
     *移动构造函数从对象“窃取”资源而不是拷贝资源。
     * 移动构造函数第一个参数是一个类类型的右值引用，任何额外的参数都必须有默认实参。
     * 除了完成资源移动，移动构造函数还必须确保移动后源对象处于这样一个状态——销毁它是无害的。
     * 一旦完成资源移动，资源所有权属于新对象，源对象默认为可以销毁了。
     * */
    Foo(Foo &&ori) noexcept {   // 移动操作不应该抛出任何异常
        //ori.a = ori.b = nullptr;
    }

    Foo &operator=(Foo &&ori) noexcept{     //移动赋值运算符
//        free();
        //赋值
        //ori.a = ori.b = nullptr;
    }

};

int main() {
    string dots(10, '.');              // 直接初始化
    string s(dots);                    // 直接初始化
    string s1 = dots;                  // 拷贝初始化
    string s2 = "9999-99-9";           // 拷贝初始化
    string s3 = string(10, '.');       // 拷贝初始化

    /*
     * 所谓右值引用就是必须绑定到右值的引用，我们通过&&而不是&来获得右值引用。
     * 右值引用只能绑定到一个将要销毁的对象，因此，我们可以将右值引用的资源“窃取”到另一个对象中。
     * 左值引用不能绑定到字面常量（右值）、右值表达式（右值）；而右值引用不能绑定到左值上：
     * */
    /*
     * 左值具有持久状态，变量是左值；右值要么是字面常量，要么就是过程中临时创建的对象。
     * 这意味着：右值引用的代码可以自由接管所引用的对象的资源。
     * */

    int i = 4;
    int &r = i;        // 正确，i是左值
//    int &r1 = i * 4;    // 错误，i * 4 返回的是16，是一个右值
//    int &&rr = i;      // 错误，i是左值
    int &&rr1 = i * 4;  // 正确，这是一个右值

    //左值转换为右值引用类型
    int &&rr3 = std::move(i);

}

