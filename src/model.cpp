#include "model.hpp"

bool Model::isDead() {
    return _wounds == 0;
}