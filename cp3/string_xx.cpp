#include <iostream>

using namespace std;

int main() {
    //初始化
    string s1;
    string s2(s1);
    string s3 = "ssss3";
    string s4("vads4");
    string s5 = s3;     //拷贝初始化
    string s6(5, '6');
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;
    cout << "s6: " << s6 << endl;
    cout << "s3[3]:" << s3[3] << endl;

    //输入输出
    /*string line;
    while (getline(cin, line)) {
        if (!line.empty()) {
            string::size_type size = line.size();
            auto  size2 = line.size();
            cout << "line size_type: " << size << endl;
            cout << "line auto size2: " << size2 << endl;
            cout << line << endl;
        }
    }*/

    string s7 = "abc";
    string s8 = s7;
    cout << (s7 == s8) << endl;
    cout << s8 << endl;

    //遍历
    string sentence = "How dare you,Fuck off!!!~";
    /*for (auto item: sentence) {
        cout << "item:" << item << endl;
    }*/
    //统计标点符号数量
    /*decltype(sentence.size()) count = 0;
    for (auto item: sentence) {
        if (ispunct(item)) {
            count++;
            cout << "标点:" << item << endl;
        }
    }
    cout<<"标点数量："<<count<<endl;*/

    //改变字符串中的某个字符
    for (auto &c: sentence) {
        c = toupper(c);
    }
    cout << "sentense:" << sentence << endl;

}