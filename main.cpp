#include "EmptyLibrary.hpp"

#include <iostream>

#include "ip_filter.hpp"

int main(int, char**) {
    sort_ip_addresses(std::vector<std::string>{ "192.168.0.1", "192.168.1.1", "192.168.10.1" });
    Library::EmptyLibrary::do_nothing();

    std::cout << "Project builded. CPP version -> " << __cplusplus << std::endl;
    std::cout << "Let's do domething great. Hello world!" << std::endl;

    return 0;
}
