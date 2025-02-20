#ifndef PARITY_H
#define PARITY_H

#include <iostream>
#include <climits>

using std::cout;
using std::endl;
using std::ostream;

class Parity {
public:
    Parity() : nEven_(0), nOdd_(0), evens_(nullptr), odds_(nullptr) { }
    Parity(int* a, size_t n);
    void insert(int val);
    int min() const;
    int max() const;
    bool odd() const;
    friend ostream& operator<<(ostream& out, const Parity& p);

private:
    size_t nEven_;
    size_t nOdd_;
    int* evens_;
    int* odds_;
    static const size_t CAP = 5;
};

#endif
