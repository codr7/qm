#include <cassert>
#include <iostream>

#include "qm/buf.hpp"

int main() {
  using namespace qm;

  Buf b;
  Pos p(2);
  assert(len(b) == 0);
  insert(b, Pos(p.tab, 1, 3), to_s("abcdefg"));
  assert(len(b) == 10);
  insert(b, Pos(p.tab, 1, 6), to_s("hij"));
  assert(len(b) == 13);
  return 0;
}
