#ifndef QM_COLOR_HPP
#define QM_COLOR_HPP

namespace qm {
  struct Color {
    Color(int r, int g, int b): r(r), g(g), b(b) {}    
    int r, g, b;
  };
}

#endif
