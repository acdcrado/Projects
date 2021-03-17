#pragma once
#include<string>
#include<math.h>
#include<iostream>
#include<vector>


// int to_int(const std::string &a){
//     int result=0;
//     int power=pow(10,a.size()-1);
//     for(int i=0;i<a.size();i++){
//         result=result +(a[i]-'0')*power;
//         power=power/10;
//     }
//     return result;
// }

// void deleteFirst(std::string *str)
// {
//     for (int i = 0; i < 7; i++)
//     {
//         str[i] = str[i + 1];
//     }
// }

// void word_maker(std::string input, std::string *result)
// {
//     int curstring = 0;
//     for (int i = 0; i < 8; i++)
//     {
//         result[i].clear();
//     }
//     for (int i = 0; i < input.size(); i++)
//     {
//         if (input.at(i) == ' ')
//         {
//             curstring++;
//         }
//         else
//         {
//             result[curstring].push_back(input.at(i));
//         }
//     }
// }



// void load_auditoriums_from_file(std::istream &cin, std::vector<Auditorium> &_auditoriums){
//     std::string info[3];
//     for (std::string line; getline(cin, line);)
//     {
//         word_maker(line, info);
//         Auditorium temp_auditorium(info[0],info[1],info[2]);
//         _auditoriums.push_back(temp_auditorium);
//     }
// }
