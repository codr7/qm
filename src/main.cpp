#include <cassert>
#include <iostream>

#include "qm/buf.hpp"
#include "qm/term.hpp"

using namespace qm;

void buf_tests() {
  Buf b;
  Pos p(2);
  assert(len(b) == 0);
  insert(b, Pos(1, 1), to_s("abcdef"));
  assert(len(b) == 9);
  insert(b, Pos(1, 4), to_s("ghi\n"));
  assert(len(b) == 13);
  insert(b, Pos(2, 0), to_s("jkl"));
  assert(len(b) == 16);
  assert(str(b) == "\n abcghidef\njkl\n");
}

int main() {
  buf_tests();
  Term term(cout);
  clear(term);
  move_to(term, Pos(20, 20));
  return 0;
}
