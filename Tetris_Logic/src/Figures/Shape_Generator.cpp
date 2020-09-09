//
// Created by Przemek on 09.09.2020.
//

#include "Figures/Shape_Generator.h"

std::vector<std::vector<std::shared_ptr<Field>>>
Shape_Generator::get_shape_from_array(std::array<std::array<int, Figure::FIGURE_SIZE>, Figure::FIGURE_SIZE> array) {
    for (auto &i : array) {
        for (auto &j : i) {
            if (j != 0 && j != 1) {
                throw std::invalid_argument("Values only 1 or 0");
            }
        }
    }
    auto vector = std::vector<std::vector<std::shared_ptr<Field>>>();
    for (auto &i: array) {
        vector.emplace_back();
        for (auto &j : i) {
            (j == 1) ? vector.back().emplace_back(std::make_shared<Field>(true))
                     : vector.back().emplace_back(std::make_shared<Field>(false));
        }
    }
    return vector;
}
