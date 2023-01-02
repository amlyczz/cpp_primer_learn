#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include "../cp7_class/Sales_data.h"

using namespace std;

int main() {

    list<string> authors = {"Milton", "Shake", "Austen"};
    vector<const char *> articles = {"a", "an", "the"};

    list<string> list2(authors);
    forward_list<string> words(articles.begin(), articles.end());

    //array
    array<int, 10>::size_type i; //包括元素类型和大小
    array<int, 42> z;    //42个int数组

    array<int, 10> ia1;     //10个默认初始化的i
    //列表初始化
    array<int, 10> ia2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> ia3 = {42};  //第一个元素为42，剩余为0

    //array可对内置数组类型进行拷贝或对象赋值
    int digs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int cpy[10] = digs;   //❌数组不支持
    array<int, 10> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> copy = digits;

    //assign
    list<string> names;
    vector<const char *> oldstyle;
    names.assign(oldstyle.cbegin(), oldstyle.cend());

    //swap
    vector<string> svec1(10);
    vector<string> svec2(24);
    swap(svec1, svec2);

    //比较
    vector<int> v1 = {1, 3, 5, 7, 9, 12};
    vector<int> v2 = {1, 3, 9};
    vector<int> v3 = {1, 3, 5, 7};
    vector<int> v4 = {1, 3, 5, 7, 9, 12};
    cout << (v1 < v2) << endl;
    cout << (v1 < v3) << endl;
    cout << (v1 == v4) << endl;
    cout << (v1 == v2) << endl;

    //插入
    vector<string> svec;
    list<string> slist;

    //插入到迭代器之前一个元素
    slist.insert(slist.begin(), "Hello");
    svec.insert(svec.begin(), "Hello");
    cout << "slist: " << endl;
    for (auto v: slist) {
        cout << " " << v << endl;
    }
    cout << "svec: " << endl;
    for (auto v: svec) {
        cout << " " << v << endl;
    }
    //插入范围元素
    svec.insert(svec.end(), 10, "Anna");

    vector<string> v = {"quasi", "simba", "frollo", "scar"};

    slist.insert(slist.begin(), v.end() - 2, v.end());
    slist.insert(slist.end(), {"these", "words", "will"});

    /*list<string> lst;
    auto iter = lst.begin();
    //等价于push_front
    string word;
    while (cin >> word) {
        iter = lst.insert(iter, word);
    }*/

    //emplace 调用构造函数来进行插入操作
    vector<Sales_data> c;
    c.emplace_back("12321312312", 25, 15);
    cout << (*c.cbegin()).isbn() << endl;
    //和上面等价
    c.push_back(Sales_data("123123213", 25, 15));
    auto interc = c.begin();
    //使用默认构造函数
    c.emplace_back();
    //和insert类似
    c.emplace(interc, "12312321123");

    if (!slist.empty()) {
        //第一个元素的拷贝
        auto val = *slist.begin(), val2 = slist.front();

        auto last = slist.end();

        //最后一个元素的拷贝
        auto val3 = *(--last);
        auto val4 = slist.back();
    }

    //删除元素
    list<string> ilist = {"a", "b", "c", "de", "ed", "sb"};
    ilist.pop_front();
    ilist.pop_back();

    //删除奇数元素
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7};
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it % 2) {
            //删除迭代器所指元素，并返回下一个元素
            it = lst.erase(it);
        } else {
            it++;
        }
    }

    //删除全部元素
    slist.erase(slist.begin(), slist.end());

    //forward_list
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7};
    //删除奇数
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) {
            //删除prev之后的一个元素，并返回删除元素后一个元素的迭代器
            curr = flst.erase_after(prev);
        } else {
            prev = curr;
            curr++;
        }
    }

    //改变尺寸
    list<int> zlist(10, 42);    //10个42
    zlist.resize(15);   //5个0添加到末尾
    zlist.resize(25, -1);   //10个-1添加到末尾
    ilist.resize(5);    //删除末尾20个元素

    //删除偶数，复制奇数
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            iter += 2;
        } else {
            iter = vi.erase(iter);
        }
    }



}