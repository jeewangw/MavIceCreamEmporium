#include "manager.h"

namespace Mice {
Manager::Manager(std::string name, std::string id, std::string phone, double salary)
             : Person(name, id, phone), _salary{salary}, _num_orders{0} { }
Manager::Manager(std::istream& ist) {
    // The header must have been stripped from the incoming stream at this point
    getline(ist, _name);
    getline(ist, _id);
    getline(ist, _phone);
    ist >> _salary; ist.ignore();
    ist >> _num_orders; ist.ignore();
}

void Manager::save(std::ostream& ost) {
    ost << "#" << std::endl << "MANAGER" << std::endl; // header
    ost << _name << std::endl;
    ost << _id << std::endl;
    ost << _phone << std::endl;
    ost << _salary << std::endl;
    ost << _num_orders << std::endl;
}

bool Manager::fill_order_and_pay() {
    ++_num_orders;
    return (_num_orders % PAY_PERIOD) == 0;
}
bool Manager::restock_and_pay() {
    _num_orders += 2;
    return ((_num_orders % PAY_PERIOD) == 0) 
       || (((_num_orders - 1) % PAY_PERIOD) == 0);
}
double Manager::pay_server() { }
int Manager::num_orders() {return _num_orders;}
int Manager::salary() {return _salary;}
}
