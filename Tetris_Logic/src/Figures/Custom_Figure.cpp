//
// Created by Przemek on 09.09.2020.
//

#include <iostream>
#include "Figures/Custom_Figure.h"

Custom_Figure::Custom_Figure(const std::vector<std::vector<Field *>> &shape) : Figure() {
    for (auto &i : shape) {
        this->shape.emplace_back();
        for (auto &j : i) {
            this->shape.back().push_back(std::make_shared<Field>(*j));
        }
    }
}
