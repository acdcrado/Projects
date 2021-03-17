#pragma once
#include <iostream>
#include <string>
#include <cmath>

/// Class containting the needed information to define a dinosaur
///
/// Where posssible, **short** is used instead of **string** in order to save memory.
///
/// Since the era, order and food of a dinosaur are limited to 4 options each, there's no need of a **string**.

class Dinosaur
{
    std::string name;
    bool gender;
    short era;
    short order;
    std::string type;
    short food;

    /// This setter is called in a parametric constructor, used for generating a dinosaur from the console.
    void setter(const std::string &, const std::string &, const std::string &,
                const std::string &, const std::string &, const std::string &);

public:
    /// Parametric constructor used for generating a dinosaur from the console.
    Dinosaur(const std::string &, const std::string &, const std::string &,
             const std::string &, const std::string &, const std::string &);
             
    /// Prints the information about a dinosaur in the console in a table.
    void print() const;
    /// Prints the information about a dinosaur when printing a cage.
    void print_on_line() const;
    /// Writes the information about a dinosaur in a file, containging the information about the Park.
    void in_file(std::ofstream &) const;

    const std::string get_name() const;
    bool get_gender() const;
    const short get_era() const;
    const short get_order() const;
    const std::string get_type() const;
    const short get_food() const;
};