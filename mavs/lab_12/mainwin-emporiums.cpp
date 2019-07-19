#include "mainwin.h"
#include "emporium.h"
#include <exception>
#include <stdexcept>

void Mainwin::on_file_open_click() {
    try {
        std::ifstream ifs{"emporium.emp", std::ifstream::in};
        _emp = new Mice::Emporium{ifs};
    } catch (std::exception& e) {
        Gtk::MessageDialog dialog{*this, "Unable to open emporium.emp"};
        dialog.set_secondary_text(e.what());
        dialog.run();
        dialog.close();
    }
}

void Mainwin::on_file_save_click() {
    try {
        std::ofstream ofs{"emporium.emp", std::ofstream::out};
        _emp->save(ofs);
    } catch (std::exception& e) {
        Gtk::MessageDialog dialog{*this, "Unable to save emporium.emp"};
        dialog.set_secondary_text(e.what());
        dialog.run();
        dialog.close();
    }
}

void Mainwin::on_file_new_click() {

	const int WIDTH = 15;

	Gtk::Dialog dlg{"New Emporium", *this};

	Gtk::Label l_st{"Do you want to save your current emporium?"};
	dlg.get_vbox()->pack_start(l_st, Gtk::PACK_SHRINK);

	dlg.add_button("Cancel", 2);
	dlg.add_button("No", 0);
	dlg.add_button("Yes", 1);

	dlg.show_all();
	int result = dlg.run();

	if(result == 2) return;

	if(result == 1) on_file_save_click();
}

