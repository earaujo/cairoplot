// CairoPlot porting to C from the original CairoPlot written in Python.
// Copyright (C) 2011-2015 Ewerton Assis.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#include "cairoplot_utils.h"

double
cairoplot_utils_max (double *values,
                     int serie_size)
{
  int i;
  double max = 0;
  for (i = 0; i < serie_size; i++)
    max = values[i] > max ? values[i] : max;
  return max;
}

double
cairoplot_utils_min (double *values,
                     int serie_size)
{
  int i;
  double min = 0;
  for (i = 0; i < serie_size; i++)
    min = values[i] < min ? values[i] : min;
  return min;
}

unsigned *
cairoplot_utils_range (unsigned begin,
                       unsigned end)
{
  unsigned *vector, i;
  vector = (unsigned *) calloc (end - begin, sizeof (unsigned));
  for (i = 0; i < end - begin; i++)
    vector[i] = i;
  return vector;
}

void
cairoplot_utils_log_base_writing (char *string,
                                  double value,
                                  long base)
{
  /* TODO Implement it! */
}

double *
cairoplot_utils_slice (double *values,
                       int begin,
                       int end)
{
  if (begin > end)
    return NULL;
  double *slice;
  int length, i;
  length = end - begin + 1;
  slice = (double *) calloc (length, sizeof (double));
  for (i = 0; i < length; i++)
    slice[i] = values[i + begin];
  return slice;
}
