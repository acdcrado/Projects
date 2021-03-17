#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "tickets.h"
#include "events.h"
#include "auditorium.h"

/// Class containing all the auditoriums. It simulates the whole ticket system.
///
/// The class contians a **vector of Auditoriums** and almost all the functionalities of the program.

class Theatre{
    std::vector<Auditorium> auditoriums;

    public:
    Theatre()=default;
    Theatre(const Theatre&)=default;
    Theatre& operator = (const Theatre&)=default;
    ~Theatre()=default;

    std::vector<Auditorium>& get_auditoriums();

    void print();
    /// Adds a event with a given name to a given auditorium on a given date.
    void add_event(Event&);
    /// Gives information about the free tickets for a given event on a given date
    void free_seats(Event&);
    /// Books a tickets on a given row and seat for a given event on a given date
    void book_ticket(Ticket&, std::string*);
    /// Unbooks a tickets on a given row and seat for a given event on a given date
    void unbook_ticket(Ticket&, std::string*);
    /// Buys a tickets on a given row and seat for a given event on a given date
    void buy_ticket(Ticket&, std::string*);
    /// Gives the information about a tickets through lookin at it's code
    void check_code(std::string&);
    /// Gives the booked but not sold tickets for a given event on a given date
    void bookings(Event&);
    /// Gives information about the sold tickets for a period of time in a given auditortium
    void report(std::string&, std::string&, std::string&);
    
    /// Opens the theatre
    void open();

    /// Loads auditoriums from a file with auditoriums only
    void load_auditoriums(std::istream &);
    /// Loads events from a file with events only
    void load_events(std::istream &);

    /// Checks if the date is valid
    bool is_valid_date(const std::string&);
    /// Checks if there are other events in this auditorium on this date
    bool is_date_free(const std::string&);

    /// Writes the informaiton about the theatre in a file
    void all_in_file(std::ofstream &);
    /// Loads the information about the theatre from a file
    void load_from_file(std::istream &);

    bool found_date(const std::string&);
    int find_code_index(const std::string&, const int&, const int&);
};

