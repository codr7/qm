#ifndef QM_TERM_HPP
#define QM_TERM_HPP

#include <ostream>

#include "qm/pos.hpp"

namespace qm {
  struct Term {
    Term(ostream& out): out(out) {}

    ostream& out;
  };

  void clear(Term& term);
  void move_to(Term& term, const Pos& pos);
}

#endif
