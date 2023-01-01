#include <string>
//#include "Window_mgr.h"

class Screen {
    //Window_mgr的成员可以访问Screen的私有部分
    friend class Window_mgr;
    //Window_mgr的clear函数可以访问Screen的私有部分
//    friend void Window_mgr::clear(ScreenIndex);

public:
    typedef std::string::size_type sst;

    Screen() = default;

    Screen(sst ht, sst wd) : height(ht), width(wd), contents(1, ' ') {}

    Screen(sst ht, sst wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }   //隐式内联
    inline char get(sst ht, sst wd) const;     //显示内联
    Screen &move(sst r, sst c);    //能在之后被设为内联
    void some_member() const;

    Screen &set(char);

    Screen &set(sst, sst, char);
    void setHeight(sst var);

    //根据对象是否是const 重载了display函数
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    sst cursor = 0;
    sst height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;  //即使在一个const对象中也能修改

    void do_display(std::ostream &os) const { os << contents; }
};

Screen::sst verify(Screen::sst);
void Screen::setHeight(sst var){
    verify(var);
}