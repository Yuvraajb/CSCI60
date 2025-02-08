#ifndef LEXICON_H
#define LEXICON_H

#include <cstdlib>
#include <iostream>
#include <fstream>

using std::string;
using std::ostream;
using std::ifstream;

class Lexicon {
public:
  static const size_t CAPACITY = 2000; 
  Lexicon() : size_(0) {}
  Lexicon(string filename);
  size_t size() const { return size_; }
  bool contains(const string& word) const;
  string operator[](size_t pos) const { return data_[pos]; }
  bool insert(const string& word);
  bool remove(const string& word);
  Lexicon operator|(const Lexicon& rhs) const;
  Lexicon operator&(const Lexicon& rhs) const;
  Lexicon operator^(const Lexicon& rhs) const;

private:
  string data_[CAPACITY];
  size_t size_;
};

ostream& operator<<(ostream& out, const Lexicon& lex);
bool operator==(const Lexicon& lhs, const Lexicon& rhs);
bool operator!=(const Lexicon& lhs, const Lexicon& rhs);
bool operator<=(const Lexicon& lhs, const Lexicon& rhs);
bool operator<(const Lexicon& lhs, const Lexicon& rhs);
bool operator>=(const Lexicon& lhs, const Lexicon& rhs);
bool operator>(const Lexicon& lhs, const Lexicon& rhs);

#endif 
