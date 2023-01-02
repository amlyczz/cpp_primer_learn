#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    //在vector上实现的栈
    stack<string, vector<string>> str_stk;
    stack<string, vector<string>> str_stk2({"sdf"});

    stack<int> intStack;
    for (auto ix = 0; ix != 10; ix++) {
        intStack.push(ix);
    }
    while (!intStack.empty()) {
        int value = intStack.top();
        intStack.pop();
    }

}