#include <iostream>

#include "qm/buf.hpp"

namespace qm {
  void insert(Buf& buf, const Pos& pos, const S& val) {
    Pos p(pos.tab);
    
    if (buf.rows.size() > pos.row) {
      for (auto i = buf.rows.begin(); i != buf.rows.end(); i++) {
	if (p.row == pos.row) {
	  i->insert(pos.col, val);
	  return;
	}
	
	p.row++;
      }
    } else {
      p.row = buf.rows.size();
    }
    
    while (p.row < pos.row) {
      buf.rows.emplace_back();
      p.row++;
    }

    S& s = buf.rows.back();
    if (pos.col > s.length()) { s.append(S(pos.col - s.length(), ' ')); }
    s.append(val);
  }

  size_t len(const Buf& buf) {
    size_t res = 0;
    for (auto &s: buf.rows) { res += s.length() + 1; }
    return res;
  }
}
