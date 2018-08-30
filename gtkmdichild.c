// gtkmdichild.c  © 2018 by Thomas Führinger
// released under the terms of the GNU Lesser General Public License

#include <gtk/gtk.h>
#include <math.h>
#include "gtkmdichild.h"

/* Private class member */
#define GTK_MDI_CHILD_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), \
	GTK_MDI_CHILD_TYPE, GtkMdiChildPrivate))


static gint offsetx, offsety, px, py, maxx, maxy;

typedef struct _GtkMdiChildPrivate GtkMdiChildPrivate;

struct _GtkMdiChildPrivate
{
	GtkLabel* title;
	GtkWidget* widget;
};

/* Forward declarations */
static void gtk_mdi_child_finalize(GtkMdiChild* self);
static gboolean gtk_mdi_child_button_press_event(GtkWidget* widget, GdkEventButton* event);
//static gboolean gtk_mdi_child_button_release_event(GtkWidget* widget, GdkEventButton* event);
static gboolean gtk_mdi_child_motion_notify_event(GtkWidget *widget, GdkEventMotion *event);

/* Define the GtkMdiChild type and inherit from GtkGrid */
G_DEFINE_TYPE(GtkMdiChild, gtk_mdi_child, GTK_TYPE_GRID);

/* Initialize the GtkMdiChild class */
static void
gtk_mdi_child_class_init(GtkMdiChildClass* klass)
{
	/* Override GtkObject methods */
	GObjectClass* object_class = G_OBJECT_CLASS(klass);
	object_class->finalize = gtk_mdi_child_finalize;

	/* Override GtkWidget methods */
	GtkWidgetClass* widget_class = GTK_WIDGET_CLASS(klass);
	//widget_class->get_preferred_width = gtk_mdi_child_get_preferred_width;
	widget_class->button_press_event = gtk_mdi_child_button_press_event;
	//widget_class->button_release_event = gtk_mdi_child_button_release_event;
	widget_class->motion_notify_event = gtk_mdi_child_motion_notify_event;

	/* Add private indirection member */
	g_type_class_add_private(klass, sizeof(GtkMdiChildPrivate));

	gtk_widget_class_set_css_name(widget_class, "mdichild");
}


static gboolean
gtk_mdi_child_button_press_event(GtkWidget* widget, GdkEventButton* event)
{
	if (event->button == 1) {
		GtkWidget* parent = gtk_widget_get_parent(widget);
		// offset == distance of parent widget from edge of screen ...
		gdk_window_get_position(gtk_widget_get_parent_window(parent), &offsetx, &offsety);
		// plus distance from pointer to edge of widget
		offsetx += (int)event->x;
		offsety += (int)event->y;
	}
	return TRUE;
}
/*
static gboolean
gtk_mdi_child_button_release_event(GtkWidget* widget, GdkEventButton* event)
{
	g_debug("gtk_mdi_child_button_release_event w %p x %d   y %d", widget, event->x, event->y);
	return TRUE;
}
*/

static gboolean gtk_mdi_child_motion_notify_event(GtkWidget* widget, GdkEventMotion* event)
{
	gint x = (int)event->x_root - offsetx;
	gint y = (int)event->y_root - offsety;

	gtk_layout_move(GTK_LAYOUT(gtk_widget_get_parent(widget)), widget, x, y);
	return TRUE;
	//return FALSE;
}

GtkWidget*
gtk_mdi_child_new_with_label(gchar* title, GtkWidget* widget)
{
	GtkMdiChild* self = GTK_MDI_CHILD(g_object_new(gtk_mdi_child_get_type(), NULL));

	gtk_container_set_border_width(self, 30);
	GtkMdiChildPrivate* priv = GTK_MDI_CHILD_PRIVATE(self);
	GtkEventBox* event_box = gtk_event_box_new();
	priv->title = gtk_label_new(title);
	gtk_container_add(GTK_CONTAINER(event_box), priv->title);
	priv->widget = widget;
	gtk_grid_attach(self, event_box, 0, 0, 1, 1);
	//gtk_grid_attach(self, priv->title, 0, 0, 1, 1);
	gtk_grid_attach(self, priv->widget, 0, 1, 1, 1);
	gtk_widget_show(priv->title);
	gtk_widget_show(priv->widget);
	gtk_widget_set_size_request(priv->title, 20, 20);
	
	return self;
}

static void
gtk_mdi_child_init(GtkMdiChild* self)
{
	gtk_widget_set_has_window(GTK_WIDGET(self), FALSE);
	gtk_style_context_add_class(gtk_widget_get_style_context(self), "background");

	gtk_container_set_border_width(self, 24);
}

static void
gtk_mdi_child_finalize(GtkMdiChild* self)
{
	g_return_if_fail(self != NULL);
	g_return_if_fail(GTK_IS_MDI_CHILD(self));

	GtkMdiChildPrivate* priv = GTK_MDI_CHILD_PRIVATE(self);
	if (priv->title)
		g_object_unref(G_OBJECT(priv->title));

	G_OBJECT_CLASS(gtk_mdi_child_parent_class)->finalize(self);
}
