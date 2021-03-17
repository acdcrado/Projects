#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "tickets.h"
#include "events.h"

/// Class representing a given auditorium.
///
/// The class contains information about the number of rows and seats on each row in the given auditorium, it's id and the events in it.

class Auditorium{
    int id;
    int rows;
    int seats_on_row;
    std::vector<Event> events;

    public:
    Auditorium()=default;
    Auditorium(std::string&, std::string&, std::string&);
    std::vector<Event>& get_events();
 
    int get_id()const;
    int get_rows()const;
    int get_seats_on_row()const;
    void print();
};