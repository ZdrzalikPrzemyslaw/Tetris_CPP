//
// Created by Przemek on 09.09.2020.
//

#include <iostream>
#include "Figures/Shape_Generator.h"

std::vector<std::vector<std::shared_ptr<Field>>>
Shape_Generator::get_shape_from_vector(std::vector<std::vector<int>> vector) {
    for (auto &i : vector) {
        for (auto &j : i) {
            if (j != 0 && j != 1) {
                throw std::invalid_argument("Values only 1 or 0");
            }
        }
    }
    auto vector_ret = std::vector<std::vector<std::shared_ptr<Field>>>();
    for (auto &i: vector) {
        vector_ret.emplace_back();
        for (auto &j : i) {
            (j == 1) ? vector_ret.back().emplace_back(std::make_shared<Field>(true))
                     : vector_ret.back().emplace_back(std::make_shared<Field>(false));
        }
    }
    return vector_ret;
}
