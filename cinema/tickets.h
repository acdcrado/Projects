#pragma once
#include<string>
#include<iostream>

/// Class representing a given ticket.
/// 
/// Base class, which contains information about the row and seat of the ticket, the unique code and the ticket's state.

class Ticket {
    std::string state_of_seat;
    std::string u_Code;
    int row;
    int seat;

    void copy (const std::string&, const std::string&, const int&, const int&);
    /// Creates a ticket from four given **strings**.
    void setter (const std::string& , const std::string& , const std::string& ,const std::string& );
    public:

    Ticket ();
    Ticket (const std::string&,const std::string&, const std::string&, const std::string&);
    Ticket (const std::string&, const std::string& , const int&, const int&);
    Ticket (const std::string&, const std::string&);
    Ticket (const  Ticket&);
    Ticket& operator = (const  Ticket&);
    ~Ticket()=default;

    void set_state_of_seat (const std::string&);
    void print() const ; 
    /// Generated a unique code for the ticket.
    void generate_code (int, int);
    /// Reads the uniqe code and print't the information about the ticket.
    void read_code (const std::string&) const;
    /// Check's whether the ticket is free or not.
    bool is_free () const;

    const std::string get_state_of_seat () const;
    const std::string get_u_Code () const;
    const int get_row () const;
    const int get_seat () const;
};
