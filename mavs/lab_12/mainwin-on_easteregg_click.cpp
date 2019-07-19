#include "mainwin.h"

void Mainwin::on_easteregg_click() {
        _emp->add_container(
            Mice::Container{"Cone", "Crispy airy delight", 0.25, 0.50, 2});
        _emp->stock_c();
        _emp->add_container(
            Mice::Container{"Waffle Cone", "Crunchy wrapped waffle cake", 0.35, 0.75, 3});
        _emp->stock_c();
        _emp->add_scoop(
            Mice::Scoop{"Chocolate", "Rich smooth chocolate ice cream", 0.20, 0.50});
        _emp->stock_s();
        _emp->add_scoop(
            Mice::Scoop{"Vanilla", "Real vanilla bean ice cream", 0.20, 0.50});
        _emp->stock_s();
        _emp->add_scoop(
            Mice::Scoop{"Strawberry", "Chunks of strawberry wrapped in vanilla ice cream", 0.20, 0.50});
        _emp->stock_s();
        _emp->add_topping(
            Mice::Topping{"Cherry", "Classic marichino cherry", 0.1, 0.2, 0});
        _emp->stock_t();
        _emp->add_topping(
            Mice::Topping{"Chocolate Sauce", "Rich thick chocolate", 0.1, 0.25, 0});
        _emp->stock_t();
        _emp->add_topping(
            Mice::Topping{"Whipped Cream", "Real sweet cream whipped to perfection", 0.1, 0.2, 0});
        _emp->stock_t();


        _emp->add_customer(
            Mice::Customer{"Ayush Karki", "LAPD", "817-555-7714"});
        _emp->add_customer(
            Mice::Customer{"Pujan Budathoki", "Glitter", "817-555-2234"});

        _emp->add_server(
            Mice::Server{"Amit Khanal", "BBT", "817-555-1212", 8.25});
        _emp->add_server(
            Mice::Server{"Rajesh Hamal", "Friends", "817-555-1213", 10.75});
        _emp->add_server(
            Mice::Server{"Hemanta Sharma", "BWidowers", "817-555-1214", 15.00});

        _emp->credit(200);

        Gtk::MessageDialog dialog{*this, "Added 2 containers, 3 scoops, 3 toppings,\n3 servers, 2 customers"
                "\nand $200 to cash register"};

        dialog.run();
        dialog.close();
 }

