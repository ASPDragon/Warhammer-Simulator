#include <iostream>
#include <memory>
#include "datasheet.hpp"

int main() {
    std::cout << "Input character 1 params:" << std::endl;
    auto character1 = std::unique_ptr<Datasheet>();
    std::cout << "Input character 2 params:" << std::endl;
    auto character2 = std::unique_ptr<Datasheet>();
    return 0;
}