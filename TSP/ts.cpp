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
#include "functions.h"
#include "ts.h"

using namespace std::chrono;

void Graph::map_fill()
{
    for (int p = 0; p < towns.size(); p++)
    {
        map[towns[p].first_town_name] = p;
        map_reverse[p] = towns[p].first_town_name;
    }
}
void Graph::print()
{
    std::cout << "hometown: " << hometown_name << std::endl;
    for (int i = 0; i < towns_size; i++)
    {
        for (int j = 0; j < towns[i].exit_roads.size(); j++)
        {
            std::cout << towns[i].first_town_name << "  " << towns[i].exit_roads[j].second_town_name
                      << "  " << towns[i].exit_roads[j].weigth << std::endl;
        }
    }
}

int Graph::find_index_town(std::string _name)
{

    for (int i = 0; i < towns.size(); i++)
    {
        if (_name == towns[i].first_town_name)
        {
            return i;
        }
    }
    return -1;
}

void Graph::load_map(std::istream &cin)
{
    std::string info[3];
    std::string line;
    getline(cin, hometown_name);
    while (getline(cin, line))
    {
        word_maker(line, info);
        if (find_index_town(info[0]) == -1)
        {
            Town temp_town(info[0], std::vector<Road>());
            towns.push_back(temp_town);
        }
        if (find_index_town(info[1]) == -1)
        {
            Town temp_town(info[1], std::vector<Road>());

            towns.push_back(temp_town);
        }
        Road temp_road(info[1], to_int(info[2]));
        towns[find_index_town(info[0])].exit_roads.push_back(temp_road);
        Road temp_road2(info[0], to_int(info[2]));
        towns[find_index_town(info[1])].exit_roads.push_back(temp_road2);
    }
    map_fill();
    towns_size = towns.size();
}

void Graph::fill_matrix()
{
    std::vector<int> temp_vector;
    for (int i = 0; i < towns_size; i++)
    {
        matrix.push_back(temp_vector);
        for (int j = 0; j < towns_size; j++)
        {
            matrix[i].push_back(-1);
        }
    }

    for (int i = 0; i < towns_size; i++)
    {
        for (int j = 0; j < towns[i].exit_roads.size(); j++)
        {
            matrix[map[towns[i].first_town_name]][map[towns[i].exit_roads[j].second_town_name]] =
                towns[i].exit_roads[j].weigth;
        }
        matrix[i][i] = 0;
    }
}

void Graph::print_matrix()
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
bool Graph::check_for_towns_with_one_route()
{

    if (towns_size == 2)
    {
        return false;
    }

    for (int i = 0; i < towns_size; i++)
    {
        if (towns[i].exit_roads.size() == 1)
        {
            return true;
        }
    }
    return false;
}
std::pair<int, std::vector<int>> Graph::full_permutations_with_matrix()
{
    if (check_for_towns_with_one_route())
    {
        std::cout << "There isn't a route which passes trough all towns exactly once.\n";
        return std::make_pair(-1, std::vector<int>());
    }
    int arr[towns_size];
    for (int i = 0; i < towns_size; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < towns_size; i++)
    {
        if (hometown_name == towns[i].first_town_name)
        {
            std::swap(arr[0], arr[i]);
        }
    }
    std::sort(arr + 1, arr + towns_size);
    int straight_forward_path = 0;
    for (int i = 0; i < towns_size - 1; i++)
    {
        if (matrix[arr[i]][arr[i + 1]] == -1)
        {
            straight_forward_path = INT_MAX;
            break;
        }
        straight_forward_path = straight_forward_path + matrix[arr[i]][arr[i + 1]];
    }
    if (straight_forward_path != INT_MAX)
    {
        straight_forward_path = straight_forward_path + matrix[arr[towns_size - 1]][arr[0]];
    }
    if (matrix[arr[towns_size - 1]][arr[0]] == -1)
    {
        straight_forward_path = INT_MAX;
    }
    std::vector<int> route(towns_size);
    for (int i = 0; i < towns_size; i++)
    {
        route[i] = arr[i];
    }
    while (nextPermutation(arr + 1, arr + towns_size))
    {
        int cur_path = 0;
        for (int i = 0; i < towns_size - 1; i++)
        {
            if (matrix[arr[i]][arr[i + 1]] == -1)
            {
                cur_path = INT_MAX;
                break;
            }
            cur_path = cur_path + matrix[arr[i]][arr[i + 1]];
        }
        if (cur_path != INT_MAX)
        {
            cur_path = cur_path + matrix[arr[towns_size - 1]][arr[0]];
        }
        if (matrix[arr[towns_size - 1]][arr[0]] == -1)
        {
            cur_path = INT_MAX;
        }

        if (straight_forward_path > cur_path)
        {
            for (int j = 0; j < towns_size; j++)
            {
                route[j] = arr[j];
            }
            straight_forward_path = cur_path;
        }
    }
    return std::make_pair(straight_forward_path, route);
}

void Graph::showGraph(std::ostream &out)
{
    out << "digraph G{\n";
    out << "edge[dir=none]\n";
    for (int i = 0; i < towns_size; i++)
    {
        out << towns[i].first_town_name << ";\n";
    }
    for (int i = 0; i < towns_size; i++)
    {
        for (int j = 0; j < towns[i].exit_roads.size(); j++)
        {
            if (find_index_town(towns[i].first_town_name) > find_index_town(towns[i].exit_roads[j].second_town_name))
            {
                out << towns[i].first_town_name << "->" << towns[i].exit_roads[j].second_town_name << "[label=\"" << towns[i].exit_roads[j].weigth << "\"];\n";
            }
        }
    }
    out << "}\n";
}

int Graph::get_distance(int start, int finish)
{
    std::string start_name, finish_name;
    start_name = map_reverse[start];
    finish_name = map_reverse[finish];

    for (int i = 0; i < towns_size; i++)
    {
        if (start_name == towns[i].first_town_name)
        {
            for (int j = 0; j < towns[i].exit_roads.size(); j++)
            {
                if (finish_name == towns[i].exit_roads[j].second_town_name)
                {
                    return towns[i].exit_roads[j].weigth;
                }
            }
        }
    }
    return -1;
}

std::pair<int, std::vector<int>> Graph::full_permutations_without_matrix()
{
    if (check_for_towns_with_one_route())
    {
        std::cout << "There isn't a route which passes trough all towns exactly once.\n";
        return std::make_pair(-1, std::vector<int>());
    }

    int arr[towns_size];
    for (int i = 0; i < towns_size; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < towns_size; i++)
    {
        if (hometown_name == towns[i].first_town_name)
        {
            std::swap(arr[0], arr[i]);
        }
    }

    std::sort(arr + 1, arr + towns_size);
    int straight_forward_path = 0;
    for (int i = 0; i < towns_size - 1; i++)
    {
        if (get_distance(arr[i], arr[i + 1]) == -1)
        {
            straight_forward_path = INT_MAX;
            break;
        }
        straight_forward_path = straight_forward_path + get_distance(arr[i], arr[i + 1]);
    }
    if (straight_forward_path != INT_MAX)
    {
        straight_forward_path = straight_forward_path + get_distance(arr[towns_size - 1], arr[0]);
    }
    if (get_distance(arr[towns_size - 1], arr[0]) == -1)
    {
        straight_forward_path = INT_MAX;
    }
    std::vector<int> route(towns_size);
    for (int i = 0; i < towns_size; i++)
    {
        route[i] = arr[i];
    }

    while (nextPermutation(arr + 1, arr + towns_size))
    {
        int cur_path = 0;
        for (int i = 0; i < towns_size - 1; i++)
        {

            if (get_distance(arr[i], arr[i + 1]) == -1)
            {
                cur_path = INT_MAX;
                break;
            }
            cur_path = cur_path + get_distance(arr[i], arr[i + 1]);
        }
        if (cur_path != INT_MAX)
        {
            cur_path = cur_path + get_distance(arr[towns_size - 1], arr[0]);
        }
        if (get_distance(arr[towns_size - 1], arr[0]) == -1)
        {
            cur_path = INT_MAX;
        }

        if (straight_forward_path > cur_path && cur_path > 0)
        {
            for (int j = 0; j < towns_size; j++)
            {
                route[j] = arr[j];
            }
            straight_forward_path = cur_path;
        }
    }

    return std::make_pair(straight_forward_path, route);
}

void Graph::dfs_help(int start, int curr, int path, int num, int &minPath, std::vector<int> road, std::vector<int> &min_road, std::vector<bool> used)
{

    for (int i = 0; i < towns[curr].exit_roads.size(); i++)
    {
        int next = map[towns[curr].exit_roads[i].second_town_name];
        if (next == start && num == towns_size)
        {
            path += towns[curr].exit_roads[i].weigth;
            if (path < minPath or minPath == -1)
            {
                minPath = path;
                for (int i = 0; i < towns_size; i++)
                {
                    min_road[i] = road[i];
                }
            }
        }
        if (!used[next])
        {
            used[next] = true;
            road[num] = next;
            dfs_help(start, next, path + towns[curr].exit_roads[i].weigth, num + 1, minPath, road, min_road, used);
            used[next] = false;
        }
    }
}

std::pair<int, std::vector<int>> Graph::dfs()
{

    int start, curr, path, num;
    start = map[hometown_name];
    int minPath = -1;
    std::vector<int> road(towns_size);
    std::vector<int> min_road(towns_size);
    std::vector<bool> used(towns_size);
    road[0] = start;
    used[start] = true;

    for (int i = 0; i < towns[start].exit_roads.size(); i++)
    {
        int second = map[towns[start].exit_roads[i].second_town_name];
        road[1] = second;
        used[second] = true;
        dfs_help(start, second, towns[start].exit_roads[i].weigth, 2, minPath, road, min_road, used);
        used[second] = false;
    }
    return std::make_pair(minPath, min_road);
}

void Graph::run()
{
    std::string map_name;
    std::cout << "Please enter a map to use!\n";
    std::cin >> map_name;
    std::ifstream map;

    map.open(map_name.c_str(), std::ios::in);
    load_map(map);
    auto start = high_resolution_clock::now();
    fill_matrix();
    std::cout << "Permutations with matrix:\n";
    std::pair<int, std::vector<int>> algo1 = full_permutations_with_matrix();
    print_results(algo1.first, algo1.second);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
    std::cout << std::endl;

    auto start1 = high_resolution_clock::now();
    std::cout << "Permutations without matrix:\n";
    std::pair<int, std::vector<int>> algo2 = full_permutations_without_matrix();
    print_results(algo2.first, algo2.second);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    std::cout << "Execution time: " << duration1.count() << " microseconds" << std::endl
              << std::endl;

    std::ofstream viz("graph.dot");
    showGraph(viz);
    std::cout << "DFS:\n";
    auto start2 = high_resolution_clock::now();
    std::pair<int, std::vector<int>> algo3 = dfs();
    print_results(algo3.first, algo3.second);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    std::cout << "Execution time: " << duration2.count() << " microseconds" << std::endl;
}

void Graph::print_results(int result, std::vector<int> route)
{
    if (result == -1 || result == INT_MAX)
    {
        std::cout << "There isn't a route which passes trough all towns exactly once.\n";
        return;
    }
    std::cout << "Weight of shortest route: " << result << std::endl;
    std::cout << "Shortest route: ";
    for (int i = 0; i < towns_size; i++)
    {
        std::cout << map_reverse[route[i]] << " -> ";
    }
    std::cout << hometown_name;
    std::cout << std::endl;
}
