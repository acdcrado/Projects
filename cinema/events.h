#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "tickets.h"

/// Class representing a given event.
///
/// The class contains information about the name and date of the event, the auditorium in which it is and all the bought or booked tickets.

class Event{
    std::string name;
    std::string date;
    int auditorium;
    std::vector<Ticket> tickets;

    void copy(const std::string&,const std::string &, const int&,const std::vector<Ticket>& );

    public:
    Event()=default;
    Event(const std::string&,const std::string &, const int&);
    Event(const std::string&,const std::string &);
    Event(const std::string&,const std::string &, const std::string&);
    Event(const std::string&,const std::string &, const int&, const std::vector<Ticket>&);
    Event(const Event &)=default;
    Event& operator = (const Event &)=default;
    ~Event()=default;

    void print();

    std::string get_date()const;
    std::string get_name()const;
    std::vector<Ticket>& get_tickets();
    int get_auditorium()const;
    /// Gives the number of bought tickets for a given event.
    int bought_tickets()const;
};