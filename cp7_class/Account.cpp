#include <iostream>
#include "Account.h"

using namespace std;
//定义并初始化静态成员
double Account::interestRate = 0.01;

int main() {
    //访问静态
    double r = Account::rate();
    Account ac1;
    Account *ac2 = &ac1;
    r = ac1.rate();
    r = ac2->rate();
    cout << "interestRate: " << Account::rate() << endl;

}

