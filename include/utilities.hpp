/**
 * @file utilities.hpp
 * @brief File containing utilities useful for the game.
 */
#ifndef UTILITIES_H
#define UTILITIES_H

#include <sstream>
#include <string>

/**
 * @brief Transforms a lot of things into a string.
 * @param obj The object to convert to string.
 * @returns The string representation of the object
 */
template <typename T>
std::string to_string(const T& obj)
{
    std::ostringstream obj_str;
    obj_str << obj;
    return obj_str.str();
}

#endif
