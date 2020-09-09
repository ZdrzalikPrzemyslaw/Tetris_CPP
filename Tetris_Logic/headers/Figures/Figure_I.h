//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_I_H
#define TETRIS_FIGURE_I_H


#include "Figures/Figure.h"

class Figure_I : public Figure {
public:
    Figure_I();

    ~Figure_I();

private:
    std::vector<std::vector<std::shared_ptr<Field>>> baseShape = {
            {std::make_shared<Field>(false), std::make_shared<Field>(false),
                    std::make_shared<Field>(false), std::make_shared<Field>(false)},
            {std::make_shared<Field>(false), std::make_shared<Field>(false),
                    std::make_shared<Field>(false), std::make_shared<Field>(false)},
            {std::make_shared<Field>(true), std::make_shared<Field>(true),
                    std::make_shared<Field>(true), std::make_shared<Field>(true)},
            {std::make_shared<Field>(false),  std::make_shared<Field>(false),
                    std::make_shared<Field>(false),  std::make_shared<Field>(false)}
    };
};


#endif //TETRIS_FIGURE_I_H
