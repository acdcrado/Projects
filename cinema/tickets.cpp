#include<iostream>
#include<string>
#include "tickets.h"
#include <cmath>
int to_int(const std::string &a){
    int result=0;
    int power=pow(10,a.size()-1);
    for(int i=0;i<a.size();i++){
        result=result +(a[i]-'0')*power;
        power=power/10;
    }
    return result;
}

int id=1000;

 Ticket:: Ticket(){
    state_of_seat="free";
    u_Code="999";
    row=0;
    seat=0;
}

void  Ticket::setter(const std::string& _state_of_seat, const std::string& _u_Code, const std::string& _row ,const std::string& _seat){
    state_of_seat=_state_of_seat;
    u_Code=_u_Code;
    row=to_int(_row);
    seat=to_int(_seat);
    id++;
}

void  Ticket::copy (const std::string& _state_of_seat, const std::string& _u_Code, const int& _row, const int& _seat) {
    state_of_seat = _state_of_seat;
    u_Code = _u_Code;
    row = _row;
    seat = _seat;
}
 Ticket:: Ticket(const std::string& _state_of_seat,const std::string& _u_Code, const std::string& _row, const std::string& _seat){
    setter(_state_of_seat, _u_Code,  _row , _seat);
}

 Ticket:: Ticket (const std::string& _state_of_seat,const std::string& _u_Code, const int& _row, const int& _seat) {
    copy(_state_of_seat, _u_Code, _row, _seat);
}

 Ticket:: Ticket (const  Ticket& other) {
    copy(other.state_of_seat, other.u_Code, other.row, other.seat);
}
Ticket::Ticket(const std::string& _row, const std::string& _seat){
    row=to_int(_row);
    seat=to_int(_seat);
}

 Ticket&  Ticket::operator = (const  Ticket& other) {
    if(this != &other) {
        copy(other.state_of_seat, other.u_Code, other.row, other.seat);
    }
    return *this;
}


const std::string  Ticket::get_state_of_seat () const {
    return state_of_seat;
}

const std::string  Ticket::get_u_Code() const {
    return u_Code;
}

const int  Ticket::get_row () const {
    return row;
}

const int  Ticket::get_seat () const {
    return seat;
}

void  Ticket::set_state_of_seat (const std::string& _state_of_seat) {
    state_of_seat=_state_of_seat;
}

bool  Ticket::is_free () const {
   return state_of_seat == "free";
}

void  Ticket::generate_code(int _row, int _seat) {
    std::string temp_code = std::to_string(id);
    temp_code = temp_code + 'r';
    temp_code = temp_code + std::to_string(_row);
    temp_code = temp_code + 's';
    temp_code = temp_code + std::to_string(_seat);
    u_Code = temp_code;
    id++;
    row =_row;
    seat =_seat;
}

void  Ticket::read_code (const std::string& _code) const {
    std::string _seat;
    std::string _row;
    int i=0;
    while(_code[i]!='r'){
        i++;
    }
    while(_code[i]!='s'){
        _row.push_back(_code[i]);
        i++;
    }
    while(i<_code.size()){   
        _seat.push_back(_code[i]);
        i++;
    }
    _seat.erase(_seat.begin());
    _row.erase(_row.begin());
    std::cout<<"Your seat is located on row "<<_row<<" and the it's number is "<<_seat<<".\n";
}

void  Ticket::print () const {
    std::cout<<"Code: "<<u_Code<<" Type: "<<state_of_seat<<" Row: "<<get_row()<<" Seat: "<<get_seat()<<"\n";
}