#ifndef MAINWIN_H
#define MAINWIN_H

#include "manager.h"
#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "serving.h"
#include "order.h"
#include "server.h"
#include "customer.h"
#include "emporium.h"
#include <gtkmm.h>
#include <string>

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
	void on_edit_repeated_server_click(int c); //loop to edit server salary
	void on_edit_server_click(); //Edit Server Salary
	void on_order_report_click();  // Add Order Report
	void on_inventory_click();  // Inventory Report
	void on_server_report_click();  // Server Report
	void on_customer_report_click(); // Customer Report
	void on_statement_click();  // ALL PROFIT AND LOSS REPORT
	Gtk::Label *msg;                      // Status message display
	void display_time();			//Display time
	void on_button1_clicked();    // Select item CONTAINER
	void on_button2_clicked();    // Select item FLAVOR
	void on_button3_clicked();    // Select item TOPPINGS
	void on_exit_click();				// Exit Screen
	void on_logout_click();				//Logout
	void on_selectuser_click();			// Select User
	void on_welcome_click();			// Welcome Screen
	void mywindow ();				// Login All
	void mywindow1 ();				// Login Owner
	void mywindow2 ();				// Login Manager
	void mywindow3();				// Login Server
	void mywindow4 ();				// Login Customer
	void on_receipt_click();   			// On Order Receipt Click
	void on_server_preperation_click();	// On Server Prep Click

	void on_file_new_click();  //On New Emporium Click
        void on_file_open_click();                     // Open an Emporium file
        void on_file_save_click();                     // Save an Emporium file
        void on_create_order_click();                  // Create a new order
        void on_create_item_click();                   // Create a new item
        void on_create_server_click();                 // Create a new server
        void on_create_customer_click();               // Create a new customer
	void on_create_manager_click();               // Create a new manager

        void on_fill_order_click();                    // Fill an order
        void on_pay_for_order_click();                 // Pay for an order
        void on_cancel_order_click();                  // Cancel an order
        void on_all_click();                           // Select all roles
        void on_owner_click();                         // Select owner role
        void on_manager_click();                       // Select manager role
        void on_server_click();                        // Select server role
        void on_customer_click();                      // Select customer role
        void on_about_click();                         // Display About dialog
        void on_quit_click();                          // Exit the program
        void on_easteregg_click();                     // TODO: For test only
	
    private:
        Gtk::MenuItem *menuitem_new;
        Gtk::MenuItem *menuitem_open;
        Gtk::MenuItem *menuitem_save;
        Gtk::MenuItem *menuitem_easteregg;
        Gtk::MenuItem *menuitem_quit;
        Gtk::MenuItem *menuitem_order;
        Gtk::MenuItem *menuitem_customer;
        Gtk::MenuItem *menuitem_item;
        Gtk::MenuItem *menuitem_server;
	Gtk::MenuItem *menuitem_manager;
        Gtk::MenuItem *menuitem_fill_order;
        Gtk::MenuItem *menuitem_pay_for_order;
        Gtk::MenuItem *menuitem_cancel_order;

        Gtk::ToolButton *new_emporium_button;
        Gtk::ToolButton *create_order_button;
        Gtk::ToolButton *create_item_button;
	Gtk::ToolButton *create_time_button;


        void create_order();                           // Create a new order
        Mice::Serving create_serving();                // Create a new serving
        int select_container();                        // Select a container index
        int select_scoop();                            // Select a scoop index
        int select_topping();                          // Select a container index
        int select_customer();                         // Select a customer index
        int select_order(Mice::Order_state state);     // Select an order index by state
	 int select_order();     // Select an order index
	 
        int select_server();                           // Select a server index
        int select_from_vector
            (std::vector<std::string> names, 
             std::string title);                       // Select from a list of strings
        void on_create_person_click(std::string role); // Create a new person
        void on_order_receipt_click(int order);      // Order receipt
	void on_display_server_preperation_click(int order);  // Display server preperation receipt
        Mice::Emporium* _emp;                          // Currently active emporium
};
#endif 

