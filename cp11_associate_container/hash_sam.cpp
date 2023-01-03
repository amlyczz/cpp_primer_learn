#include <iostream>
#include "../cp7_class/Sales_data.h"
#include <unordered_set>

using namespace std;

size_t hasher(const Sales_data &sd) {
    return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

int main() {
    using sd = unordered_multiset<Sales_data,
            decltype(hasher) *, decltype(eqOp) *>;
    sd bookstore(42, hasher, eqOp);

}