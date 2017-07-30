#include <vector>
#include <iostream>
#include <range/v3/all.hpp>
#include "util.hpp"

using namespace ranges;

namespace dc {
  template <typename T>
  auto sum(std::vector<T> list) -> T {
    if (list.size() == 0) {
      return 0;
    } else {
      return list.at(0) + sum(u::get_tail(list));
    }
  }

  template <typename T>
  auto count(std::vector<T> list) -> int {
    if (list.size() == 0) {
      return 0;
    } else {
      return 1 + count(u::get_tail(list));
    }
  }

  template <typename T>
  auto max(std::vector<T> list) -> T {
    if (list.size() == 0) {
      throw std::runtime_error("can not find max elem for an empty list");
    } else if (list.size() == 1) {
      return list.at(0);
    } else {
      auto first = list.at(0);
      auto rest_max = max(u::get_tail(list));
      return first >= rest_max ? first : rest_max;
    }
  }

  template <typename T>
  auto binary_search_dc(std::vector<T> list, T elem) -> int {
    if (list.size() == 0) {
      throw std::runtime_error("can not find elem in an empty list");
    } else {
      auto low = 0;
      auto high = list.size() - 1;

      auto mid = high + low / 2;
      auto mid_elem = list.at(mid);
      if (mid_elem == elem) {
        return mid;
      } else if (mid_elem > elem) {
        return binary_search_dc(u::slice(list, low, mid - 1), elem);
      } else {
        return binary_search_dc(u::slice(list, mid + 1, high), elem);
      }
    }
  }

  template <typename T>
  auto quick_sort(std::vector<T> list) -> std::vector<T> {
    if (list.size() <= 1) {
      return list;
    } else {
      auto pivot = list.at(0);
      auto tail = u::get_tail(list);

      auto less_list = tail | view::filter([=](T x) { return x <= pivot; });
      auto greater_list = tail | view::filter([=](T x) { return x > pivot; });

      auto less_sorted = quick_sort<T>(less_list);
      auto greater_sorted = quick_sort<T>(greater_list);
      auto pivot_sorted = { pivot };
      return view::concat(less_sorted, view::concat(pivot_sorted, greater_sorted));
    }
  }
}
