#ifndef QM_TERM_HPP
#define QM_TERM_HPP

#include <cstdlib>
#include <iostream>

#include <termios.h>
#include <unistd.h>

namespace qm {
  struct Color;
  struct Pos;
  
  struct Term {
    Term(int in = STDIN_FILENO, ostream& out = cout);
    ~Term();

    int in;
    ostream& out;
    termios org;
    bool raw;
  };

  void clear(Term& term);
  void reset(Term& term);
  void move_to(Term& term, const Pos& pos);
  void set_bg(Term& term, const Color& bg);
  void set_fg(Term& term, const Color& fg);
  void raw(Term& term);
  int get_key(Term& term);
}

#endif
