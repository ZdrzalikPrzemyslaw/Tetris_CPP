//
// Created by Przemek on 09.09.2020.
//

#include <iostream>
#include "Figures/Custom_Figure.h"

Custom_Figure::Custom_Figure(const std::vector<std::vector<std::shared_ptr<Field>>> &shape) : Figure() {
    this->shape = shape;
}
