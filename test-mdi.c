#include <stdlib.h>
#include <gtk/gtk.h>
#include "gtkmdichild.h"
#include "gtkmdiarea.h"

int main(int   argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *label;
	GtkWidget *mdi_area;
	GtkWidget *mdi_child;

	gtk_init(&argc, &argv);

	const gchar* sCSS =
		"mdiarea {"
		"    color: #cfcfcd;"
		"}"
		"mdichild {"
		"    padding: 4px;"
		"    margin: 0px;"
		"    border-color: #b6b6b3;"
		"    border-width: 1px;"
		"    background-color: #cfcfcd;"
		"}";

	GtkCssProvider* gtkCssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_data(gtkCssProvider, sCSS, -1, NULL);
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(gtkCssProvider),
		GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(window), "Test App");

	g_signal_connect(window, "destroy",
		G_CALLBACK(exit), NULL);

	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

	mdi_area = gtk_mdi_area_new(FALSE);

	label = gtk_label_new("Hello MDI");
	mdi_child = gtk_mdi_child_new_with_label("Child 1", label);
	gtk_container_add(GTK_CONTAINER(mdi_area), mdi_child);
	gtk_layout_move(mdi_area, mdi_child, 30, 40);

	//label = gtk_label_new("Hello Again");
	label = gtk_button_new();
	gtk_widget_set_size_request(label, 120, 80);
	mdi_child = gtk_mdi_child_new_with_label("Child 2", label);
	gtk_container_add(GTK_CONTAINER(mdi_area), mdi_child);
	gtk_layout_move(mdi_area, mdi_child, 130, 140);
	gtk_widget_show(mdi_child);

	gtk_container_add(GTK_CONTAINER(window), mdi_area);
	gtk_widget_show_all(mdi_area);


	gtk_widget_show(window);
	gtk_main();

	return 0;
}
