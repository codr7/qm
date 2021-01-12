#ifndef QM_POS_HPP
#define QM_POS_HPP

#include "qm/s.hpp"

namespace qm {
  
  struct Pos {
    Pos(size_t row = 0, size_t col = 0): row(row), col(col) {}
    size_t row, col;
  };

  bool operator==(const Pos& x, const Pos& y);
  bool operator<(const Pos& x, const Pos& y);
  bool operator>(const Pos& x, const Pos& y);

}	      

#endif
