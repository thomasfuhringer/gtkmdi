// gtkmdiarea.h  © 2018 by Thomas Führinger

#ifndef GTK_MDI_AREA_H
#define GTK_MDI_AREA_H

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GTK_MDI_AREA_TYPE            (gtk_mdi_area_get_type())
#define GTK_MDI_AREA(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), GTK_MDI_AREA_TYPE, GtkMdiArea))
#define GTK_MDI_AREA_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), GTK_MDI_AREA_TYPE, GtkMdiAreaClass))
#define GTK_IS_MDI_AREA(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), GTK_MDI_AREA_TYPE))
#define GTK_IS_MDI_AREA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GTK_MDI_AREA_TYPE))

typedef struct _GtkMdiArea       GtkMdiArea;
typedef struct _GtkMdiAreaClass  GtkMdiAreaClass;

struct _GtkMdiArea
{
	GtkLayout parent_instance;
};

struct _GtkMdiAreaClass
{
	GtkLayoutClass parent_class;
};

GType gtk_mdi_area_get_type(void) G_GNUC_CONST;
GtkWidget* gtk_mdi_area_new(gboolean tabbed);
//GDK_AVAILABLE_IN_ALL void gtk_mdi_area_move (GtkMdiArea* self, GtkWidget* widget, gint x, gint y);

G_END_DECLS

#endif /* GTK_MDI_AREA_H */
