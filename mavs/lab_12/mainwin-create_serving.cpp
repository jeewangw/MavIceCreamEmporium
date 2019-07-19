#include "mainwin.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <vector>

Mice::Serving Mainwin::create_serving() {
    int container = select_container();
    if (container == -1) throw std::runtime_error("Canceled");

    Mice::Serving serving{_emp->container(container)};
    _emp->use_c();
    _emp->debit(_emp->container(container).cost());
    _emp->credit(_emp->container(container).price());
    _emp->income(_emp->container(container).price());

    bool has_no_scoops = true;
    for (int i=0; i<_emp->container(container).max_scoops(); ++i) {
        int scoop = select_scoop();
        if (scoop == -1) break;
        serving.add_scoop(_emp->scoop(scoop));
        _emp->use_s();
        _emp->debit(_emp->scoop(scoop).cost());
        _emp->credit(_emp->scoop(scoop).price());
        _emp->income(_emp->scoop(scoop).price());
        has_no_scoops = false;
    }
    if (has_no_scoops) throw std::runtime_error("Canceled");

    if (_emp->num_toppings() > 0) {
        std::vector<std::string> amounts = 
            {"Light", "Normal", "Extra", "Drenched"};
        while (true) {
            int topping = select_topping();
            if (topping == -1) break;
            try {
                _emp->topping(topping).set_amount(
                    select_from_vector(amounts, "Amount")+1);
            } catch (std::exception e) {
                break;
            }
            serving.add_topping(_emp->topping(topping));
            _emp->use_t();
            _emp->debit(_emp->topping(topping).cost());
            _emp->credit(_emp->topping(topping).price());
            _emp->income(_emp->topping(topping).price());
        }
    }

    return serving;
}
