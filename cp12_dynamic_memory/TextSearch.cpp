#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include "TextQuery.h"

#endif

#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include "QueryResult.h"


using namespace std;

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<string>) {
    std::string text;
    vector<string> zz{"sb", "aaaa"};
    for (auto d: zz) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        std::string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines) {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }

}

QueryResult TextQuery::query(const std::string &sought) const {
    //如果未找到，返回指向set的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    } else {
        return QueryResult(sought, loc->second, file);
    }
}

std::ostream &TextQuery::print(std::ostream &os, const QueryResult &qr) {
    //如果找到单词则打印
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << endl;
    //打印单词出现的每一行
    for (auto num: *qr.lines) {
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << std::endl;
    }
    return os;
}

int main() {

}