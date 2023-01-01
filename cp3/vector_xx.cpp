#include <iostream>
#include <vector>

using namespace std;

/*
 * vector
 * */
int main() {
    //初始化
    vector<int> v1 = {0, 1};
    vector<int> v2 = v1;
    vector<int> v3(v2);
    cout << "v1: " << v1.data() << endl;
    cout << "v2: " << v2.data() << endl;
    cout << "v3: " << v3.data() << endl;
    vector<string> v4(10, "aahph");
    for (auto item: v4) {
        cout << "item: " << item << endl;
    }
    vector<int> v5(5);
    for (auto value: v5) {
        cout << "intialize value: " << value << endl;
    }
    vector<int> v6(10, 1);
    vector<int> v7{10, 12, 123, 345, 567, 12, 321};
    cout << "v6: " << endl;
    for (auto v: v6) {
        cout << v << " ";
    }
    cout << endl << "v7: " << endl;
    for (auto v: v7) {
        cout << v << " ";
    }
    cout << endl;
    //输入
    /*vector<string> text;
    string word;
    while (cin >> word) {
        text.push_back(word);
    }
    cout << "text: " << endl;
    for (auto v: text) {
        cout << v << endl;
    }
    vector<string>::size_type size = text.size();
    cout << "size: " << size << endl;*/
    auto bbegin = v7.begin();
    auto eend = v7.end();

    //迭代器
    string s = "something stupid";
    cout << "迭代器,s: " << endl;
    for (auto item = s.begin(); !isspace(*item) && item != s.end(); item++) {
        cout << *item << endl;
    }
    vector<string> vec1{"a", "b", "", "c", "d"};
    //获得只读迭代器
    auto cbegin = vec1.cbegin();
    auto cend = vec1.cend();
    //迭代器类型
    vector<string>::iterator bb = vec1.begin();
    vector<string>::const_iterator cbb = vec1.cbegin();

    //解引用
    for (auto cur = vec1.begin(); cur != vec1.end(); cur++) {
        cout << "item: " << *cur << " 是否为空" << (*cur).empty() << endl;
    }

    //迭代器运算
    cout << "bbegin+1: " << (*(cbb + 1)) << endl;

    //迭代器大小比较(位置)
    vector<string>::iterator bp1 = bb + 1;
    vector<string>::iterator bp2 = bb + 2;
    cout << "bp1 < bp2 ? " << (bp1 < bp2) << endl;

    //vector 与数组
    int arr[] = {1, 2, 3, 4};
    vector<int> varr(begin(arr), end(arr));
}