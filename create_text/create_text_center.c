#include <cairo.h>
#include <gtk/gtk.h>

static void do_drawing(cairo_t *cr, GtkWidget *widget)
{
    GtkWidget *win = gtk_widget_get_toplevel(widget);
    gint w, h;
    gtk_window_get_size(GTK_WINDOW(win), &w, &h);

    cairo_set_source_rgb(cr, 0, 0, 0); // black
    cairo_select_font_face(cr, "Courier",
        CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 60.0);

    // calc "ZetCode" width and height.
    cairo_text_extents_t extents;
    const char *msg = "hello";
    cairo_text_extents(cr, msg, &extents);

    cairo_move_to(cr, w/2 - extents.width/2, h/ 2);
    cairo_show_text(cr, msg);
}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    do_drawing(cr, widget);
    return FALSE;
}

int main(int argc, char *argv[])
{

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *draw_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), draw_area);

    g_signal_connect(G_OBJECT(draw_area), "draw", G_CALLBACK(on_draw_event), NULL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
    gtk_window_set_title(GTK_WINDOW(window), "cairo with gtk+3.0");

    gtk_widget_show_all(window);

    gtk_main();

    return 0;

}
