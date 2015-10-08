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

#ifndef __cairoplot_retro_h__
#define __cairoplot_retro_h__

#define Y_TOP                   20
#define Y_BOTTOM                50
#define X_LEFT                  50
#define X_RIGHT                 50
#define X_AXI_BASE              50
#define Y_AXI_BASE              50
#define TEXT_X_DISPLACEMENT     2
#define TEXT_Y_DISPLACEMENT     4
#define TEXT_WIDHT              40
#define NUM_VERT_LABELS         5

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void
cairoplot_draw_axis (cairo_t *context, double width, double height);

void
cairoplot_draw_labels (cairo_t *context, double width, double height,
                       double *values, int serie_size,
                       short show_vlabels, short show_hlabels);

void
cairoplot_dot_line (cairo_t *context, double width, double height,
                    double *values, int serie_size,
                    double color_r, double color_g, double color_b,
                    short show_dots);

void
cairoplot_function (cairo_t *context, double width, double height,
                    double *values, int serie_size,
                    double color_r, double color_g, double color_b);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __cairoplot_retro_h__
