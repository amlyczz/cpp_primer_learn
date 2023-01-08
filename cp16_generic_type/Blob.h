#ifndef CPP_PRIMER_LEARN_BLOB_H
#define CPP_PRIMER_LEARN_BLOB_H

#include <vector>
#include <memory>

#endif //CPP_PRIMER_LEARN_BLOB_H

template<typename>
class BlobPtr;

template<typename T>
class Blob {
    friend class BlobPtr<T>;

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();

    Blob(std::initializer_list<T> il);

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    void push_back(T &&t) { data->push_back(std::move(t)); }

    void pop_back();

    T &back();

    T &operator[](size_type i);

    static std::size_t count() { return ctr; }

private:
    std::shared_ptr<std::vector<T>> data;
    static std::size_t ctr;

    void check(size_type i, const std::string &msg) const {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }
};

//模板类外成员函数
template<typename T>
T &Blob<T>::operator[](size_type i) {
    return (*data)[i];
}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) {}