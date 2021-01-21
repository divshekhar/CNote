#include <gtk/gtk.h>

void changeStatus(GtkWidget *statusBar,guint statusContext,gchar *str)
{
    gtk_statusbar_pop(GTK_STATUSBAR(statusBar),statusContext);
    gtk_statusbar_push(GTK_STATUSBAR(statusBar),statusContext,str);
}

void quit_button(GtkWidget *widget, gpointer data)
{
    g_print("clicked\n");
}

void menuBar(GtkWidget* window)
{
   GtkWidget *menu, *box;
    menu = gtk_menu_bar_new();
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    // File Menu

    GtkWidget *file, *edit, *view, *tools, *about;
    file = gtk_menu_item_new_with_mnemonic("File");

        // File Submenu
        GtkWidget *filesubmenu;
        filesubmenu = gtk_menu_new();
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(file),filesubmenu);

        GtkWidget *newFile, *open, *save, *saveAs, *properties,*quit;
        newFile = gtk_menu_item_new_with_label("New");
        gtk_menu_shell_append(GTK_MENU_SHELL(filesubmenu),newFile);
        open = gtk_menu_item_new_with_label("Open");
        gtk_menu_shell_append(GTK_MENU_SHELL(filesubmenu),open);
        save = gtk_menu_item_new_with_label("Save");
        gtk_menu_shell_append(GTK_MENU_SHELL(filesubmenu),save);
        saveAs = gtk_menu_item_new_with_label("Save As");
        gtk_menu_shell_append(GTK_MENU_SHELL(filesubmenu),saveAs);
        properties = gtk_menu_item_new_with_label("Properties");
        gtk_menu_shell_append(GTK_MENU_SHELL(filesubmenu),properties);
        quit = gtk_menu_item_new_with_label("Quit");
        g_signal_connect(G_OBJECT(quit), "clicked", G_CALLBACK(gtk_main_quit), NULL);
        gtk_menu_shell_append(GTK_MENU_SHELL(filesubmenu),quit);
    // File Menu Appended
    gtk_menu_shell_append(GTK_MENU_SHELL(menu),file);


    // Edit Menu
    edit = gtk_menu_item_new_with_label("Edit");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu),edit);

    view = gtk_menu_item_new_with_label("View");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu),view);

    tools = gtk_menu_item_new_with_label("Tools");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu),tools);

    about = gtk_menu_item_new_with_label("About");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu),about);


    GtkWidget *textarea;
    textarea = gtk_text_view_new();
    GtkAdjustment *hadjustment;
    hadjustment = gtk_adjustment_new(100,0,100,10,1,10);
    gtk_scrollable_set_hadjustment(GTK_SCROLLABLE(textarea),hadjustment);

    GtkWidget *statusBar;
    statusBar = gtk_statusbar_new();
    guint statusContext;
    statusContext = gtk_statusbar_get_context_id(GTK_STATUSBAR(statusBar),"start");
    changeStatus(statusBar,statusContext,"CNote : Developed by Divyanshu Shekhar");


    gtk_container_add(GTK_CONTAINER(window),box);

    gtk_box_pack_start(GTK_BOX(box),menu,0,0,0);
    gtk_box_pack_start(GTK_BOX(box),textarea,TRUE,TRUE,0);
    gtk_box_pack_start(GTK_BOX(box),statusBar,0,0,0);
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
