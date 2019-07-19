#include "mainwin.h"

void Mainwin::on_selectuser_click() {

    // /////////////////////////////
    // Select USER Type
    Gtk::Dialog dialog_type{"Select User Type", *this};
    //dialog_type.set_title("Select Item Type");
    const int WIDTH = 15;

    // Type
    Gtk::HBox b_type;

    Gtk::Label l_type{"Type:"};
    l_type.set_width_chars(WIDTH);
    b_type.pack_start(l_type, Gtk::PACK_SHRINK);

    // TODO: Replace this with 3 large, colorful buttons
    Gtk::ComboBoxText c_type;
    c_type.set_size_request(WIDTH*10);
    const int ALL = 0;
    c_type.append("All User");
    const int OWNER = 1;
    c_type.append("Owner");
    const int MANAGER = 2;
    c_type.append("Manager");
    const int SERVER = 3;
    c_type.append("Server");
    const int CUSTOMER = 4;
    c_type.append("Customer");
    
    b_type.pack_start(c_type, Gtk::PACK_SHRINK);
    dialog_type.get_vbox()->pack_start(b_type, Gtk::PACK_SHRINK);

    // Show dialog_type
    dialog_type.add_button("Cancel", 0);
    dialog_type.add_button("OK", 1);
    dialog_type.show_all();
    if (dialog_type.run() != 1) {
        dialog_type.close();
	on_selectuser_click();
        return;
    }

    int type = c_type.get_active_row_number();

    dialog_type.close();

    // //////////////////////////////
    // Define Item

   // Gtk::Dialog dialog;
    if (type == ALL) 
{
    on_all_click();

//LOGIN SCREEN DISPLAY
     mywindow();
}
    else if (type == OWNER) {
    on_owner_click();
//LOGIN SCREEN DISPLAY
     mywindow1();
}
    else if (type == MANAGER) {
    on_manager_click(); 
//LOGIN SCREEN DISPLAY
     mywindow2();
}
    else if (type == SERVER) {
    on_server_click();
//LOGIN SCREEN DISPLAY
     mywindow3();
 }
    else {
	on_customer_click();
//LOGIN SCREEN DISPLAY
   //  mywindow4();
}

}

