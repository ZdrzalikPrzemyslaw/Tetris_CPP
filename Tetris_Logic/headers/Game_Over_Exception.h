//
// Created by Przemek on 13.09.2020.
//

#ifndef TETRIS_GAME_OVER_EXCEPTION_H
#define TETRIS_GAME_OVER_EXCEPTION_H

#include <exception>
#include <string>

class Game_Over_Exception: virtual public std::exception {
protected:

    int error_number;               ///< Error number
    int error_offset;               ///< Error offset
    std::string error_message;      ///< Error message

public:

    /** Constructor (C++ STL string, int, int).
     *  @param msg The error message
     *  @param err_num Error number
     *  @param err_off Error offset
     */
    explicit
    Game_Over_Exception(const std::string& msg, int err_num, int err_off):
            error_number(err_num),
            error_offset(err_off),
            error_message(msg)
    {}

    /** Destructor.
     *  Virtual to allow for subclassing.
     */
    virtual ~Game_Over_Exception() throw () {}

    /** Returns a pointer to the (constant) error description.
     *  @return A pointer to a const char*. The underlying memory
     *  is in possession of the Except object. Callers must
     *  not attempt to free the memory.
     */
    virtual const char* what() const throw () {
        return error_message.c_str();
    }

    /** Returns error number.
     *  @return #error_number
     */
    virtual int getErrorNumber() const throw() {
        return error_number;
    }

    /**Returns error offset.
     * @return #error_offset
     */
    virtual int getErrorOffset() const throw() {
        return error_offset;
    }

};

#endif //TETRIS_GAME_OVER_EXCEPTION_H
