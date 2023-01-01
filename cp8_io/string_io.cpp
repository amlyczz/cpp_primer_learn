#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string line = "", word;
    vector<PersonInfo> people;
    while (getline(cin, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (const auto &entry: people) {
        ostringstream formatted, badNums;
        for (const auto &nums: entry.phones) {  //每个号码
            if ((entry.phones.size() & 1) == 0) {
                formatted << " |formatted:" << nums;
            } else {
                badNums << " |badNums:" << nums;
            }
        }
        cout << formatted.str() << endl;
        cout << badNums.str() << endl;
    }
}