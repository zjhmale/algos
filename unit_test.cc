#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "binary_search.hpp"
#include "selection_sort.hpp"
#include "tco_recursion.hpp"

TEST_CASE("binary_search") {
  REQUIRE(bs::binary_search<int>({1, 2, 3, 4, 5}, 3) == 2);
  REQUIRE(bs::binary_search<int>({1, 2, 3, 4, 5}, 5) == 4);
  REQUIRE(bs::binary_search<int>({1, 2, 3, 4, 5}, 1) == 0);
}

TEST_CASE("get_tail") {
  std::vector<int> tail = {2, 3, 4, 5};
  REQUIRE(ss::get_tail<int>({1, 2, 3, 4, 5}) == tail);
}

TEST_CASE("min_element") {
  REQUIRE(ss::min_element<int>({1, 2, 3, 4, 5}) == 1);
  REQUIRE(ss::min_element<int>({5, 4, 3, 2, 1}) == 1);
}

TEST_CASE("remove_element") {
  std::vector<int> result = {1, 2, 4, 5};
  REQUIRE(ss::remove_element<int>({1, 2, 3, 4, 5}, 3) == result);
}

TEST_CASE("selection_sort") {
  std::vector<int> l = {1, 2, 3, 4, 5};
  REQUIRE(ss::selection_sort<int>({2, 4, 1, 5, 3}) == l);
}

TEST_CASE("tco_recursion") {
  REQUIRE(tr::fact_tco(5, 1) == 120);
}

