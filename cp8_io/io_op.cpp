#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream out1, out2;
//    out1 = out2   不能拷贝io流
    int ival;
    cin >> ival;
    cout << "fail(): " << cin.fail() << endl;
    auto old_state = cin.rdstate();
    cin.clear();
    cin.setstate(old_state);
    //复位failbit和badbit
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);

    cout << "Hi!" << flush;    //刷新缓冲区
    cout << "啊!" << ends;     //填充一个空字符，刷新缓冲区
    cout << endl;
    cout << unitbuf;    //所有输出操作都会立即刷新缓冲区
    cout << nounitbuf;   //回到正常模式

    cin.tie(&cout); //输入输出流关联起来
    ostream *old_tie = cin.tie(nullptr);
    cin.tie(&cerr);

}