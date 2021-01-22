#include <gtk/gtk.h>
#include "menubar.h"

void quit_button(GtkWidget *widget, gpointer data)
{
    g_print("To Implement Quit.\n");
}

void save_button(GtkWidget *widget, gpointer *buffer)
{
    GtkTextIter start, end;
    gchar *text;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    g_print("Buffer Text: ");
    g_print(text);
    g_print("\n");
    g_free(text);
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
        g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(quit_button), &window);
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


    GtkTextTagTable *textTable = gtk_text_tag_table_new();
    GtkTextBuffer *buffer = gtk_text_buffer_new(textTable);
    GtkWidget *textarea = gtk_text_view_new();
    gtk_text_view_set_buffer(textarea, buffer);
    g_signal_connect(G_OBJECT(save), "activate", G_CALLBACK(save_button), buffer);

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
