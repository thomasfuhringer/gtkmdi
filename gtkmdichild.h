// gtkmdichild.h  © 2018 by Thomas Führinger

#ifndef GTK_MDI_CHILD_H
#define GTK_MDI_CHILD_H

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GTK_MDI_CHILD_TYPE            (gtk_mdi_child_get_type())
#define GTK_MDI_CHILD(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), GTK_MDI_CHILD_TYPE, GtkMdiChild))
#define GTK_MDI_CHILD_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), GTK_MDI_CHILD_TYPE, GtkMdiChildClass))
#define GTK_IS_MDI_CHILD(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), GTK_MDI_CHILD_TYPE))
#define GTK_IS_MDI_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GTK_MDI_CHILD_TYPE))

typedef struct _GtkMdiChild           GtkMdiChild;
typedef struct _GtkMdiChildClass      GtkMdiChildClass;

struct _GtkMdiChild
{
	GtkGrid parent_instance;
};

struct _GtkMdiChildClass
{
	GtkGridClass parent_class;
};

GType gtk_mdi_child_get_type(void) G_GNUC_CONST;
GtkWidget* gtk_mdi_child_new_with_label(gchar* title, GtkWidget* widget);

G_END_DECLS

#endif /* GTK_MDI_CHILD_H */
