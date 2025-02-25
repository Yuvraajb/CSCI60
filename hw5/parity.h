// Yuvraaj Bhatter

#ifndef PARITY_H
#define PARITY_H

#include <iostream>
#include <climits>

using std::cout;
using std::endl;
using std::ostream;

class Parity {
public:
  Parity();
  Parity(int * a, size_t n);
  Parity(const Parity& rhs);
  ~Parity();
  Parity& operator =(const Parity& rhs);
  void insert(int val);
  size_t remove(int val);
  int min() const;
  int max() const;
  bool odd() const;
  friend ostream& operator <<(ostream& out, const Parity& p);

private:
  size_t nEven_;
  size_t nOdd_;
  int *evens_;
  int *odds_;
  static const size_t CAP = 5;
};

#endif
