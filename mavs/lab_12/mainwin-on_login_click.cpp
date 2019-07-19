#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include "dialogs.h"

void Mainwin::mywindow()
{

std::string title, author;

   // Gtk::Dialog *dialog = new Gtk::Dialog();
    Gtk::Dialog dialog;
   // dialog->set_title("Login to Use App");

    // USERNAME
    Gtk::HBox b_title;

    Gtk::Label l_title{"User Name:"};
    l_title.set_width_chars(15);
    b_title.pack_start(l_title, Gtk::PACK_SHRINK);

    Gtk::Entry e_title;
    e_title.set_max_length(50);
    b_title.pack_start(e_title, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_title, Gtk::PACK_SHRINK);

    // PASSWORD
    Gtk::HBox b_author;

    Gtk::Label l_author{"Password:"};
    l_author.set_width_chars(15);
    b_author.pack_start(l_author, Gtk::PACK_SHRINK);

    Gtk::Entry e_author;
    e_author.set_max_length(50);
    e_author.set_visibility(false);
    b_author.pack_start(e_author, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_author, Gtk::PACK_SHRINK);


    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all();
    int result = dialog.run();

    dialog.close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    title = e_title.get_text();
    author = e_author.get_text();
   
    if (result == 1) {
    
// VERIFY ID AND PASSWORD 

	if(title.compare("admin") == 0 && author.compare("password") == 0)
    {
    
	cout << "Login Successful" ;
    }
else
    {
	mywindow();

    }
}
else { mywindow(); }
 }

