#include <iostream>
#include "Sales_data.h"

using namespace std;

int main() {
    string null_book = "9-999-99999-9";
    Sales_data salesData;
    Sales_data null_ref = salesData.combine(null_book);
    cout << "null_book_No:" << null_ref.isbn() << endl;
}

double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

//this是该对象的常量指针，该函数返回值是Sales_data的引用，通过解引用this返回该对象的引用
Sales_data &Sales_data::combine(const Sales_data &source) {
    units_sold += source.units_sold;
    revenue += source.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;

}

ostream &print(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lsd, const Sales_data &rsd) {
    Sales_data sum = lsd;
    sum.combine(rsd);
    return sum;
}

Sales_data::Sales_data(std::istream &is) {
    read(is, *this);
}