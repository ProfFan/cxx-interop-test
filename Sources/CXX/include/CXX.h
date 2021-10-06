#ifndef CXX_H
#define CXX_H

#include <sstream>
#include <string>
#include <vector>
class V {
public:
  V() : Vec({1, 2, 3, 4}), str("Hello from C++!") {}
  std::vector<int> &getVec() { return Vec; }
  std::vector<int> Vec;
  std::string str;
};

using cxx_std_vector_of_int = std::vector<int>;

static int dummy() {
  auto v = new V();
  std::vector<int> vec(v->Vec);

  vec.push_back(10);

  delete v;

  return vec[0];
}

namespace test {

class Dumper {
public:
  static std::string dump(const std::vector<int> &array);
};

}
#endif
