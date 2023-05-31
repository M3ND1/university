
#include <iostream>

#include <gtk/gtk.h>

#if defined(_WIN32) || defined(WIN32)
#include <gdk/gdkwin32.h>
#elif defined(__unix__) || defined(__unix) || defined(unix) || defined(__linux__) || defined(__linux) || defined(linux) || defined(__gnu_linux__)
#else
#endif
// buttons

// ========================================================================================================================

    GtkBuilder  *gbuilder;
    GError      *gerror = NULL;
    GtkWidget   *gtk_window_1;
    GtkWidget   *gtk_button_1;
    GtkWidget   *gtk_label_1;
    GtkWidget   *gtk_text_view_1;

// ========================================================================================================================

void logtx (std::string str) {

    GtkTextBuffer *buffer;
    GtkTextIter iter;

    // jakiego parametru spodziewa sie gtk_text_view_get_buffer ?
    // jakiego typu jest obiekt gtk_text_view_1 ?
    // co robi makro GTK_TEXT_VIEW ? - takie operacje wykonuje sie czesto

    buffer = gtk_text_view_get_buffer ( GTK_TEXT_VIEW(gtk_text_view_1) );

    gtk_text_buffer_get_iter_at_offset (buffer, &iter, 0);
    gtk_text_buffer_insert (buffer, &iter, std::string(str + "\n").c_str(), -1);
}

// ========================================================================================================================

// "extern "C" G_MODULE_EXPORT" ponizej jest niezbedne, zeby gtk_builder_connect_signals() podpial do sygnalu funkcje o nazwie zdefiniowanej w pliku glade
// unikamy korzystania z tej metody - jest mniej uniwersalna

void on_window_main_destroy () {
    gtk_main_quit ();
}

// ========================================================================================================================

void on_gtk_button_1_clicked (GtkButton *button, gpointer user_data) {
    gtk_label_set_text ( GTK_LABEL (gtk_label_1), "123456" );
    logtx ("przycisk 1");
}
// ====
void on_calculator_button_clicked(GtkButton *button, gpointer user_data) {
    const gchar *text = gtk_button_get_label(button
}

// ========================================================================================================================

int main( int argc, char *argv[]) {

    gtk_init(&argc, &argv);

    // wczytamy widgety z pliku *.glade za pomoca GtkBuilder
    gbuilder = gtk_builder_new();
    if ( !gtk_builder_add_from_file(gbuilder, "pwi_glade_1.glade", &gerror) ) { // jesli wystapill blad
        // klasa diagnostyczna powinna zapisac do pliku: "GBuilder error: " + std::string(gerror->message)
        g_free( gerror );
        return( 1 ); // wyjscie z programu z kodem informacji o bledzie
    }

    // gbuilder ma informacje o wszystkich widgetach zdefiniowanych w pliku glade
    // ponizej podpinamy recznie po kolei widgety o zadanych identyfikatorach do zmiennych GtkWidget* zdefiniowanych w naszym programie
    // podpinamy tylko te widgety, z ktorych zamierzamy korzystac

    gtk_window_1 = GTK_WIDGET ( gtk_builder_get_object( gbuilder, "gtk_window_1" ) );
    gtk_button_1 = GTK_WIDGET ( gtk_builder_get_object( gbuilder, "gtk_button_1" ) );
    gtk_label_1 = GTK_WIDGET ( gtk_builder_get_object( gbuilder, "gtk_label_1" ) );
    gtk_text_view_1 = GTK_WIDGET ( gtk_builder_get_object( gbuilder, "gtk_text_view_1" ) );

    gtk_builder_connect_signals( gbuilder, NULL );  // w tym projekcie automatyczne podpiecie tylko on_window_main_destroy()

    g_object_unref ( G_OBJECT( gbuilder ) );     // mozna juz usunac gbuilder

    // preferujemy takie podpinanie funkcji do sygnalow emitowanych przez widgety
    g_signal_connect ( gtk_button_1, "clicked", G_CALLBACK(on_gtk_button_1_clicked), NULL );   // reczne podpiecie funkcji do sygnalu 'clicked' dla widgetu gtk_button_1

    // ustaw rozmiar glownego okna
    gtk_window_set_default_size ( GTK_WINDOW(gtk_window_1), 800, 650 );
    // ustaw okno w centrum glownego ekranu
    gtk_window_set_position ( GTK_WINDOW(gtk_window_1), GTK_WIN_POS_CENTER );

    // a jak zmienic tytul glownego okienka ?

    // pokaz glowne okno
    gtk_widget_show ( gtk_window_1 );

    gtk_main(); // w tej petli program okienkowy tkwi, dopóki go nie zakonczymy przyciskiem 'X'

// ========================================================================================================================

    // zakonczenie przeniesiono do on_window_main_destroy

    return 0;
}

