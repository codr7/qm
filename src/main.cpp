#include <cassert>
#include <iostream>

#include "qm/buf.hpp"
#include "qm/color.hpp"
#include "qm/term.hpp"

using namespace qm;

void buf_tests() {
  Buf b;

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
  move_to(term, Pos(0, 0));
  //set_bg(term, Color(0, 0, 0));
  //cout << "Hello" << endl;
  set_bg(term, Color(255, 0, 0));
  set_fg(term, Color(255, 255, 255));
  cout << "Hello" << endl;
  return 0;
}
