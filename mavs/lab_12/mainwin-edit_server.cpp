#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iomanip>

void Mainwin::on_edit_server_click() {
 if (_emp->num_servers() == 0) {
        Gtk::MessageDialog dialog{*this, "\nThere must be atleast one server."};
        dialog.run();
        dialog.close();
        return;
    }
for (int c = 0; c < _emp->num_servers(); ++c) {
on_edit_repeated_server_click(c);
}
}
void Mainwin::on_edit_repeated_server_click(int c) {


if (_emp->num_servers() > 0) {
 
    const int WIDTH = 15;

    Gtk::Dialog dialog{"Edit Server", *this};
    // Name 
    Gtk::HBox b_name;
	std::string name1 = _emp->server(c).name();
	std::string name2 = "     Name : ";
	std::string result = name2 + name1;
    Gtk::Label l_name{result};
    l_name.set_width_chars(WIDTH);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(WIDTH*4);
  //  b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    // ID
    Gtk::HBox b_id;
	std::string id1 = _emp->server(c).id();
	std::string id2 = "     ID : ";
	std::string result1 = id2 + id1;
    Gtk::Label l_id{result1};
    l_id.set_width_chars(WIDTH);
    b_id.pack_start(l_id, Gtk::PACK_SHRINK);

    Gtk::Entry e_id;
    e_id.set_max_length(WIDTH*4);
  //  b_id.pack_start(e_id, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_id, Gtk::PACK_SHRINK);

    // Phone
    Gtk::HBox b_phone;
	std::string phone1 = _emp->server(c).phone();
	std::string phone2 = "     Phone : ";
	std::string result2 = phone2 + phone1;
    Gtk::Label l_phone{result2};
    l_phone.set_width_chars(WIDTH);
    b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

    Gtk::Entry e_phone;
    e_phone.set_max_length(WIDTH*4);
 //   b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    // Salary (Server and Manager only)
    Gtk::HBox b_salary;

    Gtk::Label l_salary{"Hourly Wage:"};
    l_salary.set_width_chars(WIDTH);
    b_salary.pack_start(l_salary, Gtk::PACK_SHRINK);

    Gtk::Entry e_salary;
    e_salary.set_max_length(WIDTH*4);
    b_salary.pack_start(e_salary, Gtk::PACK_SHRINK);
  //  if (role == "Server" || role == "Manager") {
        dialog.get_vbox()->pack_start(b_salary, Gtk::PACK_SHRINK);
 //   } 

    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all(); 

    double d_salary;
    bool valid_data = false;

    while(!valid_data) {
        if (dialog.run() != 1) {
            dialog.close();
            return;
        }

        // Data validation
        valid_data = true;

        if (e_name.get_text().length() == 0) {
            e_name.set_text("*** name is required ***");
            valid_data = false;
        }

        if (e_id.get_text().length() == 0) {
            e_id.set_text("*** id is required ***");
            valid_data = false;
        }

        if (e_phone.get_text().length() == 0) {
            e_phone.set_text("*** phone is required ***");
            valid_data = false;
        }

     //   if (role == "Server" || role == "Manager") {
            try {
                d_salary = std::stod(e_salary.get_text());
            } catch(std::exception e) {
                e_salary.set_text("*** invalid salary ***");
                valid_data = false;
            }
     //   }


        for (int s=0; s < _emp->num_servers(); ++s) {
            if (_emp->server(s).name() == e_name.get_text()) {
                e_name.set_text("*** duplicate name ***");
                valid_data = false;
            }
            if (_emp->server(s).id() == e_id.get_text()) {
                e_id.set_text("*** duplicate id ***");
                valid_data = false;
            }
        }
    }
        
    // Instance person
  //  if (role == "Server") {
        Mice::Server s{name1, id1, phone1, d_salary};
        _emp->add_server(s);
    
//std::cout << "TEST DONE " << std::endl;
 //   }
    
    dialog.close();
} 
}
