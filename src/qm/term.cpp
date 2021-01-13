#include "qm/color.hpp"
#include "qm/pos.hpp"
#include "qm/term.hpp"

namespace qm {
  static ostream& esc(Term &term) {
    term.out << char(27) << '[';
    return term.out;
  }
		      
  void clear(Term& term) { esc(term) << "2J"; }
  
  void move_to(Term& term, const Pos& pos) { esc(term) << pos.row+1 << ';' << pos.col+1 << 'H'; }

  void set_bg(Term& term, const Color& c) { esc(term) << "48;2;" << c.r << ';' << c.g << ';' << c.b << 'm'; }

  void set_fg(Term& term, const Color& c) { esc(term) << "38;2;" << c.r << ';' << c.g << ';' << c.b << 'm'; }
}
