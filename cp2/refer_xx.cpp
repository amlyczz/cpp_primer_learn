#include <iostream>

using namespace std;

int main(){
    int ival = 123;
    //引用，必须被初始化
    int &refVal = ival;
    cout<<"refval:"<<refVal<<endl;
    int ival2=2;
    //引用经初始化后，永远和初始化的对象绑定，后续对引用的更改都是对绑定的对象的更改
    refVal = ival2;
    cout<<"refval:"<<refVal<<" ival:"<<ival<<endl;
    ival2 = 3;
    cout<<"refval:"<<refVal<<endl;

}