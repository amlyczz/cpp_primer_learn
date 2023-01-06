#include "Quote.h"

#ifndef CPP_PRIMER_LEARN_BULK_QUOTE_H
#define CPP_PRIMER_LEARN_BULK_QUOTE_H

#endif //CPP_PRIMER_LEARN_BULK_QUOTE_H

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;

    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
            Quote(book, p), min_qty(qty), discount(disc) {}


    double net_price(std::size_t cnt) const override {
        if (cnt >= min_qty) {
            return cnt * (1 - discount) * price;
        } else {
            return cnt * price;
        }
    }

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};