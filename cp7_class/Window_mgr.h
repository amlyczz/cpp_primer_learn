#include <vector>
#include "Screen.h"

using ScreenIndex = std::vector<Screen>::size_type;

class Window_mgr {
public:
    void clear(ScreenIndex);

    ScreenIndex addScreen(const Screen &);

private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    //改变Screen的私有部分
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex addScreen(const Screen &screen) {
    screens.push_back(s);
    return screens.size() - 1;
}
