#include "util.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

namespace ss {
  template<typename T>
  auto min_element(std::vector<T> list) -> T {
    if (list.size() <= 0) {
      throw std::runtime_error("can not find the minimum element for an empty list");
    } else if (list.size() == 1) {
      return list.at(0);
    } else {
      auto first = list.at(0);
      return std::min(first, min_element(u::get_tail(list)));
    }
  }

  template<typename T>
  auto remove_element(std::vector<T> list, T elem) -> std::vector<T> {
    auto first = list.at(0);
    auto rest = u::get_tail(list);
    if (first == elem) {
      return rest;
    } else {
      auto rest_removed = remove_element(rest, elem);
      rest_removed.insert(rest_removed.begin(), first);
      return rest_removed;
    }
  }

  template<typename T>
  auto selection_sort(std::vector<T> list) -> std::vector<T> {
    if (list.size() <= 0) {
      return list;
    } else {
      auto min_elem = min_element(list);
      auto rest = remove_element(list, min_elem);
      auto rest_sorted = selection_sort(rest);
      rest_sorted.insert(rest_sorted.begin(), min_elem);
      return rest_sorted;
    }
  }
}
