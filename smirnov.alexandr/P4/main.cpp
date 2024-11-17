#include "functions.hpp"

int main()
{
  const char * str2 = "def ";
  char * str1 = nullptr;
  try
  {
    str1 = smirnov::getLine(std::cin, '\n');
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (str1[0] == '\n')
  {
    delete[] str1;
    std::cerr << "Error: empty string\n";
    return 1;
  }
  std::cout << smirnov::uniString(str1, str2) << "\n";
  delete[] str1;
}
