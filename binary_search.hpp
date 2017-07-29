#include <vector>

namespace bs {
  template<typename T>
  auto binary_search(std::vector<T> list, T item) -> T {
    auto low = 0;
    auto high = list.size() - 1;

    while (low <= high) {
      auto mid = (low + high) / 2;
      auto mid_item = list.at(mid);
      if (mid_item == item) {
        return mid;
      } else if (mid_item < item) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }
}
