
#ifndef CPP_PRIMER_LEARN_QUOTE_H
#define CPP_PRIMER_LEARN_QUOTE_H


class Quote {
public:
    Quote() = default;

    Quote(const std::string &book, double sales_price) :
            bookNo(book), price(sales_price) {}

    std::string isbn() const {
        return bookNo;
    }

    virtual double net_price(std::size_t n) const {
        return n * price;
    }
    //纯虚函数
//    virtual double net_price2(std::size_t n) const = 0;

    virtual ~Quote() = default;

    static void statmen();

private:
    std::string bookNo;

protected:
    double price = 0.0;
};


#endif //CPP_PRIMER_LEARN_QUOTE_H
