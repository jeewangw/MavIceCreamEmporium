#include "mainwin.h"

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog{};
    dialog.set_transient_for(*this);
    dialog.set_program_name("Mav's Ice Cream Emporium");
    auto logo = Gdk::Pixbuf::create_from_file("logo.png");
    dialog.set_logo(logo);
    dialog.set_version("Sprint 5");
    dialog.set_copyright("Copyright 2017");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Jeevan Gyawali"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {"Logo by Jeevan Gyawali",
                                            "Ice Cream Cone by Patrick Trouvé from the Noun Project, https://thenounproject.com/term/ice-cream-cone/63026/"};
    dialog.set_artists(artists);
    dialog.run();
}

