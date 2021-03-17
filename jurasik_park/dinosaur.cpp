#include <iostream>
#include "dinosaur.h"
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>

void Dinosaur::setter(const std::string &_name, const std::string &_gender, const std::string &_era,
                      const std::string &_order, const std::string &_type, const std::string &_food)
{
    name = _name;
    if (strcmp(_gender.c_str(), "male") == 0)
    {
        gender = 0;
    }
    else if (strcmp(_gender.c_str(), "female") == 0)
    {
        gender = 1;
    }
    else
    {
        std::cout << _gender.c_str() << "  ";
        std::cout << "Invalid gender\n";
    }
    if (strcmp(_era.c_str(), "creda") == 0)
    {
        era = 1;
    }
    else if (strcmp(_era.c_str(), "trias") == 0)
    {
        era = 2;
    }
    else if (strcmp(_era.c_str(), "jura") == 0)
    {
        era = 3;
    }
    else
    {
        std::cout << "Invalid era\n";
    }
    if (strcmp(_order.c_str(), "herbivorous") == 0)
    {
        order = 1;
    }
    else if (strcmp(_order.c_str(), "carnivorous") == 0)
    {
        order = 2;
    }
    else if (strcmp(_order.c_str(), "flying") == 0)
    {
        order = 3;
    }
    else if (strcmp(_order.c_str(), "aquatic") == 0)
    {
        order = 4;
    }
    else
    {
        std::cout << "Invalid order\n";
    }
    type = _type;
    if (strcmp(_food.c_str(), "grass") == 0)
    {
        food = 1;
    }
    else if (strcmp(_food.c_str(), "meat") == 0)
    {
        food = 2;
    }
    else if (strcmp(_food.c_str(), "fish") == 0)
    {
        food = 3;
    }
    else
    {
        std::cout << "Invalid food\n";
    }
}
Dinosaur::Dinosaur(const std::string &_name, const std::string &_gender, const std::string &_era,
                   const std::string &_order, const std::string &_type, const std::string &_food)
{
    setter(_name, _gender, _era, _order, _type, _food);
}

const std::string Dinosaur::get_name() const
{
    return name;
}
bool Dinosaur::get_gender() const
{
    return gender;
}
const short Dinosaur::get_era() const
{
    return era;
}
const short Dinosaur::get_order() const
{
    return order;
}
const std::string Dinosaur::get_type() const
{
    return type;
}
const short Dinosaur::get_food() const
{
    return food;
}
void Dinosaur::print() const
{
    std::cout << "Name: " << this->get_name()
              << "\nGenger: ";
    if (this->get_gender() == 0)
    {
        std::cout << "male";
    }
    else
    {
        std::cout << "female";
    }
    std::cout << "\nEra: ";
    if (this->get_era() == 1)
    {
        std::cout << "creda";
    }
    else if (this->get_era() == 2)
    {
        std::cout << "trias";
    }
    else
    {
        std::cout << "jura";
    }
    std::cout << "\nOrder: ";
    if (this->get_order() == 1)
    {
        std::cout << "herbivorous";
    }
    else if (this->get_order() == 2)
    {
        std::cout << "carnivorous";
    }
    else if (this->get_order() == 3)
    {
        std::cout << "flying";
    }
    else
    {
        std::cout << "aquatic";
    }
    std::cout << "\nType: " << this->get_type()
              << "\nFood: ";
    if (this->get_food() == 1)
    {
        std::cout << "grass";
    }
    else if (this->get_food() == 2)
    {
        std::cout << "meat";
    }
    else
    {
        std::cout << "fish";
    }
    std::cout << "\n";
}
void Dinosaur::in_file(std::ofstream &out) const
{

    out << this->get_name() << " ";
    if (this->get_gender() == 0)
    {
        out << "male ";
    }
    else
    {
        out << "female ";
    }
    if (this->get_era() == 1)
    {
        out << "creda ";
    }
    else if (this->get_era() == 2)
    {
        out << "trias ";
    }
    else
    {
        out << "jura ";
    }
    if (this->get_order() == 1)
    {
        out << "herbivorous ";
    }
    else if (this->get_order() == 2)
    {
        out << "carnivorous ";
    }
    else if (this->get_order() == 3)
    {
        out << "flying ";
    }
    else
    {
        out << "aquatic ";
    }
    out << this->get_type() << " ";
    if (this->get_food() == 1)
    {
        out << "grass ";
    }
    else if (this->get_food() == 2)
    {
        out << "meat";
    }
    else
    {
        out << "fish";
    }
    out << "\n";
}
void Dinosaur::print_on_line() const
{

    std::cout << this->get_name() << " ";
    if (this->get_gender() == 0)
    {
        std::cout << "male ";
    }
    else
    {
        std::cout << "female ";
    }
    if (this->get_era() == 1)
    {
        std::cout << "creda ";
    }
    else if (this->get_era() == 2)
    {
        std::cout << "trias ";
    }
    else
    {
        std::cout << "jura ";
    }
    if (this->get_order() == 1)
    {
        std::cout << "herbivorous ";
    }
    else if (this->get_order() == 2)
    {
        std::cout << "carnivorous ";
    }
    else if (this->get_order() == 3)
    {
        std::cout << "flying ";
    }
    else
    {
        std::cout << "aquatic ";
    }
    std::cout << this->get_type() << " ";
    if (this->get_food() == 1)
    {
        std::cout << "grass";
    }
    else if (this->get_food() == 2)
    {
        std::cout << "meat";
    }
    else
    {
        std::cout << "fish";
    }
    std::cout << "\n";
}