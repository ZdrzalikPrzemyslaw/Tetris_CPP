//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <memory>
#include "vector"
#include "Field.h"

class Figure {
public:
    void rotate();
    static const int FIGURE_SIZE = 4;
    [[nodiscard]] const std::vector<std::vector<std::shared_ptr<Field>>> &getShape() const;
    std::string toString();
    friend std::ostream& operator<<(std::ostream& osm, Figure figure);
    friend bool operator ==(const Figure &lhs, const Figure &rhs);
    Figure();
    ~Figure();
protected:
    std::vector<std::vector<std::shared_ptr<Field>>> shape;

};


#endif //TETRIS_FIGURE_H
