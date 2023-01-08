#include <iostream>
#include "Blob.h"

using namespace std;

template<typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

// 数组的引用
//非类型参数必须是常量表达式
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2);
}

template<typename T, class C>
inline T min(const C &, const C &);

typedef Blob<string> StrBlob;
template<typename T> using twin = pair<T, T>;
twin<string> authors;   //为pair<string, string>
int main() {

}