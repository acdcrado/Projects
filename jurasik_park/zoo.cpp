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
#include "zoo.h"
#include "functions.h"

void Zoo::new_cage(std::string *info)
{

    Cage temp_cage;
    temp_cage.set_climat(info[0]);
    temp_cage.set_capacity(info[1]);
    temp_cage.set_space_left(temp_cage.get_capacity());
    temp_cage.set_food(30);
    Cages.push_back(temp_cage);
    std::cout << "Cage added successfully!\n";
}
void Zoo::update_Cages()
{
    std::fstream file_Cages2("Cages.txt", std::fstream::out | std::fstream::trunc);
    for (int i = 0; i < Cages.size(); i++)
    {
        Cages[i].in_file(file_Cages2);
    }
    file_Cages2.close();
}

void Zoo::find_suitable_cage(const Dinosaur &cur_dino)
{
    short cur_era = cur_dino.get_era();
    short cur_order = cur_dino.get_order();
    if (cur_order == 1)
    {
        cur_order++;
    }
    cur_order--;
    bool cage_found = false;
    for (int i = 0; i < Cages.size(); i++)
    {
        if (cur_order == Cages[i].get_climat())
        {
            if (Cages[i].get_space_left() == Cages[i].get_capacity())
            {
                Cages[i].set_era(cur_era);
                Cages[i].add_dino_in_the_cage(cur_dino);
                cage_found = true;
                Cages[i].set_space_left(Cages[i].get_space_left() - 1);
                i = Cages.size();
            }
            else if (Cages[i].get_dinos_era() == cur_era && Cages[i].get_space_left() >= 1)
            {
                Cages[i].add_dino_in_the_cage(cur_dino);
                cage_found = true;
                Cages[i].set_space_left(Cages[i].get_space_left() - 1);
                i = Cages.size();
            }
        }
    }
    if (cage_found == false)
    {
        while (cage_found == false)
        {
            std::string buf1, buf2;
            Cage temp_cage;
            std::cout << "There isn't a suitable cage fot this dinosaur, please create one: \n";
            std::cout << "Climate: ";
            std::cin >> buf1;
            temp_cage.set_climat(buf1);
            std::cout << "Capacity: ";
            std::cin >> buf2;
            temp_cage.set_capacity(buf2);
            temp_cage.set_space_left(temp_cage.get_capacity());
            temp_cage.set_food(30);
            Cages.push_back(temp_cage);
            std::cout << "Cage added successfully!\n";

            if (temp_cage.get_climat() == cur_order)
            {
                cage_found = true;
                Cages[Cages.size() - 1].set_era(cur_era);
                Cages[Cages.size() - 1].add_dino_in_the_cage(cur_dino);
                Cages[Cages.size() - 1].set_space_left(Cages[Cages.size() - 1].get_space_left() - 1);
            }
        }
        char elem = getchar();
    }
}
void Zoo::loadCagesAndDinos(std::istream &cin, std::vector<Dinosaur> &dinos)
{
    std::string info[8];
    Cage temp_cage;
    bool isFirst = true;
    int i = 1;
    for (std::string line; getline(cin, line);)
    {
        word_maker(line, info);
        i++;
        if (wordcounter(line) == 4)
        {
            if (!isFirst)
            {
                Cages.push_back(temp_cage);
            }
            isFirst = false;
            temp_cage.get_dinos_in_the_cage().clear();
            temp_cage.set_climat(info[0]);
            temp_cage.set_capacity(info[1]);
            temp_cage.set_space_left(info[2]);
            temp_cage.set_food(info[3]);
        }
        else
        {
            Dinosaur temp_dinosaur(info[0], info[1], info[2], info[3], info[4], info[5]);
            temp_cage.set_era(temp_dinosaur.get_era());
            temp_cage.get_dinos_in_the_cage().push_back(temp_dinosaur);
            dinos.push_back(temp_dinosaur);
        }
    }
    Cages.push_back(temp_cage);
}
void Zoo::feed_dinos()
{
    int dead_dinos = 0;
    for (int i = 0; i < Cages.size(); i++)
    {
        if (Cages[i].get_food() == 0 && Cages[i].get_dinos_in_the_cage().size() > 0)
        {
            Cages[i].get_dinos_in_the_cage().erase(Cages[i].get_dinos_in_the_cage().begin());
            Cages[i].set_space_left(Cages[i].get_space_left() + 1);
            dead_dinos++;
        }
        else
        {
            Cages[i].set_food(Cages[i].get_food() - Cages[i].get_dinos_in_the_cage().size());
            if (Cages[i].get_food() < 0)
            {
                Cages[i].set_food(0);
            }
        }
        update_Cages();
    }
    if (dead_dinos > 0)
    {
        std::cout << "Unfortunately, during the night " << dead_dinos << " dino/s have starved to death!\n";
    }
}
void Zoo::remove_dino(std::string *info, std::vector<Dinosaur> &dinosaurs)
{
    while (find_index(dinosaurs, info[0]) != -1)
    {
        dinosaurs.erase(dinosaurs.begin() + find_index(dinosaurs, info[0]));
        std::cout << "Dino removed successfully!\n";
    }
    for (int i = 0; i < Cages.size(); i++)
    {
        for (int j = 0; j < Cages[i].get_dinos_in_the_cage().size(); j++)
        {
            if (strcmp(info[0].c_str(), (Cages[i].get_dinos_in_the_cage()[j].get_name()).c_str()) == 0)
            {

                Cages[i].get_dinos_in_the_cage().erase(Cages[i].get_dinos_in_the_cage().begin() +
                                                       find_index(Cages[i].get_dinos_in_the_cage(), info[0]));
                Cages[i].set_space_left(Cages[i].get_space_left() + 1);
            }
        }
    }
}
void Zoo::openZoo()
{
    int workers_needed;
    int workers_hired;
    std::ifstream workers;
    workers.open("staff.txt", std::ios::in);
    if (workers.good())
    {
        int buf2;
        workers >> buf2;
        workers_hired = buf2;
    }
    else
    {
        workers_needed = 0;
        workers_hired = 0;
    }
    workers.close();

    bool zoo_is_open = true;
    std::vector<Dinosaur> dinosaurs;
    std::string str, info[8];
    Cage temp_cage;

    std::ofstream buf;
    buf.open("Cages.txt", std::ios::app);
    buf.close();

    std::fstream file_cage1;
    file_cage1.open("Cages.txt");
    file_cage1.seekp(0, std::ios::end);
    int size = file_cage1.tellp();
    if (size == 0)
    {
        srand((unsigned)time(0));
        int randomNumber;
        randomNumber = (std::rand() % 20) + 1;
        std::cout << "Number of random generated cages: "
                  << randomNumber << "\n";
        for (int i = 0; i < randomNumber; i++)
        {
            temp_cage.create_random_cage();
            temp_cage.in_file(file_cage1);
            Cages.push_back(temp_cage);
        }
        file_cage1.close();
    }
    else
    {
        file_cage1.close();
        std::ifstream file_cage2;
        file_cage2.open("Cages.txt");
        loadCagesAndDinos(file_cage2, dinosaurs);
        file_cage2.close();
    }
    feed_dinos();
    std::cout << "$\n";
    while (zoo_is_open)
    {
        getline(std::cin, str);
        std::cout << "\n";
        word_maker(str, info);
        if (strcmp(info[0].c_str(), "newDino") == 0)
        {
            deleteFirst(info);
            if (wordcounter(str) != 7)
            {
                std::cout << "You haven't provided the needed information to create a Dinosaur, please enter newDino, followed by dinosaur's name, gender, era, order, type and food.\n";
            }
            else
            {
                Dinosaur temp_dinosaur(info[0], info[1], info[2], info[3], info[4], info[5]);
                dinosaurs.push_back(temp_dinosaur);
                find_suitable_cage(temp_dinosaur);
                std::cout << "Dinosaur added successfully!\n";
            }
        }
        else if (strcmp(info[0].c_str(), "newCage") == 0)
        {
            deleteFirst(info);
            if (wordcounter(str) != 3)
            {
                std::cout << "You haven't provided the needed information to create a Cage, please enter newCage, followed by cages's climate and capacity.\n";
            }
            else
            {
                new_cage(info);
            }
        }
        else if (strcmp(info[0].c_str(), "removeDino") == 0)
        {
            deleteFirst(info);
            remove_dino(info, dinosaurs);
        }
        else if (strcmp(info[0].c_str(), "fillCages") == 0)

        {
            for (int i = 0; i < Cages.size(); i++)
            {
                Cages[i].set_food("30");
            }
        }
        else if (strcmp(info[0].c_str(), "showDinos") == 0)
        {
            for (int i = 0; i < dinosaurs.size(); i++)
            {
                std::cout << "Dinosaur " << i + 1 << ".\n";
                dinosaurs[i].print();
                std::cout << "\n";
            }
        }
        else if (strcmp(info[0].c_str(), "showCages") == 0)
        {
            for (int i = 0; i < Cages.size(); i++)
            {
                std::cout << "Cage " << i + 1 << ".\n";
                Cages[i].print();
                std::cout << "\n";
            }
        }
        else if (strcmp(info[0].c_str(), "closeZoo") == 0)
        {
            update_Cages();
            zoo_is_open = false;
        }
        else if (strcmp(info[0].c_str(), "hireStaff") == 0)
        {
            workers_hired = workers_hired + to_int(info[1]);
            update_Staff(workers_hired);
            std::cout << "\n";
        }
        else if (strcmp(info[0].c_str(), "help") == 0)
        {
            help();
        }
        else if (strcmp(info[0].c_str(), "saveZoo") == 0)
        {
            update_Cages();
        }
        else
        {
            std::cout << "Invalid command! Enter help to see the supported commands!\n";
        }
        std::cout << "$\n";
    }

    int w;
    workers_needed = dinosaurs.size() + Cages.size();
    while (workers_hired < workers_needed)
    {
        std::cout << "Attention! More staff needed! Please hire some:\n";
        std::cout << "Workers needed: " << workers_needed << "\n";
        std::cout << "Workers hired: " << workers_hired << "\n";
        std::cin >> w;
        workers_hired = workers_hired + w;
    }
    update_Staff(workers_hired);
    for (int i = 0; i < Cages.size(); i++)
    {
        if (Cages[i].get_food() == 0)
        {
            std::cout << "There isn't any food left in some of the cages. Would you like to fully fill all of them? Y/N\n";
            char answer;
            std::cin >> answer;
            if (answer == 'Y')
            {
                for (int j = 0; j < Cages.size(); j++)
                {
                    Cages[j].set_food("30");
                }
            }
            update_Cages();
            i = Cages.size();
        }
    }
}
