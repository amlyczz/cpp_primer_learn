

#include <vector>
#include <string>
#include <memory>
#include <set>
#include <map>

class QueryResult;
using line_no = std::vector<std::string>::size_type;

class TextQuery {
public:

    TextQuery(std::ifstream &);

    QueryResult query(const std::string &) const;

    std::ostream &print(std::ostream &os, const QueryResult &qr);

private:
    std::shared_ptr<std::vector<std::string>> file;
    //每个单词到行号的集合的映射
    std::map<std::string, std::shared_ptr<std::set<line_no>>>
            wm;

};

