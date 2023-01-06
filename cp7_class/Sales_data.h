#include <utility>

class Sales_data {
    //友元：可以允许其他类或函数访问它的非公有成员
    friend Sales_data add(const Sales_data &, const Sales_data &);

    friend std::ostream &print(std::ostream &, const Sales_data &);

    friend std::istream &read(std::istream &, Sales_data &);

    friend std::ostream &operator<<(std::ostream &os, const Sales_data &item);

    friend std::istream &operator>>(std::istream &is, Sales_data &item);

    friend Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs);

public:
    //构造函数
    Sales_data() = default;

    Sales_data(const std::string &s) : bookNo(s) {}

    Sales_data(std::string s, unsigned n, double p) :
            bookNo(std::move(s)), units_sold(n), revenue(p * n) {}

    //cpp11 委托构造函数
    Sales_data(std::string &s) : Sales_data(s, 0, 0) {}

    //抑制构造函数隐式类型转换
    explicit Sales_data(std::istream &);

    //说明this是一个指向常量的指针
    std::string isbn() const { return bookNo; }

    Sales_data &combine(const Sales_data &);

    //复合赋值运算符
    Sales_data &operator+=(const Sales_data &right){
        this->units_sold += right.units_sold;
        return *this;
    }

    //大括号赋值
    Sales_data &operator=(std::initializer_list<int> list);


private:
    double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

//有些编译器需要在类外再次对友元进行声明
Sales_data add(const Sales_data &, const Sales_data &);

std::ostream &print(std::ostream &, const Sales_data &);

std::istream &read(std::istream &, Sales_data &);

std::ostream &operator<<(std::ostream &os, const Sales_data &item);

std::istream &operator>>(std::istream &is, Sales_data &item);

Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs);
