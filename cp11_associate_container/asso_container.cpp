#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include "../cp7_class/Sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

void word_transform() {
    map<string, string> wdMap = {
            {"k",   "okay?"},
            {"y",   "why"},
            {"r",   "are"},
            {"u",   "you"},
            {"pic", "picture"},
            {"thk", "thanks!"},
            {"18r", "later"},
    };
    string text("k y r u pic thk s 18r");
    cout << "text: " << endl;
    istringstream txStream(text);
    string word;
    bool firstWd = true;
    while (txStream >> word) {
        if (firstWd) {
            firstWd = false;
        } else {
            cout << " ";
        }
        cout << wdMap[word] << endl;
    }

}


int main() {
    //map
    map<string, size_t> word_count;
    /*string word;
    while (cin >> word) {
        word_count[word]++;
    }
    for (const auto &w: word_count) {
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times " : " time ") << endl;
    }*/
    map<string, string> authors = {
            {"Joyce",   "James"},
            {"Austen",  "June"},
            {"dickens", "Charles"}
    };
    vector<string> svec = {"a", "a", "b", "c", "c", "d", "e", "f", "F"};
    //set
    set<string> setz(svec.cbegin(), svec.cend());
    cout << "set: " << endl;
    for (auto &c: setz) {
        cout << c << " ";
    }
    cout << endl;

    multiset<string> mulSet(svec.cbegin(), svec.cend());
    cout << "mulSet: " << endl;
    for (auto &c: mulSet) {
        cout << c << " ";
    }
    cout << endl;

    //bookstore中多条记录可以有相同的isbn
    //元素以isbn顺序排列
    multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);

    //pair
    pair<string, string> author2{"James", "Joyce"};
    cout << "pair:" << author2.first << " " << author2.second << endl;

    //k,v类型
    set<string>::value_type v1; //string
    set<string>::key_type k1;   //string

    map<string, int>::value_type v2; //pair<cosnt string, int>
    map<string, int>::key_type k2; //string
    map<string, int>::mapped_type m3; //int

    //迭代器
    //为value_type类型 => pair
    auto map_it = word_count.begin();
    cout << map_it->first;
    cout << " " << map_it->second;
//    map_it->first = "new key";  ❌ key为const
    ++map_it->second;

    word_count.insert({"sdf", 1});
    word_count.insert(make_pair("df", 2));
    word_count.insert(pair<string, size_t>("fds", 3));
    word_count.insert(map<string, size_t>::value_type("gs", 4));


    multimap<string, string> auths;
    auths.insert({"Barth, Jaon", "Sot-Weed Factor"});
    auths.insert({"Barth, John", "Jsdffd lwj"});

    //删除元素
    auto cnt = auths.erase("Barth, Jaon");

    word_count["asdf"] = 1;

    cout << "authors[\"Joyce\"]" << authors["Joyce"] << endl;

    set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto iter = iset.find(0);

    word_transform();
}