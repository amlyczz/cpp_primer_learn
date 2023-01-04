#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_

#include "TextQuery.h"

#endif

class QueryResult {
    friend std::ostream &TextQuery::print(std::ostream &, const QueryResult &);

public:
    QueryResult(std::string s,
                std::shared_ptr <std::set<line_no>> p,
                std::shared_ptr <std::vector<std::string>> f) :
            sought(s), lines(p), file(f) {}

private:
    std::string sought; //查询单词
    std::shared_ptr <std::set<line_no>> lines;   //出现的行号
    std::shared_ptr <std::vector<std::string>> file; //输入文件


};