#pragma once

#include <vector>

namespace u {
  template<typename T>
  auto get_tail(std::vector<T> list) -> std::vector<T> {
    std::vector<T> rest;
    std::copy(list.cbegin() + 1, list.cend(), std::back_inserter(rest));
    return rest;
  }

  template<typename T>
  auto slice(std::vector<T> list, int start, int end) -> std::vector<T> {
    std::vector<T> rest;
    std::copy(list.cbegin() + start, list.cbegin() + end + 1, std::back_inserter(rest));
    return rest;
  }
}
