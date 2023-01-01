#include <fstream>
#include <iostream>
#include "../cp7_class/Sales_data.h"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream in(argv[1]);
    ofstream out;
    out.open(argv[2]);
    cout << argv[0] << " " << argv[1] << " " << argv[2] << endl;
    /*Sales_data total;
    if (read(in, total)) {
        Sales_data trans;
        while (read(in, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    } else {
        cerr << "No Data?!" << endl;
    }*/
    if (out) {
        string s;
        while (getline(in, s)) {
            out << s << endl;
        }
    } else {
        cout << "打开失败？！" << endl;
    }

}