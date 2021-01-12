#include "qm/pos.hpp"

namespace qm {

  bool operator==(const Pos& x, const Pos& y) { return x.row == y.row && x.col == y.col; }

  bool operator<(const Pos& x, const Pos& y) { return x.row < y.row || (x.row == y.row && x.col < y.col); }
  bool operator>(const Pos& x, const Pos& y) { return x.row > y.row || (x.row == y.row && x.col > y.col); }

}
