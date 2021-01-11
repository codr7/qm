#include <iostream>

#include "qm/buf.hpp"

namespace qm {
  void insert(Buf& buf, const Pos& pos, const S& val) {
    Pos p(pos.tab);

    for (auto i = buf.text.begin(); i != buf.text.end(); i++) {
      if (p == pos) {
	buf.text.insert(i, val);
	return;
      }
      
      if (p + *i > pos) {
	size_t j = pos - p;
	S p = i->substr(0, j);
	*i = i->substr(j);
	buf.text.insert(i, p + val);
	return;
      }
      
      p += *i;
    }

    if (p < pos) { buf.text.emplace_back(pos - p, ' '); }
    buf.text.push_back(val);
  }
  
  size_t len(const Buf& buf) {
    size_t res = 0;
    for (auto &s: buf.text) { res += s.length(); }
    return res;
  }
}
