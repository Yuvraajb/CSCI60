#include "parity.h"

void Parity::insert(int val) {
    if (val % 2 == 0) {
        if (nEven_ % CAP == 0) {
            int* newEvens = new int[nEven_ + CAP];
            for (size_t i = 0; i < nEven_; ++i) {
                newEvens[i] = evens_[i];
            }
            delete[] evens_;
            evens_ = newEvens;
        }
        evens_[nEven_++] = val;
    } else {
        if (nOdd_ % CAP == 0) {
            int* newOdds = new int[nOdd_ + CAP];
            for (size_t i = 0; i < nOdd_; ++i) {
                newOdds[i] = odds_[i];
            }
            delete[] odds_;
            odds_ = newOdds;
        }
        odds_[nOdd_++] = val;
    }
}

bool Parity::odd() const {
    return (nEven_ + nOdd_) % 2 != 0;
}

Parity::Parity(int* a, size_t n) : nEven_(0), nOdd_(0), evens_(nullptr), odds_(nullptr) {
    for (size_t i = 0; i < n; ++i) {
        insert(a[i]);
    }
}

int Parity::min() const {
    int minVal = INT_MAX;
    for (size_t i = 0; i < nEven_; ++i) {
        if (evens_[i] < minVal) minVal = evens_[i];
    }
    for (size_t i = 0; i < nOdd_; ++i) {
        if (odds_[i] < minVal) minVal = odds_[i];
    }
    return minVal;
}

int Parity::max() const {
    int maxVal = INT_MIN;
    for (size_t i = 0; i < nEven_; ++i) {
        if (evens_[i] > maxVal) maxVal = evens_[i];
    }
    for (size_t i = 0; i < nOdd_; ++i) {
        if (odds_[i] > maxVal) maxVal = odds_[i];
    }
    return maxVal;
}

ostream& operator<<(ostream& out, const Parity& p) {
    out << "E: ";
    for (size_t i = 0; i < p.nEven_; ++i) {
        out << p.evens_[i] << " ";
    }
    out << "\nO: ";
    for (size_t i = 0; i < p.nOdd_; ++i) {
        out << p.odds_[i] << " ";
    }
    return out;
}