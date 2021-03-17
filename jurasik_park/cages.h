#pragma once
#include <iostream>
#include <string>
#include "dinosaur.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

/// Class containging dinosaurs and the information needed to define a cage.
///
/// For the same reason as in dinosaur, we are using **short** instead of **string** in order to save memory.
class Cage
{
    /// Compatible with the type of the dinosaurs.
    short climat;
    short capacity;
    short space_left;
    std::vector<Dinosaur> dinos_in_the_cage;
    /// Keeps the era of the dinosaurs in the current cage.
    short dinos_era;
    ///Maximum food in a single cage is 30, which is enough for feeding 10 dinosaurs for 3 days. Afterwards, they will slowly start dying.
    short food;

    void copy(const short &, const short &, const short &, const std::vector<Dinosaur> &, const short &, const short &);

public:
    Cage() = default;
    Cage(const short &, const short &, const short &, const std::vector<Dinosaur> &, const short &, const short &);
    Cage(Cage const &other);
    Cage &operator=(Cage const &other);
    ~Cage() = default;

    /// Function creating a random cage using two random generated integers.
    void create_random_cage();
    /// Prints the information about a cage and the dinosaurs in it in the console in a table.
    void print() const;
    void add_dino_in_the_cage(const Dinosaur &);
    /// Writes the information about a cage in a file, containging the information about the Park.
    void in_file(std::fstream &) const;

    void set_climat(const std::string &);
    void set_capacity(const std::string &);
    void set_space_left(const short &);
    void set_space_left(const std::string &);
    void set_food(const short &);
    void set_food(const std::string &);
    void set_era(const short &);

    std::vector<Dinosaur> &get_dinos_in_the_cage();
    /// Function converting **string** to **short**.
    const short short_maker(const std::string &) const;
    const short get_climat() const;
    const short get_food() const;
    const short get_capacity() const;
    const short get_space_left() const;
    const short get_dinos_era() const;
};