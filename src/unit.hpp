#pragma once

#include <vector>

class Datasheet;
class Model;

class Unit {
public:
    Unit();
    
private:
    std::vector<Model> unit;
};