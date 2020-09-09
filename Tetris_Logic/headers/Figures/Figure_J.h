//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_J_H
#define TETRIS_FIGURE_J_H

#include "Figure.h"


class Figure_J : public Figure {
public:
    Figure_J();

    ~Figure_J();

private:
    std::vector<std::vector<std::shared_ptr<Field>>> baseShape = {
            {std::make_shared<Field>(false), std::make_shared<Field>(false),
                    std::make_shared<Field>(false), std::make_shared<Field>(false)},
            {std::make_shared<Field>(false), std::make_shared<Field>(false),
                    std::make_shared<Field>(false), std::make_shared<Field>(false)},
            {std::make_shared<Field>(false), std::make_shared<Field>(true),
                    std::make_shared<Field>(false), std::make_shared<Field>(false)},
            {std::make_shared<Field>(false), std::make_shared<Field>(true),
                    std::make_shared<Field>(true), std::make_shared<Field>(true)}
    };
};


#endif //TETRIS_FIGURE_J_H
