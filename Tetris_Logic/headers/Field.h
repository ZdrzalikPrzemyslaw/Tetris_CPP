//
// Created by Przemek on 09.09.2020.
//

#ifndef TETRIS_FIELD_H
#define TETRIS_FIELD_H


#include <string>

class Field {
private:
    bool is_taken;
public:
    void setIsTaken(bool isTaken);
public:
    [[nodiscard]] bool isTaken() const;
    Field();
    explicit Field(bool isTaken);
    ~Field();
    [[nodiscard]] std::string toString() const;
    friend bool operator ==(const Field &lhs, const Field &rhs);
    friend bool operator !=(const Field &lhs, const Field &rhs);

};


#endif //TETRIS_FIELD_H
