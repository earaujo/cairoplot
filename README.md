# The CairoPlot Porting to C code
   
> WARNING: This project is not maintained anymore

The original [CairoPlot](https://launchpad.net/cairoplot) library uses PyCairo, a library written in Python
and used to plot graphics. This porting was born in December 2010; though there's already another supposed
to be official porting project also based on [CairoPlot](https://github.com/gass/cairoplot); it uses Cairo
and Gnome/Gtk+.

This porting can be used in any `cairo_context_t` &mdash; on any target surface. This porting was not finished
(it is far from that), so it has some use limitations. So far it supports:

 * Dotted-line graphics

## License

Please refer to the included LICENCE file for terms of use. This porting is licensed under
LGPL v2.1 just as the original code written in Python.

Copyright 2011-2015 Ewerton Assis
