#include "all.h"

void tkach::output_table(double start, double end, size_t maxkolvo, const double error, const double step)
{
  for(auto i = start; i < end; i += step)
  {
    tkach::output_row(i, maxkolvo, error);
  }
}
