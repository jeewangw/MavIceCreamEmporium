#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include<ctime>


Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(500, 400);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //
    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         N E W   E M P O R I U M
    // (Owner) “Create a New Emporium” Append New to the File menu
    menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Emporium", true));
     menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_file_new_click));
    filemenu->append(*menuitem_new);

    //         O P E N   E M P O R I U M
    // (Owner) “Open an Emporium File” Append Open to the File menu
    menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_file_open_click));
    filemenu->append(*menuitem_open);

    //         S A V E   E M P O R I U M
    // (Owner) “Save an Emporium File” Append Save to the File menu
    menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_file_save_click));
    filemenu->append(*menuitem_save);

    //         E A S T E R   E G G
    // (TODO: Test Only) “Create a New Emporium” Append Easter Egg to the File menu
    menuitem_easteregg = Gtk::manage(new Gtk::MenuItem("_Easter Egg", true));
    menuitem_easteregg->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_easteregg_click));
    filemenu->append(*menuitem_easteregg);

    //         Q U I T
    // Append Quit to the File menu
    menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);

    //
    //     E D I T
    // Create a Edit menu and add to the menu bar
    Gtk::MenuItem *menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit", true));
    menubar->append(*menuitem_edit);
    Gtk::Menu *editmenu = Gtk::manage(new Gtk::Menu());
    menuitem_edit->set_submenu(*editmenu);

    //       E D I T   S E R V E R
    // (Owner, Manager) “Add a New Employee” Append Server to the Create menu
    Gtk::MenuItem *menuitem_edserver = Gtk::manage(new Gtk::MenuItem("_Edit Server...", true));
    menuitem_edserver->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_edit_server_click));
    editmenu->append(*menuitem_edserver);

    //
    //     C R E A T E
    // Create a Create menu and add to the menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);

    //         O R D E R
    // (All) “Create Delicious Ice Cream Treats” Append Order to the Create menu
    menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order...", true));
    menuitem_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    createmenu->append(*menuitem_order);

    //         C U S T O M E R
    // (Server, Manager, Owner) “Create a New Customer” Append Customer to the Create menu
    menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer...", true));
    menuitem_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_customer_click));
    createmenu->append(*menuitem_customer);

    //         I T E M 
    // (Owner, Manager) “Create a New Container, Ice Cream Flavor, or Topping” Append Item to the Create menu
    menuitem_item = Gtk::manage(new Gtk::MenuItem("_Item...", true));
    menuitem_item->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
    createmenu->append(*menuitem_item);

    //         S E R V E R
    // (Owner, Manager) “Add a New Employee” Append Server to the Create menu
    menuitem_server = Gtk::manage(new Gtk::MenuItem("_Server...", true));
    menuitem_server->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_server_click));
    createmenu->append(*menuitem_server);

    //         M A N A G E R
    // (Owner) “Add a New Manager” Append Manager to the Create menu
    menuitem_manager = Gtk::manage(new Gtk::MenuItem("_Manager...", true));
    menuitem_manager->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_manager_click));
    createmenu->append(*menuitem_manager);

    //
    //     P R O C E S S
    // Create a Process menu and add to the menu bar
    Gtk::MenuItem *menuitem_process = Gtk::manage(new Gtk::MenuItem("_Process", true));
    menubar->append(*menuitem_process);
    Gtk::Menu *processmenu = Gtk::manage(new Gtk::Menu());
    menuitem_process->set_submenu(*processmenu);

    //         F I L L   O R D E R
    // (Server) “_Fill Order..."
    menuitem_fill_order = Gtk::manage(new Gtk::MenuItem("_Fill Order", true));
    menuitem_fill_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_fill_order_click));
    processmenu->append(*menuitem_fill_order);

    //         P A Y
    // (All) “_Pay.."
    menuitem_pay_for_order = Gtk::manage(new Gtk::MenuItem("_Pay for Order", true));
    menuitem_pay_for_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_pay_for_order_click));
    processmenu->append(*menuitem_pay_for_order);

    //         C A N C E L   O R D E R
    // (Customer, Server) “_Fill Order...", true));
    menuitem_cancel_order = Gtk::manage(new Gtk::MenuItem("_Cancel Order", true));
    menuitem_cancel_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_cancel_order_click));
    processmenu->append(*menuitem_cancel_order);

    //     R E P O R T
    // Create a Report menu and add to the menu bar
    Gtk::MenuItem *menuitem_report = Gtk::manage(new Gtk::MenuItem("_Report", true));
    menubar->append(*menuitem_report);
    Gtk::Menu *reportmenu = Gtk::manage(new Gtk::Menu());
    menuitem_report->set_submenu(*reportmenu);


    //           R E C E I P T
    // Append Receipt to the Report menu
    Gtk::MenuItem *menuitem_receipt_report = Gtk::manage(new Gtk::MenuItem("_Receipt", true));
    menuitem_receipt_report->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_receipt_click));
    reportmenu->append(*menuitem_receipt_report);

    //           S E R V E R   P R E P
    // Append Server Prep to the Report menu
    Gtk::MenuItem *menuitem_server_prep_report = Gtk::manage(new Gtk::MenuItem("_Server Preperation", true));
    menuitem_server_prep_report->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_server_preperation_click));
    reportmenu->append(*menuitem_server_prep_report);

    //           P R O F I T   A N D  L O S S
    // Append Profit and Loss Statement to the view menu
    Gtk::MenuItem *menuitem_statement = Gtk::manage(new Gtk::MenuItem("_Profit/Loss Statement", true));
    menuitem_statement->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_statement_click));
    reportmenu->append(*menuitem_statement);

    //           I N V E N T O R Y
    // Append Inventory to the view menu
    Gtk::MenuItem *menuitem_inventory = Gtk::manage(new Gtk::MenuItem("_Inventory", true));
    menuitem_inventory->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_inventory_click));
    reportmenu->append(*menuitem_inventory);

    //           S E R V E R   R E P O R T
    // Append Inventory to the view menu
    Gtk::MenuItem *menuitem_server_report = Gtk::manage(new Gtk::MenuItem("_Server Report", true));
    menuitem_server_report->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_server_report_click));
    reportmenu->append(*menuitem_server_report);

    //           C U S T O M E R   R E P O R T
    // Append Inventory to the view menu
    Gtk::MenuItem *menuitem_customer_report = Gtk::manage(new Gtk::MenuItem("_Customer Report", true));
    menuitem_customer_report->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_customer_report_click));
    reportmenu->append(*menuitem_customer_report);

 //           O R D E R   R E P O R T
    // Append Inventory to the view menu
    Gtk::MenuItem *menuitem_order_report = Gtk::manage(new Gtk::MenuItem("_Order Report", true));
    menuitem_order_report->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_order_report_click));
    reportmenu->append(*menuitem_order_report);



    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
    helpmenu->append(*menuitem_about);

    //           L O G  O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_logout = Gtk::manage(new Gtk::MenuItem("Log Out", true));
    menuitem_logout->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_logout_click));
    helpmenu->append(*menuitem_logout);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //     N E W   E M P O R I U M
    // Add a new emporium icon
    new_emporium_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_emporium_button->set_tooltip_markup("Create a New Emporium");
    new_emporium_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_file_new_click));
    toolbar->append(*new_emporium_button);

    //     C R E A T E   O R D E R
    // Add a Create Order icon
    Gtk::Image *create_order_button_image = Gtk::manage(new Gtk::Image("new_order.png"));
    create_order_button = Gtk::manage(new Gtk::ToolButton(*create_order_button_image));
    create_order_button->set_tooltip_markup("Create a new order");
    create_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
    toolbar->append(*create_order_button);

    //     C R E A T E   C R E A T E   I T E M
    // Add a Create Item icon
    Gtk::Image *create_item_button_image = Gtk::manage(new Gtk::Image("create_item.png"));
    create_item_button = Gtk::manage(new Gtk::ToolButton(*create_item_button_image)); 


    create_item_button->set_tooltip_markup("Create a new item");
    create_item_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_item_click));
    toolbar->append(*create_item_button);

//     D I S P L A Y  T I M E
    // Add a Clock icon
    Gtk::Image *create_time_button_image = Gtk::manage(new Gtk::Image("time.png"));
    create_time_button = Gtk::manage(new Gtk::ToolButton(*create_time_button_image));
    create_time_button->set_tooltip_markup("Display Time");
    create_time_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::display_time));
Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*create_time_button);

    //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit MICE");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
 //   Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
  //  sep->set_expand(true);  // The expanding sep forces the Quit button to the right
  //  toolbar->append(*sep);
    toolbar->append(*quit_button);

   // SELECT USER
    on_selectuser_click();

   

   // STARTING WINDOW
    on_welcome_click();

  // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);
 
// GET LOCAL TIME IN STATUS BAR
time_t curr_time;
curr_time = time(NULL);

tm *tm_local = localtime(&curr_time);

std::cout << "Current local time : " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec;

std::string result;
std::string s1 = "Current Local Time : ";

// Changing integer to string
int n2 = tm_local->tm_hour;
std::string s2;
std::ostringstream convert;
convert << n2;
s2 = convert.str();

std::string s3 = ":";

// Changing integer to string
int n4 = tm_local->tm_min;
std::string s4;
std::ostringstream convert1;
convert1 << n4;
s4 = convert1.str();

std::string s5 = ":";

// Changing integer to string
int n6 = tm_local->tm_sec;
std::string s6;
std::ostringstream convert2;
convert2 << n6;
s6 = convert2.str();

result = s1 + s2 + s3 + s4 + s5 + s6;


     // s collects the status message
    Glib::ustring s = result;

    // Display the collected status on the status bar
    msg->set_markup(s);

	// REFRESH TIME IN EVERY 5 SECONDS
	display_time();

    // Make the box and everything in it visible
    vbox->show_all();

    // Start with a default emporium
    _emp = new Mice::Emporium{"Default"};
    set_title("Mav's Ice Cream Emporium");

	
}

Mainwin::~Mainwin() { }

void Mainwin::on_quit_click() {
   on_exit_click();
    hide();
}

// Set sensitivities based on role

void Mainwin::on_all_click() {
    menuitem_new->set_sensitive(true);
   menuitem_open->set_sensitive(true);
    menuitem_save->set_sensitive(true);
    menuitem_easteregg->set_sensitive(true);
    menuitem_quit->set_sensitive(true);
    menuitem_order->set_sensitive(true);
    menuitem_customer->set_sensitive(true);
    menuitem_item->set_sensitive(true);
    menuitem_server->set_sensitive(true);
    menuitem_manager->set_sensitive(true);
    menuitem_fill_order->set_sensitive(true);
    menuitem_pay_for_order->set_sensitive(true);
    menuitem_cancel_order->set_sensitive(true);

    new_emporium_button->set_sensitive(menuitem_new->get_sensitive());
    create_order_button->set_sensitive(menuitem_order->get_sensitive());
    create_item_button->set_sensitive(menuitem_item->get_sensitive());
}

void Mainwin::on_owner_click() {
    menuitem_new->set_sensitive(true);
    menuitem_open->set_sensitive(true);
    menuitem_save->set_sensitive(true);
    menuitem_easteregg->set_sensitive(true);
    menuitem_quit->set_sensitive(true);
    menuitem_order->set_sensitive(true);
    menuitem_customer->set_sensitive(true);
    menuitem_item->set_sensitive(true);
    menuitem_server->set_sensitive(true);
    menuitem_server->set_sensitive(true);
    menuitem_fill_order->set_sensitive(true);
    menuitem_pay_for_order->set_sensitive(true);
    menuitem_cancel_order->set_sensitive(true);

    new_emporium_button->set_sensitive(menuitem_new->get_sensitive());
    create_order_button->set_sensitive(menuitem_order->get_sensitive());
    create_item_button->set_sensitive(menuitem_item->get_sensitive());
}

void Mainwin::on_manager_click() {
    menuitem_new->set_sensitive(false);
    menuitem_open->set_sensitive(true);
    menuitem_save->set_sensitive(true);
    menuitem_easteregg->set_sensitive(true);
    menuitem_quit->set_sensitive(true);
    menuitem_order->set_sensitive(true);
    menuitem_customer->set_sensitive(true);
    menuitem_manager->set_sensitive(false);
    menuitem_item->set_sensitive(true);
    menuitem_server->set_sensitive(true);
    menuitem_fill_order->set_sensitive(true);
    menuitem_pay_for_order->set_sensitive(true);
    menuitem_cancel_order->set_sensitive(true);

    new_emporium_button->set_sensitive(menuitem_new->get_sensitive());
    create_order_button->set_sensitive(menuitem_order->get_sensitive());
    create_item_button->set_sensitive(menuitem_item->get_sensitive());
}

void Mainwin::on_server_click() {
    menuitem_new->set_sensitive(false);
    menuitem_open->set_sensitive(false);
    menuitem_save->set_sensitive(false);
    menuitem_easteregg->set_sensitive(false);
    menuitem_quit->set_sensitive(true);
    menuitem_order->set_sensitive(true);
    menuitem_customer->set_sensitive(true);
    menuitem_server->set_sensitive(false);
    menuitem_item->set_sensitive(false);
    menuitem_manager->set_sensitive(false);
    menuitem_fill_order->set_sensitive(true);
    menuitem_pay_for_order->set_sensitive(true);
    menuitem_cancel_order->set_sensitive(true);

    new_emporium_button->set_sensitive(menuitem_new->get_sensitive());
    create_order_button->set_sensitive(menuitem_order->get_sensitive());
    create_item_button->set_sensitive(menuitem_item->get_sensitive());
}

void Mainwin::on_customer_click() {
    menuitem_new->set_sensitive(false);
    menuitem_open->set_sensitive(false);
    menuitem_save->set_sensitive(false);
    menuitem_easteregg->set_sensitive(false);
    menuitem_quit->set_sensitive(true);
    menuitem_order->set_sensitive(true);
    menuitem_customer->set_sensitive(false);
    menuitem_manager->set_sensitive(false);
    menuitem_item->set_sensitive(false);
    menuitem_server->set_sensitive(false);
    menuitem_fill_order->set_sensitive(false);
    menuitem_pay_for_order->set_sensitive(false);
    menuitem_cancel_order->set_sensitive(true);

    new_emporium_button->set_sensitive(menuitem_new->get_sensitive());
    create_order_button->set_sensitive(menuitem_order->get_sensitive());
    create_item_button->set_sensitive(menuitem_item->get_sensitive());
}

