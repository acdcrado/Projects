#pragma once
#include <iostream>
#include <string>
#include "dinosaur.h"
#include <vector>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include "Cages.h"
#include <fstream>

/// Class containing cages, which simulates the whole Jurassic Park.

class Zoo
{
    std::vector<Cage> Cages;

public:
/// Clears the information in  the file with about the Park and rewrites it saving the lastly applied changes to the Park
    void update_Cages();
/// Finds a suitable cage having in mind the dinosaurs type and era, and the space left in the cage.
    void find_suitable_cage(const Dinosaur &);
/// Loads the information about the Park from a file. This function is called everytime the Park is launched exepect if there aren't any cages and dinosaurs saved. In this case, random number of cages are generated.
    void loadCagesAndDinos(std::istream &, std::vector<Dinosaur> &);
/// Feeds the dinosaurs upon launching and reduces the food left in each cage.
    void feed_dinos();
/// The main function which executes the commands read from the console. In the end, it checks whether there is enough staff anf food in the Park.
    void openZoo();
/// Adds a new cage to the vector of cages in the Park.
    void new_cage(std::string*);
/// Removes a dinosaur.
    void remove_dino(std::string*, std::vector<Dinosaur>&);
};