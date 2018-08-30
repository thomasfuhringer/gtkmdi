// gtkmdiarea.c  © 2018 by Thomas Führinger
// released under the terms of the GNU Lesser General Public License

#include <gtk/gtk.h>
#include <math.h>
#include "gtkmdichild.h"
#include "gtkmdiarea.h"

/* Private class member */
#define GTK_MDI_AREA_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), \
	GTK_MDI_AREA_TYPE, GtkMdiAreaPrivate))

typedef struct _GtkMdiAreaPrivate GtkMdiAreaPrivate;

struct _GtkMdiAreaPrivate
{
	gboolean tabbed;
};

/* Forward declarations */
//static void gtk_mdi_area_get_preferred_width(GtkWidget *widget,	int *minimal, int *natural);
//static void gtk_mdi_area_get_preferred_height(GtkWidget *widget, int *minimal, int *natural);
//static void gtk_mdi_area_size_allocate(GtkWidget *widget, GtkAllocation *allocation);
static GType gtk_mdi_area_child_type(GtkMdiArea* self);

/* Define the GtkMdiArea type and inherit from GtkLayout */
G_DEFINE_TYPE(GtkMdiArea, gtk_mdi_area, GTK_TYPE_LAYOUT);

/* Initialize the GtkMdiArea class */
static void
gtk_mdi_area_class_init(GtkMdiAreaClass* klass)
{
	/* Override GtkWidget methods */
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(klass);
	//widget_class->get_preferred_width = gtk_mdi_area_get_preferred_width;
	//widget_class->get_preferred_height = gtk_mdi_area_get_preferred_height;
	//widget_class->size_allocate = gtk_mdi_area_size_allocate;

	/* Override GtkContainer methods */
	GtkContainerClass* container_class = GTK_CONTAINER_CLASS(klass);
	container_class->child_type = gtk_mdi_area_child_type;

	/* Override GtkLayout methods */
	//GtkLayoutClass* layout_class = GTK_LAYOUT_CLASS(klass);

	/* Add private indirection member */
	g_type_class_add_private(klass, sizeof(GtkMdiAreaPrivate));

	gtk_widget_class_set_css_name(widget_class, "mdiarea");
}

/* Initialize a new GtkMdiArea instance */
static void
gtk_mdi_area_init(GtkMdiArea* self)
{
	gtk_style_context_add_class(gtk_widget_get_style_context(self), "background");
}

/* Return a new GtkMdiArea cast to a GtkWidget */
GtkWidget *
gtk_mdi_area_new(gboolean tabbed)
{
	GtkMdiArea* self = GTK_WIDGET(g_object_new(gtk_mdi_area_get_type(), NULL));
	GtkMdiAreaPrivate* priv = GTK_MDI_AREA_PRIVATE(self);
	priv->tabbed = tabbed;
	return self;
}

/* Return the type of children this container accepts */
static GType
gtk_mdi_area_child_type(GtkMdiArea* self)
{
	return GTK_MDI_CHILD_TYPE;
}
