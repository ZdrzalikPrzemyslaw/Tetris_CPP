//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <memory>
#include <vector>
#include "Field.h"

class Figure {
public:
    void rotate();
    [[nodiscard]] const std::vector<std::vector<std::shared_ptr<Field>>> &getShape() const;
    std::string toString();
    friend std::ostream& operator<<(std::ostream& osm, Figure figure);
    friend bool operator ==(const Figure &lhs, const Figure &rhs);
    Figure();
    Figure(Figure const &figure);
    ~Figure();
    int getWidth() const;
    int getHeight() const;
protected:
    std::vector<std::vector<std::shared_ptr<Field>>> shape;
private:
    static const int FIGURE_SIZE = 4;
    std::pair<int, int> pos;
public:
    const std::pair<int, int> &getPos() const;
    int get_x_pos();
    int get_y_pos();
    void set_x_pos(int x_pos);
    void set_y_pos(int y_pos);

    void setPos(int x_pos, int y_pos);
};


#endif //TETRIS_FIGURE_H
