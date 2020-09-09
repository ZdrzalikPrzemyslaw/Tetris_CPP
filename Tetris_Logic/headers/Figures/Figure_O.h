//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_O_H
#define TETRIS_FIGURE_O_H


#include "Figure.h"

class Figure_O : public Figure {
public:
    Figure_O();

    ~Figure_O();
private:
    std::vector<std::vector<std::shared_ptr<Field>>> baseShape = {
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false)),
                    std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false))},
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(true)),
                    std::make_shared<Field>(new Field(true)), std::make_shared<Field>(new Field(false))},
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(true)),
                    std::make_shared<Field>(new Field(true)), std::make_shared<Field>(new Field(false))},
            {std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false)),
                    std::make_shared<Field>(new Field(false)), std::make_shared<Field>(new Field(false))}
    };
};


#endif //TETRIS_FIGURE_O_H
