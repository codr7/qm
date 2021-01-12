#ifndef QM_UTIL_HPP
#define QM_UTIL_HPP

namespace qm {
  template <typename T>
  vector<T> split(T in, typename T::value_type del) {
    size_t i = 0, j;
    vector<T> out;
    T t;
    
    while ((j = in.find(del, i)) != T::npos) {
      t = in.substr(i, j - i);
      i = j + 1;
      out.push_back(t);
    }
    
    out.push_back(in.substr(i));
    return out;
  }
}

#endif
