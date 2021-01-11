#ifndef QM_POS_HPP
#define QM_POS_HPP

#include "qm/s.hpp"

namespace qm {
  
  struct Pos {
    Pos(size_t tab, size_t row = 1, size_t col = 0): row(row), col(col) {}
    size_t tab, row, col;
  };

  bool operator==(const Pos& x, const Pos& y);
  bool operator<(const Pos& x, const Pos& y);
  bool operator>(const Pos& x, const Pos& y);
  Pos operator+(Pos x, const S& y);
  void operator+=(Pos& x, const S& y);
  size_t operator-(const Pos& x, const Pos& y);

}	      

#endif
