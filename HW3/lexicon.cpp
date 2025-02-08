// Name: Yuvraaj Bhatter

#include "lexicon.h"
#include <fstream>

Lexicon::Lexicon(string filename) : size_(0) {
    ifstream in(filename);
    string word;

    while (in >> word && size_ < CAPACITY) {
        if (!contains(word)) {  
            data_[size_++] = word;
        }
    }
    in.close();
}

bool Lexicon::contains(const string& word) const {
    for (size_t i = 0; i < size_; i++) {
        if (data_[i] == word) return true;
    }
    return false;
}

bool Lexicon::insert(const string &word) {
    if (size_ >= CAPACITY || contains(word)) {
        return false; 
    }
    data_[size_++] = word;
    return true;
}

bool Lexicon::remove(const string &word) {
    for (size_t i = 0; i < size_; i++) {
        if (data_[i] == word) {
            data_[i] = data_[--size_]; 
            return true;
        }
    }
    return false;
}

Lexicon Lexicon::operator|(const Lexicon& rhs) const {
    Lexicon result;
    for (size_t i = 0; i < size_; i++) {
        result.insert(data_[i]);
    }
    for (size_t i = 0; i < rhs.size_; i++) {
        result.insert(rhs.data_[i]);
    }
    return result;
}

Lexicon Lexicon::operator&(const Lexicon& rhs) const {
    Lexicon result;
    for (size_t i = 0; i < size_; i++) {
        if (rhs.contains(data_[i])) {
            result.insert(data_[i]);
        }
    }
    return result;
}

Lexicon Lexicon::operator^(const Lexicon& rhs) const {
    Lexicon result;
    for (size_t i = 0; i < size_; i++) {
        if (!rhs.contains(data_[i])) {
            result.insert(data_[i]);
        }
    }
    for (size_t i = 0; i < rhs.size_; i++) {
        if (!contains(rhs.data_[i])) {
            result.insert(rhs.data_[i]);
        }
    }
    return result;
}

bool operator==(const Lexicon& lhs, const Lexicon& rhs) {
    if (lhs.size() != rhs.size()) return false;
    for (size_t i = 0; i < lhs.size(); i++) {
        if (!rhs.contains(lhs[i])) return false;
    }
    return true;
}

bool operator!=(const Lexicon& lhs, const Lexicon& rhs) {
    return !(lhs == rhs);
}

bool operator<=(const Lexicon& lhs, const Lexicon& rhs) {
    for (size_t i = 0; i < lhs.size(); i++) {
        if (!rhs.contains(lhs[i])) return false;
    }
    return true;
}

bool operator<(const Lexicon& lhs, const Lexicon& rhs) {
    return (lhs <= rhs) && (lhs.size() < rhs.size());
}

bool operator>=(const Lexicon& lhs, const Lexicon& rhs) {
    return rhs <= lhs;
}

bool operator>(const Lexicon& lhs, const Lexicon& rhs) {
    return (lhs >= rhs) && (lhs.size() > rhs.size());
}

ostream& operator<<(ostream& out, const Lexicon& lex) {
    for (size_t i = 0; i < lex.size(); i++) {
        out << lex[i] << " ";
    }
    return out;
}
