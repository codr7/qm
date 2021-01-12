#include <iostream>
#include <sstream>

#include "qm/buf.hpp"
#include "qm/util.hpp"

namespace qm {  
  void insert_line(Buf& buf, const Pos& pos, const S& val, bool endl) {
    Pos p(pos.tab);
    
    if (buf.rows.size() > pos.row) {
      for (auto i = buf.rows.begin(); i != buf.rows.end(); i++) {
	if (p.row == pos.row) {
	  if (pos.col > i->length()) { i->append(S(pos.col - i->length(), ' ')); }
	  i->insert(pos.col, val);
	  return;
	}
	
	p.row++;
      }
    } else {
      p.row = buf.rows.size();
    }

    while (buf.rows.size() < pos.row+1) {
      buf.rows.emplace_back();
    }

    S& s = buf.rows.back();
    if (pos.col > s.length()) { s.append(S(pos.col - s.length(), ' ')); }
    s.insert(pos.col, val);
  }

  void insert(Buf& buf, const Pos& pos, const S& val) {
    auto ls = split(val, '\n');
    reverse(ls.begin(), ls.end());
    Pos p = pos;
    p.row += ls.size()-1;
    size_t i = 1;
    
    for (const S& l: ls) {
      p.col = (i == ls.size()) ? pos.col : 0;
      insert_line(buf, p, l, i < ls.size());
      p.row--;
      i++;
    }
  }

  size_t len(const Buf& buf) {
    size_t res = 0;
    for (auto &s: buf.rows) { res += s.length() + 1; }
    return res;
  }

  string str(const Buf &buf) {
    stringstream out;
    for (const S& r: buf.rows) { out << from_s(r) << endl; }
    return out.str();
  }

}
