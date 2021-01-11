#include "qm/pos.hpp"

namespace qm {

  bool operator==(const Pos& x, const Pos& y) { return x.row == y.row && x.col == y.col; }

  bool operator<(const Pos& x, const Pos& y) { return x.row < y.row || (x.row == y.row && x.col < y.col); }
  bool operator>(const Pos& x, const Pos& y) { return x.row > y.row || (x.row == y.row && x.col > y.col); }

  Pos operator+(Pos x, const S& y) {
    x += y;
    return x;
  }

  void operator+=(Pos& x, const S& y) {
    for (auto c: y) {
      switch (c) {
      case '\n':
	x.row++;
	x.col = 0;
	break;
      case '\t':
	x.col += x.tab;
	break;
      default:
	x.col++;
      }
    }
  }

  size_t operator-(const Pos& x, const Pos& y) { return x.row - y.row + x.col - y.col; }

}
