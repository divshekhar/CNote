#include <gtk/gtk.h>
#include "menubar.h"

void changeStatus(GtkWidget *statusBar,guint statusContext,gchar *str)
{
    gtk_statusbar_pop(GTK_STATUSBAR(statusBar),statusContext);
    gtk_statusbar_push(GTK_STATUSBAR(statusBar),statusContext,str);
}

static void activate (GtkApplication* app, gpointer user_data)
{
    GtkWidget *window;
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "CNote");
    gtk_window_set_default_size (GTK_WINDOW (window), 800, 500);
    //GtkWidget* scrolledwindow = gtk_scrolled_window_new(NULL, NULL);

    menuBar(window);

    gtk_widget_show_all (window);
}

int main(int argc,char **argv)
{
    GtkApplication *app;
    int status;
    app = gtk_application_new ("com.hackthedeveloper", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref (app);
    return status;
}
