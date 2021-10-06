// TODO: Generate these for specializing COMDATs during irgen.
#include <CXX.h>
#include <vector>
#if !DISABLE_TEMPLATE_SPECIALIZATION
template class std::vector<int>;
#endif

namespace test {

std::string Dumper::dump(const std::vector<int> &array) {
  std::stringstream ss;
  for (auto iter = array.begin(); iter != array.end(); ++iter) {
    ss << *iter;
    if (iter + 1 != array.end())
      ss << ", ";
  }

  return ss.str();
}

} // namespace test
