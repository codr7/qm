#ifndef QM_BUF_HPP
#define QM_BUF_HPP

#include <vector>

#include "qm/pos.hpp"
#include "qm/s.hpp"

namespace qm {

  struct Buf {
    vector<S> text;
  };

  void insert(Buf& buf, const Pos& pos, const S& val);
  size_t len(const Buf& buf);
  
}

#endif
