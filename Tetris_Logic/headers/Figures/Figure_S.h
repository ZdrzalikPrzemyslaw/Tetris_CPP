//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_S_H
#define TETRIS_FIGURE_S_H


#include "Figure.h"

class Figure_S : public Figure {
public:
    Figure_S();

    ~Figure_S();

private:
    std::vector<std::vector<std::shared_ptr<Field>>> baseShape = {
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false)),
                    std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false))},
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false)),
                    std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false))},
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(true)),
                    std::make_shared<Field>(new Field(true)),  std::make_shared<Field>(new Field(false))},
            {std::make_shared<Field>(new Field(true)), std::make_shared<Field>(new Field(true)),
                    std::make_shared<Field>(new Field(false)),  std::make_shared<Field>(new Field(false))}
    };
};


#endif //TETRIS_FIGURE_S_H
