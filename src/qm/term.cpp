#include "qm/color.hpp"
#include "qm/pos.hpp"
#include "qm/term.hpp"

namespace qm {
  Term::Term(int in, ostream& out): in(in), out(out), raw(false) {}


  Term::~Term() {
    if (raw) { tcsetattr(in, TCSAFLUSH, &org); }
  }
  
  static ostream& esc(Term &term) {
    term.out << char(27) << '[';
    return term.out;
  }
		      
  void clear(Term& term) { esc(term) << "2J"; }

  void reset(Term& term) { esc(term) << 'm'; }
  
  void move_to(Term& term, const Pos& pos) { esc(term) << pos.row+1 << ';' << pos.col+1 << 'H'; }

  void set_bg(Term& term, const Color& c) { esc(term) << "48;2;" << c.r << ';' << c.g << ';' << c.b << 'm'; }

  void set_fg(Term& term, const Color& c) { esc(term) << "38;2;" << c.r << ';' << c.g << ';' << c.b << 'm'; }

  void raw(Term& term) {
    tcgetattr(term.in, &term.org);
    termios v = term.org;
    v.c_lflag &= ~ICANON;
    v.c_lflag &= ~ECHO;
    tcsetattr(term.in, TCSAFLUSH, &v);
    term.raw = true;
  }

  int get_key(Term& term) {
    char c;
    if (read(term.in, &c, 1) != 1) { throw runtime_error("Failed reading from STDIN"); }
    return c;
  }
}
