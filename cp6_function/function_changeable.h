using arrT = int[10];

void err_msg(std::initializer_list<std::string> list);

void foo(std::string, ...);

void foo(...);

std::vector<std::string> process(const std::string &s);

arrT *func(int i);

//和上面一样返回数组的指针
int (*func(int i))[10];

//和上面一样 返回值用auto表示，箭头右侧代表返回类型
auto func(int i) -> int (*)[10];

//默认实参
std::string def_func(int a = 10, char b = 'g', std::string= "ac", std::vector<std::string> vec = {"ab", "cd"});

inline const std::string &shorterString(const std::string &s1, const std::string &s2);

constexpr int fooz();
