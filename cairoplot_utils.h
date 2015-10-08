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

#ifndef _cairoplot_utils_h_
#define _cairoplot_utils_h_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct {

} cairop_t;

typedef struct {
  unsigned red;
  unsigned green;
  unsigned blue;
} cairop_color_t;

typedef struct {
  unsigned type_size;
  void * values;
  unsigned length;
} cairop_values;

typedef struct {
  unsigned type_size;
  cairop_values ** vectors;
  unsigned length;
} cairop_matrix;

double
cairoplot_utils_max (double *values,
                     int serie_size);

double
cairoplot_utils_min (double *values,
                     int serie_size);

unsigned *
cairoplot_utils_range (unsigned begin,
                       unsigned end);

void
cairoplot_utils_log_base_writing (char *string,
                                  double value,
                                  long base);

double *
cairoplot_utils_slice (double *values,
                       int begin,
                       int end);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif
