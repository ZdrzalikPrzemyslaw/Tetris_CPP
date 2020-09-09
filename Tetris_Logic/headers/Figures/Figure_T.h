//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_T_H
#define TETRIS_FIGURE_T_H


#include "Figure.h"

class Figure_T : public Figure {
public:
    Figure_T();

    ~Figure_T();

private:
    std::vector<std::vector<std::shared_ptr<Field>>> baseShape = {
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false)),
                    std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false))},
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false)),
                    std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false))},
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false)),
                    std::make_shared<Field>(new Field(true)),  std::make_shared<Field>(new Field(false))},
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(true)),
                    std::make_shared<Field>(new Field(true)),  std::make_shared<Field>(new Field(true))}
    };
};


#endif //TETRIS_FIGURE_T_H
