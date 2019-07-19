#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iomanip>

void Mainwin::on_receipt_click() {
on_order_receipt_click (select_order());

}

void Mainwin:: on_order_receipt_click (int order) {

if (0 > order || order >= _emp->num_orders () ) 
{
	Gtk::MessageDialog dialog{*this, "\nThere must be at least one order"};
        dialog.run();
        dialog.close();
	return;
}

// Convert the order to text using a string stream
std::ostringstream os;
os<< _emp->order(order) << std::endl;

 // Display the receipt in a dialog
Gtk::MessageDialog dialog{*this, "Order" + std:: to_string (_emp->order(order).id())};
dialog.set_secondary_text("<tt>"+os.str()+"</tt>",true);
dialog.run();
dialog.close();
}


void Mainwin::on_inventory_click() {
    if (_emp->num_containers() == 0 && _emp->num_scoops() == 0 && _emp->num_toppings() == 0) {
        Gtk::MessageDialog dialog{*this, "\nNo items in stock!"};
        dialog.run();
        dialog.close();
        return;
    }

    std::string report;

    std::ostringstream ic;

    if (_emp->num_containers() > 0) {
        for (int c = 0; c < _emp->num_containers(); ++c) {
            ic << _emp->container(c) << std::endl;
        }
    }
    ic << "\n";
    if (_emp->num_scoops() > 0) {
        for (int c = 0; c < _emp->num_scoops(); ++c) {
            ic << _emp->scoop(c) << std::endl;
        }
    }
    ic << "\n";
    if (_emp->num_toppings() > 0) {
        for (int c = 0; c < _emp->num_toppings(); ++c) {
            ic << _emp->topping(c) << std::endl;
        }
    }
    ic << "\n";
    ic << "\n" << std::setw(41) << "Containers in stock: " << std::setw(5) << _emp->get_amt(1);
    ic << "\n" << std::setw(41) << "Scoops in stock: " << std::setw(5) << _emp->get_amt(2);
    ic << "\n" << std::setw(41) << "Toppings in stock: " << std::setw(5) << _emp->get_amt(3);

    Gtk::MessageDialog dialog{*this, "Inventory Report"};
    dialog.set_secondary_text("<tt>" + ic.str() + "</tt>", true);
    dialog.run();
    dialog.close();

}

void Mainwin::on_statement_click() {
    std::stringstream pl;

    pl << std::setw(20) << "Cash in register: $" << std::setprecision(2) << std::fixed << _emp->cash_register();

    pl << "\n\n" << std::setw(20) << "Income: $" << std::setprecision(2) << std::fixed << _emp->get_money(1);

    pl << "\n" << std::setw(20) << "Expenses: $" << std::setprecision(2) << std::fixed << _emp->get_money(2);

    pl << "\n\n" << std::setw(20)
       << "Profit: $" << std::setprecision(2) << std::fixed << _emp->get_money(1) - _emp->get_money(2);


    Gtk::MessageDialog dialog{*this, "Profit / Loss Statement"};
    dialog.set_secondary_text("<tt>" + pl.str() + "</tt>", true);
    dialog.run();
    dialog.close();
}

void Mainwin::on_server_report_click() {
    if (_emp->num_servers() == 0) {
        Gtk::MessageDialog dialog{*this, "\nThere must be atleast one server."};
        dialog.run();
        dialog.close();
        return;
    }

    std::ostringstream stream;
    if (_emp->num_servers() > 0) {
        for (int c = 0; c < _emp->num_servers(); ++c) {

            stream << std::setw(10) << "Name: " << _emp->server(c).name() << "\n";
            stream << std::setw(10) << "Id: " << _emp->server(c).id() << "\n";
            stream << std::setw(10) << "Phone: " << _emp->server(c).phone() << "\n";
            stream << std::setw(10) << "Salary: " << std::setprecision(2) << std::fixed << _emp->server(c).salary() << "\n\n";
           
        }
    }

    Gtk::MessageDialog dialog{*this, "Server Report"};
    dialog.set_secondary_text("<tt>" + stream.str() + "</tt>", true);
    dialog.run();
    dialog.close();
}

void Mainwin::on_customer_report_click() {
    if (_emp->num_customers() == 0) {
        Gtk::MessageDialog dialog{*this, "\nThere must be atleast one customer."};
        dialog.run();
        dialog.close();
        return;
    }

    std::ostringstream stream;
    if (_emp->num_customers() > 0) {
        for (int c = 0; c < _emp->num_customers(); ++c) {

            stream << std::setw(10) << "Name: " << _emp->customer(c).name() << "\n";
            stream << std::setw(10) << "Id: " << _emp->customer(c).id() << "\n";
            stream << std::setw(10) << "Phone: " << _emp->customer(c).phone() << "\n\n";
        }
    }

    Gtk::MessageDialog dialog{*this, "Customer Report"};
    dialog.set_secondary_text("<tt>" + stream.str() + "</tt>", true);
    dialog.run();
    dialog.close();
}



void Mainwin::on_server_preperation_click() {
on_display_server_preperation_click (select_order());

}

// If any servings were added, add to orders and display the receipt
void Mainwin:: on_display_server_preperation_click (int order) {

if (0 > order || order >= _emp->num_orders () ) {
	Gtk::MessageDialog dialog{*this, "\nThere must be at least one order."};
        dialog.run();
        dialog.close();
	return;
}



 // Display the receipt in a dialog
Gtk::MessageDialog dialog{*this, "Order" + std:: to_string (_emp->order(order).id())};
dialog.set_secondary_text("<tt>"+_emp->order(order).show_server()+"</tt>",true);
dialog.run();
dialog.close();
}

void Mainwin::on_order_report_click() {
    if (_emp->num_orders() == 0) {
        Gtk::MessageDialog dialog{*this, "\nThere must be atleast one order"};
        dialog.run();
        dialog.close();
        return;
    }

    std::ostringstream stream;

    for (int c = 0; c < _emp->num_orders(); ++c) {
        if (_emp->order(c).state() == Mice::Order_state::Filled) {
            stream << std::setw(10) << "Order #"<<  _emp->order(c).id() << ": Filled\n";
        } else if (_emp->order(c).state() == Mice::Order_state::Unfilled) {
            stream << std::setw(10) << "Order #"<<  _emp->order(c).id() << ": Unfilled\n";
        } else if (_emp->order(c).state() == Mice::Order_state::Canceled) {
            stream << std::setw(10) << "Order #"<<  _emp->order(c).id() << ": Canceled\n";
        } else if (_emp->order(c).state() == Mice::Order_state::Paid) {
            stream << std::setw(10) << "Order #"<<  _emp->order(c).id() << ": Paid\n";
        }
    }

    Gtk::MessageDialog dialog{*this, "Order Report"};
    dialog.set_secondary_text("<tt>" + stream.str() + "</tt>", true);
    dialog.run();
    dialog.close();
}

