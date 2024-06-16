#pragma once

class Datasheet;

class Unit {
public:
    Unit(Datasheet& datasheet);
    
private:
    Datasheet& _datasheet;
};