#ifndef QM_S_HPP
#define QM_S_HPP

#include <string>

namespace qm {

  using namespace std;
  using S = u32string;
  using C = S::value_type;
  
  S to_s(const string& in);
}

#endif
