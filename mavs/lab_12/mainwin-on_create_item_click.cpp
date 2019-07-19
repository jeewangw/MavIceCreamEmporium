#include "mainwin.h"
#include <exception>
#include <stdexcept>

void Mainwin::on_create_item_click() {

	Gtk::Dialog dialog{"Select Item Types", *this};

	//flavor contents
	Gtk::Image c_img{"m_container.png"};
	Gtk::Button but{"", 1};
	but.set_image(c_img);
	but.signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_button1_clicked) );
	dialog.get_vbox()->pack_start(but, Gtk::PACK_SHRINK);

	Gtk::Image v_img{"m_flavor.png"};
	Gtk::Button but1{"", 2};
	but1.set_image(v_img);
	but1.signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_button2_clicked) );
	dialog.get_vbox()->pack_start(but1, Gtk::PACK_SHRINK);

	Gtk::Image s_img{"m_topping.png"};
	Gtk::Button but2{"", 3};
	but2.set_image(s_img);
	but2.signal_clicked().connect(sigc::mem_fun(*this,&Mainwin::on_button3_clicked) );
	dialog.get_vbox()->pack_start(but2, Gtk::PACK_SHRINK);

	dialog.show_all();
	std::cout << "ID:" << dialog.run() << '\n';
}
