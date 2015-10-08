# The CairoPlot Porting to C code

> CairoPlot porting to C from the original CairoPlot written in Python

[CairoPlot](https://launchpad.net/cairoplot) is a library that resides upon PyCairo, written in Python,
and used to plot graphics. This porting was born in December 2010; but there's already another supposed
to be official porting project also based on [CairoPlot](https://github.com/gass/cairoplot); it is uses
Cairo and Gnome/Gtk+.

This porting can be used in any cairo_context_t (on any target surface). The porting was not finished
(it is far from that), so it has some use limitations. So far it supports:

 * Dotted-line graphics

## License

Please refer to the included LICENSE and LGPL files for terms of use. This porting is licensed under
LGPL v2.1 just as the original code written in Python.

Copyright 2011-2015 Ewerton Assis
