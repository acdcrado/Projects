#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
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
#include "ts.h"

TEST_CASE("map1_distance"){
    std::ifstream map;
    map.open("map1.txt", std::ios::in);
    Graph test;
    test.load_map(map);
    test.fill_matrix();
    CHECK(test.full_permutations_with_matrix().first==990);
    CHECK(test.full_permutations_without_matrix().first==990);
    CHECK(test.dfs().first==990);
}
TEST_CASE("map2_distance"){
    std::ifstream map;
    map.open("map2.txt", std::ios::in);
    Graph test;
    test.load_map(map);
    test.fill_matrix();
    CHECK(test.full_permutations_with_matrix().first==1150);
    CHECK(test.full_permutations_without_matrix().first==1150);
    CHECK(test.dfs().first==1150);
}
TEST_CASE("map3_distance"){
    std::ifstream map;
    map.open("map3.txt", std::ios::in);
    Graph test;
    test.load_map(map);
    test.fill_matrix();
    CHECK(test.full_permutations_with_matrix().first==1115);
    CHECK(test.full_permutations_without_matrix().first==1115);
    CHECK(test.dfs().first==1115);
}
TEST_CASE("map4_distance"){
    std::ifstream map;
    map.open("map4.txt", std::ios::in);
    Graph test;
    test.load_map(map);
    test.fill_matrix();
    CHECK(test.full_permutations_with_matrix().first==1021);
    CHECK(test.full_permutations_without_matrix().first==1021);
    CHECK(test.dfs().first==1021);
}
TEST_CASE("map5_distance"){
    std::ifstream map;
    map.open("map5.txt", std::ios::in);
    Graph test;
    test.load_map(map);
    test.fill_matrix();
    CHECK(test.full_permutations_with_matrix().first==1218);
    CHECK(test.full_permutations_without_matrix().first==1218);
    CHECK(test.dfs().first==1218);
}
TEST_CASE("map6_distance"){
    std::ifstream map;
    map.open("map6.txt", std::ios::in);
    Graph test;
    test.load_map(map);
    test.fill_matrix();
    CHECK(test.full_permutations_with_matrix().first==1169);
    CHECK(test.full_permutations_without_matrix().first==1169);
    CHECK(test.dfs().first==1169);
}