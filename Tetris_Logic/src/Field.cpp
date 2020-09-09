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

Field::~Field() {

}

void Field::setIsTaken(bool isTaken) {
    this->is_taken = isTaken;
}