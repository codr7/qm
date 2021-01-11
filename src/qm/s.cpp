#include <codecvt>
#include <locale>

#include "qm/s.hpp"

namespace qm {
  using namespace std;
  
  S to_s(const string& in) {
    wstring_convert<codecvt_utf8_utf16<C>, C> c;
    return c.from_bytes(in);
  }

}
