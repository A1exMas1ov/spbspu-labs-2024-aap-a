#include <iostream>
#include "strfunc.h"
#include "logic.h"

int main()
{
  size_t capacity = 7;
  char* str = nullptr;
  str = reinterpret_cast<char*>(malloc(sizeof(char) * (capacity)));
  if (str == nullptr)
  {
    std::cerr << "Error: not enough memory\n";
    return 1;
  }
  try
  {
    if (!tkach::inputStr(std::cin, str, capacity).good())
    {
      free(str);
      std::cerr << "Error: input error\n";
      return 1;
    }
  }
  catch (const std::bad_alloc & e)
  {
    free(str);
    std::cerr << "Error: not enough memory\n";
    return 1;
  }
  char* str2 = nullptr;
  str2 = reinterpret_cast<char*>(malloc(sizeof(char) * (capacity)));
  tkach::getStrWithRemovedVowels(str, str2);
  if (str2 == nullptr)
  {
    free(str);
    std::cerr << "Error: not enough memory\n";
    return 1;
  }
  std::cout << str2 << "\n";
  free(str);
  free(str2);
  return 0;
}
