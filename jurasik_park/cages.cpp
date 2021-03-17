#include <iostream>
#include "dinosaur.h"
#include "cages.h"
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <fstream>
#include <cmath>

void Cage::set_climat(const std::string &_climat)
{
    if (strcmp(_climat.c_str(), "terrestrial") == 0)
    {
        climat = 1;
    }
    else if (strcmp(_climat.c_str(), "aerial") == 0)
    {
        climat = 2;
    }
    else if (strcmp(_climat.c_str(), "aquatic") == 0)
    {
        climat = 3;
    }
    else
    {
        std::cout << "Invalid climat\n";
    }
}
void Cage::add_dino_in_the_cage(const Dinosaur &dino)
{
    dinos_in_the_cage.push_back(dino);
}
const short Cage::short_maker(const std::string &a) const
{
    short result = 0;
    int power = pow(10, a.size() - 1);
    for (int i = 0; i < a.size(); i++)
    {
        result = result + (a[i] - '0') * power;
        power = power / 10;
    }
    return result;
}
void Cage::set_capacity(const std::string &_capacity)
{
    capacity = short_maker(_capacity);
}
void Cage::set_space_left(const short &_capacity)
{
    space_left = _capacity;
}
void Cage::set_space_left(const std::string &a)
{
    short _capacity = short_maker(a);
    space_left = _capacity;
}
void Cage::set_food(const std::string &a)
{
    short _food = short_maker(a);
    food = _food;
}
void Cage::set_era(const short &_era)
{
    dinos_era = _era;
}
void Cage::set_food(const short &_food)
{
    food = _food;
}
const short Cage::get_climat() const
{
    return climat;
}
const short Cage::get_food() const
{
    return food;
}
const short Cage::get_capacity() const
{
    return capacity;
}
const short Cage::get_space_left() const
{
    return space_left;
}
const short Cage::get_dinos_era() const
{
    return dinos_era;
}
std::vector<Dinosaur> &Cage::get_dinos_in_the_cage()
{
    return dinos_in_the_cage;
}

void Cage::copy(const short &_climat, const short &_capacity, const short &_space_left,
                const std::vector<Dinosaur> &_dinos_in_the_cage, const short &_dinos_era, const short &_food)
{
    climat = _climat;
    capacity = _capacity;
    space_left = _space_left;
    dinos_era = _dinos_era;

    for (int i = 0; i < _dinos_in_the_cage.size(); i++)
    {
        dinos_in_the_cage.push_back(_dinos_in_the_cage[i]);
    }

    food = _food;
}

Cage::Cage(Cage const &other)
{
    copy(other.get_climat(), other.get_capacity(), other.get_space_left(), other.dinos_in_the_cage, other.get_dinos_era(), other.get_food());
}
Cage::Cage(const short &_climat, const short &_capacity, const short &_space_left, const std::vector<Dinosaur> &_dinos_in_the_cage, const short &_dinos_era, const short &_food)
{
    copy(_climat, _capacity, _space_left, _dinos_in_the_cage, _dinos_era, _food);
}
Cage &Cage::operator=(Cage const &other)
{
    if (this != &other)
    {
        dinos_in_the_cage.clear();
        copy(other.get_climat(), other.get_capacity(), other.get_space_left(), other.dinos_in_the_cage, other.get_dinos_era(), other.get_food());
    }
    return *this;
}
void Cage::create_random_cage()
{
    int randomNumber;
    std::string buff;
    randomNumber = (std::rand() % 3) + 1;
    climat = randomNumber;
    randomNumber = (std::rand() % 3) + 1;
    if (randomNumber == 1)
    {
        this->set_capacity("1");
    }
    else if (randomNumber == 2)
    {
        this->set_capacity("3");
    }
    else if (randomNumber == 3)
    {
        this->set_capacity("10");
    }
    space_left = this->get_capacity();
    dinos_era = 0;
    food = 30;
}
void Cage::print() const
{
    std::cout << "Climate: ";
    if (this->get_climat() == 1)
    {
        std::cout << "terrestrial\n";
    }
    else if (this->get_climat() == 2)
    {
        std::cout << "aerial\n";
    }
    else if (this->get_climat() == 3)
    {
        std::cout << "aquatic\n";
    }
    std::cout << "Cage capacity: "
              << this->get_capacity()
              << "\n"
              << "Free space: "
              << this->get_space_left()
              << "\n"
              << "Food available in kg: "
              << this->get_food()
              << "\nDinos in the cage:\n";
    for (int i = 0; i < dinos_in_the_cage.size(); i++)
    {
        std::cout << i + 1 << ". ";
        dinos_in_the_cage[i].print_on_line();
    }
}
void Cage::in_file(std::fstream &out) const
{
    if (this->get_climat() == 1)
    {
        out << "terrestrial ";
    }
    else if (this->get_climat() == 2)
    {
        out << "aerial ";
    }
    else if (this->get_climat() == 3)
    {
        out << "aquatic ";
    }
    out << this->get_capacity()
        << " " << this->get_space_left()
        << " " << this->get_food()
        << "\n";
    for (int i = 0; i < dinos_in_the_cage.size(); i++)
    {
        out << dinos_in_the_cage[i].get_name() << " ";
        if (dinos_in_the_cage[i].get_gender() == 0)
        {
            out << "male ";
        }
        else
        {
            out << "female ";
        }
        if (dinos_in_the_cage[i].get_era() == 1)
        {
            out << "creda ";
        }
        else if (dinos_in_the_cage[i].get_era() == 2)
        {
            out << "trias ";
        }
        else
        {
            out << "jura ";
        }
        if (dinos_in_the_cage[i].get_order() == 1)
        {
            out << "herbivorous ";
        }
        else if (dinos_in_the_cage[i].get_order() == 2)
        {
            out << "carnivorous ";
        }
        else if (dinos_in_the_cage[i].get_order() == 3)
        {
            out << "flying ";
        }
        else
        {
            out << "aquatic ";
        }
        out << dinos_in_the_cage[i].get_type() << " ";
        if (dinos_in_the_cage[i].get_food() == 1)
        {
            out << "grass ";
        }
        else if (dinos_in_the_cage[i].get_food() == 2)
        {
            out << "meat";
        }
        else
        {
            out << "fish";
        }
        out << "\n";
    }
}