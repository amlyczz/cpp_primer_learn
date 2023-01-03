#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void biggies(vector<string> &words,
             vector<string>::size_type sz) {
    stable_sort(words.begin(), words.end(), isShorter);
    //迭代器指向第一个满足条件的元素
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &s) {
                          return s.size() >= sz;
                      });
    auto count = words.end() - wc;
    for_each(wc, words.end(),
             [](const string &s) { cout << s << " "; });
    cout << endl;
}

int main() {
    //查找
    vector<int> ivec{1, 2, 3};
    int val = 2;
    auto result = find(ivec.cbegin(), ivec.cend(), val);

    int ia[] = {24, 43, 34, 78, 12, 23};
    int *res = find(begin(ia), end(ia), val);

    //求和
    int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);

    //比较
    vector<int> ivec2{2, 3, 4};
    equal(ivec.cbegin(), ivec.cend(), ivec2.cbegin());

    //写入
    fill(ivec.begin(), ivec.end(), 0);

    //插入迭代器：返回与容器绑定的迭代器，
    // 通过迭代器赋值会调用push_back添加元素
    vector<int> vec;
    auto it = back_inserter(vec);
    *it = 42; //vec有一个元素：42

    //拷贝
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)];   //与a1大小相同
    //a1 拷贝到 a2
    auto ret = copy(begin(a1), end(a1), begin(a2));

    //把a1范围为0的值改为42
    replace(begin(a1), end(a1), 0, 42);
    //原序列不变，把替代后的序列添加到ivec2
    replace_copy(begin(ivec), end(ivec), back_inserter(ivec2), 0, 42);

    //排序
    vector<string> words = {"fox", "jumps", "over", "quick", "red", "slow", "the", "the"};
    //重复元素没有被删除，只是移到了最后面
    //标准库算法没有权力添加或删除元素
    unique(words.begin(), words.end());
    sort(words.begin(), words.end());
    sort(words.begin(), words.end(), isShorter);
    stable_sort(words.begin(), words.end(), isShorter);

    //lambda
    //[捕获列表](参数列表) -> 返回类型 {函数体}
    //捕获列表和函数体必不可少
    //捕获列表的值在lambda被创建时拷贝
    auto f = [] { return 42; };
    cout << f() << endl;

    auto shortF = [](const string &s1, const string &s2) {
        return s1.size() < s2.size();
    };
    stable_sort(words.begin(), words.end(), shortF);
    int param = 10;
    auto szz = [param](const string &s) {
        return s.size() >= param;
    };
    //find_if
    auto wc = find_if(words.begin(), words.end(), szz);

    //引用捕获
    size_t v1 = 42;
    auto f2 = [&v1] {
        return v1;
    };
    //隐式和显示捕获
    auto f3 = [&, v1] {
        cout << "sdf" << endl;
        return v1;
    };
    auto f4 = [=, &vec] {
        cout << "sdf" << endl;
        return v1;
    };

    //可变的拷贝变量
    auto f5 = [v1] mutable { return v1++; };
    //带有参数
    auto f6 = [](int i) { return i < 0 ? 0 : 1; };
    //指定返回类型
    auto f7 = [](int i) -> int {
        if (i < 0) {
            return -i;
        } else {
            return i;
        }
    };

    //如果lambda捕获列表为空，则可以用函数代替
    //  auto newCalable = bind(callable, arg_list);

    // auto g = bind(f, a, b, _2, c, _1);
    // =>  g(_1, _2) => f(a, b, _2, c, _1);


}