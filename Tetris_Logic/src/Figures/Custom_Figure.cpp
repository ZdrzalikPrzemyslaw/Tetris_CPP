//
// Created by Przemek on 09.09.2020.
//

#include <iostream>
#include "Figures/Custom_Figure.h"

Custom_Figure::Custom_Figure(const std::vector<std::vector<Field *>> &shape) : Figure() {
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            this->shape[i][j] = std::shared_ptr<Field>(shape[i][j]);
        }
    }
}
