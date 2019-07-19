#ifndef EMPORIUM_H
#define EMPORIUM_H

#include "container.h"
#include "scoop.h"
#include "topping.h"
#include "serving.h"
#include "order.h"
#include "server.h"
#include "customer.h"
#include "manager.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace Mice {

class Emporium {
    public:
        Emporium(std::string name);
        Emporium(std::istream& ist);
        void save(std::ostream& ost);

        std::string name();
        double cash_register();
        void debit(double amount);
        void credit(double amount);
        int next_id();

        int num_containers();
        int num_scoops();
        int num_toppings();
        int num_orders();
        int num_servers();
        int num_customers();
	int num_managers();

        Container& container(int index);
        Scoop& scoop(int index);
        Topping& topping(int index);
        Order& order(int index);
        Server& server(int index);
        Customer& customer(int index);
	Manager& manager(int index);

        void add_container(Container container);
        void add_scoop(Scoop scoop);
        void add_topping(Topping topping);
        void add_order(Order order);
        void add_server(Server server);
        void add_customer(Customer customer);
        void add_manager(Manager manager);

        void stock_c();
        void stock_s();
        void stock_t();

        void use_c();
        void use_s();
        void use_t();

        int get_amt(int n);
        double get_money(int n);
        void income(double amount);

    private:
        std::string _name;
        double _cash_register = 0;
        int _id;

        int _amt_c = 0;
        int _amt_s = 0;
        int _amt_t = 0;

        double _income = 0;
        double _expenses = 0;

        std::vector<Mice::Container> _containers;      // All defined containers
        std::vector<Mice::Scoop> _scoops;              // All defined scoops
        std::vector<Mice::Topping> _toppings;          // All defined toppings
        std::vector<Mice::Order> _orders;              // All defined orders
        std::vector<Mice::Server> _servers;            // All defined servers
        std::vector<Mice::Customer> _customers;        // All defined customers
        std::vector<Mice::Manager> _managers;
};

}
#endif 

