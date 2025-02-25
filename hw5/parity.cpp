// Yuvraaj Bhatter

#include "parity.h"

Parity::Parity(const Parity& rhs) : nEven_(rhs.nEven_), nOdd_(rhs.nOdd_) {
    evens_ = new int[nEven_];
    odds_ = new int[nOdd_];
    for (size_t i = 0; i < nEven_; ++i) {
        evens_[i] = rhs.evens_[i];
    }
    for (size_t i = 0; i < nOdd_; ++i) {
        odds_[i] = rhs.odds_[i];
    }
}

Parity::~Parity() {
    delete[] evens_;
    delete[] odds_;
}

Parity& Parity::operator=(const Parity& rhs) {
    if (this != &rhs) {
        delete[] evens_;
        delete[] odds_;
        
        nEven_ = rhs.nEven_;
        nOdd_ = rhs.nOdd_;
        evens_ = new int[nEven_];
        odds_ = new int[nOdd_];
        for (size_t i = 0; i < nEven_; ++i) {
            evens_[i] = rhs.evens_[i];
        }
        for (size_t i = 0; i < nOdd_; ++i) {
            odds_[i] = rhs.odds_[i];
        }
    }
    return *this;
}

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
        size_t i = 0;
        while (i < nEven_ && evens_[i] < val) ++i;
        for (size_t j = nEven_; j > i; --j) {
            evens_[j] = evens_[j - 1];
        }
        evens_[i] = val;
        ++nEven_;
    } else {
        if (nOdd_ % CAP == 0) {
            int* newOdds = new int[nOdd_ + CAP];
            for (size_t i = 0; i < nOdd_; ++i) {
                newOdds[i] = odds_[i];
            }
            delete[] odds_;
            odds_ = newOdds;
        }
        size_t i = 0;
        while (i < nOdd_ && odds_[i] < val) ++i;
        for (size_t j = nOdd_; j > i; --j) {
            odds_[j] = odds_[j - 1];
        }
        odds_[i] = val;
        ++nOdd_;
    }
}

size_t Parity::remove(int val) {
    size_t count = 0;
    if (val % 2 == 0) {
        size_t j = 0;
        for (size_t i = 0; i < nEven_; ++i) {
            if (evens_[i] != val) {
                evens_[j++] = evens_[i];
            } else {
                ++count;
            }
        }
        nEven_ = j;
    } else {
        size_t j = 0;
        for (size_t i = 0; i < nOdd_; ++i) {
            if (odds_[i] != val) {
                odds_[j++] = odds_[i];
            } else {
                ++count;
            }
        }
        nOdd_ = j;
    }
    return count;
}

int Parity::min() const {
    if (nEven_ == 0 && nOdd_ == 0) return INT_MAX;
    int minEven = (nEven_ > 0) ? evens_[0] : INT_MAX;
    int minOdd = (nOdd_ > 0) ? odds_[0] : INT_MAX;
    return (minEven < minOdd) ? minEven : minOdd;
}

int Parity::max() const {
    if (nEven_ == 0 && nOdd_ == 0) return INT_MIN;
    int maxEven = (nEven_ > 0) ? evens_[nEven_ - 1] : INT_MIN;
    int maxOdd = (nOdd_ > 0) ? odds_[nOdd_ - 1] : INT_MIN;
    return (maxEven > maxOdd) ? maxEven : maxOdd;
}

bool Parity::odd() const {
    return (nEven_ + nOdd_) % 2 != 0;
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
