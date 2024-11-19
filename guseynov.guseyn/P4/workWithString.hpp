#ifndef WORKWITHSTRING_HPP
#define WORKWITHSTRING_HPP

#include <cstddef>

namespace guseynov
{
  char * getNewArr(char *arr, size_t size, size_t step);
  size_t identifyUniqueChar(const char *inputString, const char *uniqueChars, size_t num);
}
#endif
