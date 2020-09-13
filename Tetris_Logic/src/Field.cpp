//
// Created by Przemek on 09.09.2020.
//

#include "Field.h"

bool Field::isTaken() const {
    return is_taken;
}

Field::Field() {
    this->is_taken = false;
}

Field::~Field() = default;

void Field::setIsTaken(bool isTaken) {
    this->is_taken = isTaken;
}


std::string Field::toString() const {
    return this->is_taken ? "1" : "0";
}

Field::Field(bool isTaken) {
    this->is_taken = isTaken;
}

bool operator==(const Field &lhs, const Field &rhs) {
    return lhs.isTaken() == rhs.isTaken();
}

bool operator!=(const Field &lhs, const Field &rhs) {
    return !(lhs == rhs);
}
