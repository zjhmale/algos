namespace tr {
  auto fact_tco(int n, int counter) -> int {
    if (n == 0) {
      return counter;
    } else {
      return fact_tco(n - 1, counter * n);
    }
  }
}
