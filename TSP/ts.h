#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <map>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>

using namespace std::chrono;
/// Class representing the whole map, with it's towns and roads
class Graph
{
    /// Struct representing the road between two towns. Contains the weight of the road and it's end.
    struct Road 
    {
        int weigth;
        std::string second_town_name;
        Road(const std::string &_second_town_name, const int &_weigth)
            : second_town_name{_second_town_name}, weigth{_weigth} {}
    };
    ///Struct representing the towns on the map. Contains the name of the town, which plays the role of the start of a road, and a vector of roads, which represent all the roads which start from the given town.
    struct Town
    {
        std::string first_town_name;
        std::vector<Road> exit_roads;
        Town(const std::string &_first_town_name, const std::vector<Road> &_exit_roads)
            : first_town_name{_first_town_name}, exit_roads{_exit_roads} {}
        void print(){
            std::cout<<first_town_name;
            std::cout<<"\nexit roads:\n";
            for(int i=0;i<exit_roads.size();i++){
                std::cout<<exit_roads[i].second_town_name<<" "<<exit_roads[i].weigth;
            }
        }
    };
    /// The name of the starting town.
    std::string hometown_name;
    /// Vector with all the towns.
    std::vector<Town> towns;
    /// Matrix used for one of the algorithms. It is filled with the distances between each two towns.
    std::vector<std::vector<int>> matrix;
    ///Map function pairing the town name with a number, for faster operations.
    std::map<std::string, int> map;
    ///Map function reversing the other map.
    std::map<int, std::string> map_reverse;
    ///The number of towns.
    int towns_size;

public:
    ///Filling the two map functions.
    void map_fill();
    ///Prints the map
    void print();
    ///Finds the position of a given town in the vector of towns.
    int find_index_town(std::string _name);
    ///Reads a .txt file for the map and fills the graph. 
    void load_map(std::istream &cin);
    ///Makes a matrix with the distances between each to towns.
    void fill_matrix();
    ///Prints the matrix with distances.
    void print_matrix();
    ///Checks if there are towns with only road coming out of them.
    bool check_for_towns_with_one_route();
    ///Function used to represent the graph using GraphWiz.
    void showGraph(std::ostream &out);
    ///The first algorithm. It makes all the possible permutation- all the possible routes and them returns the shortest one. Gets the distances between two towns by looking in the matrix filled before that.
    std::pair<int,std::vector<int>> full_permutations_with_matrix();
    ///Returns the distance between two towns by searching it directly, without using the matrix.
    int get_distance(int start, int finish);
    ///The second algorithm. Works exactly like the first one, just wihtout using the matrix.
    std::pair<int,std::vector<int>> full_permutations_without_matrix();
    void dfs_help(int start, int curr, int path, int num, int &minPath, std::vector<int> road, std::vector<int> &min_road, std::vector<bool> used);
    ///The third algorithm. Recursively based, it tries all possible routes without the need of permutations.
    std::pair<int,std::vector<int>> dfs();
    ///Starts the program
    void run();
    ///Prints the lenght of the shortest path and through which towns it passes.
    void print_results(int result, std::vector<int> route);
};
