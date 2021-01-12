#include "qm/term.hpp"

namespace qm {
  static ostream& esc(Term &term) {
    term.out << char(27) << '[';
    return term.out;
  }
		      
  void clear(Term& term) { esc(term) << "2J"; }
  
  void move_to(Term& term, const Pos& pos) { esc(term) << pos.row << ';' << pos.col << 'H'; }
}
