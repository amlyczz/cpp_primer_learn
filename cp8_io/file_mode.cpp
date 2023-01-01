#include <fstream>
#include <iostream>

using namespace std;

int main() {
    //file1 都被截断
    ofstream out("file1");
    ofstream out2("file1", ofstream::out);
    ofstream out3("file1", ofstream::out | ofstream::trunc);

    //file2保留文件内容
    ofstream app("file2", ofstream::app);
    ofstream app2("file2", ofstream::out | ofstream::app);

    //每次调用open都会确定文件模式
    ofstream out4;
    out4.open(R"(B:\CppProject\cpp_primer_learn\cp8_io\scratchpad.out)");    //输出和截断模式
    out4 << "输出和截断模式" << endl;
    out4.close();
    out4.open(R"(B:\CppProject\cpp_primer_learn\cp8_io\precious.out)", ofstream::app);    //追加
    out4 << "追加模式" << endl;
    out4.close();
}