#include <cairo.h>
#include <cairo-pdf.h>

int main(void)
{
    cairo_surface_t *surface = cairo_pdf_surface_create(
        "output.pdf", 504, 648);

    cairo_t *cr = cairo_create(surface);

    cairo_set_source_rgb(cr, 0, 0, 0); // black
    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
        CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 32.0);

    cairo_move_to(cr, 10.0, 50.0);
    cairo_show_text(cr, "こんにちは世界cairo");

    cairo_show_page(cr);

    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;

}
