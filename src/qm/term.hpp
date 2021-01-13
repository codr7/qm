#ifndef QM_TERM_HPP
#define QM_TERM_HPP

#include <ostream>

namespace qm {
  struct Color;
  struct Pos;
  
  struct Term {
    Term(ostream& out): out(out) {}

    ostream& out;
  };

  void clear(Term& term);
  void move_to(Term& term, const Pos& pos);
  void set_bg(Term& term, const Color& bg);
  void set_fg(Term& term, const Color& fg);
}

#endif
