#include "EmptyLibrary.hpp"

#include <iostream>

int main(int, char**) {
    Library::EmptyLibrary::do_nothing();

    std::cout << "Project builded. CPP version -> " << __cplusplus << std::endl;
    std::cout << "Let's do domething great. Hello world!" << std::endl;

    return 0;
}
