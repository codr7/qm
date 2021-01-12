#include <cassert>
#include <iostream>

#include "qm/buf.hpp"

int main() {
  using namespace qm;

  Buf b;
  Pos p(2);
  assert(len(b) == 0);
  insert(b, Pos(p.tab, 1, 1), to_s("abcdef"));
  assert(len(b) == 9);
  insert(b, Pos(p.tab, 1, 4), to_s("ghi\n"));
  assert(len(b) == 13);
  insert(b, Pos(p.tab, 2, 0), to_s("jkl"));
  assert(len(b) == 16);
  assert(str(b) == "\n abcghidef\njkl\n");

  return 0;
}
