//
// Created by kuritsumplus on 18.06.2025.
//

#ifndef TEMPLATE_CPP_PROJECT_EMPTYLIBRARY_HPP
#define TEMPLATE_CPP_PROJECT_EMPTYLIBRARY_HPP

#include "current_version.hpp"

#include <iostream>

namespace Library {

class EmptyLibrary {
public:
    static int do_nothing() {
        std::cout << "Project version: " << PROJECT_VERSION << std::endl;
        std::cout << "This library do nothing." << std::endl;

        return 0;
    }
};

} // Library

#endif //TEMPLATE_CPP_PROJECT_EMPTYLIBRARY_HPP
