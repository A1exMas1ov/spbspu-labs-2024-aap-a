#include <iostream>
#include "f.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t k = 0;
  std::cin >> left >> right >> k;

  const double step = 0.25;
  const double error = 0.001;

  for(double i = left; i < right; i += step)
  {
    kos::output(i, k, error);
  }
  kos::output(right, k, error);
  return 0;
}