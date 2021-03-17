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
/// Functions used throughout the program.


/// Function printing in the console the supported commands by the program.

void help(){
    std::cout<<"newDino - Adds a new dinosaur\n";
    std::cout<<"newCage - Adds a new cage\n";
    std::cout<<"removeDino - Removes a already existing dinosaur\n";
    std::cout<<"fillCages - Fills all cages with maximum food\n";
    std::cout<<"showDinos - Shows all dinosaurs in the zoo\n";
    std::cout<<"showCages - Show all cages in the zoo\n";
    std::cout<<"hireStaff - Hires a number of new workers in the zoo\n";
    std::cout<<"saveZoo - Saves the last changes made to the zoo\n";
    std::cout<<"closeZoo - Closes the program and saves the last changes made to the zoo\n";

}

/// Function updating the number of staff working in the Park.
void update_Staff(int _workers_hired){
    std::fstream work;
    work.open("staff.txt", std::fstream::out | std::fstream::trunc);
    work<<_workers_hired;
    work.close();
}


int wordcounter(std::string str)
{
    int words = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == ' ')
        {
            words++;
        }
    }
    return words;
}
/// Deletes the first word from the input, which is actually the command given.
void deleteFirst(std::string *str)
{
    for (int i = 0; i < 7; i++)
    {
        str[i] = str[i + 1];
    }
}

/// Function converting **string** to **int**.
int to_int(const std::string &a){
    int result=0;
    int power=pow(10,a.size()-1);
    for(int i=0;i<a.size();i++){
        result=result +(a[i]-'0')*power;
        power=power/10;
    }
    return result;
}

/// Splits the input to a array of **string**.
void word_maker(std::string input, std::string *result)
{
    int curstring = 0;
    for (int i = 0; i < 8; i++)
    {
        result[i].clear();
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (input.at(i) == ' ')
        {
            curstring++;
        }
        else
        {
            result[curstring].push_back(input.at(i));
        }
    }
}

/// Finds the index of a Dinosaur in a given vector, searching by dinosaur's name.
int find_index(const std::vector<Dinosaur> &dino, std::string _name)
{
    for (int i = 0; i < dino.size(); i++)
    {
        if (_name == dino[i].get_name())
        {
            return i;
        }
    }
    return -1;
}