#ifndef CPP_PRIMER_LEARN_STRVEC_H
#define CPP_PRIMER_LEARN_STRVEC_H

#endif //CPP_PRIMER_LEARN_STRVEC_H

class StrVec {
public:
    //下标运算符
    std::string &operator[](std::size_t n) {
        return elements[n];
    }

    const std::string &operator[](std::size_t n) const {
        return elements[n];
    }

    //前置自增/减运算符
    StrVec &operator++() {
        cnt++;
        return *this;
    }

    StrVec &operator--() {
        cnt--;
        return *this;
    }

    //后置自增/减运算符
    //参数没有用到
    StrVec operator++(int) {
        StrVec ret = *this;
        this->cnt++;
        return ret;
    }

    StrVec &operator--(int);


    //函数调用运算符
    int operator()(int val) const {
        if (val < 0) {
            return -val;
        } else {
            return val;
        }
    }

    //类型转换运算符
    //转化为int
    operator int() const{
        return cnt;
    }

private:
    std::string *elements;
    int cnt;
};