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

#include "cairoplot_backwards.h"

void
cairoplot_draw_axis (cairo_t *context, double width, double height)
{
  cairo_set_line_width (context, 1);
  cairo_set_source_rgb (context, 0.0, 0.0, 0.0);
  cairo_move_to (context, X_AXI_BASE, 0);
  cairo_line_to (context, X_AXI_BASE, height - Y_AXI_BASE);
  cairo_stroke (context);
  cairo_move_to (context, X_AXI_BASE, height - Y_AXI_BASE);
  cairo_line_to (context, width - (X_RIGHT / 2), height - Y_AXI_BASE);
  cairo_stroke (context);
}

void
cairoplot_draw_labels (cairo_t *context, double width, double height,
                       double *values, int serie_size,
                       short show_vlabels, short show_hlabels)
{
  int counter;
  char *buffer;
  double max_value, min_value;

  max_value = cairoplot_utils_max (values, serie_size);
  min_value = cairoplot_utils_min (values, serie_size);
  buffer = (char *) calloc (50, sizeof(char));

  cairo_set_font_size (context, 10.0);

  if (show_hlabels)
    {
      double horizontal_step;
      horizontal_step = (double) (width - X_RIGHT) / (serie_size + 1);
      cairo_set_source_rgb (context, 0, 0, 0);
      cairo_select_font_face (context, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
      for (counter = 0; counter < serie_size + 1; counter++)
        {
          sprintf (buffer, "%d", counter);
          cairo_set_source_rgb (context, 0, 0, 0);
          cairo_move_to (context, (counter * horizontal_step) + X_LEFT - TEXT_X_DISPLACEMENT, height - 40);
          cairo_rotate (context, M_PI / 2.5);
          cairo_show_text (context, buffer);
          cairo_rotate (context, -(M_PI / 2.5));
          if (counter > 0)
            {
              cairo_new_path (context);
              cairo_set_line_width (context, 0.5);
              cairo_set_source_rgb (context, 0.4, 0.4, 0.4);
              cairo_move_to (context, (counter * horizontal_step) + X_LEFT - TEXT_X_DISPLACEMENT + 2, 0);
              cairo_line_to (context, (counter * horizontal_step) + X_LEFT - TEXT_X_DISPLACEMENT + 2, height - Y_AXI_BASE);
              cairo_stroke (context);
            }
        }
    }

  if (show_vlabels)
    {
      double vertical_step, y;
      cairo_text_extents_t extents;

      counter = 0;
      y = (height - Y_BOTTOM);
      vertical_step = (double) (height - Y_TOP - Y_BOTTOM) / NUM_VERT_LABELS;
      while (y > 0)
        {
          double item = (min_value + ((max_value - min_value) * ((double) counter / (double) NUM_VERT_LABELS)));
          sprintf (buffer, "%.1lf", item);
          cairo_set_source_rgb (context, 0, 0, 0);
          cairo_text_extents (context, buffer, &extents);
          cairo_move_to (context, TEXT_WIDHT - (double) extents.width, y + TEXT_Y_DISPLACEMENT);
          cairo_show_text(context, buffer);
          if (counter > 0)
            {
              cairo_new_path (context);
              cairo_set_line_width (context, 0.5);
              cairo_set_source_rgb (context, 0.4, 0.4, 0.4);
              cairo_move_to (context, X_AXI_BASE, y);
              cairo_line_to (context, width - (X_RIGHT / 2), y);
              cairo_stroke (context);
            }
          y -= vertical_step;
          counter++;
        }
    }
  free (buffer);
}

void
cairoplot_dot_line (cairo_t *context, double width, double height,
                    double *values, int serie_size,
                    double color_r, double color_g, double color_b,
                    short show_dots)
{
  int counter;
  double horizontal_step;
  double relative_height, relative_width;
  double last, max_value;

  max_value = cairoplot_utils_max (values, serie_size);
  relative_height = (height - Y_TOP - Y_BOTTOM) / max_value;
  relative_width = (width - X_RIGHT) / (serie_size + 1);
  last = 0;

  cairo_set_source_rgb (context, color_r, color_g, color_b);
  for (counter = 0; counter < serie_size; counter++)
    {
      if (counter > 0)
        {
          cairo_move_to (context, relative_width * (counter - 1) + X_LEFT, (double) height - (last * relative_height) - Y_BOTTOM);
          cairo_line_to (context, relative_width * counter + X_LEFT, (double) height - (values[counter] * relative_height) - Y_BOTTOM);
          cairo_set_line_width (context, 2.5);
          cairo_stroke (context);
        }
      if (show_dots)
        {
          cairo_new_path (context);
          cairo_arc (context, relative_width * counter + X_LEFT, (double) height - (values[counter] * relative_height) - Y_BOTTOM, 3, 0, 2.1 * M_PI);
          cairo_close_path (context);
          cairo_fill (context);
        }
      last = values[counter];
    }
}

void
cairoplot_function (cairo_t *context, double width, double height,
                    double *values, int serie_size,
                    double color_r, double color_g, double color_b)
{
    /* TODO Implement it! */
}
