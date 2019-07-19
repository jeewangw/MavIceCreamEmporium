#include "mainwin.h"
#include <exception>
#include <stdexcept>


void Mainwin::on_button1_clicked() {

// //////////////////////////////
    // Define Item
    const int WIDTH = 15;
    Gtk::Dialog dialog;
    //if (type == CONTAINER) 
    dialog.set_title("Create Container");
   // else if (type == SCOOP) dialog.set_title("Create Flavor");
   // else dialog.set_title("Create Topping");
    dialog.set_transient_for(*this);

    // Name 
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(WIDTH);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(WIDTH*4);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    // DONE: Replace this with a Gtk::TextView inside a Gtk::ScrolledWindow
    // Description
    Gtk::HBox b_desc;

    Gtk::Label l_desc{"Description:"};
    l_desc.set_width_chars(WIDTH);
    b_desc.pack_start(l_desc, Gtk::PACK_SHRINK);

    Gtk::Entry e_desc;
    e_desc.set_max_length(WIDTH*4);
  //  b_desc.pack_start(e_desc, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_desc, Gtk::PACK_SHRINK); 

    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TextView m_TextView;
    m_TextView.set_border_window_size(Gtk::TEXT_WINDOW_LEFT,4);
    m_TextView.set_border_window_size(Gtk::TEXT_WINDOW_RIGHT,4);

   //m_TextView.set_left_margin(WIDTH*4);

    m_ScrolledWindow.add(m_TextView);
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_AUTOMATIC);
	
	//m_ScrolledWindow.pack_start(e_desc, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(m_ScrolledWindow);

   

    // Cost
    Gtk::HBox b_cost;

    Gtk::Label l_cost{"Cost:"};
    l_cost.set_width_chars(WIDTH);
    b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

    Gtk::Entry e_cost;
    e_cost.set_max_length(WIDTH*4);
    b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

    // Price
    Gtk::HBox b_price;

    Gtk::Label l_price{"Price:"};
    l_price.set_width_chars(WIDTH);
    b_price.pack_start(l_price, Gtk::PACK_SHRINK);

    Gtk::Entry e_price;
    e_price.set_max_length(WIDTH*4);
    b_price.pack_start(e_price, Gtk::PACK_SHRINK);
    dialog.get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

    // Max Scoops (Container only)
    Gtk::HBox b_max_scoops;

    Gtk::Label l_max_scoops{"Max Scoops:"};
    l_max_scoops.set_width_chars(WIDTH);
    b_max_scoops.pack_start(l_max_scoops, Gtk::PACK_SHRINK);

    Gtk::Entry e_max_scoops;
    e_max_scoops.set_max_length(WIDTH*4);
    b_max_scoops.pack_start(e_max_scoops, Gtk::PACK_SHRINK);
  //  if (type == CONTAINER) {
        dialog.get_vbox()->pack_start(b_max_scoops, Gtk::PACK_SHRINK);
 //   }

    // Show dialog
    dialog.add_button("Cancel", 0);
    dialog.add_button("OK", 1);
    dialog.show_all();

    bool valid_data = false;
    double d_cost;
    double d_price;
    int i_max_scoops;

    while(!valid_data) {
        if (dialog.run() != 1) {
            dialog.close();
            return;
        }

        // Data validation
        valid_data = true;
        try {
            d_cost = std::stod(e_cost.get_text());
        } catch(std::exception e) {
            e_cost.set_text("*** invalid cost ***");
            valid_data = false;
        }
        try {
            d_price = std::stod(e_price.get_text());
        } catch(std::exception e) {
            e_price.set_text("*** invalid price ***");
            valid_data = false;
        }
      //  if (type == CONTAINER) {
            try {
                i_max_scoops = std::stoi(e_max_scoops.get_text());
            } catch(std::exception e) {
                e_max_scoops.set_text("*** invalid max scoops ***");
                valid_data = false;
            }
    //    } 

        for (int c=0; c < _emp->num_containers(); ++c) {
            if (_emp->container(c).name() == e_name.get_text()) {
                e_name.set_text("*** duplicate name ***");
                valid_data = false;
            }
        }
        for (int m=0; m < _emp->num_scoops(); ++m) {
            if (_emp->scoop(m).name() == e_name.get_text()) {
                e_name.set_text("*** duplicate name ***");
                valid_data = false;
            }
        }
        for (int t=0; t < _emp->num_toppings(); ++t) {
            if (_emp->topping(t).name() == e_name.get_text()) {
                e_name.set_text("*** duplicate name ***");
                valid_data = false;
            }
        }
    }
        
    // Instance item
 //   if (type == CONTAINER) {
        _emp->add_container(
            Mice::Container{e_name.get_text(), e_desc.get_text(), d_cost, d_price, i_max_scoops});
 /*   } else if (type == SCOOP) {
        _emp->add_scoop(
            Mice::Scoop{e_name.get_text(), e_desc.get_text(), d_cost, d_price});
    } else {
        _emp->add_topping(
            Mice::Topping{e_name.get_text(), e_desc.get_text(), d_cost, d_price, 0});
    } */
    
    dialog.close(); }
