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

bool nextPermutation(int *begin, int *end)
{
    if (begin == end)
        return false;

    int *i = begin;
    ++i;
    if (i == end)
        return false;

    i = end;
    --i;

    while (true)
    {
        int *j = i;
        --i;

        if (*i < *j)
        {
            int *k = end;

            while (!(*i < *--k))
             /* pass */;

            std::iter_swap(i, k);
            std::reverse(j, end);
            return true;
        }

        if (i == begin)
        {
            std::reverse(begin, end);
            return false;
        }
    }
}

int min(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

void word_maker(std::string input, std::string *result)
{
    int curstring = 0;
    for (int i = 0; i < 3; i++)
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

int to_int(const std::string &a)
{
    int result = 0;
    int power = pow(10, a.size() - 1);
    for (int i = 0; i < a.size(); i++)
    {
        result = result + (a[i] - '0') * power;
        power = power / 10;
    }
    return result;
}
